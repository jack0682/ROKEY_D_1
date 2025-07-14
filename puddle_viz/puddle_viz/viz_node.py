import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from puddle_interfaces.msg import PuddleArray
from visualization_msgs.msg import Marker, MarkerArray

class PuddleVizNode(Node):
    def __init__(self):
        super().__init__('viz_node')

        # 파라미터 선언 및 불러오기
        self.declare_parameter("marker_namespace", "puddles")
        self.declare_parameter("color_safe", {"r": 0.0, "g": 1.0, "b": 0.0, "a": 0.7})
        self.declare_parameter("color_risk", {"r": 1.0, "g": 0.0, "b": 0.0, "a": 0.8})
        self.declare_parameter("color_emergency", {"r": 0.7, "g": 0.0, "b": 0.7, "a": 0.8})
        self.declare_parameter("marker_scale", {"x": 0.3, "y": 0.3, "z": 0.05})
        self.declare_parameter("text_scale", 0.2)
        self.declare_parameter("lifetime_sec", 3.0)

        self.ns = self.get_parameter("marker_namespace").value
        self.color_safe = self.get_parameter("color_safe").value
        self.color_risk = self.get_parameter("color_risk").value
        self.color_emergency = self.get_parameter("color_emergency").value
        self.scale = self.get_parameter("marker_scale").value
        self.text_scale = self.get_parameter("text_scale").value
        self.lifetime = self.get_parameter("lifetime_sec").value

        # 구독자 & 퍼블리셔
        self.subscription = self.create_subscription(
            PuddleArray,
            "/puddle_tracking",
            self.puddle_callback,
            10
        )
        self.publisher = self.create_publisher(MarkerArray, "~/markers", 10)

        self.get_logger().info("🗺️ PuddleVizNode initialized")

    def get_color_by_risk(self, level: int):
        if level == 0:
            return self.color_safe
        elif level == 1:
            return self.color_risk
        else:
            return self.color_emergency

    def puddle_callback(self, msg):
        markers = MarkerArray()
        stamp = msg.header.stamp
        frame = msg.header.frame_id

        for puddle in msg.puddles:
            pos = (puddle.x, puddle.y, puddle.z)
            risk = puddle.risk_level

            # Sphere Marker
            m = Marker()
            m.header = Header(stamp=stamp, frame_id=frame)
            m.ns = self.ns
            m.id = puddle.id
            m.type = Marker.SPHERE
            m.action = Marker.ADD
            m.pose.position.x = pos[0]
            m.pose.position.y = pos[1]
            m.pose.position.z = pos[2]
            m.pose.orientation.w = 1.0
            m.scale.x = self.scale['x']
            m.scale.y = self.scale['y']
            m.scale.z = self.scale['z']
            c = self.get_color_by_risk(risk)
            m.color.r = c['r']
            m.color.g = c['g']
            m.color.b = c['b']
            m.color.a = c['a']
            m.lifetime.sec = int(self.lifetime)
            markers.markers.append(m)

            # Text Marker
            t = Marker()
            t.header = m.header
            t.ns = self.ns + "_text"
            t.id = 1000 + puddle.id
            t.type = Marker.TEXT_VIEW_FACING
            t.action = Marker.ADD
            t.pose.position.x = pos[0]
            t.pose.position.y = pos[1]
            t.pose.position.z = pos[2] + 0.1
            t.scale.z = self.text_scale
            t.color.r = 1.0
            t.color.g = 1.0
            t.color.b = 1.0
            t.color.a = 1.0
            t.text = f"ID:{puddle.id} A:{int(puddle.area)} Risk:{risk}"
            t.lifetime.sec = int(self.lifetime)
            markers.markers.append(t)

        self.publisher.publish(markers)
        self.get_logger().info(f"🟢 {len(markers.markers)}개 marker 퍼블리시 완료")

def main(args=None):
    rclpy.init(args=args)
    node = PuddleVizNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
