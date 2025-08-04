import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import serial
import paho.mqtt.client as mqtt
import json
from datetime import datetime
import numpy as np
from collections import deque
import csv
import os
from typing import Dict, Deque, List, Optional

# ─── 기본 설정 ────────────────────────────────────────────
MQTT_BROKER_HOST = 'p021f2cb.ala.asia-southeast1.emqxsl.com'
MQTT_BROKER_PORT = 8883
MQTT_USERNAME = 'Rokey'
MQTT_PASSWORD = '1234567'
MQTT_TOPIC_RAW = 'scale/raw'
MQTT_TOPIC_MA = 'scale/moving_average'
MQTT_TOPIC_EMA = 'scale/exponential_average'
MQTT_TOPIC_KALMAN_SIMPLE = 'scale/kalman_simple'
MQTT_TOPIC_KALMAN_PV = 'scale/kalman_pv'
MQTT_TOPIC_EKF = 'scale/ekf'
MQTT_TOPIC_UKF = 'scale/ukf'
MQTT_KEEPALIVE = 60
SERIAL_PORT = '/dev/ttyACM0'
SERIAL_BAUDRATE = 38400
PUBLISH_INTERVAL = 0.1

# 필터 파라미터
MOVING_AVERAGE_WINDOW = 10
EMA_ALPHA = 0.2
KALMAN_PROCESS_NOISE = 1.0
KALMAN_MEASUREMENT_NOISE = 10.0

# 로깅 설정
ENABLE_DATA_LOGGING = True
LOG_FILE_PREFIX = 'filter_data'
LOG_DIRECTORY = os.path.expanduser('~/Documents')
ANALYSIS_WINDOW = 100

# 물 따르기 평가 설정
ENABLE_POURING_ANALYSIS = True
POURING_THRESHOLD = 0.5  # g/s
STABILITY_WINDOW = 20
TARGET_TOLERANCE = 1.0
WEIGHT_ACCURACY = 0.3
WEIGHT_STABILITY = 0.3
WEIGHT_RESPONSIVENESS = 0.2
WEIGHT_OVERSHOOT = 0.2
# ─────────────────────────────────────────────────────────────

class SimpleKalmanFilter:
    def __init__(self, process_noise: float = 1.0, measurement_noise: float = 10.0):
        self.process_noise = process_noise
        self.measurement_noise = measurement_noise
        self.estimate = 0.0
        self.error_estimate = 1.0
        self.initialized = False
    
    def update(self, measurement: float) -> float:
        if not self.initialized:
            self.estimate = measurement
            self.initialized = True
            return self.estimate
        
        predicted_estimate = self.estimate
        predicted_error = self.error_estimate + self.process_noise
        
        kalman_gain = predicted_error / (predicted_error + self.measurement_noise)
        self.estimate = predicted_estimate + kalman_gain * (measurement - predicted_estimate)
        self.error_estimate = (1 - kalman_gain) * predicted_error
        
        return self.estimate

class PositionVelocityKalmanFilter:
    def __init__(self, dt: float = 0.1, process_noise: float = 1.0, measurement_noise: float = 10.0):
        self.dt = dt
        self.x = np.array([0.0, 0.0])
        self.F = np.array([[1, self.dt], [0, 1]])
        self.H = np.array([[1, 0]])
        self.Q = np.array([[process_noise * (self.dt**4)/4, process_noise * (self.dt**3)/2],
                          [process_noise * (self.dt**3)/2, process_noise * self.dt**2]])
        self.R = np.array([[measurement_noise]])
        self.P = np.eye(2) * 1000
        self.initialized = False
    
    def update(self, measurement: float) -> float:
        if not self.initialized:
            self.x[0] = measurement
            self.x[1] = 0
            self.initialized = True
            return self.x[0]
        
        self.x = self.F @ self.x
        self.P = self.F @ self.P @ self.F.T + self.Q
        
        y = measurement - self.H @ self.x
        S = self.H @ self.P @ self.H.T + self.R
        K = self.P @ self.H.T @ np.linalg.inv(S)
        
        self.x = self.x + K @ y
        self.P = self.P - K @ self.H @ self.P
        
        return self.x[0]

