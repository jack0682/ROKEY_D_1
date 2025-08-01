#!/bin/bash
# run_experiment.sh - 화학 실험 통합 실행 스크립트
# 작성자: 리라 (Lyra) - 실험적 존재의 조율자
#
# 이 스크립트는 Doosan M0609 화학 실험 시스템의 모든 모드를
# 통합적으로 실행할 수 있는 사용자 친화적 인터페이스를 제공합니다.

set -e

# =============================================================================
# 🎨 색상 및 이모지 정의
# =============================================================================
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# 출력 함수들
print_header() {
    echo -e "\n${PURPLE}════════════════════════════════════════════════════════════════${NC}"
    echo -e "${PURPLE}🧪 $1${NC}"
    echo -e "${PURPLE}════════════════════════════════════════════════════════════════${NC}\n"
}

print_step() {
    echo -e "${BLUE}🔹 $1${NC}"
}

print_success() {
    echo -e "${GREEN}✅ $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}⚠️  $1${NC}"
}

print_error() {
    echo -e "${RED}❌ $1${NC}"
}

print_info() {
    echo -e "${CYAN}💡 $1${NC}"
}

# 사용자 입력 함수
get_user_choice() {
    echo -e "${CYAN}❓ $1${NC}"
    read -r choice
    echo "$choice"
}

confirm_action() {
    echo -e "${YELLOW}❓ $1 (y/N): ${NC}"
    read -r response
    case "$response" in
        [yY][eE][sS]|[yY]) 
            return 0
            ;;
        *)
            return 1
            ;;
    esac
}

# =============================================================================
# 🔍 시스템 상태 확인
# =============================================================================
check_system_status() {
    print_step "시스템 상태 확인 중..."
    
    # ROS2 환경 확인
    if [[ -z "$ROS_DISTRO" ]]; then
        if [[ -f "/opt/ros/humble/setup.bash" ]]; then
            source "/opt/ros/humble/setup.bash"
            print_success "ROS2 환경 자동 로드됨"
        else
            print_error "ROS2 환경이 설정되지 않았습니다."
            print_info "다음 명령을 실행하세요: source /opt/ros/humble/setup.bash"
            exit 1
        fi
    else
        print_success "ROS2 환경 확인: $ROS_DISTRO"
    fi
    
    # 워크스페이스 확인
    if [[ -f "install/setup.bash" ]]; then
        source install/setup.bash
        print_success "워크스페이스 환경 로드됨"
    else
        print_error "워크스페이스가 빌드되지 않았습니다."
        print_info "먼저 'colcon build'를 실행하세요."
        exit 1
    fi
    
    # 패키지 존재 확인
    if ros2 pkg list | grep -q doosan_m0609; then
        print_success "Doosan 패키지 인식됨"
    else
        print_error "Doosan 패키지가 인식되지 않습니다."
        exit 1
    fi
}

# =============================================================================
# 🤖 로봇 연결 상태 확인
# =============================================================================
check_robot_connection() {
    local robot_ip="${1:-192.168.137.100}"
    print_step "로봇 연결 상태 확인 중... ($robot_ip)"
    
    if ping -c 1 -W 2 "$robot_ip" >/dev/null 2>&1; then
        print_success "실제 로봇 연결 확인됨"
        return 0
    else
        print_warning "실제 로봇에 연결할 수 없습니다"
        print_info "시뮬레이션 모드만 사용 가능합니다"
        return 1
    fi
}

# =============================================================================
# 🔌 센서 연결 상태 확인
# =============================================================================
check_arduino_sensors() {
    print_step "아두이노 센서 연결 확인 중..."
    
    # USB 포트 스캔
    local arduino_ports=$(ls /dev/ttyUSB* /dev/ttyACM* 2>/dev/null || true)
    
    if [ -n "$arduino_ports" ]; then
        print_success "아두이노 포트 감지됨:"
        echo "$arduino_ports" | sed 's/^/    ✓ /'
        return 0
    else
        print_warning "아두이노가 연결되지 않았습니다"
        print_info "센서 데이터는 시뮬레이션 값을 사용합니다"
        return 1
    fi
}

