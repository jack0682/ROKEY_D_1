# /home/jack/turtlebot4_ws/src/puddle_detection/puddle_detection/agsenet_node.py

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Header
from cv_bridge import CvBridge
from puddle_interfaces.msg import Puddle, PuddleArray
import os
import sys

import cv2
import torch
import numpy as np
from pathlib import Path

# ✅ AGSENet 모델 경로 설정 (상위 디렉토리 경로 수동 추가)
CURRENT_DIR = os.path.dirname(os.path.abspath(__file__))
PARENT_DIR = os.path.abspath(os.path.join(CURRENT_DIR, ".."))
AGSENET_MODEL_DIR = os.path.join(PARENT_DIR, "agsenet_model")
sys.path.append(AGSENET_MODEL_DIR)

# ✅ 모델 임포트
from agsenet_model.AGSENet import AGSENet

class AGSENetNode(Node):
    def __init__(self):
        super().__init__('agsenet_node')

        # Parameters
        self.declare_parameter("image_topic", "/oakd/rgb/preview/image_raw")
        self.declare_parameter("model_path", str(Path(__file__).parent.parent / "models" / "model.pth"))
        self.declare_parameter("threshold", 0.5)

        # Parameters 읽기
        image_topic = self.get_parameter("image_topic").value
        model_path = self.get_parameter("model_path").value
        self.threshold = self.get_parameter("threshold").value

        # Load AGSENet model
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        self.model = AGSENet()
        self.model.load_state_dict(torch.load(model_path, map_location=self.device))
        self.model.eval().to(self.device)
        self.get_logger().info(f"✅ AGSENet 모델 로드 완료: {model_path}")

        # ROS Interface
        self.bridge = CvBridge()
        self.subscription = self.create_subscription(Image, image_topic, self.image_callback, 10)
        self.publisher = self.create_publisher(PuddleArray, "puddle_array", 10)

    def preprocess(self, cv_image):
        img = cv2.resize(cv_image, (256, 256))  # 논문 입력 크기
        img_tensor = torch.from_numpy(img.transpose(2, 0, 1)).float() / 255.0
        return img_tensor.unsqueeze(0).to(self.device)

    def postprocess(self, mask, original_shape):
        # 마스크 → 바이너리 → 원본 사이즈 복원
        mask = torch.sigmoid(mask).squeeze().detach().cpu().numpy()
        mask = (mask > self.threshold).astype(np.uint8) * 255
        return cv2.resize(mask, (original_shape[1], original_shape[0]))

    def image_callback(self, msg):
        try:
            # Convert to OpenCV image
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            input_tensor = self.preprocess(cv_image)
            with torch.no_grad():
                output = self.model(input_tensor)
            mask = self.postprocess(output, cv_image.shape)

            # Find contours for puddle candidates
            contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

            puddle_array = PuddleArray()
            puddle_array.header = Header()
            puddle_array.header.stamp = msg.header.stamp
            puddle_array.header.frame_id = msg.header.frame_id

            for i, cnt in enumerate(contours):
                area = cv2.contourArea(cnt)
                if area < 100:  # 너무 작은 puddle은 무시
                    continue
                M = cv2.moments(cnt)
                if M["m00"] == 0:
                    continue
                cx = M["m10"] / M["m00"]
                cy = M["m01"] / M["m00"]

                puddle = Puddle()
                puddle.id = i
                puddle.x = float(cx)
                puddle.y = float(cy)
                puddle.z = 0.0  # depth 미사용
                puddle.area = float(area)
                puddle.hu_moments = cv2.HuMoments(M).flatten().tolist()
                puddle.euler_char = 1  # 외곽선 1개 기준
                puddle.shape_hash = str(hash(str(puddle.hu_moments)))
                puddle.risk_level = 1 if area > 1500 else 0
                puddle.timestamp = msg.header.stamp

                puddle_array.puddles.append(puddle)

            self.publisher.publish(puddle_array)
            self.get_logger().info(f"🟦 puddle {len(puddle_array.puddles)}개 검출됨")

        except Exception as e:
            self.get_logger().error(f"❌ AGSENet 추론 실패: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = AGSENetNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
