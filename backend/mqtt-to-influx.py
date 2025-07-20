#!/usr/bin/env python3
"""
MQTT → InfluxDB 정밀 브리지
데이터의 흐름을 정확히 포착하고, 손실 없이 전달하는 견고한 연결고리

Author: Lyra
Version: 2.0.0
"""

import ssl
import json
import yaml
import time
import logging
import signal
import sys
import threading
from datetime import datetime, timezone
from pathlib import Path
from typing import Dict, Any, Optional, List
from dataclasses import dataclass
from queue import Queue, Empty
import traceback

import paho.mqtt.client as mqtt
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS, ASYNCHRONOUS
from influxdb_client.client.exceptions import InfluxDBError

# 로깅 설정
def setup_logging(level=logging.INFO, log_file=None):
    """로깅 시스템을 정교하게 설정합니다"""
    formatter = logging.Formatter(
        '%(asctime)s | %(levelname)-8s | %(name)-20s | %(message)s',
        datefmt='%Y-%m-%d %H:%M:%S'
    )
    
    # 콘솔 핸들러
    console_handler = logging.StreamHandler()
    console_handler.setFormatter(formatter)
    
    # 파일 핸들러 (선택사항)
    handlers = [console_handler]
    if log_file:
        file_handler = logging.FileHandler(log_file, encoding='utf-8')
        file_handler.setFormatter(formatter)
        handlers.append(file_handler)
    
    logging.basicConfig(
        level=level,
        handlers=handlers,
        force=True
    )

@dataclass
class MQTTMessage:
    """MQTT 메시지를 구조화된 형태로 담는 그릇"""
    topic: str
    payload: str
    qos: int
    retain: bool
    timestamp: datetime
    
    def __post_init__(self):
        if isinstance(self.timestamp, str):
            self.timestamp = datetime.fromisoformat(self.timestamp)

@dataclass
class InfluxPoint:
    """InfluxDB 포인트 데이터"""
    measurement: str
    tags: Dict[str, str]
    fields: Dict[str, Any]
    timestamp: datetime

