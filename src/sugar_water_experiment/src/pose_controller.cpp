/**
 * @file pose_controller.cpp
 * @brief Pose 제어 유틸리티 클래스
 */

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <cmath>

class PoseController {
public:
    PoseController(rclcpp::Node* node) : node_(node) {
        pose_pub_ = node_->create_publisher<geometry_msgs::msg::PoseStamped>("robot/target_pose", 10);
        joint_pub_ = node_->create_publisher<sensor_msgs::msg::JointState>("robot/target_joints", 10);
    }
    
    bool moveToJointPosition(const std::vector<double>& joint_angles_deg) {
        sensor_msgs::msg::JointState joint_msg;
        joint_msg.header.stamp = node_->get_clock()->now();
        joint_msg.header.frame_id = "base_link";
        
        joint_msg.name = {"joint1", "joint2", "joint3", "joint4", "joint5", "joint6"};
        joint_msg.position.clear();
        
        // 각도를 라디안으로 변환
        for (const auto& angle : joint_angles_deg) {
            joint_msg.position.push_back(angle * M_PI / 180.0);
        }
        
        joint_pub_->publish(joint_msg);
        return true;
    }
    
    bool moveToCartesianPosition(double x, double y, double z, double rx, double ry, double rz) {
        geometry_msgs::msg::PoseStamped pose_msg;
        pose_msg.header.stamp = node_->get_clock()->now();
        pose_msg.header.frame_id = "base_link";
        
        // 위치 설정 (mm를 m로 변환)
        pose_msg.pose.position.x = x / 1000.0;
        pose_msg.pose.position.y = y / 1000.0;
        pose_msg.pose.position.z = z / 1000.0;
        
        // 오일러 각도를 쿼터니언으로 변환 (단순화)
        pose_msg.pose.orientation.x = rx / 180.0 * M_PI;
        pose_msg.pose.orientation.y = ry / 180.0 * M_PI;
        pose_msg.pose.orientation.z = rz / 180.0 * M_PI;
        pose_msg.pose.orientation.w = 1.0;
        
        pose_pub_->publish(pose_msg);
        return true;
    }

private:
    rclcpp::Node* node_;
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_pub_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
};
