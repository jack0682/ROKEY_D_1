#include "doosan_m0609_controller/doosan_robot_controller.hpp"
#include <chrono>
#include <functional>

using namespace std::chrono_literals;

DoosanRobotController::DoosanRobotController() 
    : Node("doosan_robot_controller"), running_(true) {
    
    RCLCPP_INFO(this->get_logger(), "Initializing Doosan M0609 Robot Controller");
    
    // Initialize parameters
    initializeParameters();
    
    // Initialize DRFL
    m_drfl = std::make_unique<DRFL>();
    
    // Setup ROS2 components
    setupPublishersAndServices();
    
    // Auto-connect if enabled
    if (auto_connect_) {
        if (connectToRobot(robot_ip_)) {
            RCLCPP_INFO(this->get_logger(), "Auto-connected to robot at %s", robot_ip_.c_str());
        } else {
            RCLCPP_WARN(this->get_logger(), "Failed to auto-connect to robot");
        }
    }
    
    // Start status thread
    status_thread_ = std::thread(&DoosanRobotController::statusThreadFunction, this);
    
    RCLCPP_INFO(this->get_logger(), "Doosan Robot Controller initialized successfully");
}

DoosanRobotController::~DoosanRobotController() {
    running_ = false;
    
    if (status_thread_.joinable()) {
        status_thread_.join();
    }
    
    if (m_drfl && m_drfl->isConnected()) {
        disconnectFromRobot();
    }
    
    RCLCPP_INFO(this->get_logger(), "Doosan Robot Controller shutdown complete");
}

void DoosanRobotController::initializeParameters() {
    // Declare parameters with defaults
    this->declare_parameter("robot_ip", "192.168.137.100");
    this->declare_parameter("publish_rate", 10.0);
    this->declare_parameter("auto_connect", false);
    
    // Get parameter values
    robot_ip_ = this->get_parameter("robot_ip").as_string();
    publish_rate_ = this->get_parameter("publish_rate").as_double();
    auto_connect_ = this->get_parameter("auto_connect").as_bool();
    
    RCLCPP_INFO(this->get_logger(), "Parameters - IP: %s, Rate: %.1fHz, Auto-connect: %s", 
                robot_ip_.c_str(), publish_rate_, auto_connect_ ? "true" : "false");
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
        "move_joint", 
        std::bind(&DoosanRobotController::handleMoveJ, this, 
                  std::placeholders::_1, std::placeholders::_2));
    
    connect_service_ = this->create_service<doosan_m0609_controller::srv::ConnectRobot>(
        "connect_robot",
        std::bind(&DoosanRobotController::handleConnectRobot, this,
                  std::placeholders::_1, std::placeholders::_2));
    
    // Timers
    auto timer_period = std::chrono::duration<double>(1.0 / publish_rate_);
    joint_state_timer_ = this->create_wall_timer(
        timer_period, std::bind(&DoosanRobotController::publishJointStates, this));
    
    status_timer_ = this->create_wall_timer(
        1s, std::bind(&DoosanRobotController::publishRobotStatus, this));
}

void DoosanRobotController::publishJointStates() {
    if (!m_drfl || !m_drfl->isConnected()) {
        return;
    }
    
    try {
        auto joint_positions = m_drfl->getJointPosition();
        
        // Custom joint state message
        auto custom_msg = doosan_m0609_controller::msg::JointState();
        custom_msg.header.stamp = this->get_clock()->now();
        custom_msg.header.frame_id = "base_link";
        custom_msg.position = joint_positions;
        custom_msg.velocity = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}; // TODO: Get actual velocities
        custom_msg.effort = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};   // TODO: Get actual efforts
        
        joint_state_pub_->publish(custom_msg);
        
        // Standard joint state message
        auto std_msg = sensor_msgs::msg::JointState();
        std_msg.header = custom_msg.header;
        std_msg.name = {"joint1", "joint2", "joint3", "joint4", "joint5", "joint6"};
        std_msg.position = joint_positions;
        std_msg.velocity = custom_msg.velocity;
        std_msg.effort = custom_msg.effort;
        
        std_joint_state_pub_->publish(std_msg);
        
    } catch (const std::exception& e) {
        RCLCPP_ERROR(this->get_logger(), "Failed to publish joint states: %s", e.what());
    }
}

void DoosanRobotController::publishRobotStatus() {
    auto msg = doosan_m0609_controller::msg::RobotStatus();
    msg.header.stamp = this->get_clock()->now();
    msg.header.frame_id = "base_link";
    
    if (m_drfl) {
        msg.is_connected = m_drfl->isConnected();
        msg.has_control_authority = m_drfl->hasControlAuthority();
        msg.robot_state = m_drfl->getRobotState();
        msg.is_enabled = msg.is_connected && msg.has_control_authority;
        msg.error_message = "";
    } else {
        msg.is_connected = false;
        msg.has_control_authority = false;
        msg.robot_state = "UNINITIALIZED";
        msg.is_enabled = false;
        msg.error_message = "DRFL not initialized";
    }
    
    robot_status_pub_->publish(msg);
}

void DoosanRobotController::statusThreadFunction() {
    RCLCPP_INFO(this->get_logger(), "Status monitoring thread started");
    
    while (running_) {
        // Monitor robot status and handle any issues
        if (m_drfl && m_drfl->isConnected()) {
            // Check for any error conditions here
            // This could include safety monitoring, connection health, etc.
        }
        
        std::this_thread::sleep_for(100ms);
    }
    
    RCLCPP_INFO(this->get_logger(), "Status monitoring thread stopped");
}

