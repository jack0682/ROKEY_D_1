// Arduino HX711 로드셀 인터페이스 노드
// Day 1 목표: 0.01g 분해능, 80Hz 샘플링

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>
#include <sensor_msgs/msg/temperature.hpp>

class LoadcellNode : public rclcpp::Node
{
public:
    LoadcellNode() : Node("loadcell_node")
    {
        // Day 1 구현 예정:
        // - Arduino Serial 통신
        // - HX711 데이터 파싱
        // - 무게 데이터 퍼블리시
        
        RCLCPP_INFO(this->get_logger(), "Arduino Loadcell Interface Node Started - Day 1 Implementation");
        RCLCPP_INFO(this->get_logger(), "Target: 0.01g resolution, 80Hz sampling rate");
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LoadcellNode>());
    rclcpp::shutdown();
    return 0;
}
