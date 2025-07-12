import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Header
from common_msgs.msg import BoundingBox, BoundingBoxes
from cv_bridge import CvBridge
import cv2
import numpy as np
from ultralytics import YOLO
import time
import os
from datetime import datetime

class YOLOv8InferNode(Node):
    def __init__(self):
        super().__init__('yolov8_infer_node')

        self.declare_parameter('model_path', '/yolo_experiments_ws/models/yolov8.pt')
        self.declare_parameter('image_topic', '/robot1/oakd/rgb/image_raw')
        self.declare_parameter('conf_threshold', 0.3)
        self.declare_parameter('imgsz', 640)

        model_path = self.get_parameter('model_path').get_parameter_value().string_value
        self.conf_threshold = self.get_parameter('conf_threshold').get_parameter_value().double_value
        self.imgsz = self.get_parameter('imgsz').get_parameter_value().integer_value
        image_topic = self.get_parameter('image_topic').get_parameter_value().string_value

        self.bridge = CvBridge()
        self.model = YOLO(model_path)

        self.subscriber = self.create_subscription(
            Image,
            image_topic,
            self.image_callback,
            10
        )

        self.publisher = self.create_publisher(BoundingBoxes, '/bounding_boxes', 10)

        # 성능 측정용 변수
        self.start_time = time.time()
        self.frame_count = 0
        self.total_infer_time = 0.0

        self.get_logger().info(f'YOLOv8 Inference Node started with model: {model_path}')

    def image_callback(self, msg):
        # 최초 초기화
        if not hasattr(self, 'log_entries'):
            self.log_entries = []
            self.model_name = 'YOLOv8'
            self.log_dir = '/home/jack/yolo_experiments_ws/logs'
            os.makedirs(self.log_dir, exist_ok=True)
            self.timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
            self.log_path = os.path.join(self.log_dir, f'{self.model_name}_eval_{self.timestamp}.csv')

        elapsed = time.time() - self.start_time
        if elapsed >= 60.0:
            avg_time = self.total_infer_time / max(self.frame_count, 1)
            fps = self.frame_count / elapsed

            # 로그 출력
            self.get_logger().info(f' [{self.model_name}] 평가 종료')
            self.get_logger().info(f' 총 프레임: {self.frame_count}, 평균 추론 시간: {avg_time:.4f}s, FPS: {fps:.2f}')
            self.get_logger().info(f' 결과 저장 위치: {self.log_path}')

            # CSV 저장
            with open(self.log_path, 'w') as f:
                f.write('frame_id,timestamp,infer_time_ms,num_detections\n')
                for entry in self.log_entries:
                    f.write(f"{entry['frame_id']},{entry['timestamp']},{entry['infer_time_ms']:.2f},{entry['num_detections']}\n")

            rclpy.shutdown()
            return

        # 이미지 수신 및 변환
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        except Exception as e:
            self.get_logger().error(f'CV bridge conversion failed: {e}')
            return

        # 추론
        infer_start = time.time()
        results = self.model.predict(source=cv_image, conf=self.conf_threshold, imgsz=self.imgsz, verbose=False)
        infer_end = time.time()

        infer_time_ms = (infer_end - infer_start) * 1000.0
        timestamp = datetime.now().strftime('%H:%M:%S.%f')[:-3]
        num_detections = len(results[0].boxes) if results[0].boxes is not None else 0

        self.frame_count += 1
        self.total_infer_time += (infer_end - infer_start)

        # 로그 기록
        self.log_entries.append({
            'frame_id': self.frame_count,
            'timestamp': timestamp,
            'infer_time_ms': infer_time_ms,
            'num_detections': num_detections
        })

        self.get_logger().info(
            f"[{self.model_name}] Frame {self.frame_count:03d} | Time: {timestamp} | "
            f"Infer: {infer_time_ms:.2f} ms | Detections: {num_detections}"
        )

        # 퍼블리시 메시지
        detections = results[0].boxes
        boxes_msg = BoundingBoxes()
        boxes_msg.header = msg.header
        boxes_msg.boxes = []

        if detections is not None:
            for i, box in enumerate(detections):
                b = box.xyxy[0].cpu().numpy()
                conf = box.conf[0].item()
                cls_id = int(box.cls[0].item())
                name = self.model.names[cls_id] if hasattr(self.model, 'names') else str(cls_id)

                bb = BoundingBox()
                bb.header = msg.header
                bb.id = i
                bb.class_name = name
                bb.confidence = float(conf)
                bb.xmin = int(b[0])
                bb.ymin = int(b[1])
                bb.xmax = int(b[2])
                bb.ymax = int(b[3])

                boxes_msg.boxes.append(bb)

        self.publisher.publish(boxes_msg)

def main(args=None):
    rclpy.init(args=args)
    node = YOLOv8InferNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
