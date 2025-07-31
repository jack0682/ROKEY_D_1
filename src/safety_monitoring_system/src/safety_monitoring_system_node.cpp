// safety_monitoring_system - 구현 예정
#include <rclcpp/rclcpp.hpp>

class Safety_monitoring_systemNode : public rclcpp::Node
{
public:
    Safety_monitoring_systemNode() : Node("safety_monitoring_system_node")
    {
        RCLCPP_INFO(this->get_logger(), "Safety_monitoring_system Node - Implementation pending");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Safety_monitoring_systemNode>());
    rclcpp::shutdown();
    return 0;
}
