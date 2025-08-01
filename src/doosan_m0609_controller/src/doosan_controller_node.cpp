#include "doosan_m0609_controller/doosan_robot_controller.hpp"
#include <rclcpp/rclcpp.hpp>
#include <memory>
#include <signal.h>

// Signal handler for graceful shutdown
std::shared_ptr<DoosanRobotController> g_node = nullptr;

void signalHandler(int signum) {
    RCLCPP_INFO(rclcpp::get_logger("main"), "Interrupt signal (%d) received. Shutting down...", signum);
    if (g_node) {
        rclcpp::shutdown();
    }
}

int main(int argc, char** argv) {
    // Initialize ROS2
    rclcpp::init(argc, argv);
    
    // Setup signal handlers
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    
    try {
        // Create and run the node
        g_node = std::make_shared<DoosanRobotController>();
        
        RCLCPP_INFO(g_node->get_logger(), "Doosan M0609 Controller Node started");
        RCLCPP_INFO(g_node->get_logger(), "Available services:");
        RCLCPP_INFO(g_node->get_logger(), "  - /move_joint (MoveJ service)");
        RCLCPP_INFO(g_node->get_logger(), "  - /connect_robot (Connection service)");
        RCLCPP_INFO(g_node->get_logger(), "Available topics:");
        RCLCPP_INFO(g_node->get_logger(), "  - /joint_states (sensor_msgs/JointState)");
        RCLCPP_INFO(g_node->get_logger(), "  - /joint_states_custom (custom JointState)");
        RCLCPP_INFO(g_node->get_logger(), "  - /robot_status (RobotStatus)");
        
        // Spin the node
        rclcpp::spin(g_node);
        
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("main"), "Exception in main: %s", e.what());
        return 1;
    }
    
    // Cleanup
    g_node.reset();
    rclcpp::shutdown();
    
    RCLCPP_INFO(rclcpp::get_logger("main"), "Doosan M0609 Controller Node shutdown complete");
    return 0;
}
