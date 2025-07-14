# tf_point_transform.py
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from geometry_msgs.msg import PointStamped
import tf2_ros
import tf2_geometry_msgs

class TfPointTransform(Node):
    def __init__(self):
        super().__init__('tf_point_transform')

        # TF 관련 초기화
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        # depth, width 초기값
        self.latest_depth = None
        self.latest_width = None

        # ✅ 퍼블리셔에서 보낸 값들을 구독
        self.create_subscription(Float32, '/depth_m', self.depth_callback, 10)
        self.create_subscription(Float32, '/real_width_cm', self.width_callback, 10)

        # TF 변환 타이머 시작
        self.get_logger().info("TF Tree 안정화 시작. 5초 후 변환 시작합니다.")
        self.start_timer = self.create_timer(5.0, self.start_transform)

    def depth_callback(self, msg):
        self.latest_depth = msg.data
        self.get_logger().info(f"[Subscribed] depth_m = {self.latest_depth:.2f} m")

    def width_callback(self, msg):
        self.latest_width = msg.data
        self.get_logger().info(f"[Subscribed] real_width_m = {self.latest_width:.2f} cm")

    def start_transform(self):
        self.get_logger().info("TF Tree 안정화 완료. 변환 시작합니다.")
        self.transform_timer = self.create_timer(2.0, self.timer_callback)
        self.start_timer.cancel()

    def timer_callback(self):
        try:
            if self.latest_depth is None:
                self.get_logger().warn("아직 depth_m 값을 수신하지 못했습니다.")
                return

            # base_link 기준 포인트 생성
            point_base = PointStamped()
            point_base.header.stamp = self.get_clock().now().to_msg()
            point_base.header.frame_id = 'base_link'
            point_base.point.x = (self.latest_depth)**2- (self.latest_width)**2 # depth 값을 x로 사용
            point_base.point.y = 0.0
            point_base.point.z = 0.0

            try:
                point_map = self.tf_buffer.transform(
                    point_base,
                    'map',
                    timeout=rclpy.duration.Duration(seconds=0.5)
                )
                self.get_logger().info(
                    f"""[Base_link] ({point_base.point.x:.2f}, {point_base.point.y:.2f}, {point_base.point.z:.2f})
                [Map]       ({point_map.point.x:.2f}, {point_map.point.y:.2f}, {point_map.point.z:.2f})
                [Depth]     {self.latest_depth:.2f} m
                [Width]     {self.latest_width:.2f} cm"""
                )

            except Exception as e:
                self.get_logger().warn(f"TF transform to map failed: {e}")

        except Exception as e:
            self.get_logger().warn(f"Unexpected error: {e}")

def main():
    rclpy.init()
    node = TfPointTransform()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
