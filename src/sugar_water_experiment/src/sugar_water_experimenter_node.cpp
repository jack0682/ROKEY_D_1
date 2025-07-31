/**
 * @file sugar_water_experimenter_node.cpp (Fixed & Simplified)
 * @brief 간단한 설탕물 제조 실험 노드
 * @author Jack
 * @date 2024
 */

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float32.hpp>
#include <std_msgs/msg/bool.hpp>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

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

// Pose 데이터 구조체
struct PoseData {
    double x, y, z, rx, ry, rz;
    bool is_joint_space;
    
    PoseData(double x_, double y_, double z_, double rx_, double ry_, double rz_, bool joint = false)
        : x(x_), y(y_), z(z_), rx(rx_), ry(ry_), rz(rz_), is_joint_space(joint) {}
};

class SugarWaterExperimenterNode : public rclcpp::Node {
public:
    SugarWaterExperimenterNode() : Node("sugar_water_experimenter_node"), 
                                   current_state_(ExperimentState::IDLE),
                                   target_concentration_(0.05),
                                   current_weight_(0.0),
                                   current_pose_index_(0) {
        
        // 퍼블리셔 초기화
        pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("robot/target_pose", 10);
        joint_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("robot/target_joints", 10);
        status_pub_ = this->create_publisher<std_msgs::msg::String>("experiment/status", 10);
        gripper_pub_ = this->create_publisher<std_msgs::msg::Bool>("robot/gripper_command", 10);
        concentration_pub_ = this->create_publisher<std_msgs::msg::Float32>("experiment/concentration", 10);
        
        // 구독자 초기화
        weight_sub_ = this->create_subscription<std_msgs::msg::Float32>(
            "sensors/weight", 10,
            std::bind(&SugarWaterExperimenterNode::weightCallback, this, std::placeholders::_1)
        );
        
        // 타이머 초기화
        control_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&SugarWaterExperimenterNode::controlLoop, this)
        );
        
        // 실험 좌표 초기화
        initializeExperimentPoses();
        
        RCLCPP_INFO(this->get_logger(), "🧪 Sugar Water Experimenter Node initialized");
        RCLCPP_INFO(this->get_logger(), "Target concentration: %.1f%%", target_concentration_ * 100);
    }

