#pragma once

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>

namespace arduino_loadcell_interface
{
    class LoadcellInterface
    {
    public:
        LoadcellInterface();
        ~LoadcellInterface();
        
        // Day 1 구현 예정 메서드들
        bool initialize_serial_connection();
        float read_weight();
        bool calibrate(float known_weight);
        
    private:
        // Day 1 구현 예정 멤버 변수들
        std::string serial_port_;
        int baud_rate_;
        float calibration_factor_;
    };
}
