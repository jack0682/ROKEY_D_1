#include "doosan_m0609_controller/doosan_robot_controller.hpp"
#include <chrono>

using namespace std::chrono_literals;

DoosanRobotController::DoosanRobotController() 
    : Node("doosan_m0609_controller"), running_(true) {
    
    RCLCPP_INFO(this->get_logger(), "🤖 Initializing Doosan M0609 Controller with Real DRFL...");
    
    // Initialize parameters
    initializeParameters();
    
    // Create real DRFL instance (C++ wrapper class)
    m_drfl = std::make_unique<DRAFramework::CDRFL>();
    
    // Setup publishers and services
    setupPublishersAndServices();
    
    // Auto connect if enabled
    if (auto_connect_) {
        if (connectToRobot(robot_ip_)) {
            RCLCPP_INFO(this->get_logger(), "✅ Successfully connected to M0609 at %s", robot_ip_.c_str());
        } else {
            RCLCPP_WARN(this->get_logger(), "⚠️ Failed to auto-connect to robot. Use connect service manually.");
        }
    }
    
    RCLCPP_INFO(this->get_logger(), "🚀 Doosan M0609 Controller initialized");
}

DoosanRobotController::~DoosanRobotController() {
    running_ = false;
    
    if (status_thread_.joinable()) {
        status_thread_.join();
    }
    
    disconnectFromRobot();
}

void DoosanRobotController::initializeParameters() {
    // Declare parameters with defaults
    this->declare_parameter("robot_ip", "192.168.137.100");
    this->declare_parameter("publish_rate", 100.0);  // Hz
    this->declare_parameter("auto_connect", true);
    
    // Get parameter values
    robot_ip_ = this->get_parameter("robot_ip").as_string();
    publish_rate_ = this->get_parameter("publish_rate").as_double();
    auto_connect_ = this->get_parameter("auto_connect").as_bool();
    
    RCLCPP_INFO(this->get_logger(), "📋 Parameters - IP: %s, Rate: %.1f Hz", 
                robot_ip_.c_str(), publish_rate_);
}

void DoosanRobotController::setupPublishersAndServices() {
    // Publishers
    joint_state_pub_ = this->create_publisher<doosan_m0609_controller::msg::JointState>(
        "joint_states_custom", 10);
    
    robot_status_pub_ = this->create_publisher<doosan_m0609_controller::msg::RobotStatus>(
        "robot_status", 10);
    
    std_joint_state_pub_ = this->create_publisher<sensor_msgs::msg::JointState>(
        "joint_states", 10);
    
    // Services
    move_j_service_ = this->create_service<doosan_m0609_controller::srv::MoveJ>(
        "move_j", std::bind(&DoosanRobotController::handleMoveJ, this,
        std::placeholders::_1, std::placeholders::_2));
    
    connect_service_ = this->create_service<doosan_m0609_controller::srv::ConnectRobot>(
        "connect_robot", std::bind(&DoosanRobotController::handleConnectRobot, this,
        std::placeholders::_1, std::placeholders::_2));
    
    // Timers
    auto timer_period = std::chrono::milliseconds(static_cast<int>(1000.0 / publish_rate_));
    joint_state_timer_ = this->create_wall_timer(
        timer_period, std::bind(&DoosanRobotController::publishJointStates, this));
    
    status_timer_ = this->create_wall_timer(
        1s, std::bind(&DoosanRobotController::publishRobotStatus, this));
}