void DoosanRobotController::handleMoveJ(
    const std::shared_ptr<doosan_m0609_controller::srv::MoveJ::Request> request,
    std::shared_ptr<doosan_m0609_controller::srv::MoveJ::Response> response) {
    
    RCLCPP_INFO(this->get_logger(), "MoveJ service called");
    
    // Validate input
    if (request->target_joints.size() != 6) {
        response->success = false;
        response->message = "Invalid joint array size. Expected 6 joints.";
        RCLCPP_ERROR(this->get_logger(), "%s", response->message.c_str());
        return;
    }
    
    if (!validateJointLimits(request->target_joints)) {
        response->success = false;
        response->message = "Joint positions exceed safety limits";
        RCLCPP_ERROR(this->get_logger(), "%s", response->message.c_str());
        return;
    }
    
    // Check robot state
    if (!m_drfl || !m_drfl->isConnected()) {
        response->success = false;
        response->message = "Robot not connected";
        RCLCPP_ERROR(this->get_logger(), "%s", response->message.c_str());
        return;
    }
    
    if (!m_drfl->hasControlAuthority()) {
        response->success = false;
        response->message = "No control authority";
        RCLCPP_ERROR(this->get_logger(), "%s", response->message.c_str());
        return;
    }
    
    // Execute movement
    try {
        bool result = m_drfl->moveJ(
            request->target_joints,
            request->velocity_ratio,
            request->acceleration_ratio,
            request->time_out
        );
        
        response->success = result;
        response->message = result ? "Movement completed successfully" : "Movement failed";
        
        RCLCPP_INFO(this->get_logger(), "MoveJ result: %s", response->message.c_str());
        
    } catch (const std::exception& e) {
        response->success = false;
        response->message = std::string("Exception during movement: ") + e.what();
        RCLCPP_ERROR(this->get_logger(), "%s", response->message.c_str());
    }
}

void DoosanRobotController::handleConnectRobot(
    const std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot::Request> request,
    std::shared_ptr<doosan_m0609_controller::srv::ConnectRobot::Response> response) {
    
    RCLCPP_INFO(this->get_logger(), "ConnectRobot service called - %s %s", 
                request->connect ? "CONNECT" : "DISCONNECT", request->robot_ip.c_str());
    
    if (request->connect) {
        response->success = connectToRobot(request->robot_ip);
        response->message = response->success ? "Connected successfully" : "Connection failed";
    } else {
        response->success = disconnectFromRobot();
        response->message = response->success ? "Disconnected successfully" : "Disconnect failed";
    }
    
    RCLCPP_INFO(this->get_logger(), "ConnectRobot result: %s", response->message.c_str());
}

bool DoosanRobotController::connectToRobot(const std::string& ip) {
    if (!m_drfl) {
        RCLCPP_ERROR(this->get_logger(), "DRFL not initialized");
        return false;
    }
    
    try {
        if (m_drfl->openConnection(ip)) {
            if (m_drfl->setRobotControl(true)) {
                robot_ip_ = ip;
                RCLCPP_INFO(this->get_logger(), "Successfully connected to robot at %s", ip.c_str());
                return true;
            } else {
                RCLCPP_ERROR(this->get_logger(), "Failed to get robot control authority");
                m_drfl->closeConnection();
                return false;
            }
        } else {
            RCLCPP_ERROR(this->get_logger(), "Failed to open connection to %s", ip.c_str());
            return false;
        }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(this->get_logger(), "Exception during connection: %s", e.what());
        return false;
    }
}

bool DoosanRobotController::disconnectFromRobot() {
    if (!m_drfl) {
        return true;
    }
    
    try {
        m_drfl->setRobotControl(false);
        m_drfl->closeConnection();
        RCLCPP_INFO(this->get_logger(), "Successfully disconnected from robot");
        return true;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(this->get_logger(), "Exception during disconnection: %s", e.what());
        return false;
    }
}

bool DoosanRobotController::validateJointLimits(const std::vector<double>& joints) {
    // M0609 joint limits (approximate, in radians)
    const std::vector<std::pair<double, double>> joint_limits = {
        {-3.14159, 3.14159},  // Joint 1: ±180°
        {-1.5708, 1.5708},    // Joint 2: ±90°
        {-2.0944, 2.0944},    // Joint 3: ±120°
        {-3.14159, 3.14159},  // Joint 4: ±180°
        {-1.5708, 1.5708},    // Joint 5: ±90°
        {-3.14159, 3.14159}   // Joint 6: ±180°
    };
    
    for (size_t i = 0; i < joints.size() && i < joint_limits.size(); ++i) {
        if (joints[i] < joint_limits[i].first || joints[i] > joint_limits[i].second) {
            RCLCPP_WARN(this->get_logger(), "Joint %zu value %.3f exceeds limits [%.3f, %.3f]", 
                       i+1, joints[i], joint_limits[i].first, joint_limits[i].second);
            return false;
        }
    }
    
    return true;
}

void DoosanRobotController::handleEmergencyStop() {
    if (m_drfl) {
        m_drfl->emergencyStop();
        RCLCPP_WARN(this->get_logger(), "EMERGENCY STOP ACTIVATED!");
    }
}
