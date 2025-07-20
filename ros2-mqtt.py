#!/usr/bin/env python3
"""
ROS2 → MQTT 자동 브리지
현재 시스템의 모든 ROS2 토픽을 자동으로 감지하고 MQTT로 전송

존재하는 모든 데이터의 흐름을 놓치지 않고 포착하는 완전한 관찰자
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSReliabilityPolicy, QoSHistoryPolicy
import json
import ssl
import time
import yaml
import logging
import threading
from datetime import datetime
from pathlib import Path
from typing import Dict, Any, Optional, List, Set
import importlib
import traceback

import paho.mqtt.client as mqtt

# ROS2 메시지 타입 동적 임포트를 위한 헬퍼
def import_message_type(msg_type_str: str):
    """메시지 타입 문자열에서 실제 클래스를 동적으로 임포트"""
    try:
        # 예: 'geometry_msgs/msg/Twist' -> geometry_msgs.msg, Twist
        parts = msg_type_str.split('/')
        if len(parts) >= 3:
            package = parts[0]
            module = parts[1] 
            class_name = parts[2]
            
            module_path = f"{package}.{module}"
            msg_module = importlib.import_module(module_path)
            return getattr(msg_module, class_name)
    except Exception as e:
        print(f"메시지 타입 임포트 실패 {msg_type_str}: {e}")
        return None

class UniversalROSMQTTBridge(Node):
    """모든 ROS2 토픽을 자동으로 처리하는 범용 브리지"""
    
    def __init__(self, config_path="config/settings.yaml"):
        super().__init__('universal_ros_mqtt_bridge')
        
        self.config = self._load_config(config_path)
        self.mqtt_client = None
        
        # 동적 구독자 관리
        self.active_subscribers = {}
        self.topic_types = {}
        self.topic_stats = {}
        
        # 토픽 필터링
        self.ignored_topics = set([
            '/rosout',
            '/rosout_agg', 
            '/parameter_events',
            '/robot_description',
            # 대용량 데이터 토픽들 (선택적 제외)
            # '/camera/image_raw',  # 원시 이미지는 제외하고 compressed만
        ])
        
        self.topic_patterns_to_ignore = [
            '/tf',  # TF 데이터는 너무 빈번함
            '/tf_static',
        ]
        
        # 통계
        self.published_count = 0
        self.start_time = datetime.now()
        self.last_discovery_time = None
        
        # 로깅 설정
        self.setup_logging()
        
        # QoS 프로필
        self.qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=1
        )
        
        self.get_logger().info("🤖 범용 ROS2-MQTT 브리지 초기화 완료")
        
    def _load_config(self, config_path):
        """설정 파일 로드"""
        try:
            with open(config_path, 'r', encoding='utf-8') as f:
                return yaml.safe_load(f)
        except FileNotFoundError:
            # 기본 설정 사용
            return {
                'mqtt': {
                    'broker': 'p021f2cb.ala.asia-southeast1.emqxsl.com',
                    'port': 8883,
                    'username': 'Rokey',
                    'password': '1234567',
                    'use_tls': True
                }
            }
    
    def setup_logging(self):
        """로깅 시스템 설정"""
        logging.basicConfig(
            level=logging.INFO,
            format='%(asctime)s - %(levelname)s - [ROS2-MQTT] %(message)s'
        )
        self.logger = logging.getLogger(__name__)
    
    def setup_mqtt(self):
        """MQTT 클라이언트 설정"""
        mqtt_config = self.config['mqtt']
        
        # 클라이언트 생성
        client_id = f"ros2_universal_bridge_{int(time.time())}"
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
        
        # 콜백 설정
        self.mqtt_client.on_connect = self._on_mqtt_connect
        self.mqtt_client.on_disconnect = self._on_mqtt_disconnect
        self.mqtt_client.on_publish = self._on_mqtt_publish
        
        # 연결
        try:
            self.mqtt_client.connect(
                mqtt_config['broker'], 
                mqtt_config['port'], 
                keepalive=60
            )
            self.mqtt_client.loop_start()
            self.get_logger().info(f"MQTT 브로커 연결: {mqtt_config['broker']}:{mqtt_config['port']}")
            return True
        except Exception as e:
            self.get_logger().error(f"MQTT 연결 실패: {e}")
            return False
    
    def _on_mqtt_connect(self, client, userdata, flags, rc):
        """MQTT 연결 콜백"""
        if rc == 0:
            self.get_logger().info("✅ MQTT 브로커에 연결됨")
        else:
            self.get_logger().error(f"❌ MQTT 연결 실패: {rc}")
    
    def _on_mqtt_disconnect(self, client, userdata, rc):
        """MQTT 연결 해제 콜백"""
        self.get_logger().warning("⚠️ MQTT 연결이 해제됨")
    
    def _on_mqtt_publish(self, client, userdata, mid):
        """MQTT 발행 콜백"""
        self.published_count += 1
    
    def discover_topics(self) -> Dict[str, str]:
        """현재 시스템의 모든 토픽을 자동 발견"""
        self.get_logger().info("🔍 ROS2 토픽 자동 발견 중...")
        
        try:
            # 현재 활성 토픽들과 타입 정보 가져오기
            topic_names_and_types = self.get_topic_names_and_types()
            
            discovered_topics = {}
            for topic_name, type_list in topic_names_and_types:
                if type_list:  # 타입 정보가 있는 경우
                    msg_type = type_list[0]  # 첫 번째 타입 사용
                    
                    # 필터링 적용
                    if self._should_ignore_topic(topic_name):
                        continue
                    
                    discovered_topics[topic_name] = msg_type
                    self.get_logger().debug(f"발견된 토픽: {topic_name} ({msg_type})")
            
            self.last_discovery_time = datetime.now()
            self.get_logger().info(f"📡 {len(discovered_topics)}개 토픽 발견됨")
            
            return discovered_topics
            
        except Exception as e:
            self.get_logger().error(f"토픽 발견 중 오류: {e}")
            return {}
    
    def _should_ignore_topic(self, topic_name: str) -> bool:
        """토픽을 무시해야 하는지 판단"""
        # 직접 무시 목록
        if topic_name in self.ignored_topics:
            return True
        
        # 패턴 매칭으로 무시
        for pattern in self.topic_patterns_to_ignore:
            if pattern in topic_name:
                return True
        
        return False
    
    def create_universal_callback(self, topic_name: str, msg_type_str: str):
        """범용 메시지 콜백 생성"""
        def callback(msg):
            try:
                # 메시지를 딕셔너리로 변환
                data = self._convert_ros_msg_to_dict(msg)
                
                # 메타데이터 추가
                data['_meta'] = {
                    'ros_topic': topic_name,
                    'ros_msg_type': msg_type_str,
                    'timestamp': datetime.now().isoformat(),
                    'source': 'ros2_universal_bridge'
                }
                
                # 통계 업데이트
                if topic_name not in self.topic_stats:
                    self.topic_stats[topic_name] = {
                        'count': 0,
                        'last_seen': None,
                        'first_seen': datetime.now()
                    }
                
                self.topic_stats[topic_name]['count'] += 1
                self.topic_stats[topic_name]['last_seen'] = datetime.now()
                
                # MQTT 토픽 생성 (ROS 토픽을 MQTT 호환 형태로 변환)
                mqtt_topic = self._ros_topic_to_mqtt_topic(topic_name)
                
                # MQTT로 발행
                self._publish_to_mqtt(mqtt_topic, data)
                
            except Exception as e:
                self.get_logger().error(f"메시지 처리 실패 {topic_name}: {e}")
                self.get_logger().debug(traceback.format_exc())
        
        return callback
    
    def _convert_ros_msg_to_dict(self, msg) -> Dict[str, Any]:
        """ROS 메시지를 딕셔너리로 변환 (재귀적)"""
        if hasattr(msg, '__slots__'):
            # ROS 메시지 객체인 경우
            result = {}
            for slot in msg.__slots__:
                value = getattr(msg, slot)
                result[slot] = self._convert_value_to_serializable(value)
            return result
        else:
            # 기본 타입인 경우
            return self._convert_value_to_serializable(msg)
    
    def _convert_value_to_serializable(self, value) -> Any:
        """값을 JSON 직렬화 가능한 형태로 변환"""
        if value is None:
            return None
        elif isinstance(value, (bool, int, float, str)):
            return value
        elif isinstance(value, (list, tuple)):
            # 리스트/튜플의 경우 길이 제한 (성능상 이유)
            if len(value) > 1000:
                return {
                    '_truncated': True,
                    '_original_length': len(value),
                    '_sample': [self._convert_value_to_serializable(v) for v in value[:10]],
                    '_summary': {
                        'min': min(value) if value and isinstance(value[0], (int, float)) else None,
                        'max': max(value) if value and isinstance(value[0], (int, float)) else None,
                        'avg': sum(value) / len(value) if value and isinstance(value[0], (int, float)) else None
                    }
                }
            else:
                return [self._convert_value_to_serializable(v) for v in value]
        elif hasattr(value, '__slots__'):
            # 중첩된 ROS 메시지
            return self._convert_ros_msg_to_dict(value)
        elif hasattr(value, '__dict__'):
            # 다른 객체
            return {k: self._convert_value_to_serializable(v) for k, v in value.__dict__.items()}
        else:
            # 변환할 수 없는 경우 문자열로
            return str(value)
    
    def _ros_topic_to_mqtt_topic(self, ros_topic: str) -> str:
        """ROS 토픽을 MQTT 토픽으로 변환"""
        # '/cmd_vel' -> 'ros2/cmd_vel'
        # '/turtle1/cmd_vel' -> 'ros2/turtle1/cmd_vel'
        mqtt_topic = ros_topic.lstrip('/')  # 앞의 '/' 제거
        mqtt_topic = mqtt_topic.replace('/', '_')  # '/'를 '_'로 변경
        return f"ros2/{mqtt_topic}"
    
    def _publish_to_mqtt(self, mqtt_topic: str, data: Dict[str, Any]):
        """MQTT로 데이터 발행"""
        if not self.mqtt_client:
            return
        
        try:
            # JSON 직렬화
            payload = json.dumps(data, default=str, ensure_ascii=False)
            
            # 페이로드 크기 체크 (MQTT 제한)
            if len(payload.encode('utf-8')) > 250000:  # 250KB 제한
                # 큰 메시지는 요약만 전송
                summary_data = {
                    '_large_message': True,
                    '_original_size': len(payload),
                    '_meta': data.get('_meta', {}),
                    '_summary': 'Message too large for MQTT transmission'
                }
                payload = json.dumps(summary_data, default=str)
            
            # MQTT 발행
            result = self.mqtt_client.publish(mqtt_topic, payload, qos=1)
            
            if result.rc == mqtt.MQTT_ERR_SUCCESS:
                self.get_logger().debug(f"📤 MQTT 발행: {mqtt_topic}")
            else:
                self.get_logger().error(f"❌ MQTT 발행 실패: {mqtt_topic} (code: {result.rc})")
                
        except Exception as e:
            self.get_logger().error(f"MQTT 발행 중 오류: {e}")
    
    def update_subscriptions(self):
        """구독 상태를 현재 토픽들과 동기화"""
        current_topics = self.discover_topics()
        
        # 새로운 토픽들 구독
        for topic_name, msg_type_str in current_topics.items():
            if topic_name not in self.active_subscribers:
                self._subscribe_to_topic(topic_name, msg_type_str)
        
        # 사라진 토픽들 구독 해제
        disappeared_topics = set(self.active_subscribers.keys()) - set(current_topics.keys())
        for topic_name in disappeared_topics:
            self._unsubscribe_from_topic(topic_name)
    
    def _subscribe_to_topic(self, topic_name: str, msg_type_str: str):
        """특정 토픽 구독"""
        try:
            # 메시지 타입 동적 임포트
            msg_class = import_message_type(msg_type_str)
            if msg_class is None:
                self.get_logger().warning(f"⚠️ 메시지 타입 로드 실패: {msg_type_str}")
                return
            
            # 콜백 생성
            callback = self.create_universal_callback(topic_name, msg_type_str)
            
            # 구독자 생성
            subscriber = self.create_subscription(
                msg_class,
                topic_name,
                callback,
                self.qos_profile
            )
            
            self.active_subscribers[topic_name] = subscriber
            self.topic_types[topic_name] = msg_type_str
            
            self.get_logger().info(f"📡 토픽 구독 시작: {topic_name} ({msg_type_str})")
            
        except Exception as e:
            self.get_logger().error(f"❌ 토픽 구독 실패 {topic_name}: {e}")
            self.get_logger().debug(traceback.format_exc())
    
    def _unsubscribe_from_topic(self, topic_name: str):
        """특정 토픽 구독 해제"""
        if topic_name in self.active_subscribers:
            try:
                self.destroy_subscription(self.active_subscribers[topic_name])
                del self.active_subscribers[topic_name]
                if topic_name in self.topic_types:
                    del self.topic_types[topic_name]
                
                self.get_logger().info(f"📡 토픽 구독 해제: {topic_name}")
                
            except Exception as e:
                self.get_logger().error(f"❌ 토픽 구독 해제 실패 {topic_name}: {e}")
    
    def print_stats(self):
        """통계 정보 출력"""
        uptime = datetime.now() - self.start_time
        rate = self.published_count / uptime.total_seconds() if uptime.total_seconds() > 0 else 0
        
        self.get_logger().info(f"📊 브리지 통계:")
        self.get_logger().info(f"   📤 발행된 메시지: {self.published_count}")
        self.get_logger().info(f"   🚀 발행률: {rate:.2f} msg/sec")
        self.get_logger().info(f"   📡 활성 구독: {len(self.active_subscribers)}개")
        self.get_logger().info(f"   ⏱️ 업타임: {uptime}")
        
        # 토픽별 통계 (상위 5개)
        if self.topic_stats:
            sorted_topics = sorted(
                self.topic_stats.items(), 
                key=lambda x: x[1]['count'], 
                reverse=True
            )[:5]
            
            self.get_logger().info("   🏆 최다 메시지 토픽:")
            for topic, stats in sorted_topics:
                self.get_logger().info(f"     • {topic}: {stats['count']}개")
    
    def run(self):
        """브리지 실행"""
        self.get_logger().info("🤖 범용 ROS2-MQTT 브리지 시작")
        
        # MQTT 연결
        if not self.setup_mqtt():
            self.get_logger().error("❌ MQTT 연결 실패 - 브리지를 시작할 수 없습니다")
            return
        
        # 초기 토픽 발견 및 구독
        self.update_subscriptions()
        
        # 주기적 작업을 위한 타이머
        self.discovery_timer = self.create_timer(10.0, self.update_subscriptions)  # 10초마다 토픽 재발견
        self.stats_timer = self.create_timer(30.0, self.print_stats)  # 30초마다 통계 출력
        
        self.get_logger().info("🚀 브리지가 정상적으로 시작됨")
        self.get_logger().info("🌊 모든 ROS2 토픽이 MQTT로 흘러갑니다...")
        
        # ROS2 스핀
        try:
            rclpy.spin(self)
        except KeyboardInterrupt:
            self.get_logger().info("👋 사용자에 의한 종료")
        finally:
            self.shutdown()
    
    def shutdown(self):
        """브리지 종료"""
        self.get_logger().info("🔄 브리지 종료 중...")
        
        # 모든 구독자 정리
        for topic_name in list(self.active_subscribers.keys()):
            self._unsubscribe_from_topic(topic_name)
        
        # MQTT 연결 종료
        if self.mqtt_client:
            self.mqtt_client.loop_stop()
            self.mqtt_client.disconnect()
        
        # 최종 통계 출력
        self.print_stats()
        
        self.get_logger().info("✅ 브리지가 정상적으로 종료됨")

def main():
    """메인 실행 함수"""
    rclpy.init()
    
    try:
        bridge = UniversalROSMQTTBridge()
        bridge.run()
    except Exception as e:
        print(f"❌ 브리지 실행 중 오류: {e}")
        traceback.print_exc()
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()