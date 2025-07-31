#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/header.hpp>
#include <memory>
#include <thread>
#include <chrono>

// 두산 공식 srv 파일들 포함
#include "doosan_m0609_control/srv/motion/move_joint.hpp"
#include "doosan_m0609_control/srv/motion/move_line.hpp"
#include "doosan_m0609_control/srv/motion/move_stop.hpp"
#include "doosan_m0609_control/srv/motion/check_motion.hpp"
#include "doosan_m0609_control/srv/motion/move_home.hpp"

#include "doosan_m0609_control/srv/system/get_robot_state.hpp"
#include "doosan_m0609_control/srv/system/get_current_pose.hpp"
#include "doosan_m0609_control/srv/system/set_robot_control.hpp"

#include "doosan_m0609_control/srv/io/set_tool_digital_output.hpp"
#include "doosan_m0609_control/srv/io/get_tool_digital_input.hpp"
#include "doosan_m0609_control/srv/io/set_ctrl_box_digital_output.hpp"
#include "doosan_m0609_control/srv/io/get_ctrl_box_digital_input.hpp"

// DartInterface 포함
#include "doosan_m0609_control/dart_interface.hpp"

class DoosanRobotNode : public rclcpp::Node {
public:
    DoosanRobotNode() : Node("doosan_robot_node") {
        RCLCPP_INFO(get_logger(), "Starting Doosan M0609 Control Node...");
        
        // 파라미터 선언
        declare_parameter("robot_ip", "192.168.137.100");
        declare_parameter("robot_port", 12345);
        declare_parameter("joint_state_rate", 10.0);  // Hz
        declare_parameter("auto_connect", true);
        
        // 파라미터 값 읽기
        robot_ip_ = get_parameter("robot_ip").as_string();
        robot_port_ = get_parameter("robot_port").as_int();
        joint_state_rate_ = get_parameter("joint_state_rate").as_double();
        auto_connect_ = get_parameter("auto_connect").as_bool();
        
        RCLCPP_INFO(get_logger(), "Robot IP: %s, Port: %d", robot_ip_.c_str(), robot_port_);
        
        // DartInterface 초기화
        dart_interface_ = std::make_unique<DartInterface>();
        
        // ROS2 서비스 서버들 생성
        createServices();
        
        // ROS2 퍼블리셔 생성
        createPublishers();
        
        // 타이머 생성
        createTimers();
        
        // 자동 연결 옵션이 활성화된 경우 로봇에 연결 시도
        if (auto_connect_) {
            connectToRobot();
        }
        
        RCLCPP_INFO(get_logger(), "Doosan Robot Node initialized successfully");
    }
    
    ~DoosanRobotNode() {
        RCLCPP_INFO(get_logger(), "Shutting down Doosan Robot Node...");
        if (dart_interface_ && dart_interface_->isConnected()) {
            dart_interface_->disconnect();
        }
    }

private:
    // ==========================================================================
    // 멤버 변수들
    // ==========================================================================
    std::unique_ptr<DartInterface> dart_interface_;
    
    // 파라미터들
    std::string robot_ip_;
    int robot_port_;
    double joint_state_rate_;
    bool auto_connect_;
    
    // ROS2 서비스 서버들 (모션 제어)
    rclcpp::Service<doosan_m0609_control::srv::motion::MoveJoint>::SharedPtr move_joint_srv_;
    rclcpp::Service<doosan_m0609_control::srv::motion::MoveLine>::SharedPtr move_line_srv_;
    rclcpp::Service<doosan_m0609_control::srv::motion::MoveStop>::SharedPtr move_stop_srv_;
    rclcpp::Service<doosan_m0609_control::srv::motion::CheckMotion>::SharedPtr check_motion_srv_;
    rclcpp::Service<doosan_m0609_control::srv::motion::MoveHome>::SharedPtr move_home_srv_;
    
