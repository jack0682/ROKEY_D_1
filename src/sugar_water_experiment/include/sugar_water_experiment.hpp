#ifndef SUGAR_WATER_EXPERIMENT_HPP
#define SUGAR_WATER_EXPERIMENT_HPP

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <std_msgs/msg/float32.hpp>
#include <std_msgs/msg/string.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <vector>
#include <memory>
#include <chrono>

namespace sugar_water_experiment {

// Pose 데이터 구조체
struct PoseData {
    double x, y, z, rx, ry, rz;
    bool is_joint_space;
    
    PoseData(double x_, double y_, double z_, double rx_, double ry_, double rz_, bool joint = false)
        : x(x_), y(y_), z(z_), rx(rx_), ry(ry_), rz(rz_), is_joint_space(joint) {}
};

// 실험 상태 열거형
enum class ExperimentState {
    IDLE,
    INITIALIZING,
    MOVING_TO_CUP,
    GRASPING_CUP,
    PLACING_CUP_ON_SCALE,
    GRASPING_SPOON,
    SCOOPING_SUGAR,
    ADDING_SUGAR,
    GRASPING_WATER_CONTAINER,
    POURING_WATER,
    COMPLETE,
    ERROR
};

// 실험 결과 구조체
struct ExperimentResult {
    float target_concentration;
    float measured_concentration;
    float accuracy_percentage;
    int total_time_seconds;
    bool success;
    std::string error_message;
    
    ExperimentResult() : target_concentration(0.0), measured_concentration(0.0), 
                        accuracy_percentage(0.0), total_time_seconds(0), success(false) {}
};

} // namespace sugar_water_experiment

#endif // SUGAR_WATER_EXPERIMENT_HPP
