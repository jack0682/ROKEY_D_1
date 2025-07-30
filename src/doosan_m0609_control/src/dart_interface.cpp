#include "doosan_m0609_control/dart_interface.hpp"
#include <cmath>

// DRFL 네임스페이스 사용
using namespace DRAFramework;

DartInterface::DartInterface()
: m_connected(false) {
    // 생성자에서는 객체만 초기화, 실제 연결은 connect()에서 수행
}

DartInterface::~DartInterface() {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_connected) {
        // 1. 제어권 해제 (중요!)
        try {
            m_robot.SetRobotControl(ROBOT_CONTROL_RESET_SAFET_OFF);
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Robot control released");
        } catch (const std::exception& e) {
            RCLCPP_WARN(rclcpp::get_logger("DartInterface"), "Failed to release robot control: %s", e.what());
        }
        
        // 2. 연결 종료
        m_robot.CloseConnection();
        m_connected = false;
        RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Robot connection closed");
    }
}

bool DartInterface::connect(const std::string& host, int port) {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (m_connected) {
        RCLCPP_WARN(rclcpp::get_logger("DartInterface"), "Already connected to robot");
        return true;
    }

    try {
        // 1. 로봇 연결 시도
        RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Attempting to connect to robot at %s:%d", host.c_str(), port);
        
        // ✅ 수정: OpenConnection은 직접 bool 반환, DRFL_SUCCESS 비교 불필요
        if (m_robot.OpenConnection(host, static_cast<unsigned int>(port))) {
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Successfully connected to robot");
            
            // 2. 로봇 상태 확인
            ROBOT_STATE robot_state = m_robot.GetRobotState();
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Current robot state: %d", static_cast<int>(robot_state));
            
            // 3. 제어권 요청 (매우 중요!)
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Requesting robot control authority...");
            if (m_robot.SetRobotControl(ROBOT_CONTROL_ENABLE_OPERATION)) {
                RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Robot control authority granted");
                
                // 4. 안전 설정
                m_robot.SetSafeStopResetType(SAFE_STOP_RESET_TYPE_DEFAULT);
                
                // 5. 연결 완료
                m_connected = true;
                return true;
            } else {
                RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Failed to get robot control authority");
                m_robot.CloseConnection();
                return false;
            }
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Failed to connect to robot at %s:%d", host.c_str(), port);
            return false;
        }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Exception during robot connection: %s", e.what());
        return false;
    }
}

bool DartInterface::disconnect() {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        return true;
    }

    try {
        // 1. 제어권 해제
        if (m_robot.SetRobotControl(ROBOT_CONTROL_RESET_SAFET_OFF)) {
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Robot control released");
        } else {
            RCLCPP_WARN(rclcpp::get_logger("DartInterface"), "Failed to release robot control");
        }
        
        // 2. 연결 종료
        m_robot.CloseConnection();
        m_connected = false;
        
        RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Disconnected from robot");
        return true;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Exception during disconnect: %s", e.what());
        return false;
    }
}

bool DartInterface::isConnected() const {
    return m_connected;
}

void DartInterface::logIfFailed(bool success, const std::string& context) const {
    if (!success) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "%s failed", context.c_str());
    }
}

// ============================================================================
// 모션 제어 API들
// ============================================================================

bool DartInterface::moveJ(const std::array<double, 6>& joint_target) {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return false;
    }

    try {
        // 1. 데이터 타입 변환 (double[] -> float[])
        float target_pos[NUM_JOINT];
        for (int i = 0; i < NUM_JOINT; i++) {
            target_pos[i] = static_cast<float>(joint_target[i]);
        }

        // 2. ✅ 수정: 올바른 MoveJ API 호출
        // MoveJ(float fTargetPos[NUM_JOINT], float fTargetVel, float fTargetAcc, 
        //       float fTargetTime = 0.f, MOVE_MODE eMoveMode = MOVE_MODE_ABSOLUTE, 
        //       float fBlendingRadius = 0.f, BLENDING_SPEED_TYPE eBlendingType = BLENDING_SPEED_TYPE_DUPLICATE)
        bool success = m_robot.MoveJ(
            target_pos,                     // 목표 관절 위치
            60.0f,                          // 속도 (deg/sec)
            200.0f,                         // 가속도 (deg/sec²)
            0.0f,                           // 시간 (0 = 속도/가속도 기반)
            MOVE_MODE_ABSOLUTE,             // 절대 좌표 모드
            0.0f,                           // 블렌딩 반지름
            BLENDING_SPEED_TYPE_DUPLICATE   // 블렌딩 타입
        );
        
        if (success) {
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "MoveJ command sent successfully");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "MoveJ command failed");
        }
        
        return success;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "MoveJ exception: %s", e.what());
        return false;
    }
}

