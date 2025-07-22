#!/usr/bin/env python3
"""
Crack Detection MQTT 신뢰성 측정 시스템 - 완성본
Publisher (Crack Detection) -> MQTT Broker -> Subscriber (Local Computer)
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy
from sensor_msgs.msg import Image, CameraInfo
from geometry_msgs.msg import PointStamped
from std_msgs.msg import String
import tf2_ros

import paho.mqtt.client as mqtt
import ssl
import json
import time
import threading
import statistics
import queue
from dataclasses import dataclass, asdict
from typing import Dict, List, Optional, Tuple
import numpy as np
from collections import defaultdict, deque
from datetime import datetime, timezone
import uuid
import psutil
import os
from cv_bridge import CvBridge
import cv2
import math
from ultralytics import YOLO

# ========================
# 신뢰성 메트릭 데이터 클래스
# ========================
@dataclass
class MQTTReliabilityMetrics:
    """MQTT 신뢰성 메트릭"""
    timestamp: float
    total_published: int
    total_received: int
    total_lost: int
    avg_latency_ms: float
    p95_latency_ms: float
    p99_latency_ms: float
    max_latency_ms: float
    min_latency_ms: float
    jitter_ms: float
    message_rate_per_sec: float
    throughput_kbps: float
    delivery_success_rate: float
    duplicate_count: int
    out_of_order_count: int
    broker_processing_time_ms: float

@dataclass
class MessageTracker:
    """개별 메시지 추적"""
    message_id: str
    sequence_number: int
    publish_timestamp_ns: int
    receive_timestamp_ns: Optional[int] = None
    payload_size: int = 0
    is_received: bool = False
    is_duplicate: bool = False
    latency_ms: Optional[float] = None

class MQTTReliabilityTracker:
    """MQTT 신뢰성 추적 클래스"""
    
    def __init__(self, window_size: int = 1000):
        self.window_size = window_size
        self.message_trackers: Dict[str, MessageTracker] = {}
        self.sequence_counter = 0
        self.latency_measurements = deque(maxlen=window_size)
        self.received_sequences = set()
        self.last_sequence = -1
        
        # 통계 변수
        self.total_published = 0
        self.total_received = 0
        self.total_lost = 0
        self.duplicate_count = 0
        self.out_of_order_count = 0
        self.total_bytes_sent = 0
        self.total_bytes_received = 0
        
        # 시간 기반 메트릭
        self.start_time = time.time()
        self.last_metrics_time = time.time()
        
        # 스레드 안전성
        self.lock = threading.Lock()
    
    def enhance_message_for_tracking(self, msg_dict: dict) -> dict:
        """메시지에 추적용 정보 추가"""
        with self.lock:
            self.sequence_counter += 1
            message_id = str(uuid.uuid4())
            publish_time_ns = time.time_ns()
            
            enhanced_msg = msg_dict.copy()
            enhanced_msg.update({
                'message_id': message_id,
                'sequence_number': self.sequence_counter,
                'publish_timestamp_ns': publish_time_ns,
                'publisher_id': 'crack_detector',
                'reliability_tracking': True
            })
            
            # 메시지 추적 시작
            payload_size = len(json.dumps(enhanced_msg).encode('utf-8'))
            tracker = MessageTracker(
                message_id=message_id,
                sequence_number=self.sequence_counter,
                publish_timestamp_ns=publish_time_ns,
                payload_size=payload_size
            )
            
            self.message_trackers[message_id] = tracker
            self.total_published += 1
            self.total_bytes_sent += payload_size
            
            return enhanced_msg
    
    def process_received_message(self, msg_dict: dict) -> Optional[float]:
        """수신된 메시지 처리 및 지연 시간 계산"""
        if not msg_dict.get('reliability_tracking', False):
            return None
            
        receive_time_ns = time.time_ns()
        message_id = msg_dict.get('message_id')
        sequence_number = msg_dict.get('sequence_number')
        
        if not message_id or not sequence_number:
            return None
        
        with self.lock:
            # 중복 검사
            if sequence_number in self.received_sequences:
                self.duplicate_count += 1
                return None
            
            self.received_sequences.add(sequence_number)
            
            # 순서 검사
            if sequence_number < self.last_sequence:
                self.out_of_order_count += 1
            self.last_sequence = max(self.last_sequence, sequence_number)
            
            # 지연 시간 계산
            if message_id in self.message_trackers:
                tracker = self.message_trackers[message_id]
                tracker.receive_timestamp_ns = receive_time_ns
                tracker.is_received = True
                
                latency_ms = (receive_time_ns - tracker.publish_timestamp_ns) / 1_000_000
                tracker.latency_ms = latency_ms
                
                self.latency_measurements.append(latency_ms)
                self.total_received += 1
                self.total_bytes_received += tracker.payload_size
                
                return latency_ms
        
        return None
    
    def cleanup_old_messages(self, max_age_seconds: float = 10.0):
        """오래된 메시지 정리"""
        current_time_ns = time.time_ns()
        cutoff_time_ns = current_time_ns - (max_age_seconds * 1_000_000_000)
        
        with self.lock:
            to_remove = []
            for message_id, tracker in self.message_trackers.items():
                if tracker.publish_timestamp_ns < cutoff_time_ns:
                    if not tracker.is_received:
                        self.total_lost += 1
                    to_remove.append(message_id)
            
            for message_id in to_remove:
                del self.message_trackers[message_id]
    
    def get_current_metrics(self) -> MQTTReliabilityMetrics:
        """현재 신뢰성 메트릭 계산"""
        current_time = time.time()
        time_elapsed = current_time - self.start_time
        
        with self.lock:
            if len(self.latency_measurements) > 0:
                latencies = list(self.latency_measurements)
                avg_latency = statistics.mean(latencies)
                p95_latency = np.percentile(latencies, 95)
                p99_latency = np.percentile(latencies, 99)
                max_latency = max(latencies)
                min_latency = min(latencies)
                
                # 지터 계산 (연속 지연 시간 차이의 표준편차)
                if len(latencies) > 1:
                    jitter = statistics.stdev([abs(latencies[i] - latencies[i-1]) 
                                             for i in range(1, len(latencies))])
                else:
                    jitter = 0.0
            else:
                avg_latency = p95_latency = p99_latency = 0.0
                max_latency = min_latency = jitter = 0.0
            
            # 전달 성공률
            if self.total_published > 0:
                delivery_rate = (self.total_received / self.total_published) * 100
            else:
                delivery_rate = 0.0
            
            # 메시지 처리율
            message_rate = self.total_received / max(time_elapsed, 1.0)
            
            # 처리량 (kbps)
            throughput_kbps = (self.total_bytes_received * 8) / (max(time_elapsed, 1.0) * 1000)
            
            return MQTTReliabilityMetrics(
                timestamp=current_time,
                total_published=self.total_published,
                total_received=self.total_received,
                total_lost=self.total_lost,
                avg_latency_ms=avg_latency,
                p95_latency_ms=p95_latency,
                p99_latency_ms=p99_latency,
                max_latency_ms=max_latency,
                min_latency_ms=min_latency,
                jitter_ms=jitter,
                message_rate_per_sec=message_rate,
                throughput_kbps=throughput_kbps,
                delivery_success_rate=delivery_rate,
                duplicate_count=self.duplicate_count,
                out_of_order_count=self.out_of_order_count,
                broker_processing_time_ms=0.0  # 추후 구현
            )

# ========================
# 수정된 Crack Detection 노드
# ========================
class EnhancedDetectWithDepthWithTf(Node):
    """신뢰성 측정 기능이 추가된 Crack Detection 노드"""
    
    def __init__(self):
        super().__init__('enhanced_crack_detector')
        
        # 기본 설정
        self.setup_basic_config()
        
        # 신뢰성 추적기 초기화
        self.reliability_tracker = MQTTReliabilityTracker()
        
        # MQTT 클라이언트 설정
        self.setup_mqtt_subscriber()
        
        # 메트릭 출력 타이머
        self.metrics_timer = self.create_timer(5.0, self.print_subscriber_metrics)
        
        # 데이터 로깅 설정
        self.setup_data_logging()
        
        self.get_logger().info("MQTT Reliability Subscriber started")
    
    def setup_mqtt_subscriber(self):
        """MQTT 구독자 설정"""
        try:
            self.mqtt_client = mqtt.Client(
                client_id=self.client_id,
                protocol=mqtt.MQTTv311
            )
            self.mqtt_client.tls_set()
            self.mqtt_client.username_pw_set(self.username, self.password)
            self.mqtt_client.on_connect = self.on_mqtt_connect
            self.mqtt_client.on_message = self.on_mqtt_message
            self.mqtt_client.on_disconnect = self.on_mqtt_disconnect
            
            self.mqtt_client.connect(self.broker, self.port)
            self.mqtt_client.loop_start()
            
        except Exception as e:
            self.get_logger().error(f"MQTT subscriber setup failed: {e}")
    
    def on_mqtt_connect(self, client, userdata, flags, rc):
        """MQTT 연결 콜백"""
        if rc == 0:
            self.get_logger().info("✅ MQTT Subscriber connected successfully")
            client.subscribe(self.mqtt_topic)
            self.get_logger().info(f"📡 Subscribed to topic: {self.mqtt_topic}")
        else:
            self.get_logger().error(f"❌ MQTT Subscriber connection failed: {rc}")
    
    def on_mqtt_message(self, client, userdata, msg):
        """MQTT 메시지 수신 콜백"""
        try:
            payload = msg.payload.decode('utf-8')
            msg_dict = json.loads(payload)
            
            # 신뢰성 추적 처리
            latency = self.reliability_tracker.process_received_message(msg_dict)
            
            if latency is not None:
                self.get_logger().debug(f"📨 Received message with latency: {latency:.2f}ms")
                
                # 메시지 타입별 로깅
                msg_type = msg_dict.get('type', 'unknown')
                robot_id = msg_dict.get('robot_id', 'unknown')
                location = msg_dict.get('location', [0, 0])
                
                self.log_received_message(msg_type, robot_id, location, latency)
            
        except json.JSONDecodeError as e:
            self.get_logger().warning(f"JSON decode error: {e}")
        except Exception as e:
            self.get_logger().error(f"Message processing error: {e}")
    
    def on_mqtt_disconnect(self, client, userdata, rc):
        """MQTT 연결 해제 콜백"""
        if rc != 0:
            self.get_logger().warning(f"⚠️ MQTT Subscriber unexpected disconnection: {rc}")
    
    def setup_data_logging(self):
        """데이터 로깅 설정"""
        self.log_file_path = f"mqtt_reliability_log_{datetime.now().strftime('%Y%m%d_%H%M%S')}.csv"
        self.message_log = []
        
        # CSV 헤더 작성
        import csv
        with open(self.log_file_path, 'w', newline='') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow([
                'timestamp', 'message_type', 'robot_id', 'location_x', 'location_y',
                'latency_ms', 'sequence_number', 'confidence', 'area'
            ])
    
    def log_received_message(self, msg_type, robot_id, location, latency):
        """수신된 메시지 로깅"""
        import csv
        timestamp = datetime.now().isoformat()
        
        try:
            with open(self.log_file_path, 'a', newline='') as csvfile:
                writer = csv.writer(csvfile)
                writer.writerow([
                    timestamp, msg_type, robot_id, 
                    location[0] if len(location) > 0 else 0,
                    location[1] if len(location) > 1 else 0,
                    latency, '', '', ''  # sequence_number, confidence, area는 추후 추가
                ])
        except Exception as e:
            self.get_logger().error(f"Logging error: {e}")
    
    def print_subscriber_metrics(self):
        """구독자 메트릭 출력"""
        metrics = self.reliability_tracker.get_current_metrics()
        
        self.get_logger().info(f"""