void DoosanRobotController::publishJointStates() {
    if (!m_drfl) {
        return;
    }
    
    try {
        // 🔥 실제 DRFL API 사용하여 관절 위치 읽기 (글로벌 스코프 타입 사용)
        LPROBOT_POSE current_pose = m_drfl->GetCurrentPose(ROBOT_SPACE_JOINT);
        if (!current_pose) {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                                "Failed to get current joint positions");
            return;
        }
        
        // Create custom message
        auto custom_msg = std::make_unique<doosan_m0609_controller::msg::JointState>();
        custom_msg->header.stamp = this->now();
        custom_msg->header.frame_id = "base_link";
        
        // 🎯 DRFL 데이터를 우리 메시지 형식으로 변환
        for (size_t i = 0; i < 6; ++i) {
            custom_msg->position[i] = current_pose->_fPosition[i];
            custom_msg->velocity[i] = 0.0;  // DRFL에서 속도 정보 추가 필요시 구현
            custom_msg->effort[i] = 0.0;    // DRFL에서 토크 정보 추가 필요시 구현
        }
        
        // Publish custom message
        joint_state_pub_->publish(std::move(custom_msg));
        
        // Create standard ROS2 joint state message
        auto std_msg = std::make_unique<sensor_msgs::msg::JointState>();
        std_msg->header.stamp = this->now();
        std_msg->header.frame_id = "base_link";
        
        // Joint names for M0609
        std_msg->name = {"joint1", "joint2", "joint3", "joint4", "joint5", "joint6"};
        
        // Convert to std::vector
        std_msg->position.assign(custom_msg->position.begin(), custom_msg->position.end());
        std_msg->velocity.assign(custom_msg->velocity.begin(), custom_msg->velocity.end());
        std_msg->effort.assign(custom_msg->effort.begin(), custom_msg->effort.end());
        
        // Publish standard message
        std_joint_state_pub_->publish(std::move(std_msg));
        
    } catch (const std::exception& e) {
        RCLCPP_ERROR_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                             "Error publishing joint states: %s", e.what());
    }
}

void DoosanRobotController::publishRobotStatus() {
    if (!m_drfl) {
        return;
    }
    
    try {
        auto status_msg = std::make_unique<doosan_m0609_controller::msg::RobotStatus>();
        status_msg->header.stamp = this->now();
        status_msg->header.frame_id = "base_link";
        
        // 🔥 실제 DRFL API 사용하여 로봇 상태 읽기 (글로벌 스코프 타입 사용)
        ROBOT_STATE robot_state = m_drfl->GetRobotState();
        ROBOT_MODE robot_mode = m_drfl->GetRobotMode();
        
        status_msg->is_connected = (robot_state != STATE_NOT_READY);
        status_msg->has_control_authority = (robot_state >= STATE_STANDBY);
        status_msg->robot_state = std::to_string(static_cast<int>(robot_state));
        status_msg->is_enabled = status_msg->is_connected && status_msg->has_control_authority;
        status_msg->error_message = "";
        
        robot_status_pub_->publish(std::move(status_msg));
        
    } catch (const std::exception& e) {
        RCLCPP_ERROR_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
                             "Error publishing robot status: %s", e.what());
    }
}

void DoosanRobotController::handleMoveJ(
    const std::shared_ptr<doosan_m0609_controller::srv::MoveJ::Request> request,
    std::shared_ptr<doosan_m0609_controller::srv::MoveJ::Response> response) {
    
    RCLCPP_INFO(this->get_logger(), "🦾 Received MoveJ request");
    
    if (!m_drfl) {
        response->success = false;
        response->message = "DRFL not initialized";
        RCLCPP_ERROR(this->get_logger(), "%s", response->message.c_str());
        return;
    }
    
    // Convert std::array to float array for DRFL
    float target_joints[NUM_JOINT];
    for (size_t i = 0; i < 6; ++i) {
        target_joints[i] = static_cast<float>(request->target_joints[i]);
    }
    
    if (!validateJointLimits(request->target_joints)) {
        response->success = false;
        response->message = "Joint limits exceeded";
        RCLCPP_ERROR(this->get_logger(), "%s", response->message.c_str());
        return;
    }
    
    try {
        // 🔥 실제 DRFL API 사용하여 관절 움직임 실행
        bool result = m_drfl->MoveJ(
            target_joints,
            static_cast<float>(request->velocity_ratio * 100.0),     // DRFL은 % 단위
            static_cast<float>(request->acceleration_ratio * 100.0), // DRFL은 % 단위
            static_cast<float>(request->time_out)
        );
        
        response->success = result;
        response->message = result ? "MoveJ completed successfully" : "MoveJ failed";
        
        if (result) {
            RCLCPP_INFO(this->get_logger(), "✅ MoveJ completed successfully");
        } else {
            RCLCPP_ERROR(this->get_logger(), "❌ MoveJ failed");
        }
        
    } catch (const std::exception& e) {
        response->success = false;
        response->message = std::string("MoveJ exception: ") + e.what();
        RCLCPP_ERROR(this->get_logger(), "💥 MoveJ exception: %s", e.what());
    }
}