class MessageProcessor:
    """MQTT 메시지를 InfluxDB 포인트로 변환하는 처리기"""
    
    def __init__(self, default_measurement="mqtt_message"):
        self.default_measurement = default_measurement
        self.logger = logging.getLogger(self.__class__.__name__)
        
    def process_message(self, mqtt_msg: MQTTMessage) -> List[InfluxPoint]:
        """MQTT 메시지를 InfluxDB 포인트로 변환"""
        try:
            # 기본 태그 설정
            base_tags = self._extract_topic_tags(mqtt_msg.topic)
            base_tags.update({
                "topic": mqtt_msg.topic,
                "qos": str(mqtt_msg.qos),
                "retain": str(mqtt_msg.retain).lower()
            })
            
            # 페이로드 파싱
            fields = self._parse_payload(mqtt_msg.payload)
            
            # 복수의 포인트가 필요한 경우 (JSON 객체의 각 필드별로)
            points = []
            
            if isinstance(fields, dict) and len(fields) > 1:
                # JSON 객체인 경우: 각 필드를 별도 측정으로 분리
                for field_name, field_value in fields.items():
                    if self._is_numeric(field_value):
                        points.append(InfluxPoint(
                            measurement=f"{self.default_measurement}_{field_name}",
                            tags=base_tags.copy(),
                            fields={"value": field_value},
                            timestamp=mqtt_msg.timestamp
                        ))
                    else:
                        # 문자열 필드는 태그로 추가
                        string_tags = base_tags.copy()
                        string_tags[field_name] = str(field_value)
                        points.append(InfluxPoint(
                            measurement=f"{self.default_measurement}_meta",
                            tags=string_tags,
                            fields={"present": 1},
                            timestamp=mqtt_msg.timestamp
                        ))
            else:
                # 단일 값이거나 단순한 경우
                points.append(InfluxPoint(
                    measurement=self.default_measurement,
                    tags=base_tags,
                    fields=fields if isinstance(fields, dict) else {"value": fields},
                    timestamp=mqtt_msg.timestamp
                ))
                
            return points
            
        except Exception as e:
            self.logger.error(f"메시지 처리 실패: {mqtt_msg.topic} -> {e}")
            # 실패한 경우에도 raw 메시지는 보존
            return [InfluxPoint(
                measurement="mqtt_raw_error",
                tags={"topic": mqtt_msg.topic, "error": str(e)},
                fields={"raw_payload": mqtt_msg.payload},
                timestamp=mqtt_msg.timestamp
            )]
    
    def _extract_topic_tags(self, topic: str) -> Dict[str, str]:
        """토픽에서 의미있는 태그를 추출"""
        parts = topic.split('/')
        tags = {}
        
        if len(parts) >= 1:
            tags["category"] = parts[0]
        if len(parts) >= 2:
            tags["subcategory"] = parts[1]
        if len(parts) >= 3:
            tags["device_id"] = parts[2]
            
        # 토픽 깊이 정보
        tags["topic_depth"] = str(len(parts))
        
        return tags
    
    def _parse_payload(self, payload: str) -> Any:
        """페이로드를 적절한 형태로 파싱"""
        if not payload:
            return {"empty": True}
            
        # JSON 파싱 시도
        try:
            data = json.loads(payload)
            if isinstance(data, dict):
                # 딕셔너리의 모든 값을 적절한 타입으로 변환
                parsed = {}
                for key, value in data.items():
                    parsed[self._sanitize_field_name(key)] = self._convert_value(value)
                return parsed
            else:
                return self._convert_value(data)
        except json.JSONDecodeError:
            pass
        
        # 숫자 파싱 시도
        try:
            if '.' in payload:
                return float(payload)
            else:
                return int(payload)
        except ValueError:
            pass
        
        # 불린 파싱 시도
        if payload.lower() in ('true', 'false', 'on', 'off', '1', '0'):
            return payload.lower() in ('true', 'on', '1')
        
        # 기본적으로 문자열로 처리
        return payload
    
    def _sanitize_field_name(self, name: str) -> str:
        """InfluxDB 필드명 규칙에 맞게 정리"""
        # 특수문자를 언더스코어로 변경
        import re
        sanitized = re.sub(r'[^a-zA-Z0-9_]', '_', str(name))
        # 숫자로 시작하면 접두사 추가
        if sanitized[0].isdigit():
            sanitized = f"field_{sanitized}"
        return sanitized.lower()
    
    def _convert_value(self, value: Any) -> Any:
        """값을 InfluxDB 호환 타입으로 변환"""
        if isinstance(value, (int, float, bool)):
            return value
        elif isinstance(value, str):
            # 문자열 길이 제한 (InfluxDB 성능을 위해)
            return value[:1000] if len(value) > 1000 else value
        else:
            return str(value)[:1000]
    
    def _is_numeric(self, value: Any) -> bool:
        """값이 숫자인지 확인"""
        return isinstance(value, (int, float)) and not isinstance(value, bool)