    // ROS2 서비스 서버들 (시스템)
    rclcpp::Service<doosan_m0609_control::srv::system::GetRobotState>::SharedPtr get_robot_state_srv_;
    rclcpp::Service<doosan_m0609_control::srv::system::GetCurrentPose>::SharedPtr get_current_pose_srv_;
    rclcpp::Service<doosan_m0609_control::srv::system::SetRobotControl>::SharedPtr set_robot_control_srv_;
    
    // ROS2 서비스 서버들 (I/O)
    rclcpp::Service<doosan_m0609_control::srv::io::SetToolDigitalOutput>::SharedPtr set_tool_digital_output_srv_;
    rclcpp::Service<doosan_m0609_control::srv::io::GetToolDigitalInput>::SharedPtr get_tool_digital_input_srv_;
    rclcpp::Service<doosan_m0609_control::srv::io::SetCtrlBoxDigitalOutput>::SharedPtr set_ctrl_box_digital_output_srv_;
    rclcpp::Service<doosan_m0609_control::srv::io::GetCtrlBoxDigitalInput>::SharedPtr get_ctrl_box_digital_input_srv_;
    
    // ROS2 퍼블리셔들
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    
    // ROS2 타이머들
    rclcpp::TimerBase::SharedPtr joint_state_timer_;
    rclcpp::TimerBase::SharedPtr status_check_timer_;

