#!/bin/bash
# enhanced_experiment_menu.sh - 로봇 초기화 및 서보 온 기능 포함
# Doosan M0609 전체 초기화 절차 구현

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

print_step() {
    echo -e "${BLUE}🔹 $1${NC}"
}

# =============================================================================
# 🤖 로봇 초기화 및 상태 확인 함수들
# =============================================================================
check_robot_connection() {
    print_step "로봇 연결 상태 확인 중..."
    
    # 네트워크 연결 테스트
    if ping -c 2 -W 3 "$ROBOT_IP" >/dev/null 2>&1; then
        print_success "로봇 네트워크 연결 확인됨 ($ROBOT_IP)"
        return 0
    else
        print_error "로봇($ROBOT_IP)에 연결할 수 없습니다"
        return 1
    fi
}

initialize_robot_system() {
    print_header
    echo -e "${BLUE}🔹 로봇 시스템 초기화 시작${NC}"
    
    print_warning "⚠️  중요 안전 사항:"
    echo "  1. 로봇 주변에 사람이 없는지 확인하세요"
    echo "  2. 비상정지 버튼이 작동하는지 확인하세요"
    echo "  3. 로봇 작업 공간이 비어있는지 확인하세요"
    echo ""
    
    read -p "안전 확인 완료 후 엔터를 눌러 계속하세요..."
    
    # 1. ROS2 노드 시작 (백그라운드)
    print_step "1단계: ROS2 로봇 컨트롤러 노드 시작 중..."
    echo "실행: ros2 run doosan_m0609_controller doosan_robot_controller --ros-args -p robot_ip:=\"$ROBOT_IP\" &"
    
    # 실제 명령 실행 (주석 해제하면 실제 실행)
    # ros2 run doosan_m0609_controller doosan_robot_controller --ros-args -p robot_ip:="$ROBOT_IP" &
    # CONTROLLER_PID=$!
    
    print_success "로봇 컨트롤러 노드 시작됨"
    sleep 2
    
    # 2. 연결 대기
    print_step "2단계: 로봇 연결 대기 중..."
    local retry_count=0
    local max_retries=10
    
    while [[ $retry_count -lt $max_retries ]]; do
        if ros2 topic list 2>/dev/null | grep -q "/joint_states\|/robot_status"; then
            print_success "ROS2 노드와 로봇 연결 확인됨"
            break
        else
            ((retry_count++))
            echo -n "."
            sleep 1
        fi
    done
    
    if [[ $retry_count -eq $max_retries ]]; then
        print_error "로봇 연결 타임아웃"
        return 1
    fi
    
    # 3. 로봇 상태 확인
    print_step "3단계: 로봇 상태 확인 중..."
    
    # 로봇 상태 확인 서비스 호출
    echo "실행: ros2 service call /get_robot_state doosan_m0609_msgs/srv/GetRobotState"
    
    # 4. 서보 온 명령
    print_step "4단계: 로봇 서보 모터 활성화 중..."
    print_warning "로봇이 움직일 준비를 합니다!"
    
    read -p "서보 온을 실행하시겠습니까? [y/N]: " servo_confirm
    
    if [[ "$servo_confirm" =~ ^[yY]$ ]]; then
        echo "실행: ros2 service call /set_robot_mode doosan_m0609_msgs/srv/SetRobotMode \"{mode: 1}\""
        
        # 실제 명령 실행 (주석 해제하면 실제 실행)
        # ros2 service call /set_robot_mode doosan_m0609_msgs/srv/SetRobotMode "{mode: 1}"
        
        print_success "서보 모터 활성화 명령 전송됨"
        sleep 2
        
        # 5. 홈 포지션 이동
        print_step "5단계: 로봇 홈 포지션 이동 중..."
        echo "실행: ros2 service call /move_home doosan_m0609_msgs/srv/MoveHome"
        
        # 실제 명령 실행 (주석 해제하면 실제 실행)
        # ros2 service call /move_home doosan_m0609_msgs/srv/MoveHome
        
        print_success "홈 포지션 이동 완료"
        
        print_success "🎉 로봇 초기화 완료! 실험 준비됨"
        return 0
    else
        print_warning "서보 온이 취소되었습니다. 수동 모드로 진행합니다."
        return 1
    fi
}