private:
    void initializeExperimentPoses() {
        experiment_poses_.clear();
        
        // 홈 포지션 (Joint Space)
        experiment_poses_.emplace_back(0.0, 0.0, 90.0, 0.0, 90.0, 0.0, true);
        
        // 작업 위치들 (Cartesian Space)
        experiment_poses_.emplace_back(367.86, 9.39, 53.3, 71.82, 179.95, 71.35, false);      // 컵 잡기
        experiment_poses_.emplace_back(671.04, 147.98, 68.56, 100.34, 178.05, 101.34, false); // 저울에 컵 놓기
        experiment_poses_.emplace_back(777.82, -201.23, 311.01, 3.06, 92.65, 5.35, false);    // 주전자 잡기
        experiment_poses_.emplace_back(682.48, -23.15, 232.49, 179.68, -88.62, 177.4, false); // 물 따르는 위치
        experiment_poses_.emplace_back(510.9, -29.85, 95.09, 135.58, 177.6, 48.89, false);    // 수저 잡기
        experiment_poses_.emplace_back(562.69, -107.13, 72.84, 174.76, -144.74, 96.43, false); // 설탕통에 수저 넣기
        experiment_poses_.emplace_back(538.14, -84.46, 172.66, 122.94, -113.27, 115.74, false); // 설탕 푸는 위치
        experiment_poses_.emplace_back(527.7, -69.25, 184.84, 128.89, -89.76, 88.39, false);   // 설탕 든 수저 올리기
        experiment_poses_.emplace_back(598.28, 164.22, 186.63, 177.3, -86.76, 91.28, false);   // 설탕 넣는 위치
        
        current_pose_index_ = 0;
        RCLCPP_INFO(this->get_logger(), "Initialized %zu experiment poses", experiment_poses_.size());
    }
    
    void controlLoop() {
        static int loop_counter = 0;
        loop_counter++;
        
        switch (current_state_) {
            case ExperimentState::IDLE:
                if (loop_counter >= 50) { // 5초 후 시작
                    publishStatus("STARTING_EXPERIMENT");
                    RCLCPP_INFO(this->get_logger(), "🚀 Starting automated sugar water experiment!");
                    current_state_ = ExperimentState::INITIALIZING;
                    loop_counter = 0;
                }
                break;
                
            case ExperimentState::INITIALIZING:
                publishStatus("INITIALIZING_SYSTEM");
                moveToCurrentPose();
                current_state_ = ExperimentState::COMPLETE;
                RCLCPP_INFO(this->get_logger(), "✅ Initialization complete - moved to home position");
                break;
                
            case ExperimentState::COMPLETE:
                static bool completed_once = false;
                if (!completed_once) {
                    publishStatus("EXPERIMENT_COMPLETED");
                    RCLCPP_INFO(this->get_logger(), "🎉 EXPERIMENT COMPLETED!");
                    completed_once = true;
                }
                break;
                
            case ExperimentState::ERROR:
                publishStatus("ERROR_STATE");
                RCLCPP_ERROR(this->get_logger(), "Experiment in error state!");
                break;
                
            default:
                break;
        }
    }
    
    void moveToCurrentPose() {
        if (current_pose_index_ >= experiment_poses_.size()) {
            RCLCPP_WARN(this->get_logger(), "Invalid pose index: %zu", current_pose_index_);
            return;
        }
        
        const auto& pose = experiment_poses_[current_pose_index_];
        
        if (pose.is_joint_space) {
            // Joint space 이동
            sensor_msgs::msg::JointState joint_msg;
            joint_msg.header.stamp = this->get_clock()->now();
            joint_msg.header.frame_id = "base_link";
            joint_msg.name = {"joint1", "joint2", "joint3", "joint4", "joint5", "joint6"};
            joint_msg.position = {pose.x * M_PI / 180.0, pose.y * M_PI / 180.0, 
                                pose.z * M_PI / 180.0, pose.rx * M_PI / 180.0,
                                pose.ry * M_PI / 180.0, pose.rz * M_PI / 180.0};
            
            joint_pub_->publish(joint_msg);
            RCLCPP_INFO(this->get_logger(), "Moving to joint position [%.1f, %.1f, %.1f, %.1f, %.1f, %.1f]",
                       pose.x, pose.y, pose.z, pose.rx, pose.ry, pose.rz);
        } else {
            // Cartesian space 이동
            geometry_msgs::msg::PoseStamped pose_msg;
            pose_msg.header.stamp = this->get_clock()->now();
            pose_msg.header.frame_id = "base_link";
            
            // 위치 (mm를 m로 변환)
            pose_msg.pose.position.x = pose.x / 1000.0;
            pose_msg.pose.position.y = pose.y / 1000.0;
            pose_msg.pose.position.z = pose.z / 1000.0;
            
            // 자세 (단순화된 오일러 각도)
            pose_msg.pose.orientation.x = pose.rx / 180.0 * M_PI;
            pose_msg.pose.orientation.y = pose.ry / 180.0 * M_PI;
            pose_msg.pose.orientation.z = pose.rz / 180.0 * M_PI;
            pose_msg.pose.orientation.w = 1.0;
            
            pose_pub_->publish(pose_msg);
            RCLCPP_INFO(this->get_logger(), "Moving to cartesian position [%.2f, %.2f, %.2f, %.2f, %.2f, %.2f]",
                       pose.x, pose.y, pose.z, pose.rx, pose.ry, pose.rz);
        }
    }
    
    void publishStatus(const std::string& status) {
        std_msgs::msg::String status_msg;
        status_msg.data = status;
        status_pub_->publish(status_msg);
    }
    
    void weightCallback(const std_msgs::msg::Float32::SharedPtr msg) {
        current_weight_ = msg->data;
        RCLCPP_DEBUG(this->get_logger(), "Weight updated: %.3fg", current_weight_);
    }
    
    // 멤버 변수
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_pub_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_pub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr gripper_pub_;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr concentration_pub_;
    
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr weight_sub_;
    
    rclcpp::TimerBase::SharedPtr control_timer_;
    
    std::vector<PoseData> experiment_poses_;
    size_t current_pose_index_;
    
    ExperimentState current_state_;
    float target_concentration_;
    float current_weight_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    
    RCLCPP_INFO(rclcpp::get_logger("main"), "🧪 Starting Sugar Water Experimenter Node");
    
    auto node = std::make_shared<SugarWaterExperimenterNode>();
    
    try {
        rclcpp::spin(node);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("main"), "Exception: %s", e.what());
    }
    
    rclcpp::shutdown();
    return 0;
}
