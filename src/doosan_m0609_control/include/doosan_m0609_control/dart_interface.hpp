#pragma once

#include <array>
#include <string>
#include <mutex>
#include <cstdint>
#include <rclcpp/rclcpp.hpp>

// DRFL API 포함
#include <DRFL.h>

// DRFL 네임스페이스 사용
using namespace DRAFramework;

/**
 * @brief Doosan M0609 로봇을 위한 DRFL API 래퍼 클래스
 * 
 * 이 클래스는 두산 DRFL API를 ROS2 인터페이스에 맞게 래핑하여
 * 안전하고 사용하기 쉬운 로봇 제어 인터페이스를 제공합니다.
 */
class DartInterface {
public:
    /**
     * @brief 생성자
     */
    DartInterface();
    
    /**
     * @brief 소멸자 - 안전한 연결 해제
     */
    ~DartInterface();

    // ==========================================================================
    // 연결 관리
    // ==========================================================================
    
    /**
     * @brief 로봇에 연결하고 제어권 요청
     * @param host 로봇 IP 주소
     * @param port 로봇 포트 (기본값: 12345)
     * @return 연결 성공 여부
     */
    bool connect(const std::string& host, int port = 12345);
    
    /**
     * @brief 로봇 연결 해제
     * @return 해제 성공 여부
     */
    bool disconnect();
    
    /**
     * @brief 연결 상태 확인
     * @return 연결 상태
     */
    bool isConnected() const;

    // ==========================================================================
    // 모션 제어 (두산 공식 srv 호환)
    // ==========================================================================
    
    /**
     * @brief 관절 공간에서 점 대 점 이동 (MoveJ)
     * @param joint_target 목표 관절 위치 [rad] (6개 관절)
     * @param vel 속도 [deg/sec] (기본값: 60)
     * @param acc 가속도 [deg/sec²] (기본값: 200)
     * @param time 시간 [sec] (기본값: 0, 속도 기반)
     * @param mode 이동 모드 (기본값: 절대 좌표)
     * @param blend_radius 블렌딩 반지름 [mm] (기본값: 0)
     * @return 명령 성공 여부
     */
    bool moveJ(const std::array<double, 6>& joint_target, 
               double vel = 60.0, double acc = 200.0, double time = 0.0,
               int mode = 0, double blend_radius = 0.0);
    
    /**
     * @brief 태스크 공간에서 직선 이동 (MoveL)
     * @param pose_target 목표 포즈 [mm, mm, mm, rad, rad, rad] (6D 포즈)
     * @param vel 선형 속도 [mm/sec] (기본값: 50)
     * @param ang_vel 각속도 [deg/sec] (기본값: 30)
     * @param acc 선형 가속도 [mm/sec²] (기본값: 100)
     * @param ang_acc 각가속도 [deg/sec²] (기본값: 60)
     * @return 명령 성공 여부
     */
    bool moveL(const std::array<double, 6>& pose_target,
               double vel = 50.0, double ang_vel = 30.0, 
               double acc = 100.0, double ang_acc = 60.0);
    
    /**
     * @brief 블렌딩을 적용한 관절 이동
     * @param target 목표 관절 위치 [rad]
     * @param blend_radius 블렌딩 반지름 [mm]
     * @return 명령 성공 여부
     */
    bool moveJointBlend(const std::array<double, 6>& target, double blend_radius);
    
    /**
     * @brief 홈 위치로 이동
     * @return 명령 성공 여부
     */
    bool goHome();

    // ==========================================================================
    // 모션 제어 중단
    // ==========================================================================
    
    /**
     * @brief 로봇 모션 정지 (일반 정지)
     * @return 명령 성공 여부
     */
    bool stop();
    
    /**
     * @brief 비상 정지
     * @return 명령 성공 여부
     */
    bool emergencyStop();

    // ==========================================================================
    // 상태 조회
    // ==========================================================================
    
    /**
     * @brief 현재 관절 위치 조회
     * @return 관절 위치 [rad] (6개 관절)
     */
    std::array<double, 6> getJointPosition();
    
    /**
     * @brief 현재 태스크 위치 조회  
     * @return 태스크 포즈 [mm, mm, mm, rad, rad, rad]
     */
    std::array<double, 6> getTaskPosition();
    
    /**
     * @brief 현재 관절 토크 조회
     * @return 관절 토크 [N·m] (6개 관절)
     * @note 현재 미구현 - 모니터링 콜백 필요
     */
    std::array<double, 6> getJointTorque();
    
