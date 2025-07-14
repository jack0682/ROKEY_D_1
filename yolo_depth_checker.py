#!/usr/bin/env python3
import os
import sys
import math
import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from ultralytics import YOLO

# ========================
# 상수 정의
# ========================
MODEL_PATH        = '/home/okj1812/Downloads/best.pt'
COLOR_TOPIC       = '/robot1/oakd/rgb/preview/image_raw'
DEPTH_TOPIC       = '/robot1/oakd/stereo/image_raw'
TARGET_CLASS_ID   = 0       # 예: car=0
NORMALIZE_DEPTH_M = 5.0     # 최대 시각화 깊이(m)

# ========================
# 통합 YOLO+Depth 노드
# ========================
class YoloDepthNode(Node):
    def __init__(self):
        super().__init__('yolo_depth_node')
        # 모델 로드
        if not os.path.exists(MODEL_PATH):
            self.get_logger().error(f"Model not found: {MODEL_PATH}")
            sys.exit(1)
        self.model = YOLO(MODEL_PATH)
        self.names = getattr(self.model, 'names', [])

        # CvBridge
        self.bridge = CvBridge()
        self.latest_depth = None

        # 컬러 이미지 구독
        self.create_subscription(
            Image, COLOR_TOPIC, self.color_callback, 10)
        # 깊이 이미지 구독
        self.create_subscription(
            Image, DEPTH_TOPIC, self.depth_callback, 10)

        cv2.namedWindow("YOLO+Depth", cv2.WINDOW_AUTOSIZE)

    def depth_callback(self, msg: Image):
        # NumPy 배열로 변환 (단위 mm)
        depth = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        # float32(m) -> mm 로 변환
        if depth.dtype == np.float32:
            depth = np.nan_to_num(depth, nan=0.0) * 1000.0
        self.latest_depth = depth.astype(np.uint16)

    def color_callback(self, msg: Image):
        if self.latest_depth is None:
            self.get_logger().warn("Waiting for first depth frame...")
            return

        # 컬러 프레임
        img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        results = self.model(img, stream=True)

        for r in results:
            for box in r.boxes:
                cls = int(box.cls[0])
                if cls != TARGET_CLASS_ID:
                    continue
                # 바운딩 박스
                x1, y1, x2, y2 = map(int, box.xyxy[0])
                # 중앙 좌표
                cx, cy = (x1 + x2)//2, (y1 + y2)//2
                # 깊이 읽기 (mm→m)
                depth_mm = int(self.latest_depth[cy, cx])
                depth_m  = depth_mm / 1000.0

                # 시각화
                cv2.rectangle(img, (x1,y1), (x2,y2), (0,0,255), 2)
                label = self.names[cls] if cls < len(self.names) else f"class_{cls}"
                cv2.putText(img, f"{label} {box.conf[0]:.2f}", (x1, y1-10),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255,0,0), 2)
                # 깊이 텍스트
                cv2.circle(img, (cx,cy), 4, (0,255,0), -1)
                cv2.putText(img, f"{depth_m:.2f}m", (cx+5, cy-5),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0,255,0), 2)

        # 화면에 표시
        cv2.imshow("YOLO+Depth", cv2.resize(img, (img.shape[1]*2, img.shape[0]*2)))
        if cv2.waitKey(1) & 0xFF == ord('q'):
            rclpy.shutdown()

def main():
    rclpy.init()
    node = YoloDepthNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
