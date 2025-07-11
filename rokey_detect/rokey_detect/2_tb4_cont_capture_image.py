import os
import cv2
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

# ==============================
# 사용자 설정 상수 정의
# ==============================
SAVE_DIRECTORY = "captured_images"                          # 저장할 디렉토리 이름
FILE_PREFIX = "oakd_capture"                                # 저장할 파일 prefix
IMAGE_TOPIC = "/robot4/oakd/rgb/preview/image_raw"         # 구독할 이미지 토픽
CAPTURE_INTERVAL = 1.0                                       # 이미지 캡처 간격 (초 단위)

class ImageCaptureNode(Node):
    def __init__(self, save_directory: str, file_prefix: str):
        super().__init__('image_capture_node')

        # 이미지 토픽 구독
        self.subscription = self.create_subscription(
            Image,
            IMAGE_TOPIC,
            self.listener_callback,
            10
        )

        # 초기 설정
        self.bridge = CvBridge()
        self.frame = None
        self.save_directory = save_directory
        self.file_prefix = f"{file_prefix}_"
        self.image_count = 0

        # 저장 디렉토리 생성
        os.makedirs(self.save_directory, exist_ok=True)

    def listener_callback(self, msg: Image):
        self.frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')

def main():
    rclpy.init()
    node = ImageCaptureNode(SAVE_DIRECTORY, FILE_PREFIX)
    last_capture_time = time.time()

    try:
        cv2.startWindowThread()
        cv2.namedWindow("Live Feed", cv2.WINDOW_NORMAL)

        while rclpy.ok():
            rclpy.spin_once(node, timeout_sec=0.1)

            if node.frame is not None:
                # 실시간 영상 출력
                cv2.imshow("Live Feed", node.frame)
                key = cv2.waitKey(1) & 0xFF

                # CAPTURE_INTERVAL 초마다 이미지 저장
                now = time.time()
                if now - last_capture_time >= CAPTURE_INTERVAL:
                    file_name = os.path.join(
                        node.save_directory,
                        f"{node.file_prefix}img_{node.image_count}.jpg"
                    )
                    cv2.imwrite(file_name, node.frame)
                    print(f"Image saved: {file_name}")
                    node.image_count += 1
                    last_capture_time = now

                # 'q' 키를 누르면 종료
                if key == ord('q'):
                    break

    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