class InfluxDBManager:
    """InfluxDB 연결과 쓰기를 관리하는 클래스"""
    
    def __init__(self, config: Dict[str, Any]):
        self.config = config
        self.client: Optional[InfluxDBClient] = None
        self.write_api = None
        self.logger = logging.getLogger(self.__class__.__name__)
        
        # 성능 메트릭
        self.write_count = 0
        self.error_count = 0
        self.last_write_time = None
        
    def connect(self) -> bool:
        """InfluxDB에 연결"""
        try:
            # SSL 검증 비활성화로 시도 (디버깅용)
            import ssl
            ssl_context = ssl.create_default_context()
            ssl_context.check_hostname = False
            ssl_context.verify_mode = ssl.CERT_NONE
            
            self.client = InfluxDBClient(
                url=self.config['url'],
                token=self.config['token'],
                org=self.config['org'],
                timeout=30000,  # 30초 타임아웃
                verify_ssl=False  # SSL 검증 비활성화
            )
            
            # 연결 테스트
            self.logger.info(f"InfluxDB 연결 시도: {self.config['url']}")
            self.logger.info(f"조직: {self.config['org']}, 버킷: {self.config['bucket']}")
            
            health = self.client.health()
            self.logger.info(f"Health check 결과: status={health.status}, message={health.message}")
            
            if health.status == "pass":
                self.logger.info(f"InfluxDB 연결 성공: {self.config['url']}")
                
                # 비동기 쓰기 API 설정 (성능 향상)
                self.write_api = self.client.write_api(
                    write_options=ASYNCHRONOUS,
                    batch_size=1000,
                    flush_interval=1000,  # 1초마다 플러시
                    jitter_interval=100,
                    retry_interval=1000
                )
                
                return True
            else:
                self.logger.error(f"InfluxDB 상태 불량: {health.status} - {health.message}")
                return False
                
        except Exception as e:
            self.logger.error(f"InfluxDB 연결 실패: {e}")
            return False
    
    def write_points(self, points: List[InfluxPoint]) -> bool:
        """포인트들을 InfluxDB에 쓰기"""
        if not self.write_api:
            self.logger.error("InfluxDB가 연결되지 않음")
            return False
        
        try:
            influx_points = []
            for point_data in points:
                measurement = point_data.measurement or self.config.get("default_measurement", "mqtt_message")
                if not measurement:
                    self.logger.warning("측정값(measurement)이 None입니다. 기본값 'mqtt_message'로 대체합니다.")
                    measurement = "mqtt_message"
                    
                point = Point(point_data.measurement)
                
                # 태그 추가
                for tag_key, tag_value in point_data.tags.items():
                    point = point.tag(tag_key, str(tag_value))
                
                # 필드 추가
                for field_key, field_value in point_data.fields.items():
                    point = point.field(field_key, field_value)
                
                # 타임스탬프 설정
                point = point.time(point_data.timestamp, WritePrecision.NS)
                influx_points.append(point)
            
            # 배치 쓰기
            self.write_api.write(
                bucket=self.config['bucket'],
                record=influx_points
            )
            
            self.write_count += len(points)
            self.last_write_time = datetime.now()
            
            self.logger.debug(f"InfluxDB 쓰기 성공: {len(points)}개 포인트")
            return True
            
        except InfluxDBError as e:
            self.error_count += 1
            self.logger.error(f"InfluxDB 쓰기 오류: {e}")
            return False
        except Exception as e:
            self.error_count += 1
            self.logger.error(f"예상치 못한 쓰기 오류: {e}")
            return False
    
    def get_stats(self) -> Dict[str, Any]:
        """통계 정보 반환"""
        return {
            "write_count": self.write_count,
            "error_count": self.error_count,
            "last_write_time": self.last_write_time.isoformat() if self.last_write_time else None,
            "success_rate": (self.write_count / (self.write_count + self.error_count)) * 100 if (self.write_count + self.error_count) > 0 else 0
        }
    
    def close(self):
        """연결 종료"""
        if self.write_api:
            self.write_api.close()
        if self.client:
            self.client.close()
        self.logger.info("InfluxDB 연결이 종료되었습니다")
            

