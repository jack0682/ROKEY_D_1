import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time

class VelocityController(Node):
    def __init__(self):
        super().__init__('velocity_controller')
        self.publisher_ = self.create_publisher(Twist, '/robot1/cmd_vel', 10)
        self.get_logger().info('Velocity controller node started.')

    def move(self, linear_x=0.2, angular_z=0.0, duration=2.0):
        twist = Twist()
        twist.linear.x = linear_x
        twist.angular.z = angular_z

        self.get_logger().info(
            f'Moving: linear_x={linear_x}, angular_z={angular_z} for {duration} sec')

        start_time = time.time()
        while time.time() - start_time < duration:
            self.publisher_.publish(twist)
            time.sleep(0.1)

        self.stop()

    def stop(self):
        self.get_logger().info('Stopping robot.')
        twist = Twist()  # all 0
        self.publisher_.publish(twist)

def main(args=None):
    rclpy.init(args=args)
    node = VelocityController()

    try:
        # 예시: 0.2 m/s로 2초간 직진 후 정지
        node.move(linear_x=0.2, angular_z=0.0, duration=2.0)
        # 예시: 제자리에서 오른쪽으로 회전 (0.5 rad/s, 2초간)
        node.move(linear_x=0.0, angular_z=-0.5, duration=2.0)
    except KeyboardInterrupt:
        node.stop()

    rclpy.shutdown()

if __name__ == '__main__':
    main()