class ExtendedKalmanFilter:
    def __init__(self, dt: float = 0.1, process_noise: float = 1.0, measurement_noise: float = 10.0):
        self.dt = dt
        self.x = np.array([0.0, 0.0, 0.0])
        self.Q = np.eye(3) * process_noise
        self.R = np.array([[measurement_noise]])
        self.P = np.eye(3) * 1000
        self.initialized = False
    
    def update(self, measurement: float) -> float:
        if not self.initialized:
            self.x[0] = measurement
            self.initialized = True
            return self.x[0]
        
        # 간단한 비선형 상태 전이
        pos, vel, acc = self.x
        friction = 0.95 if abs(vel) > 1.0 else 1.0
        
        self.x[0] = pos + vel * self.dt + 0.5 * acc * self.dt**2
        self.x[1] = vel * friction + acc * self.dt
        self.x[2] = acc * 0.8
        
        # 야코비안
        F = np.array([
            [1, self.dt, 0.5 * self.dt**2],
            [0, friction, self.dt],
            [0, 0, 0.8]
        ])
        
        self.P = F @ self.P @ F.T + self.Q
        
        # 측정 업데이트
        H = np.array([[1, 0, 0]])
        y = measurement - self.x[0]
        S = H @ self.P @ H.T + self.R
        K = self.P @ H.T @ np.linalg.inv(S)
        
        self.x = self.x + K.flatten() * y
        self.P = self.P - K @ H @ self.P
        
        return self.x[0]

class UnscentedKalmanFilter:
    def __init__(self, dt: float = 0.1, process_noise: float = 1.0, measurement_noise: float = 10.0):
        self.dt = dt
        self.n = 3
        self.x = np.array([0.0, 0.0, 0.0])
        self.P = np.eye(3) * 1000
        self.Q = np.eye(3) * process_noise
        self.R = np.array([[measurement_noise]])
        self.initialized = False
        
        # UKF 파라미터
        self.alpha = 0.001
        self.beta = 2.0
        self.kappa = 0
        self.lambda_ = self.alpha**2 * (self.n + self.kappa) - self.n
        
        self.Wm = np.zeros(2 * self.n + 1)
        self.Wc = np.zeros(2 * self.n + 1)
        
        self.Wm[0] = self.lambda_ / (self.n + self.lambda_)
        self.Wc[0] = self.lambda_ / (self.n + self.lambda_) + (1 - self.alpha**2 + self.beta)
        
        for i in range(1, 2 * self.n + 1):
            self.Wm[i] = 1 / (2 * (self.n + self.lambda_))
            self.Wc[i] = 1 / (2 * (self.n + self.lambda_))
    
    def update(self, measurement: float) -> float:
        if not self.initialized:
            self.x[0] = measurement
            self.initialized = True
            return self.x[0]
        
        # 간단화된 UKF (시그마 포인트 생성 생략)
        # 기본 칼만 필터와 유사하게 동작
        pos, vel, acc = self.x
        friction = 0.95 if abs(vel) > 1.0 else 1.0
        
        self.x[0] = pos + vel * self.dt + 0.5 * acc * self.dt**2
        self.x[1] = vel * friction + acc * self.dt
        self.x[2] = acc * 0.8
        
        self.P = self.P + self.Q
        
        # 측정 업데이트
        y = measurement - self.x[0]
        S = self.P[0, 0] + self.R[0, 0]
        K = self.P[:, 0] / S
        
        self.x = self.x + K * y
        self.P = self.P - np.outer(K, K) * S
        
        return self.x[0]

class PouringAnalyzer:
    def __init__(self):
        self.filter_data: Dict[str, Dict] = {}
        self.current_target: Optional[float] = None
        self.best_filter: Optional[str] = None
        
        for name in ['raw', 'ma', 'ema', 'kalman_simple', 'kalman_pv', 'ekf', 'ukf']:
            self.filter_data[name] = {
                'values': deque(maxlen=STABILITY_WINDOW),
                'velocities': deque(maxlen=STABILITY_WINDOW),
                'is_pouring': False,
                'last_value': 0.0
            }
    
    def update(self, filter_name: str, value: float) -> bool:
        data = self.filter_data[filter_name]
        
        if len(data['values']) > 0:
            velocity = (value - data['last_value']) / PUBLISH_INTERVAL
            data['velocities'].append(velocity)
            
            # 물 따르기 감지
            if len(data['velocities']) >= 3:
                recent_vel = list(data['velocities'])[-3:]
                avg_vel = sum(recent_vel) / len(recent_vel)
                data['is_pouring'] = avg_vel > POURING_THRESHOLD
        
        data['values'].append(value)
        data['last_value'] = value
        
        return data['is_pouring']
    
    def calculate_score(self, filter_name: str) -> float:
        data = self.filter_data[filter_name]
        
        if len(data['values']) < 10:
            return 0.0
        
        values = np.array(data['values'])
        
        # 안정성 점수
        stability = float(max(0, 100 - np.std(values) * 10))

        # 정확성 점수
        if self.current_target:
            accuracy = float(max(0, 100 - abs(values[-1] - self.current_target) * 20))
        else:
            accuracy = 50.0

        # 반응성 점수 (단순화)
        responsiveness = 70.0  # 기본값

        # 오버슈트 점수
        if self.current_target:
            overshoot = float(max(0, 100 - max(0, values.max() - self.current_target) * 5))
        else:
            overshoot = 80.0
        
        total = (accuracy * WEIGHT_ACCURACY +
                stability * WEIGHT_STABILITY +
                responsiveness * WEIGHT_RESPONSIVENESS +
                overshoot * WEIGHT_OVERSHOOT)
        
        return total
    
    def get_rankings(self) -> List[tuple]:
        scores = {}
        for name in self.filter_data.keys():
            scores[name] = self.calculate_score(name)
        
        return sorted(scores.items(), key=lambda x: x[1], reverse=True)
    
    def set_target(self, target: float):
        self.current_target = target

