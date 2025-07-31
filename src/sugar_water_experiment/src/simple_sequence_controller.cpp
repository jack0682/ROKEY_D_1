/**
 * @file simple_sequence_controller.cpp (Fixed)
 * @brief 제공된 10개 pose를 순차적으로 실행하는 단순 컨트롤러
 * @author Jack
 * @date 2024
 */

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/float32.hpp>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>

class SimpleSequenceController : public rclcpp::Node {
public:
    SimpleSequenceController() : Node("simple_sequence_controller") {
        // 퍼블리셔 초기화
        pose_pub_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("target_pose", 10);
        joint_pub_ = this->create_publisher<sensor_msgs::msg::JointState>("target_joints", 10);
        status_pub_ = this->create_publisher<std_msgs::msg::String>("experiment_status", 10);
        
        // 제공된 좌표들 초기화
        initializePoses();
        
        // 타이머 생성 (5초 후 실험 시작)
        timer_ = this->create_wall_timer(
            std::chrono::seconds(5),
            std::bind(&SimpleSequenceController::startExperiment, this)
        );
        
        RCLCPP_INFO(this->get_logger(), "Simple Sequence Controller initialized");
        RCLCPP_INFO(this->get_logger(), "Experiment will start in 5 seconds...");
    }

private:
    void initializePoses() {
        // x1: 홈 포지션 (Joint Space)
        joint_positions_ = {0.0, 0.0, 90.0, 0.0, 90.0, 0.0};
        
        // x2-x10: Cartesian Space Poses
        poses_.push_back({367.86, 9.39, 53.3, 71.82, 179.95, 71.35});      // x2: 컵 잡기
        poses_.push_back({671.04, 147.98, 68.56, 100.34, 178.05, 101.34}); // x3: 저울에 컵 놓기
        poses_.push_back({777.82, -201.23, 311.01, 3.06, 92.65, 5.35});    // x4: 주전자 잡기
        poses_.push_back({682.48, -23.15, 232.49, 179.68, -88.62, 177.4}); // x5: 물 따르는 위치
        poses_.push_back({510.9, -29.85, 95.09, 135.58, 177.6, 48.89});    // x6: 수저 잡기
        poses_.push_back({562.69, -107.13, 72.84, 174.76, -144.74, 96.43}); // x7: 설탕통에 수저 넣기
        poses_.push_back({538.14, -84.46, 172.66, 122.94, -113.27, 115.74}); // x8: 설탕 푸는 위치
        poses_.push_back({527.7, -69.25, 184.84, 128.89, -89.76, 88.39});   // x9: 설탕 든 수저 올리기
        poses_.push_back({598.28, 164.22, 186.63, 177.3, -86.76, 91.28});   // x10: 설탕 넣는 위치
        
        RCLCPP_INFO(this->get_logger(), "Initialized %zu poses", poses_.size());
    }
    
    void startExperiment() {
        timer_->cancel(); // 타이머 정지
        
        publishStatus("EXPERIMENT_STARTED");
        RCLCPP_INFO(this->get_logger(), "🧪 Starting Sugar Water Experiment!");
        
        // Step 1: 홈 포지션으로 이동
        moveToJointPosition();
        std::this_thread::sleep_for(std::chrono::seconds(3));
        
        // Step 2-10: 각 Cartesian 위치로 순차 이동
        for (size_t i = 0; i < poses_.size(); ++i) {
            publishStatus("MOVING_TO_POSE_" + std::to_string(i + 2));
            RCLCPP_INFO(this->get_logger(), 
                       "Moving to Pose %zu: [%.2f, %.2f, %.2f, %.2f, %.2f, %.2f]",
                       i + 2, poses_[i][0], poses_[i][1], poses_[i][2], 
                       poses_[i][3], poses_[i][4], poses_[i][5]);
            
            moveToCartesianPosition(poses_[i]);
            
            // 각 위치에서 수행할 작업 시뮬레이션
            performTaskAtPosition(i + 2);
            
            // 다음 위치로 이동하기 전 대기
            std::this_thread::sleep_for(std::chrono::seconds(4));
        }
        
        publishStatus("EXPERIMENT_COMPLETED");
        RCLCPP_INFO(this->get_logger(), "🎉 Experiment completed successfully!");
    }
    
    void moveToJointPosition() {
        sensor_msgs::msg::JointState joint_msg;
        joint_msg.header.stamp = this->get_clock()->now();
        joint_msg.header.frame_id = "base_link";
        
        joint_msg.name = {"joint1", "joint2", "joint3", "joint4", "joint5", "joint6"};
        joint_msg.position = joint_positions_;
        
        // 각도를 라디안으로 변환
        for (auto& pos : joint_msg.position) {
            pos = pos * M_PI / 180.0;
        }
        
        joint_pub_->publish(joint_msg);
        RCLCPP_INFO(this->get_logger(), "Published joint target: HOME POSITION");
    }
    
    void moveToCartesianPosition(const std::vector<double>& pose) {
        geometry_msgs::msg::PoseStamped pose_msg;
        pose_msg.header.stamp = this->get_clock()->now();
        pose_msg.header.frame_id = "base_link";
        
        // 위치 설정 (mm를 m로 변환)
        pose_msg.pose.position.x = pose[0] / 1000.0;
        pose_msg.pose.position.y = pose[1] / 1000.0;
        pose_msg.pose.position.z = pose[2] / 1000.0;
        
        // 자세 설정 (Euler angles를 Quaternion으로 변환 - 단순화)
        pose_msg.pose.orientation.x = pose[3] / 180.0 * M_PI;
        pose_msg.pose.orientation.y = pose[4] / 180.0 * M_PI;
        pose_msg.pose.orientation.z = pose[5] / 180.0 * M_PI;
        pose_msg.pose.orientation.w = 1.0;
        
        pose_pub_->publish(pose_msg);
    }
    
    void performTaskAtPosition(int position_number) {
        std::string task_description;
        
        switch (position_number) {
            case 2: task_description = "컵 잡기 동작 수행"; break;
            case 3: task_description = "저울에 컵 놓기 동작 수행"; break;
            case 4: task_description = "주전자 잡기 동작 수행"; break;
            case 5: task_description = "물 따르기 동작 수행"; break;
            case 6: task_description = "수저 잡기 동작 수행"; break;
            case 7: task_description = "설탕통에 수저 넣기 동작 수행"; break;
            case 8: task_description = "설탕 푸기 동작 수행"; break;
            case 9: task_description = "설탕 든 수저 올리기 동작 수행"; break;
            case 10: task_description = "설탕 넣기 동작 수행"; break;
            default: task_description = "알 수 없는 동작"; break;
        }
        
        publishStatus("PERFORMING_TASK_" + std::to_string(position_number));
        RCLCPP_INFO(this->get_logger(), "  → %s", task_description.c_str());
        
        // 작업 수행 시뮬레이션 (2초 대기)
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    
    void publishStatus(const std::string& status) {
        std_msgs::msg::String status_msg;
        status_msg.data = status;
        status_pub_->publish(status_msg);
    }
    
    // 멤버 변수
    rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr pose_pub_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    
    std::vector<double> joint_positions_;
    std::vector<std::vector<double>> poses_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    
    RCLCPP_INFO(rclcpp::get_logger("main"), "🚀 Starting Simple Sequence Controller");
    
    auto node = std::make_shared<SimpleSequenceController>();
    
    try {
        rclcpp::spin(node);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("main"), "Exception: %s", e.what());
    }
    
    rclcpp::shutdown();
    return 0;
}
