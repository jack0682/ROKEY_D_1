// experiment_data_logger - 구현 예정
#include <rclcpp/rclcpp.hpp>

class Experiment_data_loggerNode : public rclcpp::Node
{
public:
    Experiment_data_loggerNode() : Node("experiment_data_logger_node")
    {
        RCLCPP_INFO(this->get_logger(), "Experiment_data_logger Node - Implementation pending");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Experiment_data_loggerNode>());
    rclcpp::shutdown();
    return 0;
}
