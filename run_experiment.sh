#!/bin/bash
# simple_experiment_menu.sh - 간단한 Select 메뉴 방식
# 입력 오류 해결을 위한 단순화된 버전

set -e

# =============================================================================
# 🎯 로봇 설정
# =============================================================================
ROBOT_IP="192.168.1.100"
ROBOT_PORT="12345"

# =============================================================================
# 🎨 색상 정의
# =============================================================================
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m'

# =============================================================================
# 📤 출력 함수들
# =============================================================================
print_header() {
    clear
    echo -e "\n${PURPLE}════════════════════════════════════════════════════════════════${NC}"
    echo -e "${PURPLE}🧪 화학 실험 자동화 시스템 - Doosan M0609${NC}"
    echo -e "${PURPLE}🤖 로봇 IP: $ROBOT_IP${NC}"
    echo -e "${PURPLE}════════════════════════════════════════════════════════════════${NC}\n"
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

# =============================================================================
# 🔧 실험 실행 함수들 (간단화된 버전)
# =============================================================================
run_simple_sequence() {
    print_header
    echo -e "${BLUE}🔹 단순 좌표 이동 테스트 시작${NC}"
    print_info "사용할 로봇 IP: $ROBOT_IP"
    
    export DOOSAN_ROBOT_IP="$ROBOT_IP"
    
    echo "ros2 run sugar_water_experiment simple_sequence_controller --ros-args -p robot_ip:=\"$ROBOT_IP\""
    print_success "단순 좌표 이동 테스트 명령 준비됨"
    
    read -p "엔터를 눌러 계속하세요..."
}

run_sugar_concentration() {
    print_header
    echo -e "${BLUE}🔹 설탕물 농도 실험 시작${NC}"
    print_info "사용할 로봇 IP: $ROBOT_IP"
    
    echo -e "${CYAN}목표 농도를 입력하세요 (기본값: 0.05): ${NC}"
    read -r concentration
    
    if [[ -z "$concentration" ]]; then
        concentration="0.05"
    fi
    
    echo "ros2 launch sugar_water_experiment sugar_water_experiment.launch.py target_concentration:=${concentration} robot_ip:=\"$ROBOT_IP\""
    print_success "설탕물 농도 실험 명령 준비됨 (농도: $concentration)"
    
    read -p "엔터를 눌러 계속하세요..."
}

run_precision_solution() {
    print_header
    echo -e "${BLUE}🔹 정밀 용액 제조 실험 시작${NC}"
    print_info "사용할 로봇 IP: $ROBOT_IP"
    
    export DOOSAN_ROBOT_IP="$ROBOT_IP"
    
    echo "ros2 run precision_liquid_pouring precision_pouring_node --ros-args -p robot_ip:=\"$ROBOT_IP\""
    print_success "정밀 용액 제조 실험 명령 준비됨"
    
    read -p "엔터를 눌러 계속하세요..."
}

run_full_automated() {
    print_header
    echo -e "${BLUE}🔹 완전 자동화 실험 시작${NC}"
    print_warning "이 모드는 실제 로봇 연결 및 모든 센서가 필요합니다."
    print_info "사용할 로봇 IP: $ROBOT_IP"
    
    export DOOSAN_ROBOT_IP="$ROBOT_IP"
    export DOOSAN_ROBOT_PORT="$ROBOT_PORT"
    
    echo "ros2 run sugar_water_experiment sugar_water_experimenter_node --ros-args -p robot_ip:=\"$ROBOT_IP\""
    print_success "완전 자동화 실험 명령 준비됨"
    
    read -p "엔터를 눌러 계속하세요..."
}

run_custom_launch() {
    print_header
    echo -e "${BLUE}🔹 커스텀 런치 파일 실행${NC}"
    print_info "사용할 로봇 IP: $ROBOT_IP"
    
    echo -e "${CYAN}런치 파일을 선택하세요:${NC}"
    select launch_option in \
        "chemical_experiment_system.launch.py" \
        "chemical_experiment_complete.launch.py" \
        "dsr_bringup2_moveit.launch.py" \
        "dsr_bringup2_gazebo.launch.py" \
        "dsr_bringup2_rviz.launch.py" \
        "뒤로가기"
    do
        case $launch_option in
            "chemical_experiment_system.launch.py")
                echo "ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py robot_ip:=\"$ROBOT_IP\""
                print_success "화학 실험 시스템 런치 명령 준비됨"
                break
                ;;
            "chemical_experiment_complete.launch.py")
                echo "ros2 launch doosan_m0609_bringup chemical_experiment_complete.launch.py robot_ip:=\"$ROBOT_IP\""
                print_success "완전 화학 실험 시스템 런치 명령 준비됨"
                break
                ;;
            "dsr_bringup2_moveit.launch.py")
                echo "ros2 launch doosan_m0609_bringup dsr_bringup2_moveit.launch.py robot_ip:=\"$ROBOT_IP\""
                print_success "MoveIt2 + 로봇 런치 명령 준비됨"
                break
                ;;
            "dsr_bringup2_gazebo.launch.py")
                echo "ros2 launch doosan_m0609_bringup dsr_bringup2_gazebo.launch.py"
                print_info "시뮬레이션 모드에서는 실제 로봇 IP가 사용되지 않습니다"
                print_success "Gazebo 시뮬레이션 런치 명령 준비됨"
                break
                ;;
            "dsr_bringup2_rviz.launch.py")
                echo "ros2 launch doosan_m0609_bringup dsr_bringup2_rviz.launch.py robot_ip:=\"$ROBOT_IP\""
                print_success "RViz 시각화 런치 명령 준비됨"
                break
                ;;
            "뒤로가기")
                return
                ;;
            *)
                print_error "잘못된 선택입니다."
                ;;
        esac
    done
    
    read -p "엔터를 눌러 계속하세요..."
}