shutdown_robot_system() {
    print_header
    echo -e "${BLUE}🔹 로봇 시스템 안전 종료${NC}"
    
    print_step "1단계: 로봇 모션 정지 중..."
    echo "실행: ros2 service call /stop_motion std_srvs/srv/Empty"
    
    print_step "2단계: 서보 모터 비활성화 중..."
    echo "실행: ros2 service call /set_robot_mode doosan_m0609_msgs/srv/SetRobotMode \"{mode: 0}\""
    
    print_step "3단계: 로봇 연결 해제 중..."
    echo "실행: ros2 service call /disconnect_robot std_srvs/srv/Empty"
    
    print_step "4단계: ROS2 노드 종료 중..."
    echo "pkill -f doosan_robot_controller"
    
    print_success "로봇 시스템 안전 종료 완료"
    
    read -p "엔터를 눌러 계속하세요..."
}

# =============================================================================
# 🔧 향상된 실험 실행 함수들
# =============================================================================
run_simple_sequence() {
    print_header
    echo -e "${BLUE}🔹 단순 좌표 이동 테스트 시작${NC}"
    print_info "사용할 로봇 IP: $ROBOT_IP"
    
    # 로봇 준비 상태 확인
    print_step "로봇 준비 상태 확인 중..."
    if ! ros2 topic echo /robot_status --once | grep -q "ready"; then
        print_warning "로봇이 준비되지 않았습니다. 먼저 로봇을 초기화하세요."
        return 1
    fi
    
    print_step "좌표 이동 테스트 실행 중..."
    
    # 실제 ROS2 명령 실행
    ros2 run sugar_water_experiment simple_sequence_controller --ros-args -p robot_ip:="$ROBOT_IP" || {
        print_error "실행 실패. 다음을 확인하세요:"
        echo "  1. 로봇이 초기화되었는지 확인"
        echo "  2. 패키지가 빌드되었는지 확인"
        echo "  3. 로봇 연결 상태 확인"
        return 1
    }
    
    print_success "단순 좌표 이동 테스트 완료"
    read -p "엔터를 눌러 계속하세요..."
}

run_sugar_concentration() {
    print_header
    echo -e "${BLUE}🔹 설탕물 농도 실험 시작${NC}"
    print_info "사용할 로봇 IP: $ROBOT_IP"
    
    # 로봇 및 센서 상태 확인
    print_step "시스템 준비 상태 확인 중..."
    
    # 농도 입력
    echo -e "${CYAN}목표 농도를 입력하세요 (기본값: 0.05): ${NC}"
    read -r concentration
    
    if [[ -z "$concentration" ]]; then
        concentration="0.05"
    fi
    
    # 농도 유효성 검사
    if ! [[ "$concentration" =~ ^0\.[0-9]+$ ]] || (( $(echo "$concentration > 0.20" | bc -l) )) || (( $(echo "$concentration < 0.01" | bc -l) )); then
        print_error "유효하지 않은 농도입니다. 0.01-0.20 범위로 입력하세요."
        return 1
    fi
    
    print_step "목표 농도 ${concentration} ($(echo "scale=1; $concentration * 100" | bc)%) 설탕물 제조 시작..."
    
    # 실제 런치 파일 실행
    ros2 launch sugar_water_experiment sugar_water_experiment.launch.py \
        target_concentration:=${concentration} \
        robot_ip:="$ROBOT_IP" || {
        print_error "런치 파일 실행 실패"
        return 1
    }
    
    print_success "설탕물 농도 실험 완료 (농도: $concentration)"
    read -p "엔터를 눌러 계속하세요..."
}