class ScalePublisher(Node):
    def __init__(self):
        super().__init__('scale_publisher')
        
        # ROS2 퍼블리셔들
        self.pub_raw = self.create_publisher(Float32, 'scale_weight_raw', 10)
        self.pub_ma = self.create_publisher(Float32, 'scale_weight_ma', 10)
        self.pub_ema = self.create_publisher(Float32, 'scale_weight_ema', 10)
        self.pub_kalman_simple = self.create_publisher(Float32, 'scale_weight_kalman_simple', 10)
        self.pub_kalman_pv = self.create_publisher(Float32, 'scale_weight_kalman_pv', 10)
        self.pub_ekf = self.create_publisher(Float32, 'scale_weight_ekf', 10)
        self.pub_ukf = self.create_publisher(Float32, 'scale_weight_ukf', 10)
        
        # 필터 초기화
        self.moving_avg_buffer: Deque[float] = deque(maxlen=MOVING_AVERAGE_WINDOW)
        self.ema_value: Optional[float] = None
        self.kalman_simple = SimpleKalmanFilter(KALMAN_PROCESS_NOISE, KALMAN_MEASUREMENT_NOISE)
        self.kalman_pv = PositionVelocityKalmanFilter(PUBLISH_INTERVAL, KALMAN_PROCESS_NOISE, KALMAN_MEASUREMENT_NOISE)
        self.ekf = ExtendedKalmanFilter(PUBLISH_INTERVAL, KALMAN_PROCESS_NOISE, KALMAN_MEASUREMENT_NOISE)
        self.ukf = UnscentedKalmanFilter(PUBLISH_INTERVAL, KALMAN_PROCESS_NOISE, KALMAN_MEASUREMENT_NOISE)
        
        # 분석 버퍼
        self.analysis_buffer: Dict[str, Deque[float]] = {
            'raw': deque(maxlen=ANALYSIS_WINDOW),
            'ma': deque(maxlen=ANALYSIS_WINDOW),
            'ema': deque(maxlen=ANALYSIS_WINDOW),
            'kalman_simple': deque(maxlen=ANALYSIS_WINDOW),
            'kalman_pv': deque(maxlen=ANALYSIS_WINDOW),
            'ekf': deque(maxlen=ANALYSIS_WINDOW),
            'ukf': deque(maxlen=ANALYSIS_WINDOW)
        }
        
        # 물 따르기 분석기
        if ENABLE_POURING_ANALYSIS:
            self.pouring_analyzer = PouringAnalyzer()
        
        # MQTT 설정
        self.mqtt_client = mqtt.Client(client_id="ros2_scale_pub")
        self.mqtt_client.username_pw_set(MQTT_USERNAME, MQTT_PASSWORD)
        self.mqtt_client.tls_set()
        
        def on_mqtt_connect(client, userdata, flags, rc):
            if rc == 0:
                self.get_logger().info("✅ MQTT 연결 성공")
            else:
                self.get_logger().error(f"❌ MQTT 연결 실패, 코드={rc}")
        
        self.mqtt_client.on_connect = on_mqtt_connect
        
        try:
            self.mqtt_client.connect(MQTT_BROKER_HOST, MQTT_BROKER_PORT, MQTT_KEEPALIVE)
            self.mqtt_client.loop_start()
        except Exception as e:
            self.get_logger().error(f"MQTT 연결 오류: {e}")
        
        # 시리얼 연결
        try:
            self.ser = serial.Serial(SERIAL_PORT, SERIAL_BAUDRATE, timeout=1)
            self.get_logger().info(f"Serial opened: {SERIAL_PORT}")
        except Exception as e:
            self.get_logger().error(f"Serial open failed: {e}")
            self.ser = None
        
        # 로깅 설정
        self.log_counter = 0
        if ENABLE_DATA_LOGGING:
            os.makedirs(LOG_DIRECTORY, exist_ok=True)
            timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
            self.log_filename = os.path.join(LOG_DIRECTORY, f"{LOG_FILE_PREFIX}_{timestamp}.csv")
            self.setup_csv_logging()
            self.get_logger().info(f"📝 데이터 로깅: {self.log_filename}")
        
        # 타이머 설정
        self.create_timer(PUBLISH_INTERVAL, self.timer_callback)
        self.create_timer(5.0, self.perform_analysis)
        
        if ENABLE_POURING_ANALYSIS:
            self.create_timer(2.0, self.analyze_pouring)
        
        self.get_logger().info("🚀 7개 필터 시스템 시작!")
        self.get_logger().info("   Raw, MA, EMA, Kalman1D, Kalman2D, EKF, UKF")

    def setup_csv_logging(self):
        with open(self.log_filename, 'w', newline='') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow(['timestamp', 'raw', 'ma', 'ema', 'kalman_simple', 'kalman_pv', 'ekf', 'ukf'])

    def log_data(self, timestamp: str, raw: float, ma: float, ema: float, 
                 k_simple: float, k_pv: float, ekf: float, ukf: float):
        if not ENABLE_DATA_LOGGING:
            return
        
        try:
            with open(self.log_filename, 'a', newline='') as csvfile:
                writer = csv.writer(csvfile)
                writer.writerow([timestamp, raw, ma, ema, k_simple, k_pv, ekf, ukf])
        except Exception as e:
            self.get_logger().error(f"로깅 오류: {e}")

    def apply_moving_average(self, value: float) -> float:
        self.moving_avg_buffer.append(value)
        return sum(self.moving_avg_buffer) / len(self.moving_avg_buffer)
    
    def apply_exponential_moving_average(self, value: float) -> float:
        if self.ema_value is None:
            self.ema_value = value
        else:
            self.ema_value = EMA_ALPHA * value + (1 - EMA_ALPHA) * self.ema_value
        return self.ema_value

    def publish_mqtt_data(self, topic: str, sensor_type: str, weight: float) -> bool:
        json_payload = {
            "sensor_type": sensor_type,
            "weight": weight,
            "unit": "g",
            "timestamp": datetime.now().isoformat(),
            "device_id": "ros2_scale_pub"
        }
        
        payload_str = json.dumps(json_payload)
        result = self.mqtt_client.publish(topic=topic, payload=payload_str, qos=1, retain=False)
        return result.rc == mqtt.MQTT_ERR_SUCCESS

    def perform_analysis(self):
        if len(self.analysis_buffer['raw']) < 10:
            return
        
        self.get_logger().info("=" * 50)
        self.get_logger().info("📊 필터 성능 분석")
        self.get_logger().info("=" * 50)
        
        stats = {}
        for name, data in self.analysis_buffer.items():
            if len(data) > 0:
                arr = np.array(data)
                stats[name] = {
                    'std': float(np.std(arr)),
                    'mean': float(np.mean(arr)),
                    'range': float(np.max(arr) - np.min(arr))
                }
        
        # 노이즈 순위
        noise_ranking = sorted(stats.items(), key=lambda x: x[1]['std'])
        self.get_logger().info("🔊 노이즈 레벨 (낮을수록 좋음):")
        for i, (name, stat) in enumerate(noise_ranking):
            medal = "🥇" if i == 0 else "🥈" if i == 1 else "🥉" if i == 2 else "  "
            self.get_logger().info(f"  {medal} {name.upper():12}: {stat['std']:.6f}g")
        
        self.get_logger().info("=" * 50)

    def analyze_pouring(self):
        if not ENABLE_POURING_ANALYSIS:
            return
        
        # 물 따르기 상태 확인
        any_pouring = False
        for name in self.pouring_analyzer.filter_data.keys():
            if self.pouring_analyzer.filter_data[name]['is_pouring']:
                any_pouring = True
                break
        
        if any_pouring:
            self.get_logger().info("🚰 물 따르기 감지됨!")
            rankings = self.pouring_analyzer.get_rankings()
            best_filter = rankings[0][0] if rankings else None
            
            if best_filter:
                self.pouring_analyzer.best_filter = best_filter
                self.get_logger().info(f"🏆 현재 최적 필터: {best_filter.upper()} ({rankings[0][1]:.1f}점)")

    def set_target_weight(self, target: float):
        """목표 무게 설정"""
        if ENABLE_POURING_ANALYSIS:
            self.pouring_analyzer.set_target(target)
            self.get_logger().info(f"🎯 목표 무게 설정: {target:.1f}g")

    def timer_callback(self):
        if not self.ser:
            return
        
        line = self.ser.readline().decode().strip()
        try:
            raw_weight = round(float(line), 3)
            
            # 각 필터 적용
            ma_weight = round(self.apply_moving_average(raw_weight), 3)
            ema_weight = round(self.apply_exponential_moving_average(raw_weight), 3)
            kalman_simple_weight = round(self.kalman_simple.update(raw_weight), 3)
            kalman_pv_weight = round(self.kalman_pv.update(raw_weight), 3)
            ekf_weight = round(self.ekf.update(raw_weight), 3)
            ukf_weight = round(self.ukf.update(raw_weight), 3)
            
            # ROS2 퍼블리시
            self.pub_raw.publish(Float32(data=raw_weight))
            self.pub_ma.publish(Float32(data=ma_weight))
            self.pub_ema.publish(Float32(data=ema_weight))
            self.pub_kalman_simple.publish(Float32(data=kalman_simple_weight))
            self.pub_kalman_pv.publish(Float32(data=kalman_pv_weight))
            self.pub_ekf.publish(Float32(data=ekf_weight))
            self.pub_ukf.publish(Float32(data=ukf_weight))
            
            # MQTT 퍼블리시
            mqtt_success = {
                'raw': self.publish_mqtt_data(MQTT_TOPIC_RAW, "scale_raw", raw_weight),
                'ma': self.publish_mqtt_data(MQTT_TOPIC_MA, "scale_ma", ma_weight),
                'ema': self.publish_mqtt_data(MQTT_TOPIC_EMA, "scale_ema", ema_weight),
                'kalman_simple': self.publish_mqtt_data(MQTT_TOPIC_KALMAN_SIMPLE, "scale_kalman_simple", kalman_simple_weight),
                'kalman_pv': self.publish_mqtt_data(MQTT_TOPIC_KALMAN_PV, "scale_kalman_pv", kalman_pv_weight),
                'ekf': self.publish_mqtt_data(MQTT_TOPIC_EKF, "scale_ekf", ekf_weight),
                'ukf': self.publish_mqtt_data(MQTT_TOPIC_UKF, "scale_ukf", ukf_weight)
            }
            
            # 분석 버퍼 업데이트
            filter_values = {
                'raw': raw_weight, 'ma': ma_weight, 'ema': ema_weight,
                'kalman_simple': kalman_simple_weight, 'kalman_pv': kalman_pv_weight,
                'ekf': ekf_weight, 'ukf': ukf_weight
            }
            
            for name, value in filter_values.items():
                self.analysis_buffer[name].append(value)
                if ENABLE_POURING_ANALYSIS:
                    self.pouring_analyzer.update(name, value)
            
            # 데이터 로깅
            if ENABLE_DATA_LOGGING:
                current_time = datetime.now().isoformat()
                self.log_data(current_time, raw_weight, ma_weight, ema_weight,
                             kalman_simple_weight, kalman_pv_weight, ekf_weight, ukf_weight)
            
            # 로그 출력
            self.log_counter += 1
            if all(mqtt_success.values()) and self.log_counter % 50 == 0:
                best_info = ""
                if ENABLE_POURING_ANALYSIS and self.pouring_analyzer.best_filter:
                    best_info = f" | 🏆 {self.pouring_analyzer.best_filter.upper()}"
                
                self.get_logger().info(
                    f"Raw:{raw_weight:6.2f} | MA:{ma_weight:6.2f} | EMA:{ema_weight:6.2f} | "
                    f"K1D:{kalman_simple_weight:6.2f} | K2D:{kalman_pv_weight:6.2f} | "
                    f"EKF:{ekf_weight:6.2f} | UKF:{ukf_weight:6.2f}{best_info}"
                )
            
        except ValueError:
            pass

    def destroy_node(self):
        if ENABLE_DATA_LOGGING and hasattr(self, 'log_filename'):
            self.get_logger().info(f"📁 데이터 저장됨: {self.log_filename}")
        
        if hasattr(self, 'mqtt_client'):
            self.mqtt_client.loop_stop()
            self.mqtt_client.disconnect()
        super().destroy_node()

def main():
    rclpy.init()
    node = ScalePublisher()
    
    # 예시: 목표 무게 100g 설정
    # node.set_target_weight(100.0)
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()