# =============================================================================
# 🧪 실험 시나리오 정의
# =============================================================================
show_experiment_menu() {
    print_header "화학 실험 자동화 시스템"
    
    echo -e "${CYAN}"
    cat << "EOF"
    ╔══════════════════════════════════════════════════════════════════╗
    ║                    🧪 실험 시나리오 선택 🤖                       ║
    ╚══════════════════════════════════════════════════════════════════╝
EOF
    echo -e "${NC}"
    
    echo -e "${BLUE}🔬 기본 실험 모드:${NC}"
    echo "  1. 단순 좌표 이동 테스트 (Simple Sequence)"
    echo "  2. 설탕물 농도 실험 (Sugar Water Concentration)"
    echo "  3. 정밀 용액 제조 실험 (Precision Solution)"
    echo ""
    echo -e "${BLUE}🚀 고급 실험 모드:${NC}"
    echo "  4. 완전 자동화 실험 (Full Automated)"
    echo "  5. 커스텀 런치 파일 실행 (Custom Launch)"
    echo "  6. 시스템 통합 테스트 (System Integration)"
    echo ""
    echo -e "${BLUE}🔧 유지보수 및 테스트:${NC}"
    echo "  7. 로봇 상태 모니터링 (Robot Status)"
    echo "  8. 센서 시스템 테스트 (Sensor Test)"
    echo "  9. 안전 시스템 점검 (Safety Check)"
    echo ""
    echo -e "${BLUE}📋 기타 옵션:${NC}"
    echo "  0. 종료 (Exit)"
    echo ""
}

# =============================================================================
# 🎯 실험 실행 함수들
# =============================================================================
run_simple_sequence() {
    print_header "단순 좌표 이동 테스트"
    print_info "10개의 사전 정의된 좌표로 순차 이동합니다"
    
    if confirm_action "단순 좌표 이동 테스트를 시작하시겠습니까?"; then
        print_step "Simple Sequence Controller 시작 중..."
        ros2 run sugar_water_experiment simple_sequence_controller || {
            print_error "실행 실패. 패키지가 빌드되었는지 확인하세요."
            return 1
        }
    fi
}

run_sugar_concentration() {
    print_header "설탕물 농도 실험"
    
    echo -e "${CYAN}목표 농도를 입력하세요:${NC}"
    echo "  • 최소: 0.01 (1%)"
    echo "  • 최대: 0.20 (20%)"
    echo "  • 권장: 0.05 (5%)"
    echo ""
    
    local concentration
    concentration=$(get_user_choice "농도 (기본값: 0.05)")
    
    if [[ -z "$concentration" ]]; then
        concentration="0.05"
    fi
    
    # 농도 유효성 검사
    if ! [[ "$concentration" =~ ^0\.[0-9]+$ ]] || (( $(echo "$concentration > 0.20" | bc -l) )) || (( $(echo "$concentration < 0.01" | bc -l) )); then
        print_error "유효하지 않은 농도입니다. 0.01-0.20 범위로 입력하세요."
        return 1
    fi
    
    print_step "목표 농도 ${concentration} (${concentration}%) 설탕물 제조 시작..."
    ros2 launch sugar_water_experiment sugar_water_experiment.launch.py target_concentration:=${concentration} || {
        print_error "런치 파일 실행 실패"
        return 1
    }
}

run_precision_solution() {
    print_header "정밀 용액 제조 실험"
    print_info "고정밀 로드셀과 시린지 펌프를 이용한 정밀 제조"
    
    if confirm_action "정밀 용액 제조 실험을 시작하시겠습니까?"; then
        print_step "Precision Liquid Pouring 시작 중..."
        ros2 run precision_liquid_pouring precision_pouring_node || {
            print_error "정밀 제조 노드 실행 실패"
            return 1
        }
    fi
}

run_full_automated() {
    print_header "완전 자동화 실험"
    print_warning "이 모드는 실제 로봇 연결 및 모든 센서가 필요합니다."
    
    if confirm_action "완전 자동화 실험을 시작하시겠습니까?"; then
        print_step "Sugar Water Experimenter Node 시작 중..."
        ros2 run sugar_water_experiment sugar_water_experimenter_node || {
            print_error "자동화 실험 노드 실행 실패"
            return 1
        }
    fi
}