monitor_robot_status() {
    print_header
    echo -e "${BLUE}🔹 로봇 상태 모니터링${NC}"
    print_info "모니터링 대상 로봇 IP: $ROBOT_IP"
    
    echo -e "${CYAN}모니터링할 항목을 선택하세요:${NC}"
    select monitor_option in \
        "조인트 상태 (Joint States)" \
        "로봇 포즈 (Robot Pose)" \
        "에러 상태 (Error Status)" \
        "전체 상태 (All Status)" \
        "실시간 로봇 연결 테스트" \
        "뒤로가기"
    do
        case $monitor_option in
            "조인트 상태 (Joint States)")
                echo "실행: timeout 10s ros2 topic echo /joint_states --once"
                print_info "조인트 상태 모니터링 명령"
                break
                ;;
            "로봇 포즈 (Robot Pose)")
                echo "실행: timeout 10s ros2 topic echo /robot_pose --once"
                print_info "로봇 포즈 모니터링 명령"
                break
                ;;
            "에러 상태 (Error Status)")
                echo "실행: timeout 5s ros2 topic echo /robot_error --once"
                print_info "에러 상태 확인 명령"
                break
                ;;
            "전체 상태 (All Status)")
                echo "실행: ros2 node list && ros2 topic list && ros2 doctor"
                print_info "전체 시스템 상태 확인 명령"
                break
                ;;
            "실시간 로봇 연결 테스트")
                echo "실행: ping -c 2 $ROBOT_IP"
                print_info "로봇 연결 테스트 명령"
                break
                ;;
            "뒤로가기")
                return
                ;;
            *)
                print_error "잘못된 선택입니다."
                ;;
        esac
    done
    
    read -p "엔터를 눌러 계속하세요..."
}