    // ==========================================================================
    // 초기화 함수들
    // ==========================================================================
    void createServices() {
        RCLCPP_INFO(get_logger(), "Creating ROS2 service servers...");
        
        // 모션 제어 서비스들
        move_joint_srv_ = create_service<doosan_m0609_control::srv::motion::MoveJoint>(
            "move_joint", 
            std::bind(&DoosanRobotNode::moveJointCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        move_line_srv_ = create_service<doosan_m0609_control::srv::motion::MoveLine>(
            "move_line", 
            std::bind(&DoosanRobotNode::moveLineCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        move_stop_srv_ = create_service<doosan_m0609_control::srv::motion::MoveStop>(
            "move_stop", 
            std::bind(&DoosanRobotNode::moveStopCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        check_motion_srv_ = create_service<doosan_m0609_control::srv::motion::CheckMotion>(
            "check_motion", 
            std::bind(&DoosanRobotNode::checkMotionCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        move_home_srv_ = create_service<doosan_m0609_control::srv::motion::MoveHome>(
            "move_home", 
            std::bind(&DoosanRobotNode::moveHomeCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        // 시스템 제어 서비스들
        get_robot_state_srv_ = create_service<doosan_m0609_control::srv::system::GetRobotState>(
            "get_robot_state", 
            std::bind(&DoosanRobotNode::getRobotStateCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        get_current_pose_srv_ = create_service<doosan_m0609_control::srv::system::GetCurrentPose>(
            "get_current_pose", 
            std::bind(&DoosanRobotNode::getCurrentPoseCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        set_robot_control_srv_ = create_service<doosan_m0609_control::srv::system::SetRobotControl>(
            "set_robot_control", 
            std::bind(&DoosanRobotNode::setRobotControlCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        // I/O 제어 서비스들
        set_tool_digital_output_srv_ = create_service<doosan_m0609_control::srv::io::SetToolDigitalOutput>(
            "set_tool_digital_output", 
            std::bind(&DoosanRobotNode::setToolDigitalOutputCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        get_tool_digital_input_srv_ = create_service<doosan_m0609_control::srv::io::GetToolDigitalInput>(
            "get_tool_digital_input", 
            std::bind(&DoosanRobotNode::getToolDigitalInputCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        set_ctrl_box_digital_output_srv_ = create_service<doosan_m0609_control::srv::io::SetCtrlBoxDigitalOutput>(
            "set_ctrl_box_digital_output", 
            std::bind(&DoosanRobotNode::setCtrlBoxDigitalOutputCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        get_ctrl_box_digital_input_srv_ = create_service<doosan_m0609_control::srv::io::GetCtrlBoxDigitalInput>(
            "get_ctrl_box_digital_input", 
            std::bind(&DoosanRobotNode::getCtrlBoxDigitalInputCallback, this, 
                     std::placeholders::_1, std::placeholders::_2));
        
        RCLCPP_INFO(get_logger(), "All ROS2 services created successfully");
    }
    
    void createPublishers() {
        RCLCPP_INFO(get_logger(), "Creating ROS2 publishers...");
        
        // 관절 상태 퍼블리셔
        joint_state_pub_ = create_publisher<sensor_msgs::msg::JointState>(
            "joint_states", 10);
        
        RCLCPP_INFO(get_logger(), "Publishers created successfully");
    }
    
    void createTimers() {
        RCLCPP_INFO(get_logger(), "Creating timers...");
        
        // 관절 상태 퍼블리시 타이머
        auto joint_state_period = std::chrono::milliseconds(
            static_cast<int>(1000.0 / joint_state_rate_));
        joint_state_timer_ = create_wall_timer(
            joint_state_period,
            std::bind(&DoosanRobotNode::publishJointStates, this));
        
        // 상태 체크 타이머 (1Hz)
        status_check_timer_ = create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&DoosanRobotNode::checkRobotStatus, this));
        
        RCLCPP_INFO(get_logger(), "Timers created successfully");
    }
    
    void connectToRobot() {
        RCLCPP_INFO(get_logger(), "Attempting to connect to robot...");
        
        if (dart_interface_->connect(robot_ip_, robot_port_)) {
            RCLCPP_INFO(get_logger(), "Successfully connected to robot");
        } else {
            RCLCPP_ERROR(get_logger(), "Failed to connect to robot");
        }
    }

    // ==========================================================================
    // 모션 제어 서비스 콜백 함수들
    // ==========================================================================
    void moveJointCallback(
        const std::shared_ptr<doosan_m0609_control::srv::motion::MoveJoint::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::motion::MoveJoint::Response> response) {
        
        RCLCPP_INFO(get_logger(), "MoveJoint service called");
        
        if (!dart_interface_->isConnected()) {
            response->success = false;
            RCLCPP_ERROR(get_logger(), "Robot not connected");
            return;
        }
        
        // 두산 srv 구조에 맞게 데이터 변환
        std::array<double, 6> target_joints;
        if (request->pos.size() != 6) {
            response->success = false;
            RCLCPP_ERROR(get_logger(), "Invalid joint position array size: %zu", request->pos.size());
            return;
        }
        
        for (size_t i = 0; i < 6; i++) {
            target_joints[i] = request->pos[i];
        }
        
        // DartInterface를 통해 MoveJ 실행
        response->success = dart_interface_->moveJ(target_joints);
        
        if (response->success) {
            RCLCPP_INFO(get_logger(), "MoveJoint command executed successfully");
        } else {
            RCLCPP_ERROR(get_logger(), "MoveJoint command failed");
        }
    }
    
    void moveLineCallback(
        const std::shared_ptr<doosan_m0609_control::srv::motion::MoveLine::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::motion::MoveLine::Response> response) {
        
        RCLCPP_INFO(get_logger(), "MoveLine service called");
        
        if (!dart_interface_->isConnected()) {
            response->success = false;
            RCLCPP_ERROR(get_logger(), "Robot not connected");
            return;
        }
        
        // 두산 srv 구조에 맞게 데이터 변환
        std::array<double, 6> target_pose;
        if (request->pos.size() != 6) {
            response->success = false;
            RCLCPP_ERROR(get_logger(), "Invalid pose array size: %zu", request->pos.size());
            return;
        }
        
        for (size_t i = 0; i < 6; i++) {
            target_pose[i] = request->pos[i];
        }
        
        // DartInterface를 통해 MoveL 실행
        response->success = dart_interface_->moveL(target_pose);
        
        if (response->success) {
            RCLCPP_INFO(get_logger(), "MoveLine command executed successfully");
        } else {
            RCLCPP_ERROR(get_logger(), "MoveLine command failed");
        }
    }
    
    void moveStopCallback(
        const std::shared_ptr<doosan_m0609_control::srv::motion::MoveStop::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::motion::MoveStop::Response> response) {
        
        RCLCPP_INFO(get_logger(), "MoveStop service called");
        
        if (!dart_interface_->isConnected()) {
            response->success = false;
            RCLCPP_ERROR(get_logger(), "Robot not connected");
            return;
        }
        
        // DartInterface를 통해 Stop 실행
        response->success = dart_interface_->stop();
        
        if (response->success) {
            RCLCPP_INFO(get_logger(), "Stop command executed successfully");
        } else {
            RCLCPP_ERROR(get_logger(), "Stop command failed");
        }
    }
    
    void checkMotionCallback(
        const std::shared_ptr<doosan_m0609_control::srv::motion::CheckMotion::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::motion::CheckMotion::Response> response) {
        
        RCLCPP_DEBUG(get_logger(), "CheckMotion service called");
        
        if (!dart_interface_->isConnected()) {
            response->success = false;
            response->status = -1;  // 연결 안됨
            return;
        }
        
        // 로봇 움직임 상태 확인
        bool is_moving = dart_interface_->isMoving();
        
        if (is_moving) {
            response->status = 2;  // DR_STATE_BUSY (움직임 중)
        } else {
            response->status = 0;  // DR_STATE_IDLE (정지)
        }
        
        response->success = true;
    }
    
    void moveHomeCallback(
        const std::shared_ptr<doosan_m0609_control::srv::motion::MoveHome::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::motion::MoveHome::Response> response) {
        
        RCLCPP_INFO(get_logger(), "MoveHome service called");
        
        if (!dart_interface_->isConnected()) {
            response->success = false;
            RCLCPP_ERROR(get_logger(), "Robot not connected");
            return;
        }
        
        // DartInterface를 통해 Home 실행
        response->success = dart_interface_->goHome();
        
        if (response->success) {
            RCLCPP_INFO(get_logger(), "Home command executed successfully");
        } else {
            RCLCPP_ERROR(get_logger(), "Home command failed");
        }
    }

    // ==========================================================================
    // 시스템 제어 서비스 콜백 함수들
    // ==========================================================================
    void getRobotStateCallback(
        const std::shared_ptr<doosan_m0609_control::srv::system::GetRobotState::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::system::GetRobotState::Response> response) {
        
        RCLCPP_DEBUG(get_logger(), "GetRobotState service called");
        
        if (!dart_interface_->isConnected()) {
            response->success = false;
            response->robot_state = -1;
            return;
        }
        
        // 로봇 상태 조회
        int8_t robot_state = dart_interface_->getRobotState();
        response->robot_state = robot_state;
        response->success = (robot_state >= 0);
        
        RCLCPP_DEBUG(get_logger(), "Robot state: %d", robot_state);
    }
    
    void getCurrentPoseCallback(
        const std::shared_ptr<doosan_m0609_control::srv::system::GetCurrentPose::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::system::GetCurrentPose::Response> response) {
        
        RCLCPP_DEBUG(get_logger(), "GetCurrentPose service called (space_type: %d)", 
                    request->space_type);
        
        if (!dart_interface_->isConnected()) {
            response->success = false;
            response->pos.resize(6, 0.0);
            return;
        }
        
        std::array<double, 6> current_pos;
        
        if (request->space_type == 0) {  // ROBOT_SPACE_JOINT
            current_pos = dart_interface_->getJointPosition();
        } else {  // ROBOT_SPACE_TASK
            current_pos = dart_interface_->getTaskPosition();
        }
        
        // 배열을 벡터로 변환
        response->pos.resize(6);
        for (size_t i = 0; i < 6; i++) {
            response->pos[i] = current_pos[i];
        }
        
        response->success = true;
    }
    
    void setRobotControlCallback(
        const std::shared_ptr<doosan_m0609_control::srv::system::SetRobotControl::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::system::SetRobotControl::Response> response) {
        
        RCLCPP_INFO(get_logger(), "SetRobotControl service called (control: %d)", 
                   request->robot_control);
        
        if (!dart_interface_->isConnected()) {
            response->success = false;
            RCLCPP_ERROR(get_logger(), "Robot not connected");
            return;
        }
        
        // 제어 타입에 따른 처리
        bool success = false;
        switch (request->robot_control) {
            case 0:  // CONTROL_INIT_CONFIG
            case 1:  // CONTROL_ENABLE_OPERATION
                success = dart_interface_->setTorqueOnOff(true);
                break;
            case 2:  // CONTROL_RESET_SAFET_STOP
            case 3:  // CONTROL_RESET_SAFET_OFF
                success = dart_interface_->clearAlarm();
                break;
            default:
                RCLCPP_WARN(get_logger(), "Unsupported robot control type: %d", 
                           request->robot_control);
                success = false;
        }
        
        response->success = success;
        
        if (success) {
            RCLCPP_INFO(get_logger(), "Robot control command executed successfully");
        } else {
            RCLCPP_ERROR(get_logger(), "Robot control command failed");
        }
    }

    // ==========================================================================
    // I/O 제어 서비스 콜백 함수들 (기본 구현)
    // ==========================================================================
    void setToolDigitalOutputCallback(
        const std::shared_ptr<doosan_m0609_control::srv::io::SetToolDigitalOutput::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::io::SetToolDigitalOutput::Response> response) {
        
        RCLCPP_INFO(get_logger(), "SetToolDigitalOutput service called");
        
        // TODO: DartInterface에 GPIO 함수 추가 후 구현
        response->success = false;
        RCLCPP_WARN(get_logger(), "Tool Digital Output control not yet implemented");
    }
    
    void getToolDigitalInputCallback(
        const std::shared_ptr<doosan_m0609_control::srv::io::GetToolDigitalInput::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::io::GetToolDigitalInput::Response> response) {
        
        RCLCPP_DEBUG(get_logger(), "GetToolDigitalInput service called");
        
        // TODO: DartInterface에 GPIO 함수 추가 후 구현
        response->success = false;
        RCLCPP_WARN_ONCE(get_logger(), "Tool Digital Input reading not yet implemented");
    }
    
    void setCtrlBoxDigitalOutputCallback(
        const std::shared_ptr<doosan_m0609_control::srv::io::SetCtrlBoxDigitalOutput::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::io::SetCtrlBoxDigitalOutput::Response> response) {
        
        RCLCPP_INFO(get_logger(), "SetCtrlBoxDigitalOutput service called");
        
        // TODO: DartInterface에 GPIO 함수 추가 후 구현
        response->success = false;
        RCLCPP_WARN(get_logger(), "CtrlBox Digital Output control not yet implemented");
    }
    
    void getCtrlBoxDigitalInputCallback(
        const std::shared_ptr<doosan_m0609_control::srv::io::GetCtrlBoxDigitalInput::Request> request,
        std::shared_ptr<doosan_m0609_control::srv::io::GetCtrlBoxDigitalInput::Response> response) {
        
        RCLCPP_DEBUG(get_logger(), "GetCtrlBoxDigitalInput service called");
        
        // TODO: DartInterface에 GPIO 함수 추가 후 구현
        response->success = false;
        RCLCPP_WARN_ONCE(get_logger(), "CtrlBox Digital Input reading not yet implemented");
    }

    // ==========================================================================
    // 퍼블리셔 및 주기적 함수들
    // ==========================================================================
    void publishJointStates() {
        if (!dart_interface_->isConnected()) {
            return;
        }
        
        try {
            // 현재 관절 위치 조회
            std::array<double, 6> joint_positions = dart_interface_->getJointPosition();
            
            // JointState 메시지 생성
            sensor_msgs::msg::JointState joint_msg;
            joint_msg.header.stamp = now();
            joint_msg.header.frame_id = "base_link";
            
            // 관절 이름 설정
            joint_msg.name = {"joint1", "joint2", "joint3", "joint4", "joint5", "joint6"};
            
            // 관절 위치 설정 (이미 radian으로 변환됨)
            joint_msg.position.assign(joint_positions.begin(), joint_positions.end());
            
            // 속도 및 토크는 현재 구현되지 않음
            joint_msg.velocity.resize(6, 0.0);
            joint_msg.effort.resize(6, 0.0);
            
            // 퍼블리시
            joint_state_pub_->publish(joint_msg);
            
        } catch (const std::exception& e) {
            RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 5000,
                                "Failed to publish joint states: %s", e.what());
        }
    }
    
    void checkRobotStatus() {
        if (!dart_interface_->isConnected()) {
            return;
        }
        
        try {
            // 로봇 상태 체크
            int8_t robot_state = dart_interface_->getRobotState();
            bool is_moving = dart_interface_->isMoving();
            
            RCLCPP_DEBUG(get_logger(), "Robot Status - State: %d, Moving: %s", 
                        robot_state, is_moving ? "true" : "false");
            
            // 비정상 상태 감지 및 경고
            if (robot_state == 6) {  // STATE_EMERGENCY_STOP
                RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 10000,
                                    "Robot is in EMERGENCY STOP state");
            } else if (robot_state == 5) {  // STATE_SAFE_STOP
                RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 10000,
                                    "Robot is in SAFE STOP state");
            } else if (robot_state == 3) {  // STATE_SAFE_OFF
                RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 10000,
                                    "Robot is in SAFE OFF state");
            }
            
        } catch (const std::exception& e) {
            RCLCPP_WARN_THROTTLE(get_logger(), *get_clock(), 10000,
                                "Failed to check robot status: %s", e.what());
        }
    }
};

// =============================================================================
// 메인 함수
// =============================================================================
int main(int argc, char** argv) {
    // ROS2 초기화
    rclcpp::init(argc, argv);
    
    try {
        // 노드 생성
        auto node = std::make_shared<DoosanRobotNode>();
        
        RCLCPP_INFO(rclcpp::get_logger("main"), 
                   "=== Doosan M0609 Control Node Started ===");
        RCLCPP_INFO(rclcpp::get_logger("main"), 
                   "Available services:");
        RCLCPP_INFO(rclcpp::get_logger("main"), 
                   "  Motion: /move_joint, /move_line, /move_stop, /check_motion, /move_home");
        RCLCPP_INFO(rclcpp::get_logger("main"), 
                   "  System: /get_robot_state, /get_current_pose, /set_robot_control");
        RCLCPP_INFO(rclcpp::get_logger("main"), 
                   "  I/O: /set_tool_digital_output, /get_tool_digital_input, etc.");
        RCLCPP_INFO(rclcpp::get_logger("main"), 
                   "Topics: /joint_states");
        
        // 멀티스레드 실행을 위한 executor 사용
        rclcpp::executors::MultiThreadedExecutor executor;
        executor.add_node(node);
        
        // 노드 실행
        executor.spin();
        
    } catch (const std::exception& e) {
        RCLCPP_FATAL(rclcpp::get_logger("main"), 
                    "Fatal error in Doosan Robot Node: %s", e.what());
        return -1;
    }
    
    // ROS2 종료
    rclcpp::shutdown();
    
    RCLCPP_INFO(rclcpp::get_logger("main"), 
               "=== Doosan M0609 Control Node Terminated ===");
    
    return 0;
}