void DoosanRobotController::handleConnectRobot(
    const std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot::Request> request,
    std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot::Response> response) {
    
    RCLCPP_INFO(this->get_logger(), "🔌 Connect request: %s %s", 
                request->connect ? "CONNECT" : "DISCONNECT", request->robot_ip.c_str());
    
    if (request->connect) {
        response->success = connectToRobot(request->robot_ip);
        response->message = response->success ? "Connected successfully" : "Connection failed";
    } else {
        response->success = disconnectFromRobot();
        response->message = response->success ? "Disconnected successfully" : "Disconnect failed";
    }
    
    RCLCPP_INFO(this->get_logger(), "🔌 Result: %s", response->message.c_str());
}

bool DoosanRobotController::connectToRobot(const std::string& ip) {
    if (!m_drfl) {
        RCLCPP_ERROR(this->get_logger(), "❌ DRFL instance not initialized");
        return false;
    }
    
    try {
        // 🔥 실제 DRFL 연결 (글로벌 스코프 타입 사용)
        if (!m_drfl->OpenConnection(ip)) {
            RCLCPP_ERROR(this->get_logger(), "❌ Failed to open connection to %s", ip.c_str());
            return false;
        }
        
        // 제어권 요청
        if (!m_drfl->SetRobotControl(CONTROL_SERVO_ON)) {
            RCLCPP_ERROR(this->get_logger(), "❌ Failed to get robot control authority");
            m_drfl->CloseConnection();
            return false;
        }
        
        RCLCPP_INFO(this->get_logger(), "✅ Successfully connected to M0609 and got control authority");
        return true;
        
    } catch (const std::exception& e) {
        RCLCPP_ERROR(this->get_logger(), "💥 Connection exception: %s", e.what());
        return false;
    }
}

bool DoosanRobotController::disconnectFromRobot() {
    if (!m_drfl) {
        return true;
    }
    
    try {
        // 제어권 해제 (CONTROL_SERVO_OFF는 정의되어있지 않으므로 다른 값 사용)
        m_drfl->SetRobotControl(CONTROL_INIT_CONFIG);
        
        // 연결 종료
        m_drfl->CloseConnection();
        
        RCLCPP_INFO(this->get_logger(), "✅ Disconnected from robot");
        return true;
        
    } catch (const std::exception& e) {
        RCLCPP_ERROR(this->get_logger(), "💥 Disconnection exception: %s", e.what());
        return false;
    }
}

bool DoosanRobotController::validateJointLimits(const std::array<double, 6>& joints) {
    // M0609 joint limits (in radians)
    const std::array<std::pair<double, double>, 6> joint_limits = {{
        {-3.14159, 3.14159},   // Joint 1: ±180°
        {-2.0944, 2.0944},     // Joint 2: ±120° 
        {-2.61799, 2.61799},   // Joint 3: ±150°
        {-3.14159, 3.14159},   // Joint 4: ±180°
        {-2.61799, 2.61799},   // Joint 5: ±150°
        {-6.28318, 6.28318}    // Joint 6: ±360°
    }};
    
    for (size_t i = 0; i < joints.size(); ++i) {
        if (joints[i] < joint_limits[i].first || joints[i] > joint_limits[i].second) {
            RCLCPP_WARN(this->get_logger(), "⚠️ Joint %zu value %f exceeds limits [%f, %f]",
                       i + 1, joints[i], joint_limits[i].first, joint_limits[i].second);
            return false;
        }
    }
    
    return true;
}

void DoosanRobotController::handleEmergencyStop() {
    if (m_drfl) {
        try {
            m_drfl->MoveStop(STOP_TYPE_QUICK);
            RCLCPP_WARN(this->get_logger(), "🚨 EMERGENCY STOP ACTIVATED!");
        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "💥 Emergency stop failed: %s", e.what());
        }
    }
}
