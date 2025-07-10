import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time
import math

class StarMover(Node):
    def __init__(self):
        super().__init__('star_mover')
        self.pub = self.create_publisher(Twist, '/robot1/cmd_vel', 10)
        self.rate = self.create_rate(10)
    
    def move_forward(self, duration, speed=0.2):
        twist = Twist()
        twist.linear.x = speed
        start = time.time()
        while time.time() - start < duration:
            self.pub.publish(twist)
            time.sleep(0.1)

    def rotate(self, duration, angular_speed=0.5):
        twist = Twist()
        twist.angular.z = angular_speed
        start = time.time()
        while time.time() - start < duration:
            self.pub.publish(twist)
            time.sleep(0.1)

    def draw_star(self, edges=5):
        for _ in range(edges):
            self.move_forward(3.0)      # 0.3m 이동
            self.rotate(5.0)           # 144도 회전

def main():
    rclpy.init()
    node = StarMover()
    node.draw_star()
    rclpy.shutdown()
