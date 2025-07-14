import rclpy
from rclpy.node import Node
from puddle_interfaces.msg import PuddleArray, Puddle
from std_msgs.msg import Header

from .moment_utils import compute_hu_moments, compare_hu_distance
from .topology_utils import compute_euler_characteristic

import numpy as np
from collections import deque

class TrackedPuddle:
    def __init__(self, puddle: Puddle):
        self.id = puddle.id
        self.last_seen = puddle.timestamp
        self.position = (puddle.x, puddle.y)
        self.hu_moments = np.array(puddle.hu_moments)
        self.euler_char = puddle.euler_char

class TopoMomentTracker(Node):
    def __init__(self):
        super().__init__('topo_moment_tracker')

        # 파라미터 선언
        self.declare_parameter("input_topic", "/puddle_array")
        self.declare_parameter("output_topic", "/puddle_tracking")
        self.declare_parameter("distance_threshold", 1.5)

        # 파라미터 로드
        self.input_topic = self.get_parameter("input_topic").value
        self.output_topic = self.get_parameter("output_topic").value
        self.threshold = self.get_parameter("distance_threshold").value

        # 이전 프레임 puddle 상태 저장소
        self.tracked = {}  # id → TrackedPuddle
        self.next_id = 0

        # ROS I/O
        self.subscription = self.create_subscription(PuddleArray, self.input_topic, self.puddle_callback, 10)
        self.publisher = self.create_publisher(PuddleArray, self.output_topic, 10)

        self.get_logger().info("🧠 TopoMomentTracker 노드 시작")

    def puddle_callback(self, msg: PuddleArray):
        updated_puddles = []
        unmatched = []

        for puddle in msg.puddles:
            hu = np.array(puddle.hu_moments)
            ec = puddle.euler_char
            pos = (puddle.x, puddle.y)

            best_match_id = None
            min_distance = float('inf')

            for pid, tracked in self.tracked.items():
                d_shape = compare_hu_distance(tracked.hu_moments, hu)
                d_topo = abs(tracked.euler_char - ec)
                d_geo = np.linalg.norm(np.array(tracked.position) - np.array(pos))
                total_d = d_shape + 0.5 * d_topo + 0.1 * d_geo

                if total_d < self.threshold and total_d < min_distance:
                    min_distance = total_d
                    best_match_id = pid

            if best_match_id is not None:
                puddle.id = best_match_id
                self.tracked[best_match_id] = TrackedPuddle(puddle)
            else:
                puddle.id = self.next_id
                self.tracked[self.next_id] = TrackedPuddle(puddle)
                self.next_id += 1

            updated_puddles.append(puddle)

        tracked_array = PuddleArray()
        tracked_array.header = Header()
        tracked_array.header.stamp = msg.header.stamp
        tracked_array.header.frame_id = msg.header.frame_id
        tracked_array.puddles = updated_puddles

        self.publisher.publish(tracked_array)
        self.get_logger().info(f"📌 추적된 puddle 수: {len(updated_puddles)}")

def main(args=None):
    rclpy.init(args=args)
    node = TopoMomentTracker()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