╔══════════════════════════════════════════════════════════════════╗
║                  MQTT Subscriber Metrics                        ║
╠══════════════════════════════════════════════════════════════════╣
║ Received Messages: {metrics.total_received:>6}                                ║
║ Lost Messages:     {metrics.total_lost:>6}                                ║
║ Success Rate:      {metrics.delivery_success_rate:>6.2f}%                        ║
║ Avg Latency:       {metrics.avg_latency_ms:>6.2f} ms                           ║
║ P95 Latency:       {metrics.p95_latency_ms:>6.2f} ms                           ║
║ P99 Latency:       {metrics.p99_latency_ms:>6.2f} ms                           ║
║ Max Latency:       {metrics.max_latency_ms:>6.2f} ms                           ║
║ Min Latency:       {metrics.min_latency_ms:>6.2f} ms                           ║
║ Jitter:            {metrics.jitter_ms:>6.2f} ms                              ║
║ Message Rate:      {metrics.message_rate_per_sec:>6.2f} msg/s                    ║
║ Throughput:        {metrics.throughput_kbps:>6.2f} kbps                        ║
║ Duplicates:        {metrics.duplicate_count:>4}                                  ║
║ Out of Order:      {metrics.out_of_order_count:>4}                                  ║
║ Log File:          {self.log_file_path:<30}                 ║
╚══════════════════════════════════════════════════════════════════╝
        """)

# ========================
# 성능 분석 도구
# ========================
class MQTTPerformanceAnalyzer:
    """MQTT 성능 분석 도구"""
    
    def __init__(self, log_file_path: str):
        self.log_file_path = log_file_path
        self.data = []
        self.load_data()
    
    def load_data(self):
        """로그 파일에서 데이터 로드"""
        import pandas as pd
        try:
            self.data = pd.read_csv(self.log_file_path)
            print(f"✅ Loaded {len(self.data)} records from {self.log_file_path}")
        except Exception as e:
            print(f"❌ Failed to load data: {e}")
    
    def analyze_latency_distribution(self):
        """지연 시간 분포 분석"""
        if self.data.empty:
            return
        
        latencies = self.data['latency_ms'].dropna()
        
        print("\n📊 Latency Distribution Analysis:")
        print(f"   Total Messages: {len(latencies)}")
        print(f"   Mean Latency:   {latencies.mean():.2f} ms")
        print(f"   Median Latency: {latencies.median():.2f} ms")
        print(f"   Std Deviation:  {latencies.std():.2f} ms")
        print(f"   Min Latency:    {latencies.min():.2f} ms")
        print(f"   Max Latency:    {latencies.max():.2f} ms")
        print(f"   P90 Latency:    {latencies.quantile(0.90):.2f} ms")
        print(f"   P95 Latency:    {latencies.quantile(0.95):.2f} ms")
        print(f"   P99 Latency:    {latencies.quantile(0.99):.2f} ms")
    
    def analyze_message_types(self):
        """메시지 타입별 분석"""
        if self.data.empty:
            return
        
        type_counts = self.data['message_type'].value_counts()
        
        print("\n📊 Message Type Analysis:")
        for msg_type, count in type_counts.items():
            type_data = self.data[self.data['message_type'] == msg_type]
            avg_latency = type_data['latency_ms'].mean()
            print(f"   {msg_type}: {count} messages, Avg Latency: {avg_latency:.2f} ms")
    
    def analyze_time_patterns(self):
        """시간대별 패턴 분석"""
        if self.data.empty:
            return
        
        import pandas as pd
        
        # 타임스탬프를 datetime으로 변환
        self.data['timestamp'] = pd.to_datetime(self.data['timestamp'])
        self.data['hour'] = self.data['timestamp'].dt.hour
        self.data['minute'] = self.data['timestamp'].dt.minute
        
        # 시간대별 메시지 수 분석
        hourly_counts = self.data.groupby('hour').size()
        hourly_latency = self.data.groupby('hour')['latency_ms'].mean()
        
        print("\n📊 Hourly Pattern Analysis:")
        for hour in hourly_counts.index:
            count = hourly_counts[hour]
            avg_latency = hourly_latency[hour]
            print(f"   Hour {hour:02d}: {count} messages, Avg Latency: {avg_latency:.2f} ms")
    
    def generate_report(self, output_file: str = None):
        """종합 리포트 생성"""
        if output_file is None:
            output_file = f"mqtt_performance_report_{datetime.now().strftime('%Y%m%d_%H%M%S')}.txt"
        
        with open(output_file, 'w') as f:
            f.write("MQTT Performance Analysis Report\n")
            f.write("=" * 50 + "\n")
            f.write(f"Generated: {datetime.now().isoformat()}\n")
            f.write(f"Data Source: {self.log_file_path}\n\n")
            
            # 각 분석 결과를 파일에 기록
            import sys
            from io import StringIO
            
            # stdout을 임시로 StringIO로 리다이렉트
            old_stdout = sys.stdout
            sys.stdout = captured_output = StringIO()
            
            self.analyze_latency_distribution()
            self.analyze_message_types()
            self.analyze_time_patterns()
            
            # stdout 복원
            sys.stdout = old_stdout
            
            # 캡처된 출력을 파일에 쓰기
            f.write(captured_output.getvalue())
        
        print(f"📄 Performance report saved to: {output_file}")

# ========================
# 메인 실행 함수들
# ========================
def main_publisher():
    """Crack Detection Publisher 실행"""
    rclpy.init()
    node = EnhancedDetectWithDepthWithTf()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.should_shutdown = True
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()
        print("Enhanced Crack Detector shutdown complete.")

def main_subscriber():
    """MQTT Reliability Subscriber 실행"""
    rclpy.init()
    node = MQTTReliabilitySubscriber()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        print("MQTT Reliability Subscriber shutdown complete.")

def main_analyzer():
    """성능 분석기 실행"""
    import sys
    
    if len(sys.argv) < 2:
        print("Usage: python script.py <log_file_path>")
        return
    
    log_file = sys.argv[1]
    analyzer = MQTTPerformanceAnalyzer(log_file)
    
    print("🔍 Starting MQTT Performance Analysis...")
    analyzer.analyze_latency_distribution()
    analyzer.analyze_message_types()
    analyzer.analyze_time_patterns()
    analyzer.generate_report()
    print("✅ Analysis complete!")

# ========================
# 통합 실행 스크립트
# ========================
if __name__ == '__main__':
    import sys
    
    if len(sys.argv) < 2:
        print("Usage:")
        print("  python script.py publisher    # Run Crack Detection Publisher")
        print("  python script.py subscriber   # Run MQTT Reliability Subscriber")
        print("  python script.py analyzer <log_file>  # Run Performance Analyzer")
        sys.exit(1)
    
    mode = sys.argv[1]
    
    if mode == 'publisher':
        main_publisher()
    elif mode == 'subscriber':
        main_subscriber()
    elif mode == 'analyzer':
        main_analyzer()
    else:
        print(f"Unknown mode: {mode}")
        sys.exit(1)_mqtt_client()
        
        # ROS2 설정
        self.setup_ros2_components()
        
        # YOLO 모델 로딩
        self.setup_yolo_model()
        
        # 백그라운드 스레드 시작
        self.start_background_threads()
        
        # 신뢰성 메트릭 출력 타이머
        self.metrics_timer = self.create_timer(5.0, self.print_reliability_metrics)
        
        self.get_logger().info("Enhanced Crack Detector with Reliability Tracking started")
    
    def setup_basic_config(self):
        """기본 설정 초기화"""
        self.broker = 'p021f2cb.ala.asia-southeast1.emqxsl.com'
        self.port = 8883
        self.username = 'Rokey'
        self.password = '1234567'
        self.mqtt_topic = "detect"
        self.client_id = f'enhanced-crack-detector-{np.random.randint(0, 1000)}'
        
        self.MODEL_PATH = '/home/kunwookpark/D1_ws/src/waypoint/waypoint/real_best_320.pt'
        self.IMAGE_TOPIC = '/robot1/oakd/rgb/preview/image_raw'
        self.DEPTH_TOPIC = '/robot1/oakd/stereo/image_raw'
        self.CAMERA_INFO_TOPIC = '/robot1/oakd/stereo/camera_info'
        
        # 상태 변수
        self.K = None
        self.should_exit = False
        self.should_shutdown = False
        self.depth_mm = None
        self.depth_colored = None
        self.lock = threading.Lock()
        
        # 이미지 처리
        self.bridge = CvBridge()
        self.image_queue = queue.Queue(maxsize=1)
    
    def setup_mqtt_client(self):
        """MQTT 클라이언트 설정"""
        try:
            self.mqtt_client = mqtt.Client(
                client_id=self.client_id, 
                protocol=mqtt.MQTTv311
            )
            self.mqtt_client.tls_set()
            self.mqtt_client.username_pw_set(self.username, self.password)
            self.mqtt_client.on_connect = self.on_mqtt_connect
            self.mqtt_client.on_disconnect = self.on_mqtt_disconnect
            self.mqtt_client.on_publish = self.on_mqtt_publish
            
            self.mqtt_client.connect(self.broker, self.port)
            self.mqtt_client.loop_start()
            
        except Exception as e:
            self.get_logger().error(f"MQTT setup failed: {e}")
    
    def on_mqtt_connect(self, client, userdata, flags, rc):
        """MQTT 연결 콜백"""
        if rc == 0:
            self.get_logger().info("✅ MQTT connected successfully")
        else:
            self.get_logger().error(f"❌ MQTT connection failed: {rc}")
    
    def on_mqtt_disconnect(self, client, userdata, rc):
        """MQTT 연결 해제 콜백"""
        if rc != 0:
            self.get_logger().warning(f"⚠️ MQTT unexpected disconnection: {rc}")
    
    def on_mqtt_publish(self, client, userdata, mid):
        """MQTT 발행 콜백"""
        self.get_logger().debug(f"📤 MQTT message {mid} published successfully")
    
    def setup_ros2_components(self):
        """ROS2 컴포넌트 설정"""
        # QoS 프로파일
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            durability=DurabilityPolicy.TRANSIENT_LOCAL
        )
        
        # TF 설정
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        
        # 구독자 설정
        self.rgb_img_subscription = self.create_subscription(
            Image, self.IMAGE_TOPIC, self.image_callback, 10)
        self.stereo_img_subscription = self.create_subscription(
            Image, self.DEPTH_TOPIC, self.depth_callback, 10)
        self.camera_info_subscription = self.create_subscription(
            CameraInfo, self.CAMERA_INFO_TOPIC, self.camera_info_callback, 10)
        
        # 발행자 설정
        self.map_point_pub = self.create_publisher(
            PointStamped, 'map_points', qos_profile)
        
        # TF 안정화 타이머
        self.start_timer = self.create_timer(5.0, self.start_transform)
    
    def setup_yolo_model(self):
        """YOLO 모델 로딩"""
        if not os.path.exists(self.MODEL_PATH):
            self.get_logger().error(f"Model not found: {self.MODEL_PATH}")
            return
        
        try:
            self.model = YOLO(self.MODEL_PATH)
            self.class_names = getattr(self.model, 'names', [])
            self.get_logger().info("YOLO model loaded successfully")
        except Exception as e:
            self.get_logger().error(f"YOLO model loading failed: {e}")
    
    def start_background_threads(self):
        """백그라운드 스레드 시작"""
        # 이미지 처리 스레드
        self.worker_thread = threading.Thread(target=self.visualization_loop)
        self.worker_thread.daemon = True
        self.worker_thread.start()
        
        # 신뢰성 정리 스레드
        self.cleanup_thread = threading.Thread(target=self.reliability_cleanup_loop)
        self.cleanup_thread.daemon = True
        self.cleanup_thread.start()
    
    def reliability_cleanup_loop(self):
        """주기적으로 오래된 메시지 정리"""
        while not self.should_shutdown:
            time.sleep(5.0)  # 5초마다 정리
            self.reliability_tracker.cleanup_old_messages()
    
    def camera_info_callback(self, msg):
        """카메라 정보 콜백"""
        if self.K is None:
            self.K = np.array(msg.k).reshape(3, 3)
            self.get_logger().info(
                f"Camera info: fx={self.K[0,0]:.2f}, fy={self.K[1,1]:.2f}, "
                f"cx={self.K[0,2]:.2f}, cy={self.K[1,2]:.2f}")
    
    def depth_callback(self, msg):
        """깊이 이미지 콜백"""
        if self.should_exit or self.K is None:
            return
        
        depth_mm = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        depth_vis = np.nan_to_num(depth_mm, nan=0.0)
        depth_vis = np.clip(depth_vis, 0, 3000)  # 3m 범위
        depth_vis = (depth_vis / 3000 * 255).astype(np.uint8)
        depth_colored = cv2.applyColorMap(depth_vis, cv2.COLORMAP_JET)
        
        with self.lock:
            self.depth_mm = depth_mm
            self.depth_colored = depth_colored
    
    def image_callback(self, msg):
        """이미지 콜백"""
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        
        if not self.image_queue.full():
            self.image_queue.put(frame)
        else:
            try:
                self.image_queue.get_nowait()
            except queue.Empty:
                pass
            self.image_queue.put(frame)
    
    def seg(self, img):
        """전경 분리 함수"""
        hsv_img = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
        lower_red1 = np.array([0, 50, 50])
        upper_red1 = np.array([10, 255, 255])
        lower_red2 = np.array([170, 50, 50])
        upper_red2 = np.array([180, 255, 255])

        mask1 = cv2.inRange(hsv_img, lower_red1, upper_red1)
        mask2 = cv2.inRange(hsv_img, lower_red2, upper_red2)
        bg_mask = cv2.bitwise_or(mask1, mask2)

        kernel = np.ones((5, 5), np.uint8)
        bg_mask = cv2.morphologyEx(bg_mask, cv2.MORPH_CLOSE, kernel, iterations=2)
        bg_mask = cv2.morphologyEx(bg_mask, cv2.MORPH_OPEN, kernel, iterations=2)
        bg_mask = cv2.GaussianBlur(bg_mask, (5, 5), 0)
        fg_mask = cv2.bitwise_not(bg_mask)
        white_pixel_count = np.count_nonzero(fg_mask)

        fg_mask_3ch = cv2.merge([fg_mask, fg_mask, fg_mask])
        foreground = cv2.bitwise_and(img, fg_mask_3ch)
        white_bg = np.full_like(img, 255)
        bg_mask_3ch = cv2.merge([bg_mask, bg_mask, bg_mask])
        background = cv2.bitwise_and(white_bg, bg_mask_3ch)
        result = cv2.add(foreground, background)
        
        return result, white_pixel_count
    
    def publish_enhanced_mqtt_message(self, msg_dict):
        """신뢰성 추적이 포함된 MQTT 메시지 발행"""
        try:
            # 신뢰성 추적 정보 추가
            enhanced_msg = self.reliability_tracker.enhance_message_for_tracking(msg_dict)
            
            # MQTT 발행
            json_payload = json.dumps(enhanced_msg)
            result = self.mqtt_client.publish(self.mqtt_topic, json_payload)
            
            if result.rc == mqtt.MQTT_ERR_SUCCESS:
                self.get_logger().debug(f"📡 MQTT Published: {msg_dict['type']}")
            else:
                self.get_logger().warning(f"⚠️ MQTT publish failed: {result.rc}")
                
        except Exception as e:
            self.get_logger().error(f"❌ MQTT publish error: {e}")
    
    def visualization_loop(self):
        """메인 이미지 처리 루프"""
        while not self.should_shutdown:
            try:
                frame = self.image_queue.get(timeout=0.1)
            except queue.Empty:
                continue
            
            if not hasattr(self, 'model'):
                continue
            
            try:
                results = self.model(frame, stream=True, verbose=False)
            except Exception as e:
                self.get_logger().error(f"YOLO inference error: {e}")
                continue
            
            with self.lock:
                if self.depth_mm is None or self.depth_colored is None:
                    continue
                
                depth_mm = self.depth_mm.copy()
                depth_colored = self.depth_colored.copy()
                
                object_count = 0
                
                for r in results:
                    for box in r.boxes:
                        cls = int(box.cls[0])
                        if cls != 0:  # Only process class 0 (cracks)
                            continue
                        
                        x1, y1, x2, y2 = map(int, box.xyxy[0])
                        conf = float(box.conf[0])
                        
                        if conf <= 0.6:  # Confidence threshold
                            continue
                        
                        # 바운딩 박스 중심점 계산
                        detect_cx = int((x1 + x2) / 2)
                        detect_cy = int((y1 + y2) / 2)
                        
                        # 전경 분리
                        result, area_pixels = self.seg(frame[y1:y2, x1:x2])
                        frame[y1:y2, x1:x2] = result
                        
                        # 깊이 정보 확인
                        if (0 <= detect_cx < depth_mm.shape[1] and 
                            0 <= detect_cy < depth_mm.shape[0]):
                            
                            distance_mm = depth_mm[detect_cy, detect_cx]
                            distance_m = distance_mm / 1000.0
                            
                            if distance_m <= 0 or distance_m > 3.0:
                                continue
                            
                            # 카메라 파라미터
                            fx = self.K[0,0]
                            fy = self.K[1,1]
                            cx = self.K[0,2]
                            cy = self.K[1,2]
                            
                            # 3D 좌표 변환
                            X = (detect_cx - cx) * distance_m / fx
                            Y = (detect_cy - cy) * distance_m / fy
                            Z = distance_m
                            area = area_pixels * (distance_m / fx) * (distance_m / fy)
                            
                            # TF 변환
                            try:
                                point_base = PointStamped()
                                point_base.header.stamp = rclpy.time.Time().to_msg()
                                point_base.header.frame_id = 'base_link'
                                point_base.point.x = Z
                                point_base.point.y = -X
                                point_base.point.z = -Y
                                
                                point_map = self.tf_buffer.transform(
                                    point_base, 'map',
                                    timeout=rclpy.duration.Duration(seconds=0.5)
                                )
                                
                                # MQTT 메시지 생성 및 발행
                                msg_dict = {
                                    "robot_id": "robot1",
                                    "type": "crack1",
                                    "location": [
                                        round(point_map.point.x, 2),
                                        round(point_map.point.y, 2)
                                    ],
                                    "depth": round(distance_m, 2),
                                    "area": round(area, 3),
                                    "confidence": round(conf, 2),
                                    "timestamp": datetime.now(timezone.utc).isoformat()
                                }
                                
                                # 신뢰성 추적이 포함된 발행
                                self.publish_enhanced_mqtt_message(msg_dict)
                                
                            except Exception as e:
                                self.get_logger().debug(f"TF transform failed: {e}")
                        
                        # 시각화
                        cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 0, 255), 2)
                        cv2.putText(frame, f"Crack: {conf:.2f}", (x1, y1 - 10),
                                   cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 0, 0), 2)
                        object_count += 1
                
                # 정보 표시
                cv2.putText(frame, f"Objects: {object_count}", (10, 30),
                           cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 255, 0), 2)
                
                # 신뢰성 메트릭 표시
                metrics = self.reliability_tracker.get_current_metrics()
                cv2.putText(frame, f"Sent: {metrics.total_published}, "
                                  f"Received: {metrics.total_received}, "
                                  f"Lost: {metrics.total_lost}", 
                           (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 255), 2)
                cv2.putText(frame, f"Avg Latency: {metrics.avg_latency_ms:.1f}ms, "
                                  f"Success: {metrics.delivery_success_rate:.1f}%",
                           (10, 90), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 255), 2)
                
                # 이미지 표시
                display_img = cv2.resize(frame, (frame.shape[1] * 2, frame.shape[0] * 2))
                cv2.imshow('Enhanced Crack Detection', display_img)
                
                key = cv2.waitKey(1)
                if key == ord('q'):
                    self.should_shutdown = True
                    break
    
    def print_reliability_metrics(self):
        """신뢰성 메트릭 출력"""
        metrics = self.reliability_tracker.get_current_metrics()
        
        self.get_logger().info(f"""
