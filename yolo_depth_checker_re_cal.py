# yolo_depth_checker_re_cal.py
#!/usr/bin/env python3
import os
import sys
import math
import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge
from ultralytics import YOLO
from std_msgs.msg import Float32

# ========================
# 상수 정의
# ========================
MODEL_PATH = '/home/okj1812/models/yolov8n.pt'  # 모델 경로 하드코딩
COLOR_IMAGE_TOPIC = '/robot1/oakd/rgb/preview/image_raw'
COLOR_INFO_TOPIC  = '/robot1/oakd/rgb/camera_info'
DEPTH_IMAGE_TOPIC = '/robot1/oakd/stereo/image_raw'
DEPTH_INFO_TOPIC  = '/robot1/oakd/stereo/camera_info'
WINDOW_NAME = 'YOLO+Depth'
TARGET_CLASS_ID = 0

class YoloDepthRegionNode(Node):
    def __init__(self):
        super().__init__('yolo_depth_region_node')
        # 모델 로드
        model_path = MODEL_PATH
        if not os.path.exists(model_path):
            self.get_logger().error(f"Model not found: {model_path}")
            sys.exit(1)
        self.model = YOLO(model_path)
        self.names = getattr(self.model, 'names', [])

        # CvBridge 초기화
        self.bridge = CvBridge()
        self.latest_depth = None
        self.K_color = None
        self.D_color = None
        self.map1 = None
        self.map2 = None

        # 퍼블리셔: inference 시간
        self.inf_pub = self.create_publisher(Float32, '/inference_time', 10)

        # 구독 설정
        self.create_subscription(CameraInfo, COLOR_INFO_TOPIC, self.color_info_cb, 10)
        self.create_subscription(Image,     COLOR_IMAGE_TOPIC, self.color_callback, 10)
        self.create_subscription(CameraInfo, DEPTH_INFO_TOPIC, self.depth_info_cb, 10)
        self.create_subscription(Image,     DEPTH_IMAGE_TOPIC, self.depth_callback, 10)

        cv2.namedWindow(WINDOW_NAME, cv2.WINDOW_AUTOSIZE)

    def color_info_cb(self, msg: CameraInfo):
        if self.K_color is None:
            self.K_color = np.array(msg.k).reshape(3,3)
            self.D_color = np.array(msg.d)
            h, w = int(msg.height), int(msg.width)
            self.map1, self.map2 = cv2.initUndistortRectifyMap(
                self.K_color, self.D_color, None,
                self.K_color, (w, h), cv2.CV_16SC2)
            self.get_logger().info("Color camera calibration loaded.")

    def depth_info_cb(self, msg: CameraInfo):
        # Stereo 카메라 추가 보정이 필요할 때
        pass

    def depth_callback(self, msg: Image):
        depth = self.bridge.imgmsg_to_cv2(msg, desired_encoding='passthrough')
        if depth.dtype == np.float32:
            depth = np.nan_to_num(depth, nan=0.0) * 1000.0
        self.latest_depth = depth.astype(np.uint16)

    def compute_region_depth(self, region):
        vals = region.flatten()
        vals = vals[vals > 0]
        if vals.size == 0:
            return None
        median = np.median(vals)
        p90 = np.percentile(vals, 90)
        top_vals = vals[vals >= p90]
        mean_top = np.mean(top_vals) if top_vals.size > 0 else median
        return median, mean_top

    def color_callback(self, msg: Image):
        if self.latest_depth is None or self.map1 is None:
            return
        raw = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        img = cv2.remap(raw, self.map1, self.map2, interpolation=cv2.INTER_LINEAR)

        # 추론 시간 측정
        t0 = cv2.getTickCount()
        results = self.model(img)
        t1 = cv2.getTickCount()
        dt_ms = (t1 - t0) / cv2.getTickFrequency() * 1000.0
        self.inf_pub.publish(Float32(data=dt_ms))

        for r in results:
            for box in r.boxes:
                cls = int(box.cls[0])
                if cls != TARGET_CLASS_ID:
                    continue
                x1, y1, x2, y2 = map(int, box.xyxy[0])
                region = self.latest_depth[y1:y2, x1:x2]
                stats = self.compute_region_depth(region)
                if stats is None:
                    continue
                median_mm, mean_top_mm = stats
                median_m = median_mm / 1000.0
                top_m = mean_top_mm / 1000.0

                cv2.rectangle(img, (x1, y1), (x2, y2), (0,0,255), 2)
                label = self.names[cls] if cls < len(self.names) else f"cls{cls}"
                conf = float(box.conf[0])
                cv2.putText(img, f"{label}:{conf:.2f}", (x1, y1-5), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255,0,0), 2)
                cx, cy = (x1+x2)//2, (y1+y2)//2
                cv2.circle(img, (cx, cy), 4, (0,255,0), -1)
                cv2.putText(img, f"med:{median_m:.2f}m top:{top_m:.2f}m", (x1, y2+15), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0,255,0), 1)

        cv2.imshow(WINDOW_NAME, img)
        if cv2.waitKey(1) == ord('q'):
            rclpy.shutdown()


def main():
    rclpy.init()
    node = YoloDepthRegionNode()
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
