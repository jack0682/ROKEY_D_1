/**
 * @file doosan_robot_interface.cpp
 * @brief Doosan 공식 예제 방식 기반 로봇 제어 인터페이스 구현
 * @author Jack (Refactored by Lyra)
 * @date 2024
 */

#include "sugar_water_experiment/doosan_robot_interface.hpp"
#include <iostream>
#include <stdexcept>

using namespace DRAFramework;

namespace sugar_water_experiment {

DoosanRobotInterface::DoosanRobotInterface(
    const std::string& robot_id,
    const std::string& robot_model, 
    const std::string& robot_ip)
    : robot_id_(robot_id)
    , robot_model_(robot_model)
    , robot_ip_(robot_ip)
    , connected_(false)
{
    // DRFL 인터페이스 생성 (공식 예제의 DRFL m_drfl과 동일)
    drfl_ = std::make_unique<CDRFLEx>();
    
    std::cout << "[DoosanInterface] 초기화 완료 - ID: " << robot_id_ 
              << ", Model: " << robot_model_ 
              << ", IP: " << robot_ip_ << std::endl;
}

DoosanRobotInterface::~DoosanRobotInterface() {
    if (connected_) {
        disconnect();
    }
}

bool DoosanRobotInterface::connect() {
    std::cout << "[DoosanInterface] 로봇 연결 시도: " << robot_ip_ << std::endl;
    
    try {
        // 1. 로봇 연결 (공식 예제의 openConnection과 동일)
        if (!drfl_->open_connection(robot_ip_)) {
            std::cerr << "[DoosanInterface] ❌ 연결 실패: " << robot_ip_ << std::endl;
            return false;
        }
        
        std::cout << "[DoosanInterface] ✅ TCP 연결 성공" << std::endl;
        
        // 2. 제어권 확보 (공식 예제의 setRobotControl(true)와 동일)
        if (!drfl_->set_robot_control(ROBOT_CONTROL_START)) {
            std::cerr << "[DoosanInterface] ❌ 제어권 확보 실패" << std::endl;
            drfl_->close_connection();
            return false;
        }
        
        std::cout << "[DoosanInterface] ✅ 제어권 확보 성공" << std::endl;
        
        // 3. 로봇 상태 확인
        if (!check_robot_ready()) {
            std::cerr << "[DoosanInterface] ❌ 로봇 준비 상태 불량" << std::endl;
            disconnect();
            return false;
        }
        
        connected_ = true;
        std::cout << "[DoosanInterface] 🤖 로봇 준비 완료!" << std::endl;
        return true;
        
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ 연결 중 예외 발생: " << e.what() << std::endl;
        return false;
    }
}

void DoosanRobotInterface::disconnect() {
    if (!connected_) return;
    
    try {
        std::cout << "[DoosanInterface] 연결 해제 중..." << std::endl;
        
        // 제어권 해제
        drfl_->set_robot_control(ROBOT_CONTROL_STOP);
        
        // 연결 해제
        drfl_->close_connection();
        
        connected_ = false;
        std::cout << "[DoosanInterface] ✅ 연결 해제 완료" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ⚠️ 연결 해제 중 예외: " << e.what() << std::endl;
    }
}

bool DoosanRobotInterface::set_tool_and_tcp(const std::string& tool_name, const std::string& tcp_name) {
    if (!connected_) {
        std::cerr << "[DoosanInterface] ❌ 로봇이 연결되지 않음" << std::endl;
        return false;
    }
    
    try {
        // 공식 예제의 set_tool(), set_tcp()와 동일
        if (!drfl_->set_tool(tool_name)) {
            std::cerr << "[DoosanInterface] ❌ 도구 설정 실패: " << tool_name << std::endl;
            return false;
        }
        
        if (!drfl_->set_tcp(tcp_name)) {
            std::cerr << "[DoosanInterface] ❌ TCP 설정 실패: " << tcp_name << std::endl;
            return false;
        }
        
        std::cout << "[DoosanInterface] ✅ 도구 및 TCP 설정 완료: " 
                  << tool_name << ", " << tcp_name << std::endl;
        return true;
        
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ 도구/TCP 설정 중 예외: " << e.what() << std::endl;
        return false;
    }
}

bool DoosanRobotInterface::movej(const JointPos& joint_pos, float vel, float acc) {
    if (!connected_) {
        std::cerr << "[DoosanInterface] ❌ 로봇이 연결되지 않음" << std::endl;
        return false;
    }
    
    try {
        float drfl_pos[6];
        convert_to_drfl_joint(joint_pos, drfl_pos);
        
        // 공식 예제의 movej와 동일한 호출
        bool result = drfl_->movej(drfl_pos, vel, acc);
        
        if (result) {
            std::cout << "[DoosanInterface] 🔄 Joint 이동 명령: [" 
                      << joint_pos[0] << ", " << joint_pos[1] << ", " << joint_pos[2] 
                      << ", " << joint_pos[3] << ", " << joint_pos[4] << ", " << joint_pos[5] << "]" << std::endl;
        } else {
            std::cerr << "[DoosanInterface] ❌ Joint 이동 실패" << std::endl;
        }
        
        return result;
        
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ Joint 이동 중 예외: " << e.what() << std::endl;
        return false;
    }
}

bool DoosanRobotInterface::movel(const CartesianPos& cart_pos, 
                                const std::array<float, 2>& vel, 
                                const std::array<float, 2>& acc) {
    if (!connected_) {
        std::cerr << "[DoosanInterface] ❌ 로봇이 연결되지 않음" << std::endl;
        return false;
    }
    
    try {
        float drfl_pos[6];
        float drfl_vel[2] = {vel[0], vel[1]};
        float drfl_acc[2] = {acc[0], acc[1]};
        
        convert_to_drfl_pos(cart_pos, drfl_pos);
        
        // 공식 예제의 movel과 동일한 호출
        bool result = drfl_->movel(drfl_pos, drfl_vel, drfl_acc);
        
        if (result) {
            std::cout << "[DoosanInterface] 📍 Cartesian 이동 명령: [" 
                      << cart_pos[0] << ", " << cart_pos[1] << ", " << cart_pos[2] 
                      << ", " << cart_pos[3] << ", " << cart_pos[4] << ", " << cart_pos[5] << "]" << std::endl;
        } else {
            std::cerr << "[DoosanInterface] ❌ Cartesian 이동 실패" << std::endl;
        }
        
        return result;
        
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ Cartesian 이동 중 예외: " << e.what() << std::endl;
        return false;
    }
}

bool DoosanRobotInterface::amovel(const CartesianPos& cart_pos, 
                                 const std::array<float, 2>& vel, 
                                 const std::array<float, 2>& acc) {
    if (!connected_) {
        std::cerr << "[DoosanInterface] ❌ 로봇이 연결되지 않음" << std::endl;
        return false;
    }
    
    try {
        float drfl_pos[6];
        float drfl_vel[2] = {vel[0], vel[1]};
        float drfl_acc[2] = {acc[0], acc[1]};
        
        convert_to_drfl_pos(cart_pos, drfl_pos);
        
        // 공식 예제의 amovel과 동일한 호출 (비동기)
        bool result = drfl_->amovel(drfl_pos, drfl_vel, drfl_acc);
        
        if (result) {
            std::cout << "[DoosanInterface] ⚡ 비동기 Cartesian 이동 명령: [" 
                      << cart_pos[0] << ", " << cart_pos[1] << ", " << cart_pos[2] 
                      << ", " << cart_pos[3] << ", " << cart_pos[4] << ", " << cart_pos[5] << "]" << std::endl;
        } else {
            std::cerr << "[DoosanInterface] ❌ 비동기 Cartesian 이동 실패" << std::endl;
        }
        
        return result;
        
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ 비동기 Cartesian 이동 중 예외: " << e.what() << std::endl;
        return false;
    }
}

DoosanRobotInterface::CartesianPos DoosanRobotInterface::get_current_posx() {
    CartesianPos result = {0, 0, 0, 0, 0, 0};
    
    if (!connected_) {
        std::cerr << "[DoosanInterface] ❌ 로봇이 연결되지 않음" << std::endl;
        return result;
    }
    
    try {
        // 공식 예제의 get_current_posx와 동일
        LPROBOT_TASK_POSE pose = drfl_->get_current_posx();
        
        if (pose != nullptr) {
            for (int i = 0; i < 6; ++i) {
                result[i] = pose->fTargetPos[i];
            }
        }
        
        return result;
        
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ 현재 위치 획득 중 예외: " << e.what() << std::endl;
        return result;
    }
}

DoosanRobotInterface::JointPos DoosanRobotInterface::get_current_posj() {
    JointPos result = {0, 0, 0, 0, 0, 0};
    
    if (!connected_) {
        std::cerr << "[DoosanInterface] ❌ 로봇이 연결되지 않음" << std::endl;
        return result;
    }
    
    try {
        LPROBOT_POSE pose = drfl_->get_current_posj();
        
        if (pose != nullptr) {
            for (int i = 0; i < 6; ++i) {
                result[i] = pose->fTargetPos[i];
            }
        }
        
        return result;
        
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ 현재 관절 위치 획득 중 예외: " << e.what() << std::endl;
        return result;
    }
}

bool DoosanRobotInterface::wait_motion_complete() {
    if (!connected_) return false;
    
    try {
        // 공식 예제 패턴: 모션 완료까지 대기
        return drfl_->mwait();
        
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ 모션 대기 중 예외: " << e.what() << std::endl;
        return false;
    }
}

ROBOT_STATE DoosanRobotInterface::get_robot_state() {
    if (!connected_) return ROBOT_STATE_UNKNOWN;
    
    try {
        return drfl_->get_robot_state();
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ 로봇 상태 확인 중 예외: " << e.what() << std::endl;
        return ROBOT_STATE_UNKNOWN;
    }
}

void DoosanRobotInterface::emergency_stop() {
    if (!connected_) return;
    
    try {
        std::cout << "[DoosanInterface] 🚨 비상 정지 실행!" << std::endl;
        drfl_->stop(STOP_TYPE_QUICK);
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ 비상 정지 중 예외: " << e.what() << std::endl;
    }
}

// Private 메서드들

bool DoosanRobotInterface::check_robot_ready() {
    try {
        ROBOT_STATE state = drfl_->get_robot_state();
        
        if (state == ROBOT_STATE_STANDBY || state == ROBOT_STATE_IDLE) {
            std::cout << "[DoosanInterface] ✅ 로봇 준비 상태 양호" << std::endl;
            return true;
        } else {
            std::cout << "[DoosanInterface] ⚠️ 로봇 상태: " << static_cast<int>(state) << std::endl;
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << "[DoosanInterface] ❌ 로봇 상태 확인 중 예외: " << e.what() << std::endl;
        return false;
    }
}

void DoosanRobotInterface::convert_to_drfl_pos(const CartesianPos& pos, float drfl_pos[6]) {
    for (int i = 0; i < 6; ++i) {
        drfl_pos[i] = pos[i];
    }
}

void DoosanRobotInterface::convert_to_drfl_joint(const JointPos& pos, float drfl_pos[6]) {
    for (int i = 0; i < 6; ++i) {
        drfl_pos[i] = pos[i];
    }
}

} // namespace sugar_water_experiment