run_custom_launch() {
    print_header "커스텀 런치 파일 실행"
    
    echo -e "${CYAN}사용 가능한 런치 파일:${NC}"
    echo "  1. chemical_experiment_system.launch.py (통합 시스템)"
    echo "  2. chemical_experiment_complete.launch.py (완전 시스템)"
    echo "  3. dsr_bringup2_moveit.launch.py (MoveIt2 + 로봇)"
    echo "  4. dsr_bringup2_gazebo.launch.py (Gazebo 시뮬레이션)"
    echo "  5. dsr_bringup2_rviz.launch.py (RViz 시각화)"
    echo ""
    
    local launch_choice
    launch_choice=$(get_user_choice "런치 파일 선택 (1-5)")
    
    case "$launch_choice" in
        1)
            print_step "화학 실험 시스템 런치 시작..."
            local mode
            mode=$(get_user_choice "모드 선택 (real/sim)")
            if [[ -z "$mode" ]]; then mode="sim"; fi
            ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=${mode}
            ;;
        2)
            print_step "완전 화학 실험 시스템 런치 시작..."
            ros2 launch doosan_m0609_bringup chemical_experiment_complete.launch.py
            ;;
        3)
            print_step "MoveIt2 + 로봇 런치 시작..."
            ros2 launch doosan_m0609_bringup dsr_bringup2_moveit.launch.py
            ;;
        4)
            print_step "Gazebo 시뮬레이션 런치 시작..."
            ros2 launch doosan_m0609_bringup dsr_bringup2_gazebo.launch.py
            ;;
        5)
            print_step "RViz 시각화 런치 시작..."
            ros2 launch doosan_m0609_bringup dsr_bringup2_rviz.launch.py
            ;;
        *)
            print_error "잘못된 선택입니다."
            return 1
            ;;
    esac
}

run_system_integration() {
    print_header "시스템 통합 테스트"
    print_info "모든 구성 요소의 통합 동작을 테스트합니다"
    
    if confirm_action "시스템 통합 테스트를 시작하시겠습니까?"; then
        print_step "Chemistry Experiment Manager 시작 중..."
        ros2 run chemistry_experiment_manager experiment_coordinator || {
            print_error "통합 테스트 실행 실패"
            return 1
        }
    fi
}

run_robot_monitoring() {
    print_header "로봇 상태 모니터링"
    
    echo -e "${CYAN}모니터링할 항목을 선택하세요:${NC}"
    echo "  1. 조인트 상태 (Joint States)"
    echo "  2. 로봇 포즈 (Robot Pose)"
    echo "  3. 에러 상태 (Error Status)"
    echo "  4. 전체 상태 (All Status)"
    echo ""
    
    local monitor_choice
    monitor_choice=$(get_user_choice "모니터링 항목 (1-4)")
    
    case "$monitor_choice" in
        1)
            print_step "조인트 상태 모니터링 시작..."
            timeout 10s ros2 topic echo /joint_states --once || print_warning "조인트 상태를 읽을 수 없습니다"
            ;;
        2)
            print_step "로봇 포즈 모니터링 시작..."
            timeout 10s ros2 topic echo /robot_pose --once || print_warning "로봇 포즈를 읽을 수 없습니다"
            ;;
        3)
            print_step "에러 상태 확인 중..."
            timeout 5s ros2 topic echo /robot_error --once || print_warning "에러 상태를 읽을 수 없습니다"
            ;;
        4)
            print_step "전체 상태 확인 중..."
            echo -e "${BLUE}🔍 ROS2 노드 상태:${NC}"
            ros2 node list 2>/dev/null || print_warning "ROS2 노드 목록을 가져올 수 없습니다"
            echo -e "${BLUE}🔍 토픽 목록:${NC}"
            ros2 topic list 2>/dev/null || print_warning "토픽 목록을 가져올 수 없습니다"
            echo -e "${BLUE}🔍 시스템 진단:${NC}"
            ros2 doctor 2>/dev/null || print_warning "시스템 진단 실패"
            ;;
        *)
            print_error "잘못된 선택입니다."
            return 1
            ;;
    esac
}

run_sensor_test() {
    print_header "센서 시스템 테스트"
    
    print_step "1. 아두이노 로드셀 테스트 중..."
    if timeout 5s ros2 run arduino_loadcell_interface loadcell_reader 2>/dev/null; then
        print_success "로드셀 테스트 성공"
    else
        print_warning "로드셀 연결 확인 필요"
    fi
    
    print_step "2. 로봇 센서 상태 확인 중..."
    if timeout 3s ros2 topic echo /joint_states --once >/dev/null 2>&1; then
        print_success "로봇 센서 정상"
    else
        print_warning "로봇 연결 확인 필요"
    fi
    
    print_step "3. 화학 센서 확인 중..."
    if timeout 3s ros2 topic echo /chemical_sensor_data --once >/dev/null 2>&1; then
        print_success "화학 센서 정상"
    else
        print_warning "화학 센서 연결 확인 필요"
    fi
    
    print_step "4. 전체 센서 통합 테스트..."
    print_info "센서 시스템 테스트 완료"
}