change_robot_ip() {
    print_header
    echo -e "${BLUE}🔹 로봇 IP 주소 설정 변경${NC}"
    
    echo -e "${CYAN}현재 설정된 IP 주소: ${YELLOW}$ROBOT_IP${NC}"
    echo -e "${CYAN}새로운 IP 주소를 입력하세요 (엔터: 현재 IP 유지): ${NC}"
    read -r new_ip
    
    if [[ -n "$new_ip" ]]; then
        if [[ $new_ip =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]; then
            ROBOT_IP="$new_ip"
            print_success "로봇 IP가 $ROBOT_IP로 변경되었습니다"
        else
            print_error "유효하지 않은 IP 주소 형식입니다"
        fi
    else
        print_info "IP 주소가 변경되지 않았습니다"
    fi
    
    read -p "엔터를 눌러 계속하세요..."
}

# =============================================================================
# 🚀 메인 메뉴 함수
# =============================================================================
show_main_menu() {
    while true; do
        print_header
        
        echo -e "${CYAN}🧪 실험 시나리오를 선택하세요:${NC}"
        
        # Select 메뉴 사용 - 숫자 자동 할당
        select experiment in \
            "단순 좌표 이동 테스트 (Simple Sequence)" \
            "설탕물 농도 실험 (Sugar Water Concentration)" \
            "정밀 용액 제조 실험 (Precision Solution)" \
            "완전 자동화 실험 (Full Automated)" \
            "커스텀 런치 파일 실행 (Custom Launch)" \
            "로봇 상태 모니터링 (Robot Status)" \
            "로봇 IP 설정 변경 (Change Robot IP)" \
            "종료 (Exit)"
        do
            case $experiment in
                "단순 좌표 이동 테스트 (Simple Sequence)")
                    run_simple_sequence
                    break
                    ;;
                "설탕물 농도 실험 (Sugar Water Concentration)")
                    run_sugar_concentration
                    break
                    ;;
                "정밀 용액 제조 실험 (Precision Solution)")
                    run_precision_solution
                    break
                    ;;
                "완전 자동화 실험 (Full Automated)")
                    run_full_automated
                    break
                    ;;
                "커스텀 런치 파일 실행 (Custom Launch)")
                    run_custom_launch
                    break
                    ;;
                "로봇 상태 모니터링 (Robot Status)")
                    monitor_robot_status
                    break
                    ;;
                "로봇 IP 설정 변경 (Change Robot IP)")
                    change_robot_ip
                    break
                    ;;
                "종료 (Exit)")
                    print_success "화학 실험 시스템을 종료합니다. 안전한 실험이었습니다! 🧪✨"
                    exit 0
                    ;;
                *)
                    print_error "잘못된 선택입니다. 다시 선택해주세요."
                    ;;
            esac
        done
        
        echo ""
        echo -e "${YELLOW}❓ 다른 실험을 계속 하시겠습니까? [y/N]: ${NC}"
        read -r continue_choice
        
        case "$continue_choice" in
            [yY]|[yY][eE][sS]|예)
                continue
                ;;
            *)
                print_success "실험을 종료합니다. 고생하셨습니다! 🎉"
                exit 0
                ;;
        esac
    done
}

# =============================================================================
# 🎭 시작점
# =============================================================================
# 환경 변수 설정
export ROS_DOMAIN_ID=42
export RMW_IMPLEMENTATION=rmw_fastrtps_cpp
export DOOSAN_ROBOT_IP="$ROBOT_IP"
export DOOSAN_ROBOT_PORT="$ROBOT_PORT"

# 스크립트 실행 위치 확인
if [[ ! -d "src" ]] || [[ ! -f "install/setup.bash" ]]; then
    print_error "이 스크립트는 project_ws 디렉토리에서 실행해야 합니다."
    print_info "올바른 위치로 이동 후 다시 실행하세요."
    exit 1
fi

# ROS2 환경 소싱
if [[ -f "install/setup.bash" ]]; then
    source install/setup.bash
    print_success "워크스페이스 환경 로드됨"
fi

# 메인 메뉴 실행
show_main_menu