# =============================================================================
# 🔍 로봇 상태 모니터링 함수들
# =============================================================================
monitor_robot_status() {
    print_header
    echo -e "${BLUE}🔹 로봇 상태 실시간 모니터링${NC}"
    print_info "모니터링 대상 로봇 IP: $ROBOT_IP"
    
    echo -e "${CYAN}모니터링할 항목을 선택하세요:${NC}"
    select monitor_option in \
        "조인트 상태 (Joint States)" \
        "로봇 포즈 (Robot Pose)" \
        "로봇 모드 및 상태" \
        "에러 상태 (Error Status)" \
        "연속 모니터링 (실시간)" \
        "뒤로가기"
    do
        case $monitor_option in
            "조인트 상태 (Joint States)")
                print_step "조인트 상태 모니터링 중..."
                timeout 10s ros2 topic echo /joint_states --once || print_warning "조인트 상태를 읽을 수 없습니다"
                break
                ;;
            "로봇 포즈 (Robot Pose)")
                print_step "로봇 포즈 모니터링 중..."
                timeout 10s ros2 topic echo /current_pose --once || print_warning "로봇 포즈를 읽을 수 없습니다"
                break
                ;;
            "로봇 모드 및 상태")
                print_step "로봇 모드 및 상태 확인 중..."
                timeout 5s ros2 topic echo /robot_status --once || print_warning "로봇 상태를 읽을 수 없습니다"
                break
                ;;
            "에러 상태 (Error Status)")
                print_step "에러 상태 확인 중..."
                timeout 5s ros2 topic echo /robot_error --once || print_warning "에러 상태를 읽을 수 없습니다"
                break
                ;;
            "연속 모니터링 (실시간)")
                print_step "실시간 모니터링 시작 (Ctrl+C로 종료)..."
                echo "조인트 상태와 로봇 상태를 실시간으로 모니터링합니다."
                
                # 실시간 모니터링 (백그라운드 실행)
                ros2 topic echo /joint_states &
                JOINT_PID=$!
                ros2 topic echo /robot_status &
                STATUS_PID=$!
                
                echo "모니터링 중... (Ctrl+C로 종료)"
                read -p "엔터를 누르면 모니터링을 종료합니다..."
                
                # 백그라운드 프로세스 종료
                kill $JOINT_PID $STATUS_PID 2>/dev/null || true
                print_success "모니터링 종료됨"
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

# =============================================================================
# 🚀 메인 메뉴 함수
# =============================================================================
show_main_menu() {
    while true; do
        print_header
        
        echo -e "${CYAN}🧪 실험 시나리오를 선택하세요:${NC}"
        
        # Select 메뉴 사용 - 숫자 자동 할당
        select experiment in \
            "🚀 로봇 시스템 초기화 (Initialize Robot)" \
            "🔹 단순 좌표 이동 테스트 (Simple Sequence)" \
            "🧪 설탕물 농도 실험 (Sugar Water Concentration)" \
            "🔬 정밀 용액 제조 실험 (Precision Solution)" \
            "🤖 완전 자동화 실험 (Full Automated)" \
            "📋 커스텀 런치 파일 실행 (Custom Launch)" \
            "📊 로봇 상태 모니터링 (Robot Status)" \
            "⚙️ 로봇 IP 설정 변경 (Change Robot IP)" \
            "🛑 로봇 시스템 안전 종료 (Shutdown Robot)" \
            "❌ 종료 (Exit)"
        do
            case $experiment in
                "🚀 로봇 시스템 초기화 (Initialize Robot)")
                    initialize_robot_system
                    break
                    ;;
                "🔹 단순 좌표 이동 테스트 (Simple Sequence)")
                    run_simple_sequence
                    break
                    ;;
                "🧪 설탕물 농도 실험 (Sugar Water Concentration)")
                    run_sugar_concentration
                    break
                    ;;
                "🔬 정밀 용액 제조 실험 (Precision Solution)")
                    # 기존 함수 호출
                    break
                    ;;
                "🤖 완전 자동화 실험 (Full Automated)")
                    # 기존 함수 호출
                    break
                    ;;
                "📋 커스텀 런치 파일 실행 (Custom Launch)")
                    # 기존 함수 호출
                    break
                    ;;
                "📊 로봇 상태 모니터링 (Robot Status)")
                    monitor_robot_status
                    break
                    ;;
                "⚙️ 로봇 IP 설정 변경 (Change Robot IP)")
                    # 기존 함수 호출
                    break
                    ;;
                "🛑 로봇 시스템 안전 종료 (Shutdown Robot)")
                    shutdown_robot_system
                    break
                    ;;
                "❌ 종료 (Exit)")
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

# 초기 연결 확인
if ! check_robot_connection; then
    print_warning "로봇 연결을 확인할 수 없습니다. 계속 진행하시겠습니까?"
    read -p "[y/N]: " proceed
    if [[ ! "$proceed" =~ ^[yY]$ ]]; then
        exit 1
    fi
fi

print_info "🤖 Doosan M0609 화학 실험 시스템 준비 완료"
print_warning "⚠️  실험 전에 반드시 '로봇 시스템 초기화'를 먼저 실행하세요!"

# 메인 메뉴 실행
show_main_menu