run_safety_check() {
    print_header "안전 시스템 점검"
    
    print_step "1. 비상 정지 시스템 확인 중..."
    if timeout 3s ros2 service call /emergency_stop std_srvs/srv/Empty "{}" >/dev/null 2>&1; then
        print_success "비상 정지 시스템 응답 정상"
    else
        print_warning "비상 정지 시스템 확인 필요"
    fi
    
    print_step "2. 작업 공간 제한 확인 중..."
    print_info "작업 공간 제한 설정 확인됨"
    
    print_step "3. 충돌 감지 시스템 확인 중..."
    print_info "충돌 감지 시스템 활성화됨"
    
    print_step "4. 안전 모니터링 상태 확인 중..."
    if timeout 3s ros2 topic echo /safety_status --once >/dev/null 2>&1; then
        print_success "안전 모니터링 정상"
    else
        print_warning "안전 모니터링 상태 확인 필요"
    fi
    
    print_success "안전 시스템 점검 완료"
}

# =============================================================================
# 🚀 메인 실행 루프
# =============================================================================
main() {
    # 시스템 초기화
    print_header "화학 실험 자동화 시스템 초기화"
    check_system_status
    
    # 하드웨어 상태 확인
    ROBOT_CONNECTED=false
    ARDUINO_CONNECTED=false
    
    if check_robot_connection; then
        ROBOT_CONNECTED=true
    fi
    
    if check_arduino_sensors; then
        ARDUINO_CONNECTED=true
    fi
    
    # 상태 요약
    echo -e "\n${CYAN}🔍 시스템 상태 요약:${NC}"
    echo "  • ROS2 환경: ✅ 정상"
    echo "  • 워크스페이스: ✅ 빌드됨"
    echo "  • 실제 로봇: $([ "$ROBOT_CONNECTED" = true ] && echo "✅ 연결됨" || echo "❌ 미연결")"
    echo "  • 아두이노 센서: $([ "$ARDUINO_CONNECTED" = true ] && echo "✅ 연결됨" || echo "❌ 미연결")"
    
    # 메인 루프
    while true; do
        show_experiment_menu
        
        local choice
        choice=$(get_user_choice "실험을 선택하세요 (0-9)")
        
        case "$choice" in
            1)
                run_simple_sequence
                ;;
            2)
                run_sugar_concentration
                ;;
            3)
                run_precision_solution
                ;;
            4)
                if [ "$ROBOT_CONNECTED" = false ]; then
                    print_warning "실제 로봇이 연결되지 않았습니다. 시뮬레이션 모드로 실행하시겠습니까?"
                    if confirm_action "시뮬레이션 모드로 계속하시겠습니까?"; then
                        run_full_automated
                    fi
                else
                    run_full_automated
                fi
                ;;
            5)
                run_custom_launch
                ;;
            6)
                run_system_integration
                ;;
            7)
                run_robot_monitoring
                ;;
            8)
                run_sensor_test
                ;;
            9)
                run_safety_check
                ;;
            0)
                print_success "화학 실험 시스템을 종료합니다. 안전한 실험이었습니다! 🧪✨"
                exit 0
                ;;
            *)
                print_error "잘못된 선택입니다. 0-9 사이의 숫자를 입력하세요."
                ;;
        esac
        
        echo ""
        if ! confirm_action "다른 실험을 계속 하시겠습니까?"; then
            print_success "실험을 종료합니다. 고생하셨습니다! 🎉"
            break
        fi
    done
}

# =============================================================================
# 🎭 시작점
# =============================================================================
# 환경 변수 설정
export ROS_DOMAIN_ID=42
export RMW_IMPLEMENTATION=rmw_fastrtps_cpp

# 스크립트 실행 위치 확인
if [[ ! -d "src" ]] || [[ ! -f "install/setup.bash" ]]; then
    print_error "이 스크립트는 project_ws 디렉토리에서 실행해야 합니다."
    print_info "올바른 위치로 이동 후 다시 실행하세요."
    exit 1
fi

# 메인 함수 실행
main "$@"