bool DartInterface::moveL(const std::array<double, 6>& pose_target) {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return false;
    }

    try {
        // 1. 데이터 타입 변환 (double[] -> float[])
        float target_pos[NUM_TASK];
        for (int i = 0; i < NUM_TASK; i++) {
            target_pos[i] = static_cast<float>(pose_target[i]);
        }

        // 2. ✅ 수정: 올바른 MoveL API 호출
        // MoveL(float fTargetPos[NUM_TASK], float fTargetVel[2], float fTargetAcc[2], 
        //       float fTargetTime = 0.f, MOVE_MODE eMoveMode = MOVE_MODE_ABSOLUTE, 
        //       MOVE_REFERENCE eMoveReference = MOVE_REFERENCE_BASE, 
        //       float fBlendingRadius = 0.f, BLENDING_SPEED_TYPE eBlendingType = BLENDING_SPEED_TYPE_DUPLICATE)
        float target_vel[2] = {50.0f, 30.0f};   // [linear_vel(mm/sec), angular_vel(deg/sec)]
        float target_acc[2] = {100.0f, 60.0f};  // [linear_acc(mm/sec²), angular_acc(deg/sec²)]
        
        bool success = m_robot.MoveL(
            target_pos,                     // 목표 태스크 위치
            target_vel,                     // 속도 [선형, 각속도]
            target_acc,                     // 가속도 [선형, 각가속도]
            0.0f,                           // 시간 (0 = 속도/가속도 기반)
            MOVE_MODE_ABSOLUTE,             // 절대 좌표 모드
            MOVE_REFERENCE_BASE,            // 베이스 좌표계 기준
            0.0f,                           // 블렌딩 반지름
            BLENDING_SPEED_TYPE_DUPLICATE   // 블렌딩 타입
        );
        
        if (success) {
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "MoveL command sent successfully");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "MoveL command failed");
        }
        
        return success;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "MoveL exception: %s", e.what());
        return false;
    }
}

bool DartInterface::moveJointBlend(const std::array<double, 6>& target, double blend_radius) {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return false;
    }

    try {
        // 1. 데이터 타입 변환
        float target_pos[NUM_JOINT];
        for (int i = 0; i < NUM_JOINT; i++) {
            target_pos[i] = static_cast<float>(target[i]);
        }

        // 2. ✅ 수정: 블렌딩을 적용한 MoveJ 호출
        bool success = m_robot.MoveJ(
            target_pos,                     // 목표 관절 위치
            60.0f,                          // 속도 (deg/sec)
            200.0f,                         // 가속도 (deg/sec²)
            0.0f,                           // 시간
            MOVE_MODE_ABSOLUTE,             // 절대 좌표 모드
            static_cast<float>(blend_radius), // 블렌딩 반지름 (mm)
            BLENDING_SPEED_TYPE_DUPLICATE   // 블렌딩 타입
        );
        
        logIfFailed(success, "MoveJointBlend");
        return success;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "MoveJointBlend exception: %s", e.what());
        return false;
    }
}

bool DartInterface::goHome() {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return false;
    }

    try {
        // ✅ 수정: Home 함수 호출 (매개변수: bRun = 1은 홈으로 이동)
        bool success = m_robot.Home(1);  // 1 = 홈 위치로 이동 시작
        
        if (success) {
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Home command sent successfully");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Home command failed");
        }
        
        return success;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "GoHome exception: %s", e.what());
        return false;
    }
}

// ============================================================================
// 제어 중단 API들
// ============================================================================

bool DartInterface::stop() {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return false;
    }

    try {
        // ✅ 수정: MoveStop API 호출
        bool success = m_robot.MoveStop(STOP_TYPE_QUICK);  // 빠른 정지
        
        if (success) {
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Robot stop command sent successfully");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot stop command failed");
        }
        
        return success;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Stop exception: %s", e.what());
        return false;
    }
}

bool DartInterface::emergencyStop() {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return false;
    }

    try {
        // ✅ 수정: 긴급 정지는 SetRobotControl로 수행
        bool success = m_robot.SetRobotControl(ROBOT_CONTROL_RESET_SAFET_STOP);
        
        if (success) {
            RCLCPP_WARN(rclcpp::get_logger("DartInterface"), "Emergency stop activated");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Emergency stop failed");
        }
        
        return success;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "EmergencyStop exception: %s", e.what());
        return false;
    }
}

// ============================================================================
// 상태 조회 API들
// ============================================================================

std::array<double, 6> DartInterface::getJointPosition() {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::array<double, 6> joint_pos = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return joint_pos;
    }

    try {
        // ✅ 수정: GetCurrentPose API 호출
        LPROBOT_POSE current_pose = m_robot.GetCurrentPose(ROBOT_SPACE_JOINT);
        
        if (current_pose != nullptr) {
            for (int i = 0; i < 6; i++) {
                // 각도를 degree에서 radian으로 변환
                joint_pos[i] = static_cast<double>(current_pose->_fPosition[i]) * M_PI / 180.0;
            }
            RCLCPP_DEBUG(rclcpp::get_logger("DartInterface"), "Joint positions retrieved successfully");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Failed to get joint positions");
        }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "GetJointPosition exception: %s", e.what());
    }
    
    return joint_pos;
}

