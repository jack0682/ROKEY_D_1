#ifndef DOOSAN_ROBOT_CONTROLLER_HPP
#define DOOSAN_ROBOT_CONTROLLER_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/header.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <memory>
#include <thread>
#include <atomic>

#include "doosan_m0609_controller/msg/joint_state.hpp"
#include "doosan_m0609_controller/msg/robot_status.hpp"
#include "doosan_m0609_controller/srv/move_j.hpp"
#include "doosan_m0609_controller/srv/connect_robot.hpp"
#include "DRFL.h"  // 실제 Doosan DRFL 라이브러리

class DoosanRobotController : public rclcpp::Node {
public:
    DoosanRobotController();
    ~DoosanRobotController();

private:
    // ROS2 Components
    rclcpp::Publisher<doosan_m0609_controller::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Publisher<doosan_m0609_controller::msg::RobotStatus>::SharedPtr robot_status_pub_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr std_joint_state_pub_;
    
    rclcpp::Service<doosan_m0609_controller::srv::MoveJ>::SharedPtr move_j_service_;
    rclcpp::Service<doosan_m0609_controller::srv::ConnectRobot>::SharedPtr connect_service_;
    
    rclcpp::TimerBase::SharedPtr status_timer_;
    rclcpp::TimerBase::SharedPtr joint_state_timer_;
    
    // DRFL Interface - 실제 Doosan API
    std::unique_ptr<DRAFramework::CDRFL> m_drfl;
    
    // Threading
    std::thread status_thread_;
    std::atomic<bool> running_;
    
    // Parameters
    std::string robot_ip_;
    double publish_rate_;
    bool auto_connect_;
    
    // Callbacks
    void publishJointStates();
    void publishRobotStatus();
    void statusThreadFunction();
    
    // Service callbacks
    void handleMoveJ(
        const std::shared_ptr<doosan_m0609_controller::srv::MoveJ::Request> request,
        std::shared_ptr<doosan_m0609_controller::srv::MoveJ::Response> response);
    
    void handleConnectRobot(
        const std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot::Request> request,
        std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot::Response> response);
    
    // Helper functions
    bool connectToRobot(const std::string& ip);
    bool disconnectFromRobot();
    void initializeParameters();
    void setupPublishersAndServices();
    
    // Safety functions
    bool validateJointLimits(const std::array<double, 6>& joints);
    void handleEmergencyStop();
};

#endif // DOOSAN_ROBOT_CONTROLLER_HPP
