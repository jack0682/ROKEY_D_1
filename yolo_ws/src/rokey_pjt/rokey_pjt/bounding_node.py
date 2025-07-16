import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point, PointStamped
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO

IMAGE_TOPIC = '/robot3/oakd/rgb/preview/image_raw'
# TARGET_CLASS_ID = 0
TARGET_CLASS_ID = 2 #  ['boots', 'helmet', 'human', 'vest']
MODEL_PATH = '/home/jsj2204/Downloads/yolov8n_4classes.pt'
# MODEL_PATH = '/home/jsj2204/Downloads/yolov5n_5classes.pt'

class YoloNode(Node):
    def __init__(self):
        super().__init__('yolo_node')
        self.bridge = CvBridge()
        self.model = YOLO(MODEL_PATH)
        self.class_names = self.model.names

        self.latest_distance = None

        self.sub_image = self.create_subscription(Image, IMAGE_TOPIC, self.image_callback, 10)
        self.sub_distance = self.create_subscription(PointStamped, 'person_distance', self.distance_callback, 10)
        self.pub_center = self.create_publisher(Point, 'person_center', 10)

    def distance_callback(self, msg):
        self.latest_distance = msg

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        results = self.model(frame, stream=True)

        for r in results:
            for box in r.boxes:
                cls = int(box.cls[0])
                
                if cls != TARGET_CLASS_ID:
                    continue

                x1, y1, x2, y2 = map(int, box.xyxy[0])
                cx = (x1 + x2) // 2
                cy = (y1 + y2) // 2

                # 중심 좌표 퍼블리시
                center_msg = Point()
                center_msg.x = float(cx)
                center_msg.y = float(cy)
                self.pub_center.publish(center_msg)

                label = self.class_names[cls]
                conf = float(box.conf[0])

                cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
                cv2.putText(frame, f'{label} {conf:.2f}', (x1, y1 - 10),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 0), 2)
                               
                # 수신된 거리 정보와 일치하면 표시
                if self.latest_distance:
                    if abs(int(self.latest_distance.point.x) - cx) <= 3 and abs(int(self.latest_distance.point.y) - cy) <= 3:

                        d = self.latest_distance.point.z
                        cv2.putText(frame, f'{d:.2f} m', (x1, y2 + 20),
                                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

        cv2.imshow('YOLO Detection', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            rclpy.shutdown()
            cv2.destroyAllWindows()

def main():
    rclpy.init()
    node = YoloNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
