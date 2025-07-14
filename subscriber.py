# tf_point_transform.py
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PointStamped
import tf2_ros
import tf2_geometry_msgs  # 꼭 필요

class TfPointTransform(Node):
    def __init__(self):
        super().__init__('tf_point_transform')

        # TF Buffer와 Listener 준비
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        # 5초 후에 변환 시작
        self.get_logger().info("TF Tree 안정화 시작. 5초 후 변환 시작합니다.")
        self.start_timer = self.create_timer(5.0, self.start_transform)
#---------------------------------------------------------------------------------------------        
        # 깊이 및 위치 초기값
        self.latest_depth = None
        self.latest_width = None
        self.create_subscription(PointStamped, '/object_position', self.position_callback, 10)
#---------------------------------------------------------------------------------------------
    def start_transform(self):
        self.get_logger().info("TF Tree 안정화 완료. 변환 시작합니다.")

        # 주기적 변환 타이머 등록
        self.transform_timer = self.create_timer(2.0, self.timer_callback)

        # 시작 타이머 중지 (한 번만 실행)
        self.start_timer.cancel()
#---------------------------------------------------------------------------------------------
    def position_callback(self, msg: PointStamped):
        self.latest_depth = msg.point.x
        self.latest_width = msg.point.y
        self.get_logger().info(f"[Subscribed] depth = {self.latest_depth:.2f} m, width = {self.latest_width:.2f} m")
#---------------------------------------------------------------------------------------------

    def timer_callback(self):
        try:
            if self.latest_depth is None or self.latest_width is None:
                self.get_logger().warn("아직 위치 데이터를 수신하지 못했습니다.")
                return

            point_base = PointStamped()
            point_base.header.stamp = self.get_clock().now().to_msg()
            point_base.header.frame_id = 'base_link'
            point_base.point.x = 0.0
            point_base.point.y = 0.0
            point_base.point.z = 0.0

            try:
                point_map = self.tf_buffer.transform(
                    point_base,
                    'map',
                    timeout=rclpy.duration.Duration(seconds=0.5)
                )
                # [TF 변환 성공 시]
                self.get_logger().info(f"[Base_link] ({point_base.point.x:.2f}, {point_base.point.y:.2f}, {point_base.point.z:.2f})")
                self.get_logger().info(f"[Map]       ({(point_map.point.x + self.latest_depth):.2f}, {(point_map.point.y + self.latest_width):.2f}, {point_map.point.z:.2f})")
            except Exception as e:
                self.get_logger().warn(f"⚠️ TF transform to map failed: {e}")

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
