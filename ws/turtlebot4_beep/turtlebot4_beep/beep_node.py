#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from std_msgs.msg import String, Bool, Int32
from sensor_msgs.msg import BatteryState, Imu
from geometry_msgs.msg import TransformStamped, PoseStamped, Twist
from nav_msgs.msg import Path
from irobot_create_msgs.msg import DockStatus  # 🔧 추가된 import
import tf2_ros

import paho.mqtt.client as mqtt
import ssl
import json
import random

class UnifiedROSMQTTBridge(Node):
    def __init__(self):
        super().__init__('unified_ros2_mqtt_bridge')

        # MQTT 설정
        self.broker = 'p021f2cb.ala.asia-southeast1.emqxsl.com'
        self.port = 8883
        self.username = 'Rokey'
        self.password = '1234567'
        self.topic_general = "tb4"
        self.topic_pose = "tb4"
        self.client_id = f'unified-mqtt-{random.randint(0, 1000)}'
        self._setup_mqtt()

        # ROS2 토픽 구독 설정 - 올바른 메시지 타입으로 수정
        self.topic_type_map = {
            "/robot1/battery_state": BatteryState,
            "/robot1/ip": String,
            "/robot1/cmd_vel": Twist,                    # ✅ 확인됨
            "/robot1/dock_status": DockStatus,           # 🔧 수정: Bool → DockStatus  
            "/robot1/waypoints": Path,                   # 확인 필요
            "/robot1/imu": Imu,                         # ✅ 확인됨
            "/robot1/goal_pose": PoseStamped,           # 확인 필요
        }

        qos = QoSProfile(depth=10)
        
        # 구독 생성 및 로깅 개선
        self.subscription_count = 0
        for topic, msg_type in self.topic_type_map.items():
            try:
                self.create_subscription(msg_type, topic, self._callback_factory(topic), qos)
                self.subscription_count += 1
                self.get_logger().info(f"✅ Subscribed to {topic} ({msg_type.__name__})")
            except Exception as e:
                self.get_logger().error(f"❌ Failed to subscribe to {topic}: {e}")
        
        self.get_logger().info(f"📡 Total subscriptions created: {self.subscription_count}/{len(self.topic_type_map)}")

        # TF 버퍼 및 리스너
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        # TF 전송 타이머 (1초 주기)
        self.timer = self.create_timer(1.0, self.lookup_and_publish_tf)
        
        # 통계 카운터
        self.published_count = 0
        self.error_count = 0

    def _setup_mqtt(self):
        """MQTT 클라이언트 설정 및 연결"""
        try:
            self.mqtt_client = mqtt.Client(
                client_id=self.client_id,
                protocol=mqtt.MQTTv311
            )
            self.mqtt_client.username_pw_set(self.username, self.password)
            self.mqtt_client.tls_set(cert_reqs=ssl.CERT_NONE)
            self.mqtt_client.tls_insecure_set(True)
            
            # 연결 콜백 설정
            self.mqtt_client.on_connect = self._on_mqtt_connect
            self.mqtt_client.on_disconnect = self._on_mqtt_disconnect
            
            self.mqtt_client.connect(self.broker, self.port)
            self.mqtt_client.loop_start()
            self.get_logger().info("🔄 MQTT connection initiated...")
        except Exception as e:
            self.get_logger().error(f"❌ MQTT connection failed: {e}")

    def _on_mqtt_connect(self, client, userdata, flags, rc):
        """MQTT 연결 성공 콜백"""
        if rc == 0:
            self.get_logger().info("✅ MQTT connected successfully")
        else:
            self.get_logger().error(f"❌ MQTT connection failed with code {rc}")

    def _on_mqtt_disconnect(self, client, userdata, rc):
        """MQTT 연결 해제 콜백"""
        if rc != 0:
            self.get_logger().warning(f"⚠️ MQTT unexpected disconnection: {rc}")

    def _callback_factory(self, topic_name):
        """토픽별 콜백 함수 생성"""
        def callback(msg):
            try:
                # 메시지를 딕셔너리로 변환
                if hasattr(msg, '__slots__'):
                    data_dict = {}
                    for slot in msg.__slots__:
                        value = getattr(msg, slot)
                        # 복잡한 객체들을 문자열로 변환
                        if hasattr(value, '__slots__') or hasattr(value, '__dict__'):
                            data_dict[slot] = str(value)
                        else:
                            data_dict[slot] = value
                else:
                    data_dict = {'data': str(msg)}

                # MQTT 페이로드 생성
                payload = {
                    "topic": topic_name,
                    "data": data_dict,
                    "timestamp": self.get_clock().now().to_msg().sec
                }
                
                # MQTT 발행
                json_payload = json.dumps(payload, default=str)
                result = self.mqtt_client.publish(self.topic_general, json_payload)
                
                if result.rc == mqtt.MQTT_ERR_SUCCESS:
                    self.published_count += 1
                    self.get_logger().debug(f"📤 Published to MQTT: {topic_name}")
                else:
                    self.error_count += 1
                    self.get_logger().warning(f"⚠️ MQTT publish failed for {topic_name}: {result.rc}")
                    
            except Exception as e:
                self.error_count += 1
                self.get_logger().error(f"❌ Failed to process message from {topic_name}: {e}")
        
        return callback

    def lookup_and_publish_tf(self):
        """TF 조회 및 MQTT 발행"""
        try:
            # map -> base_link 변환 조회
            trans: TransformStamped = self.tf_buffer.lookup_transform(
                'map', 'base_link', rclpy.time.Time())
            
            pose = {
                "translation": {
                    "x": trans.transform.translation.x,
                    "y": trans.transform.translation.y,
                    "z": trans.transform.translation.z
                },
                "rotation": {
                    "x": trans.transform.rotation.x,
                    "y": trans.transform.rotation.y,
                    "z": trans.transform.rotation.z,
                    "w": trans.transform.rotation.w
                },
                "timestamp": self.get_clock().now().to_msg().sec
            }
            
            result = self.mqtt_client.publish(self.topic_pose, json.dumps(pose))
            if result.rc == mqtt.MQTT_ERR_SUCCESS:
                self.get_logger().debug("📤 TF pose published to MQTT")
            else:
                self.get_logger().warning(f"⚠️ TF pose publish failed: {result.rc}")
                
        except Exception as e:
            # TF 조회 실패는 일반적이므로 DEBUG 레벨로 로깅
            self.get_logger().debug(f"TF lookup failed: {e}")

    def print_statistics(self):
        """통계 출력"""
        self.get_logger().info(f"📊 Statistics - Published: {self.published_count}, Errors: {self.error_count}")


def main(args=None):
    rclpy.init(args=args)
    
    try:
        node = UnifiedROSMQTTBridge()
        
        # 통계 출력 타이머 (30초마다)
        def print_stats():
            node.print_statistics()
        
        node.create_timer(30.0, print_stats)
        
        node.get_logger().info("🚀 Unified ROS2-MQTT Bridge started")
        node.get_logger().info("🎯 Press Ctrl+C to stop")
        
        rclpy.spin(node)
        
    except KeyboardInterrupt:
        print("\n👋 Shutting down gracefully...")
    except Exception as e:
        print(f"❌ Unexpected error: {e}")
    finally:
        try:
            if 'node' in locals():
                node.mqtt_client.loop_stop()
                node.mqtt_client.disconnect()
                node.get_logger().info("🔌 MQTT disconnected")
                node.destroy_node()
            rclpy.shutdown()
        except:
            pass


if __name__ == '__main__':
    main()