╔══════════════════════════════════════════════════════════════════╗
║                    MQTT Reliability Metrics                     ║
╠══════════════════════════════════════════════════════════════════╣
║ Messages: Sent={metrics.total_published:>4}, Received={metrics.total_received:>4}, Lost={metrics.total_lost:>4}     ║
║ Success Rate:      {metrics.delivery_success_rate:>6.2f}%                        ║
║ Avg Latency:       {metrics.avg_latency_ms:>6.2f} ms                           ║
║ P95 Latency:       {metrics.p95_latency_ms:>6.2f} ms                           ║
║ P99 Latency:       {metrics.p99_latency_ms:>6.2f} ms                           ║
║ Jitter:            {metrics.jitter_ms:>6.2f} ms                              ║
║ Message Rate:      {metrics.message_rate_per_sec:>6.2f} msg/s                    ║
║ Throughput:        {metrics.throughput_kbps:>6.2f} kbps                        ║
║ Duplicates:        {metrics.duplicate_count:>4}                                  ║
║ Out of Order:      {metrics.out_of_order_count:>4}                                  ║
╚══════════════════════════════════════════════════════════════════╝
        """)
    
    def start_transform(self):
        """TF 안정화 완료"""
        self.get_logger().info("TF Tree stabilized. Transform ready.")
        self.start_timer.cancel()

# ========================
# MQTT 구독자 (신뢰성 측정용)
# ========================
class MQTTReliabilitySubscriber(Node):
    """MQTT 구독 및 신뢰성 측정 노드"""
    
    def __init__(self):
        super().__init__('mqtt_reliability_subscriber')
        
        # 신뢰성 추적기
        self.reliability_tracker = MQTTReliabilityTracker()
        
        # MQTT 설정
        self.broker = 'p021f2cb.ala.asia-southeast1.emqxsl.com'
        self.port = 8883
        self.username = 'Rokey'
        self.password = '1234567'
        self.mqtt_topic = "detect"
        self.client_id = f'reliability-subscriber-{np.random.randint(0, 1000)}'
        
        # MQTT 클라이언트 설정
        self.setup
