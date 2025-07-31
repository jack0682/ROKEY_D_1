// Day 2: 하이브리드 센서 융합 시스템
#include <rclcpp/rclcpp.hpp>

class WeightFusionNode : public rclcpp::Node
{
public:
    WeightFusionNode() : Node("weight_fusion_node")
    {
        RCLCPP_INFO(this->get_logger(), "Weight Fusion Node - Day 2 Implementation");
        RCLCPP_INFO(this->get_logger(), "Target: 0.005g effective resolution through sensor fusion");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<WeightFusionNode>());
    rclcpp::shutdown();
    return 0;
}