class MQTTInfluxBridge:
    """정밀하고 견고한 MQTT-InfluxDB 브리지"""
    
    def __init__(self, config_path: str = None):
        if config_path is None:
            base_dir = Path(__file__).resolve().parent.parent  # backend/ 상위 폴더
            config_path = base_dir / "config/settings.yaml"
            
        self.config_path = config_path
        self.config = self._load_config()
        
        # 컴포넌트 초기화
        self.mqtt_client: Optional[mqtt.Client] = None
        self.influx_manager = InfluxDBManager(self.config['influxdb'])
        self.message_processor = MessageProcessor()
        
        # 메시지 큐 (비동기 처리용)
        self.message_queue = Queue(maxsize=10000)
        self.processing_thread = None
        self.running = False
        
        # 성능 메트릭
        self.received_count = 0
        self.processed_count = 0
        self.start_time = None
        
        # 로거 설정
        self.logger = logging.getLogger(self.__class__.__name__)
        
        # 신호 핸들러 등록
        signal.signal(signal.SIGINT, self._signal_handler)
        signal.signal(signal.SIGTERM, self._signal_handler)
    
    def _load_config(self) -> Dict[str, Any]:
        """설정 파일 로드"""
        logger = logging.getLogger(self.__class__.__name__)  # 클래스 이름 기준 로거
        
        try:
            config_file = Path(self.config_path)
            if not config_file.exists():
                raise FileNotFoundError(f"설정 파일을 찾을 수 없습니다: {self.config_path}")
            
            with open(config_file, 'r', encoding='utf-8') as f:
                config = yaml.safe_load(f)

            if 'influxdb' not in config:
                raise ValueError("❌ 설정 파일에 'influxdb' 섹션이 없습니다.")

            logger.info("✅ 설정 파일 로드 성공")
            logger.debug(f"🔍 로드된 설정: {config['influxdb']}")  # 민감정보 토큰은 자르면 좋음

            return config

        except Exception as e:
            logger.error(f"❌ 설정 파일 로드 실패: {e}")
            sys.exit(1)

    
    def _validate_config(self, config: Dict[str, Any]):
        """설정 유효성 검증"""
        required_mqtt = ['broker', 'port', 'username', 'password', 'topics']
        required_influx = ['url', 'token', 'org', 'bucket']
        
        if 'mqtt' not in config:
            raise ValueError("MQTT 설정이 없습니다")
        
        if 'influxdb' not in config:
            raise ValueError("InfluxDB 설정이 없습니다")
        
        for key in required_mqtt:
            if key not in config['mqtt']:
                raise ValueError(f"MQTT 설정에 {key}가 없습니다")
        
        for key in required_influx:
            if key not in config['influxdb']:
                raise ValueError(f"InfluxDB 설정에 {key}가 없습니다")
    
    def _setup_mqtt(self) -> bool:
        """MQTT 클라이언트 설정"""
        try:
            mqtt_config = self.config['mqtt']
            
            # 클라이언트 생성
            client_id = mqtt_config.get('client_id', f"mqtt_bridge_{int(time.time())}")
            self.mqtt_client = mqtt.Client(client_id)
            
            # 인증 설정
            self.mqtt_client.username_pw_set(
                mqtt_config['username'], 
                mqtt_config['password']
            )
            
            # TLS 설정
            if mqtt_config.get('use_tls', True):
                context = ssl.create_default_context(ssl.Purpose.SERVER_AUTH)
                context.check_hostname = False
                context.verify_mode = ssl.CERT_NONE
                self.mqtt_client.tls_set_context(context)
                self.logger.info("TLS 암호화 활성화됨")
            
            # 콜백 설정
            self.mqtt_client.on_connect = self._on_connect
            self.mqtt_client.on_disconnect = self._on_disconnect
            self.mqtt_client.on_message = self._on_message
            self.mqtt_client.on_log = self._on_log
            
            # 연결 설정
            self.mqtt_client.connect_async(
                mqtt_config['broker'], 
                mqtt_config['port'], 
                keepalive=60
            )
            
            return True
            
        except Exception as e:
            self.logger.error(f"MQTT 설정 실패: {e}")
            return False
    
    def _on_connect(self, client, userdata, flags, rc):
        """MQTT 연결 콜백"""
        if rc == 0:
            self.logger.info("MQTT 브로커에 연결됨")
            
            # 구독 설정
            topics = self.config['mqtt']['topics']
            for topic in topics:
                result = client.subscribe(topic, qos=1)
                if result[0] == mqtt.MQTT_ERR_SUCCESS:
                    self.logger.info(f"토픽 구독 성공: {topic}")
                else:
                    self.logger.error(f"토픽 구독 실패: {topic} (code: {result[0]})")
        else:
            self.logger.error(f"MQTT 연결 실패: {mqtt.connack_string(rc)} (code: {rc})")
    
    def _on_disconnect(self, client, userdata, rc):
        """MQTT 연결 해제 콜백"""
        if rc != 0:
            self.logger.warning(f"예상치 못한 MQTT 연결 해제: {rc}")
        else:
            self.logger.info("MQTT 연결이 정상적으로 해제됨")
    
    def _on_message(self, client, userdata, msg):
        """MQTT 메시지 수신 콜백"""
        try:
            mqtt_message = MQTTMessage(
                topic=msg.topic,
                payload=msg.payload.decode('utf-8', errors='replace'),
                qos=msg.qos,
                retain=msg.retain,
                timestamp=datetime.now(timezone.utc)
            )
            
            self.received_count += 1
            
            # 큐에 메시지 추가 (비동기 처리)
            try:
                self.message_queue.put_nowait(mqtt_message)
                self.logger.debug(f"메시지 수신: {msg.topic} ({len(msg.payload)} bytes)")
            except:
                self.logger.warning("메시지 큐가 가득참 - 메시지 드롭됨")
                
        except Exception as e:
            self.logger.error(f"메시지 처리 중 오류: {e}")
    
    def _on_log(self, client, userdata, level, buf):
        """MQTT 로그 콜백"""
        if level <= mqtt.MQTT_LOG_WARNING:
            self.logger.debug(f"MQTT: {buf}")
    
    def _message_processing_loop(self):
        """메시지 처리 스레드"""
        self.logger.info("메시지 처리 스레드 시작됨")
        
        while self.running:
            try:
                # 큐에서 메시지 가져오기 (타임아웃 1초)
                mqtt_message = self.message_queue.get(timeout=1.0)
                
                # 메시지 처리
                points = self.message_processor.process_message(mqtt_message)
                
                # InfluxDB에 쓰기
                if self.influx_manager.write_points(points):
                    self.processed_count += 1
                
                self.message_queue.task_done()
                
            except Empty:
                continue
            except Exception as e:
                self.logger.error(f"메시지 처리 루프 오류: {e}")
                self.logger.debug(traceback.format_exc())
        
        self.logger.info("메시지 처리 스레드 종료됨")
    
    def _signal_handler(self, signum, frame):
        """시그널 핸들러"""
        self.logger.info(f"종료 신호 수신: {signum}")
        self.stop()
    
    def start(self):
        """브리지 시작"""
        self.logger.info("MQTT-InfluxDB 브리지 시작 중...")
        self.start_time = datetime.now()
        
        # InfluxDB 연결
        if not self.influx_manager.connect():
            self.logger.error("InfluxDB 연결 실패 - 브리지를 시작할 수 없습니다")
            return False
        
        # MQTT 설정
        if not self._setup_mqtt():
            self.logger.error("MQTT 설정 실패 - 브리지를 시작할 수 없습니다")
            return False
        
        # 실행 플래그 설정
        self.running = True
        
        # 메시지 처리 스레드 시작
        self.processing_thread = threading.Thread(
            target=self._message_processing_loop,
            name="MessageProcessor"
        )
        self.processing_thread.daemon = True
        self.processing_thread.start()
        
        # MQTT 클라이언트 시작
        self.mqtt_client.loop_start()
        
        self.logger.info("🚀 브리지가 성공적으로 시작되었습니다")
        
        # 주기적 상태 출력
        try:
            while self.running:
                time.sleep(30)  # 30초마다 상태 출력
                self._print_status()
        except KeyboardInterrupt:
            self.logger.info("사용자에 의한 중단 요청")
        
        return True
    
    def stop(self):
        """브리지 정지"""
        self.logger.info("브리지 종료 중...")
        
        self.running = False
        
        # MQTT 클라이언트 정지
        if self.mqtt_client:
            self.mqtt_client.loop_stop()
            self.mqtt_client.disconnect()
        
        # 큐에 남은 메시지 처리
        self.logger.info("남은 메시지 처리 중...")
        if self.processing_thread and self.processing_thread.is_alive():
            self.processing_thread.join(timeout=5)
        
        # InfluxDB 연결 종료
        self.influx_manager.close()
        
        # 최종 통계 출력
        self._print_final_stats()
        
        self.logger.info("✅ 브리지가 정상적으로 종료되었습니다")
    
    def _print_status(self):
        """현재 상태 출력"""
        uptime = datetime.now() - self.start_time if self.start_time else None
        queue_size = self.message_queue.qsize()
        influx_stats = self.influx_manager.get_stats()
        
        self.logger.info(
            f"📊 상태 - "
            f"수신: {self.received_count}, "
            f"처리: {self.processed_count}, "
            f"큐: {queue_size}, "
            f"InfluxDB 성공률: {influx_stats['success_rate']:.1f}%, "
            f"업타임: {uptime}"
        )
    
    def _print_final_stats(self):
        """최종 통계 출력"""
        if self.start_time:
            total_time = datetime.now() - self.start_time
            rate = self.processed_count / total_time.total_seconds() if total_time.total_seconds() > 0 else 0
            
            self.logger.info(f"📈 최종 통계:")
            self.logger.info(f"   총 처리 시간: {total_time}")
            self.logger.info(f"   수신된 메시지: {self.received_count}")
            self.logger.info(f"   처리된 메시지: {self.processed_count}")
            self.logger.info(f"   처리율: {rate:.2f} msg/sec")
            self.logger.info(f"   손실률: {((self.received_count - self.processed_count) / self.received_count * 100) if self.received_count > 0 else 0:.2f}%")

def main():
    """메인 실행 함수"""
    # 로깅 설정
    setup_logging(
        level=logging.INFO,
        log_file="mqtt-bridge.log"
    )
    
    logger = logging.getLogger(__name__)
    logger.info("=== MQTT-InfluxDB 정밀 브리지 시작 ===")
    
    try:
        # 브리지 생성 및 실행
        bridge = MQTTInfluxBridge()
        bridge.start()
        
    except Exception as e:
        logger.error(f"브리지 실행 중 치명적 오류: {e}")
        logger.debug(traceback.format_exc())
        sys.exit(1)

if __name__ == "__main__":
    main()