    /**
     * @brief 로봇 움직임 상태 확인
     * @return 움직임 상태 (true: 움직임 중, false: 정지)
     */
    bool isMoving();
    
    /**
     * @brief 로봇 상태 조회
     * @return 로봇 상태 코드
     * @details
     *   0: STATE_INITIALIZING  1: STATE_STANDBY      2: STATE_MOVING
     *   3: STATE_SAFE_OFF      4: STATE_TEACHING     5: STATE_SAFE_STOP  
     *   6: STATE_EMERGENCY_STOP 7: STATE_HOMMING     8: STATE_RECOVERY
     */
    int8_t getRobotState();

    // ==========================================================================
    // 설정 및 제어
    // ==========================================================================
    
    /**
     * @brief 페이로드 설정
     * @param mass 페이로드 질량 [kg]
     * @return 설정 성공 여부
     * @note 현재 미구현 - ConfigCreateTool 필요
     */
    bool setPayload(double mass);
    
    /**
     * @brief 토크 활성화/비활성화
     * @param onoff 토크 상태 (true: ON, false: OFF)
     * @return 설정 성공 여부
     */
    bool setTorqueOnOff(bool onoff);
    
    /**
     * @brief 알람 해제
     * @return 해제 성공 여부
     */
    bool clearAlarm();

    // ==========================================================================
    // GPIO 제어 (향후 확장용)
    // ==========================================================================
    
    /**
     * @brief 툴 디지털 출력 설정
     * @param index GPIO 인덱스 (0~5)
     * @param value 출력 값 (true: HIGH, false: LOW)
     * @return 설정 성공 여부
     * @note 향후 구현 예정
     */
    bool setToolDigitalOutput(int index, bool value);
    
    /**
     * @brief 툴 디지털 입력 읽기
     * @param index GPIO 인덱스 (0~5)
     * @return 입력 값 (true: HIGH, false: LOW)
     * @note 향후 구현 예정
     */
    bool getToolDigitalInput(int index);
    
    /**
     * @brief 컨트롤박스 디지털 출력 설정
     * @param index GPIO 인덱스 (0~15)
     * @param value 출력 값 (true: HIGH, false: LOW)
     * @return 설정 성공 여부
     * @note 향후 구현 예정
     */
    bool setCtrlBoxDigitalOutput(int index, bool value);
    
    /**
     * @brief 컨트롤박스 디지털 입력 읽기
     * @param index GPIO 인덱스 (0~15)
     * @return 입력 값 (true: HIGH, false: LOW)
     * @note 향후 구현 예정
     */
    bool getCtrlBoxDigitalInput(int index);

private:
    // ==========================================================================
    // 멤버 변수
    // ==========================================================================
    
    /// 스레드 안전을 위한 뮤텍스
    mutable std::mutex m_mutex;
    
    /// DRFL 로봇 제어 객체
    CDRFL m_robot;
    
    /// 연결 상태 플래그
    bool m_connected;

    // ==========================================================================
    // 내부 유틸리티 함수
    // ==========================================================================
    
    /**
     * @brief 실패 시 로그 출력
     * @param success 성공 여부
     * @param context 컨텍스트 문자열
     */
    void logIfFailed(bool success, const std::string& context) const;
    
    /**
     * @brief 관절 각도 유효성 검증
     * @param joints 관절 각도 배열 [rad]
     * @return 유효성 여부
     */
    bool validateJointLimits(const std::array<double, 6>& joints) const;
    
    /**
     * @brief 속도 제한 검증
     * @param velocity 속도 값
     * @return 유효성 여부
     */
    bool validateVelocityLimits(double velocity) const;

    // ==========================================================================
    // 상수 정의
    // ==========================================================================
    
    /// 최대 관절 속도 [deg/sec]
    static constexpr double MAX_JOINT_VEL = 180.0;
    
    /// 최대 관절 가속도 [deg/sec²]
    static constexpr double MAX_JOINT_ACC = 900.0;
    
    /// 관절 각도 제한 [deg]
    static constexpr std::array<double, 6> JOINT_LIMITS = {
        360.0, 360.0, 170.0, 360.0, 360.0, 360.0
    };
    
    /// 최대 선형 속도 [mm/sec]
    static constexpr double MAX_LINEAR_VEL = 1000.0;
    
    /// 최대 각속도 [deg/sec]
    static constexpr double MAX_ANGULAR_VEL = 180.0;
};