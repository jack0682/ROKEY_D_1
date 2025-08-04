import ssl
import random
import time
import json
import paho.mqtt.client as mqtt
import rclpy
from datetime import datetime

MQTT_CONFIG = {
    'broker': 'p021f2cb.ala.asia-southeast1.emqxsl.com',
    'port': 8883,
    'username': 'Rokey',
    'password': '1234567',
    'topic': "ros2_topic_list",
    'client_id': f'python-mqtt-{random.randint(0, 100)}',
    'keepalive': 60
}

def connect_mqtt():
    client = mqtt.Client(client_id=MQTT_CONFIG['client_id'])
    client.username_pw_set(MQTT_CONFIG['username'], MQTT_CONFIG['password'])
    client.tls_set(cert_reqs=ssl.CERT_NONE)
    client.tls_insecure_set(True)
    client.connect(MQTT_CONFIG['broker'], MQTT_CONFIG['port'], MQTT_CONFIG['keepalive'])
    client.loop_start()
    return client

def main():
    # MQTT 연결
    client = connect_mqtt()

    # ROS2 초기화
    rclpy.init()
    node = rclpy.create_node("ros2_topic_list_publisher")

    try:
        while rclpy.ok():
            # 현재 ROS2 토픽 목록 가져오기
            topics = node.get_topic_names_and_types()
            topic_names = [name for name, _ in topics]

            # JSON 형식 데이터 구성
            json_payload = {
                "sensor_type": "ros2_topic_list",
                "topic_count": len(topic_names),
                "topics": topic_names,
                "timestamp": datetime.now().isoformat(),
                "device_id": "ros2_topic_list_pub"
            }

            # MQTT로 전송
            payload_str = json.dumps(json_payload)
            client.publish(MQTT_CONFIG['topic'], payload_str)
            print(f"[전송됨] {payload_str}")

            time.sleep(5)  # 5초마다 전송
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        client.loop_stop()

if __name__ == "__main__":
    main()
