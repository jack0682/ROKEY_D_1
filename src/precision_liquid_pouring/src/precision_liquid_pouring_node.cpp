// precision_liquid_pouring - 구현 예정
#include <rclcpp/rclcpp.hpp>

class Precision_liquid_pouringNode : public rclcpp::Node
{
public:
    Precision_liquid_pouringNode() : Node("precision_liquid_pouring_node")
    {
        RCLCPP_INFO(this->get_logger(), "Precision_liquid_pouring Node - Implementation pending");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Precision_liquid_pouringNode>());
    rclcpp::shutdown();
    return 0;
}
