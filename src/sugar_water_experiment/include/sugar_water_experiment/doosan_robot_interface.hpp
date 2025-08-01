/**
 * @file doosan_robot_interface.hpp
 * @brief Doosan 공식 예제 방식 기반 로봇 제어 인터페이스
 * @author Jack (Refactored by Lyra)
 * @date 2024
 */

#pragma once

#include <rclcpp/rclcpp.hpp>
#include <memory>
#include <vector>
#include <array>
#include <functional>
#include <chrono>
#include <thread>

// DRFL 인터페이스 사용
#include "../../dsr_common2/include/DRFLEx.h"

namespace sugar_water_experiment {

/**
 * @brief Doosan 공식 예제 방식을 따르는 로봇 제어 인터페이스
 * 
 * Python 예제의 패턴을 C++로 구현:
 * - DR_init 설정과 유사한 초기화
 * - DSR_ROBOT2의 함수들을 직접 호출하는 구조
 * - posx, posj 타입 안전성 보장
 */
class DoosanRobotInterface {
public:
    // 공식 예제와 동일한 상수들
    static constexpr const char* DEFAULT_ROBOT_ID = "dsr01";
    static constexpr const char* DEFAULT_ROBOT_MODEL = "m0609";
    static constexpr int DEFAULT_VELOCITY = 100;
    static constexpr int DEFAULT_ACC = 100;
    
    // Cartesian 좌표 (x, y, z, rx, ry, rz)
    using CartesianPos = std::array<float, 6>;
    // Joint 좌표 (j1-j6)
    using JointPos = std::array<float, 6>;
    
    /**
     * @brief 생성자 - 공식 예제의 DR_init 설정 방식 적용
     * @param robot_id 로봇 ID (기본값: "dsr01")
     * @param robot_model 로봇 모델 (기본값: "m0609")
     * @param robot_ip 로봇 IP (기본값: "192.168.1.100")
     */
    DoosanRobotInterface(
        const std::string& robot_id = DEFAULT_ROBOT_ID,
        const std::string& robot_model = DEFAULT_ROBOT_MODEL,
        const std::string& robot_ip = "192.168.1.100"
    );
    
    ~DoosanRobotInterface();
    
    /**
     * @brief 로봇 연결 및 제어권 확보 (공식 예제 패턴 적용)
     * @return 성공 여부
     */
    bool connect();
    
    /**
     * @brief 로봇 연결 해제
     */
    void disconnect();
    
    /**
     * @brief 연결 상태 확인
     * @return 연결 여부
     */
    bool is_connected() const { return connected_; }
    
    /**
     * @brief 도구 및 TCP 설정 (공식 예제 방식)
     * @param tool_name 도구 이름
     * @param tcp_name TCP 이름
     * @return 성공 여부
     */
    bool set_tool_and_tcp(const std::string& tool_name, const std::string& tcp_name);
    
    /**
     * @brief Joint 좌표 이동 (공식 예제의 movej와 동일)
     * @param joint_pos 목표 joint 좌표
     * @param vel 속도
     * @param acc 가속도
     * @return 성공 여부
     */
    bool movej(const JointPos& joint_pos, float vel = DEFAULT_VELOCITY, float acc = DEFAULT_ACC);
    
    /**
     * @brief Cartesian 좌표 이동 (공식 예제의 movel과 동일)
     * @param cart_pos 목표 Cartesian 좌표
     * @param vel 속도 [trans_vel, rot_vel]
     * @param acc 가속도 [trans_acc, rot_acc]
     * @return 성공 여부
     */
    bool movel(const CartesianPos& cart_pos, const std::array<float, 2>& vel = {DEFAULT_VELOCITY, DEFAULT_VELOCITY}, 
               const std::array<float, 2>& acc = {DEFAULT_ACC, DEFAULT_ACC});
    
    /**
     * @brief 비동기 Cartesian 이동 (공식 예제의 amovel과 동일)
     * @param cart_pos 목표 Cartesian 좌표
     * @param vel 속도
     * @param acc 가속도
     * @return 성공 여부
     */
    bool amovel(const CartesianPos& cart_pos, const std::array<float, 2>& vel = {DEFAULT_VELOCITY, DEFAULT_VELOCITY}, 
                const std::array<float, 2>& acc = {DEFAULT_ACC, DEFAULT_ACC});
    
    /**
     * @brief 현재 Cartesian 위치 획득 (공식 예제의 get_current_posx와 동일)
     * @return 현재 Cartesian 좌표
     */
    CartesianPos get_current_posx();
    
    /**
     * @brief 현재 Joint 위치 획득
     * @return 현재 Joint 좌표
     */
    JointPos get_current_posj();
    
    /**
     * @brief 모션 완료 대기 (공식 예제 패턴)
     * @return 성공 여부
     */
    bool wait_motion_complete();
    
    /**
     * @brief 로봇 상태 확인
     * @return 로봇 상태
     */
    DRAFramework::ROBOT_STATE get_robot_state();
    
    /**
     * @brief 비상 정지
     */
    void emergency_stop();

private:
    // DRFL 인터페이스
    std::unique_ptr<DRAFramework::CDRFLEx> drfl_;
    
    // 로봇 설정
    std::string robot_id_;
    std::string robot_model_;
    std::string robot_ip_;
    
    // 연결 상태
    bool connected_;
    
    /**
     * @brief 로봇 상태 체크
     * @return 작업 가능 상태 여부
     */
    bool check_robot_ready();
    
    /**
     * @brief Cartesian 좌표를 DRFL 형식으로 변환
     */
    void convert_to_drfl_pos(const CartesianPos& pos, float drfl_pos[6]);
    
    /**
     * @brief Joint 좌표를 DRFL 형식으로 변환
     */
    void convert_to_drfl_joint(const JointPos& pos, float drfl_pos[6]);
};

} // namespace sugar_water_experiment
