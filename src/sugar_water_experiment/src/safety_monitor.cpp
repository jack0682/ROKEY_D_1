/**
 * @file safety_monitor.cpp
 * @brief 안전 감시 시스템
 */

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/bool.hpp>
#include <geometry_msgs/msg/wrench_stamped.hpp>
#include <chrono>

class SafetyMonitor {
public:
    SafetyMonitor(rclcpp::Node* node) : node_(node), emergency_stop_activated_(false) {
        // 구독자
        force_sub_ = node_->create_subscription<geometry_msgs::msg::WrenchStamped>(
            "robot/force_torque", 10,
            std::bind(&SafetyMonitor::forceCallback, this, std::placeholders::_1)
        );
        
        robot_status_sub_ = node_->create_subscription<std_msgs::msg::String>(
            "robot/status", 10,
            std::bind(&SafetyMonitor::robotStatusCallback, this, std::placeholders::_1)
        );
        
        // 퍼블리셔
        emergency_stop_pub_ = node_->create_publisher<std_msgs::msg::Bool>("robot/emergency_stop", 10);
        safety_status_pub_ = node_->create_publisher<std_msgs::msg::String>("safety/status", 10);
        
        // 타이머
        safety_check_timer_ = node_->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&SafetyMonitor::performSafetyCheck, this)
        );
        
        RCLCPP_INFO(node_->get_logger(), "Safety Monitor initialized");
    }
    
    bool isSystemSafe() const {
        return !emergency_stop_activated_ && 
               isForceWithinLimits() && 
               isRobotStatusNormal() &&
               isWorkspaceRestricted();
    }
    
    void activateEmergencyStop(const std::string& reason) {
        if (!emergency_stop_activated_) {
            emergency_stop_activated_ = true;
            
            std_msgs::msg::Bool stop_msg;
            stop_msg.data = true;
            emergency_stop_pub_->publish(stop_msg);
            
            std_msgs::msg::String status_msg;
            status_msg.data = "EMERGENCY_STOP: " + reason;
            safety_status_pub_->publish(status_msg);
            
            RCLCPP_ERROR(node_->get_logger(), "🚨 EMERGENCY STOP ACTIVATED: %s", reason.c_str());
        }
    }
    
    void resetEmergencyStop() {
        if (emergency_stop_activated_) {
            emergency_stop_activated_ = false;
            
            std_msgs::msg::Bool stop_msg;
            stop_msg.data = false;
            emergency_stop_pub_->publish(stop_msg);
            
            std_msgs::msg::String status_msg;
            status_msg.data = "EMERGENCY_STOP_RESET";
            safety_status_pub_->publish(status_msg);
            
            RCLCPP_INFO(node_->get_logger(), "Emergency stop reset");
        }
    }

private:
    void performSafetyCheck() {
        if (emergency_stop_activated_) return;
        
        // 힘/토크 제한 확인
        if (!isForceWithinLimits()) {
            activateEmergencyStop("Excessive force detected");
            return;
        }
        
        // 로봇 상태 확인
        if (!isRobotStatusNormal()) {
            activateEmergencyStop("Robot status abnormal");
            return;
        }
        
        // 작업공간 제한 확인
        if (!isWorkspaceRestricted()) {
            activateEmergencyStop("Robot outside safe workspace");
            return;
        }
        
        // 센서 타임아웃 확인
        if (isSensorTimeout()) {
            activateEmergencyStop("Sensor communication timeout");
            return;
        }
        
        // 정상 상태 퍼블리시
        std_msgs::msg::String status_msg;
        status_msg.data = "SYSTEM_SAFE";
        safety_status_pub_->publish(status_msg);
    }
    
    bool isForceWithinLimits() const {
        // 최대 허용 힘: 10N
        return current_force_magnitude_ < MAX_FORCE_LIMIT;
    }
    
    bool isRobotStatusNormal() const {
        return robot_status_ != "ERROR" && robot_status_ != "FAULT";
    }
    
    bool isWorkspaceRestricted() const {
        // 작업공간 제한 확인 (실제 구현에서는 로봇 위치 확인)
        return true; // 단순화
    }
    
    bool isSensorTimeout() const {
        auto now = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_sensor_update_);
        return duration.count() > SENSOR_TIMEOUT_MS;
    }
    
    void forceCallback(const geometry_msgs::msg::WrenchStamped::SharedPtr msg) {
        float fx = msg->wrench.force.x;
        float fy = msg->wrench.force.y;
        float fz = msg->wrench.force.z;
        
        current_force_magnitude_ = sqrt(fx*fx + fy*fy + fz*fz);
        last_sensor_update_ = std::chrono::steady_clock::now();
    }
    
    void robotStatusCallback(const std_msgs::msg::String::SharedPtr msg) {
        robot_status_ = msg->data;
        last_sensor_update_ = std::chrono::steady_clock::now();
    }
    
    // 상수
    static constexpr float MAX_FORCE_LIMIT = 10.0; // 10N
    static constexpr int SENSOR_TIMEOUT_MS = 1000; // 1초
    
    // 멤버 변수
    rclcpp::Node* node_;
    
    rclcpp::Subscription<geometry_msgs::msg::WrenchStamped>::SharedPtr force_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr robot_status_sub_;
    
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr emergency_stop_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr safety_status_pub_;
    
    rclcpp::TimerBase::SharedPtr safety_check_timer_;
    
    bool emergency_stop_activated_;
    float current_force_magnitude_ = 0.0;
    std::string robot_status_ = "UNKNOWN";
    std::chrono::steady_clock::time_point last_sensor_update_;
};
