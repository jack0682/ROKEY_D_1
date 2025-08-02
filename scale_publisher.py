import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
import serial
import threading
import paho.mqtt.client as mqtt
import json
from datetime import datetime

# ─── 공통 설정 구역 ────────────────────────────────────────────
MQTT_BROKER_HOST = 'p021f2cb.ala.asia-southeast1.emqxsl.com'
MQTT_BROKER_PORT = 8883
MQTT_USERNAME = 'Rokey'
MQTT_PASSWORD = '1234567'
MQTT_TOPIC = 'test'
MQTT_KEEPALIVE = 60
SERIAL_PORT = '/dev/ttyACM0'
SERIAL_BAUDRATE = 38400
PUBLISH_INTERVAL = 0.1
# ─────────────────────────────────────────────────────────────

class ScalePublisher(Node):
    def __init__(self):
        super().__init__('scale_publisher')
        
        # ROS2 퍼블리셔
        self.pub = self.create_publisher(Float32, 'scale_weight', 10)
        
        # MQTT 클라이언트 설정 (TLS 추가)
        self.mqtt_client = mqtt.Client(client_id="ros2_scale_pub")
        self.mqtt_client.username_pw_set(MQTT_USERNAME, MQTT_PASSWORD)
        
        # TLS 설정 추가 (포트 8883 사용시 필수)
        self.mqtt_client.tls_set()
        
        # MQTT 연결 콜백 추가 (디버깅용)
        def on_mqtt_connect(client, userdata, flags, rc):
            if rc == 0:
                self.get_logger().info("✅ MQTT 연결 성공")
            else:
                self.get_logger().error(f"❌ MQTT 연결 실패, 코드={rc}")
        
        self.mqtt_client.on_connect = on_mqtt_connect
        
        try:
            self.mqtt_client.connect(MQTT_BROKER_HOST, MQTT_BROKER_PORT, MQTT_KEEPALIVE)
            self.mqtt_client.loop_start()
            self.get_logger().info(f"MQTT 브로커 연결 시도: {MQTT_BROKER_HOST}:{MQTT_BROKER_PORT}")
        except Exception as e:
            self.get_logger().error(f"MQTT 연결 오류: {e}")
        
        try:
            self.ser = serial.Serial(SERIAL_PORT, SERIAL_BAUDRATE, timeout=1)
            self.get_logger().info(f"Serial opened: {SERIAL_PORT}")
        except Exception as e:
            self.get_logger().error(f"Serial open failed: {e}")
            self.ser = None
        
        # 주기적 퍼블리시 타이머
        self.create_timer(PUBLISH_INTERVAL, self.timer_callback)

    def timer_callback(self):
        if not self.ser:
            return
        
        line = self.ser.readline().decode().strip()
        try:
            weight = round(float(line), 3)
            
            # ROS2 퍼블리시 (기존 방식 유지)
            ros_msg = Float32(data=weight)
            self.pub.publish(ros_msg)
            
            # JSON 형태로 MQTT 퍼블리시
            json_payload = {
                "sensor_type": "scale",
                "weight": weight,
                "unit": "g",
                "timestamp": datetime.now().isoformat(),
                "device_id": "ros2_scale_pub"
            }
            
            payload_str = json.dumps(json_payload)
            result = self.mqtt_client.publish(
                topic=MQTT_TOPIC,
                payload=payload_str,
                qos=1,
                retain=False
            )
            
            # 퍼블리시 결과 확인
            if result.rc == mqtt.MQTT_ERR_SUCCESS:
                self.get_logger().info(f"Published JSON: {payload_str}")
            else:
                self.get_logger().warn(f"MQTT publish failed: {result.rc}")
                
        except ValueError:
            pass  # 숫자가 아닌 입력은 무시

def main():
    rclpy.init()
    node = ScalePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()