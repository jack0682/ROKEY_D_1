// salt_concentration_calculator - 구현 예정
#include <rclcpp/rclcpp.hpp>

class Salt_concentration_calculatorNode : public rclcpp::Node
{
public:
    Salt_concentration_calculatorNode() : Node("salt_concentration_calculator_node")
    {
        RCLCPP_INFO(this->get_logger(), "Salt_concentration_calculator Node - Implementation pending");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Salt_concentration_calculatorNode>());
    rclcpp::shutdown();
    return 0;
}