std::array<double, 6> DartInterface::getTaskPosition() {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::array<double, 6> task_pos = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return task_pos;
    }

    try {
        // ✅ 수정: GetCurrentPose API 호출 (태스크 공간)
        LPROBOT_POSE current_pose = m_robot.GetCurrentPose(ROBOT_SPACE_TASK);
        
        if (current_pose != nullptr) {
            for (int i = 0; i < 6; i++) {
                if (i < 3) {
                    // 위치는 mm 단위 그대로 사용
                    task_pos[i] = static_cast<double>(current_pose->_fPosition[i]);
                } else {
                    // 자세는 degree에서 radian으로 변환
                    task_pos[i] = static_cast<double>(current_pose->_fPosition[i]) * M_PI / 180.0;
                }
            }
            RCLCPP_DEBUG(rclcpp::get_logger("DartInterface"), "Task positions retrieved successfully");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Failed to get task positions");
        }
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "GetTaskPosition exception: %s", e.what());
    }
    
    return task_pos;
}

std::array<double, 6> DartInterface::getJointTorque() {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::array<double, 6> torque = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return torque;
    }

    try {
        // ❌ 주의: DRFL API에는 직접적인 토크 조회 함수가 없음
        // 실시간 모니터링 데이터에서 토크를 얻어야 함
        // 현재는 더미 데이터 반환
        RCLCPP_WARN_ONCE(rclcpp::get_logger("DartInterface"), 
                         "Joint torque reading not implemented - requires monitoring callback");
        
        // TODO: SetOnMonitoringData 콜백을 통해 토크 데이터 수집 구현 필요
        
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "GetJointTorque exception: %s", e.what());
    }
    
    return torque;
}

bool DartInterface::isMoving() {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        return false;
    }

    try {
        // ✅ 수정: GetRobotState로 모션 상태 확인
        ROBOT_STATE robot_state = m_robot.GetRobotState();
        
        // STATE_MOVING = 2 (DRFS.h에서 정의됨)
        bool moving = (robot_state == 2);  // STATE_MOVING
        
        return moving;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "IsMoving exception: %s", e.what());
        return false;
    }
}

int8_t DartInterface::getRobotState() {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        return -1; // 연결되지 않음을 나타내는 값
    }

    try {
        // ✅ 수정: GetRobotState API 호출
        ROBOT_STATE robot_state = m_robot.GetRobotState();
        return static_cast<int8_t>(robot_state);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "GetRobotState exception: %s", e.what());
        return -1;
    }
}

// ============================================================================
// 설정 명령 API들
// ============================================================================

bool DartInterface::setPayload(double mass) {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return false;
    }

    try {
        // ❌ 주의: DRFL API에는 직접적인 SetPayload 함수가 없음
        // ConfigCreateTool 또는 SetCurrentTool을 사용해야 함
        RCLCPP_WARN_ONCE(rclcpp::get_logger("DartInterface"), 
                         "SetPayload not directly supported - use ConfigCreateTool instead");
        
        // TODO: ConfigCreateTool을 사용한 페이로드 설정 구현 필요
        // 예시:
        // float weight = static_cast<float>(mass);
        // float cog[3] = {0.0f, 0.0f, 0.0f};
        // float inertia[6] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
        // bool success = m_robot.ConfigCreateTool("payload_tool", weight, cog, inertia);
        
        return false;  // 현재 미구현
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "SetPayload exception: %s", e.what());
        return false;
    }
}

bool DartInterface::setTorqueOnOff(bool onoff) {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return false;
    }

    try {
        // ✅ 수정: SetRobotControl로 토크 활성화/비활성화
        ROBOT_CONTROL control_mode;
        if (onoff) {
            control_mode = ROBOT_CONTROL_ENABLE_OPERATION;  // 토크 ON
        } else {
            control_mode = ROBOT_CONTROL_RESET_SAFET_OFF;   // 토크 OFF
        }
        
        bool success = m_robot.SetRobotControl(control_mode);
        
        if (success) {
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Torque %s successfully", 
                       onoff ? "enabled" : "disabled");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Failed to %s torque", 
                        onoff ? "enable" : "disable");
        }
        
        return success;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "SetTorqueOnOff exception: %s", e.what());
        return false;
    }
}

bool DartInterface::clearAlarm() {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_connected) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Robot not connected");
        return false;
    }

    try {
        // ✅ 수정: SetRobotControl로 알람 리셋
        bool success = m_robot.SetRobotControl(ROBOT_CONTROL_RESET_SAFET_STOP);
        
        if (success) {
            RCLCPP_INFO(rclcpp::get_logger("DartInterface"), "Robot alarm cleared successfully");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "Failed to clear robot alarm");
        }
        
        return success;
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("DartInterface"), "ClearAlarm exception: %s", e.what());
        return false;
    }
}