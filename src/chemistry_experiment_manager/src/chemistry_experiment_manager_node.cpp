// chemistry_experiment_manager - 구현 예정
#include <rclcpp/rclcpp.hpp>

class Chemistry_experiment_managerNode : public rclcpp::Node
{
public:
    Chemistry_experiment_managerNode() : Node("chemistry_experiment_manager_node")
    {
        RCLCPP_INFO(this->get_logger(), "Chemistry_experiment_manager Node - Implementation pending");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Chemistry_experiment_managerNode>());
    rclcpp::shutdown();
    return 0;
}
