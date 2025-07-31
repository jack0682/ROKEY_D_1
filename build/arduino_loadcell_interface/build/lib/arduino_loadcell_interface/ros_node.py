import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64

from arduino_loadcell_interface.interface import LoadCellSerialInterface


class LoadCellPublisherNode(Node):
    def __init__(self):
        super().__init__("loadcell_serial_node")

        # Declare and read parameters
        self.declare_parameter("port", "/dev/ttyUSB0")
        self.declare_parameter("baudrate", 38400)
        self.declare_parameter("publish_topic", "/loadcell/weight")
        self.declare_parameter("publish_rate", 10.0)

        port = self.get_parameter("port").get_parameter_value().string_value
        baudrate = self.get_parameter("baudrate").get_parameter_value().integer_value
        topic_name = self.get_parameter("publish_topic").get_parameter_value().string_value
        publish_rate = self.get_parameter("publish_rate").get_parameter_value().double_value

        # ROS2 publisher
        self.publisher_ = self.create_publisher(Float64, topic_name, 10)

        # Serial interface
        self.serial_interface = LoadCellSerialInterface(
            port=port,
            baudrate=baudrate
        )
        try:
            self.serial_interface.start()
        except Exception as e:
            self.get_logger().error(f"Failed to start LoadCellSerialInterface: {e}")
            return

        # Timer for publishing data
        timer_period = 1.0 / publish_rate
        self.timer = self.create_timer(timer_period, self.timer_callback)

        self.get_logger().info(f"LoadCellPublisherNode started: publishing to '{topic_name}'")

    def timer_callback(self):
        weight = self.serial_interface.get_last_weight()
        if weight is not None:
            msg = Float64()
            msg.data = weight
            self.publisher_.publish(msg)
            self.get_logger().debug(f"Published weight: {weight:.3f} g")

    def destroy_node(self):
        self.serial_interface.stop()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = LoadCellPublisherNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("KeyboardInterrupt received. Shutting down.")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
