import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient

class GoalSender(Node):
    def __init__(self):
        super().__init__('goal_sender')
        self._action_client = ActionClient(self, NavigateToPose, '/navigate_to_pose')

    def send_goal(self, x, y, yaw_deg=0.0):
        from tf_transformations import quaternion_from_euler
        import math

        # 좌표 설정
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()
        goal_msg.pose.pose.position.x = x
        goal_msg.pose.pose.position.y = y

        # orientation (yaw to quaternion)
        q = quaternion_from_euler(0, 0, math.radians(yaw_deg))
        goal_msg.pose.pose.orientation.x = q[0]
        goal_msg.pose.pose.orientation.y = q[1]
        goal_msg.pose.pose.orientation.z = q[2]
        goal_msg.pose.pose.orientation.w = q[3]

        # 서버 연결 기다리기
        self._action_client.wait_for_server()
        self.get_logger().info(f'Sending goal to ({x:.2f}, {y:.2f})')

        # 목표 전송
        send_goal_future = self._action_client.send_goal_async(goal_msg)
        send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn('Goal rejected.')
            return
        self.get_logger().info('Goal accepted.')

        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self.result_callback)

    def result_callback(self, future):
        result = future.result().result
        self.get_logger().info('Navigation result: SUCCESS')
        rclpy.shutdown()

def main(args=None):
    rclpy.init(args=args)
    node = GoalSender()
    # 예시: (1.0m, 0.5m) 좌표로 이동
    node.send_goal(1.0, 0.5, yaw_deg=0.0)
    rclpy.spin(node)

if __name__ == '__main__':
    main()
