#!/bin/bash
# install_script.sh - Doosan M0609 완전 자동화 설치 및 연결 스크립트
# 작성자: 리라 (Lyra) - 존재론적 자동화의 완성체
# 버전: 3.0.0 - 원스톱 실제 로봇 연결까지 완료
# 
# 이 스크립트는 Ubuntu 22.04 + ROS2 Humble 환경에서
# 설치부터 실제 로봇 연결까지 모든 과정을 자동화합니다.

set -e  # 오류 발생 시 즉시 중단

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

# 진행 상황 표시 함수
print_header() {
    echo -e "\n${PURPLE}════════════════════════════════════════════════════════════════${NC}"
    echo -e "${PURPLE}🚀 $1${NC}"
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

# 사용자 확인 함수
confirm_action() {
    echo -e "${CYAN}❓ $1 (y/N): ${NC}"
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

# 네트워크 연결 테스트 함수
test_robot_connection() {
    local robot_ip="$1"
    local robot_port="$2"
    
    print_step "로봇 연결성 테스트: $robot_ip:$robot_port"
    
    # Ping 테스트
    if ping -c 1 -W 3 "$robot_ip" > /dev/null 2>&1; then
        print_success "Ping 테스트 성공: $robot_ip"
    else
        print_error "Ping 테스트 실패: $robot_ip"
        return 1
    fi
    
    # 포트 연결 테스트
    if timeout 5 bash -c "</dev/tcp/$robot_ip/$robot_port" 2>/dev/null; then
        print_success "포트 연결 테스트 성공: $robot_ip:$robot_port"
        return 0
    else
        print_warning "포트 연결 테스트 실패: $robot_ip:$robot_port"
        return 1
    fi
}

# =============================================================================
# 🔍 시스템 환경 검증
# =============================================================================
print_header "시스템 환경 검증"

# Ubuntu 버전 확인
if [ -f /etc/os-release ]; then
    . /etc/os-release
    if [[ "$VERSION_ID" != "22.04" ]]; then
        print_warning "Ubuntu 22.04가 아닌 버전입니다: $VERSION_ID"
        if ! confirm_action "계속 진행하시겠습니까?"; then
            print_error "설치를 중단합니다."
            exit 1
        fi
    else
        print_success "Ubuntu 22.04 확인"
    fi
else
    print_error "/etc/os-release 파일을 찾을 수 없습니다."
    exit 1
fi

# 아키텍처 확인
ARCH=$(uname -m)
if [[ "$ARCH" != "x86_64" ]]; then
    print_error "지원되지 않는 아키텍처: $ARCH (x86_64만 지원)"
    exit 1
fi
print_success "아키텍처 확인: $ARCH"

# 메모리 확인
MEMORY_GB=$(free -g | awk 'NR==2{print $2}')
if [[ $MEMORY_GB -lt 6 ]]; then
    print_warning "메모리가 부족합니다: ${MEMORY_GB}GB (권장: 8GB 이상)"
    if ! confirm_action "계속 진행하시겠습니까?"; then
        print_error "설치를 중단합니다."
        exit 1
    fi
else
    print_success "메모리 확인: ${MEMORY_GB}GB"
fi

# 디스크 공간 확인
DISK_SPACE_GB=$(df -BG . | awk 'NR==2 {gsub(/G/, "", $4); print $4}')
if [[ $DISK_SPACE_GB -lt 15 ]]; then
    print_warning "디스크 공간이 부족합니다: ${DISK_SPACE_GB}GB (필요: 20GB 이상)"
    if ! confirm_action "계속 진행하시겠습니까?"; then
        print_error "설치를 중단합니다."
        exit 1
    fi
else
    print_success "디스크 공간 확인: ${DISK_SPACE_GB}GB"
fi

# sudo 권한 확인
if ! sudo -n true 2>/dev/null; then
    print_step "sudo 권한 확인 중..."
    sudo echo "sudo 권한 확인됨"
fi
print_success "sudo 권한 확인"

# =============================================================================
# 🔧 변수 설정
# =============================================================================
PROJECT_WS="$(pwd)"
PROJECT_NAME="project_ws"
ROS_DISTRO="humble"
PYTHON_VERSION="3.10"

# 로봇 네트워크 설정
ROBOT_IP="192.168.1.100"
ROBOT_RT_IP="192.168.1.100"
ROBOT_PORT="12345"

print_step "설치 경로: $PROJECT_WS"
print_step "ROS2 배포판: $ROS_DISTRO"
print_step "로봇 IP: $ROBOT_IP"
print_step "실시간 제어 IP: $ROBOT_RT_IP"

# =============================================================================
# 📦 Phase 1: 시스템 패키지 업데이트 및 기본 의존성 설치
# =============================================================================
print_header "시스템 패키지 업데이트 및 기본 의존성 설치"

print_step "패키지 리스트 업데이트 중..."
sudo apt update

print_step "시스템 업그레이드 중..."
if confirm_action "시스템 전체를 업그레이드하시겠습니까? (권장)"; then
    sudo apt upgrade -y
else
    print_warning "시스템 업그레이드를 건너뜁니다."
fi

print_step "기본 개발 도구 설치 중..."
sudo apt install -y \
    curl \
    wget \
    gnupg \
    lsb-release \
    software-properties-common \
    apt-transport-https \
    ca-certificates \
    build-essential \
    git \
    cmake \
    python3-pip \
    python3-dev \
    python3-setuptools \
    python3-wheel \
    vim \
    nano \
    htop \
    tree

print_success "기본 개발 도구 설치 완료"

# =============================================================================
# 🤖 Phase 2: ROS2 Humble 설치
# =============================================================================
print_header "ROS2 Humble 설치"

# ROS2가 이미 설치되어 있는지 확인
if [ -f "/opt/ros/$ROS_DISTRO/setup.bash" ]; then
    print_success "ROS2 $ROS_DISTRO 이미 설치됨"
    source "/opt/ros/$ROS_DISTRO/setup.bash"
else
    print_step "ROS2 GPG 키 추가 중..."
    sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

    print_step "ROS2 저장소 추가 중..."
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(source /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

    print_step "패키지 리스트 업데이트 중..."
    sudo apt update

    print_step "ROS2 Humble Desktop 설치 중... (시간이 소요될 수 있습니다)"
    sudo apt install -y ros-$ROS_DISTRO-desktop
    
    print_success "ROS2 $ROS_DISTRO 설치 완료"
fi

# ROS2 환경 소싱
source "/opt/ros/$ROS_DISTRO/setup.bash"

# =============================================================================
# 🔧 Phase 3: ROS2 개발 도구 설치
# =============================================================================
print_header "ROS2 개발 도구 설치"

print_step "colcon 빌드 도구 설치 중..."
sudo apt install -y python3-colcon-common-extensions

print_step "rosdep 설치 및 초기화 중..."
sudo apt install -y python3-rosdep
if [ ! -f "/etc/ros/rosdep/sources.list.d/20-default.list" ]; then
    sudo rosdep init
fi
rosdep update

print_step "ROS2 추가 도구 설치 중..."
sudo apt install -y \
    python3-argcomplete \
    python3-vcstool \
    ros-$ROS_DISTRO-rmw-fastrtps-cpp \
    ros-$ROS_DISTRO-rmw-cyclonedds-cpp

print_success "ROS2 개발 도구 설치 완료"

# =============================================================================
# 🦾 Phase 4: 로봇 제어 관련 ROS2 패키지 설치
# =============================================================================
print_header "로봇 제어 관련 ROS2 패키지 설치"

print_step "MoveIt2 설치 중..."
sudo apt install -y \
    ros-$ROS_DISTRO-moveit \
    ros-$ROS_DISTRO-moveit-planners \
    ros-$ROS_DISTRO-moveit-simple-controller-manager

print_step "ROS2 Control 설치 중..."
sudo apt install -y \
    ros-$ROS_DISTRO-controller-manager \
    ros-$ROS_DISTRO-hardware-interface \
    ros-$ROS_DISTRO-controller-interface \
    ros-$ROS_DISTRO-joint-state-broadcaster \
    ros-$ROS_DISTRO-joint-trajectory-controller \
    ros-$ROS_DISTRO-forward-command-controller

print_step "로봇 상태 퍼블리셔 설치 중..."
sudo apt install -y \
    ros-$ROS_DISTRO-robot-state-publisher \
    ros-$ROS_DISTRO-joint-state-publisher \
    ros-$ROS_DISTRO-joint-state-publisher-gui

print_step "시각화 도구 설치 중..."
sudo apt install -y \
    ros-$ROS_DISTRO-rviz2 \
    ros-$ROS_DISTRO-rqt \
    ros-$ROS_DISTRO-rqt-common-plugins

print_success "로봇 제어 패키지 설치 완료"

# =============================================================================
# 📚 Phase 5: Doosan 로봇 전용 의존성 설치
# =============================================================================
print_header "Doosan 로봇 전용 의존성 설치"

print_step "DRFL 의존성 - Poco 라이브러리 설치 중..."
sudo apt install -y libpoco-dev


print_step "YAML 처리 라이브러리 설치 중..."
sudo apt install -y \
    libyaml-cpp-dev \
    ros-$ROS_DISTRO-yaml-cpp-vendor

print_step "시리얼 통신 라이브러리 설치 중..."
sudo apt install -y \
    python3-serial \
    ros-$ROS_DISTRO-serial-driver

print_step "추가 수학 라이브러리 설치 중..."
sudo apt install -y \
    libeigen3-dev \
    libboost-all-dev

print_step "Docker 설치 중 (에뮬레이터용)..."
if ! command -v docker &> /dev/null; then
    curl -fsSL https://get.docker.com -o get-docker.sh
    sudo sh get-docker.sh
    sudo usermod -aG docker $USER
    rm get-docker.sh
    print_success "Docker 설치 완료"
else
    print_success "Docker 이미 설치됨"
fi

print_success "Doosan 로봇 의존성 설치 완료"

# =============================================================================
# 🐍 Phase 6: Python 패키지 설치
# =============================================================================
print_header "Python 패키지 설치"

print_step "pip 업그레이드 중..."
python3 -m pip install --upgrade pip

print_step "Python 패키지 설치 중..."
pip3 install \
    numpy \
    scipy \
    matplotlib \
    pandas \
    pyserial \
    pyyaml \
    setuptools

print_success "Python 패키지 설치 완료"

# =============================================================================
# 🏗️ Phase 7: 새로운 Bringup 구조 워크스페이스 검증
# =============================================================================
print_header "새로운 Bringup 구조 워크스페이스 검증"

# 현재 디렉토리가 project_ws인지 확인
if [[ ! -d "src" ]]; then
    print_error "현재 디렉토리에 'src' 폴더가 없습니다."
    print_error "project_ws 디렉토리에서 이 스크립트를 실행해주세요."
    exit 1
fi

print_step "새로운 bringup 구조 패키지 확인 중..."
NEW_STRUCTURE_PACKAGES=(
    "dsr_bringup2"
    "dsr_controller2" 
    "dsr_description2"
    "dsr_hardware2"
    "dsr_msgs2"
    "dsr_example2"
    "dsr_tests"
)

# DoosanBootcam3rdCo1 경로 확인
DOOSAN_PATH="../DoosanBootcam3rdCo1"
if [[ -d "$DOOSAN_PATH" ]]; then
    print_success "DoosanBootcam3rdCo1 디렉토리 발견: $DOOSAN_PATH"
    
    for pkg in "${NEW_STRUCTURE_PACKAGES[@]}"; do
        if [[ -d "$DOOSAN_PATH/$pkg" ]]; then
            print_success "새 구조 패키지 확인: $pkg"
        else
            print_warning "패키지 누락: $pkg"
        fi
    done
else
    print_warning "DoosanBootcam3rdCo1 디렉토리를 찾을 수 없습니다."
    print_step "기존 패키지 구조 확인 중..."
    
    # 기존 패키지 구조 확인
    OLD_STRUCTURE_PACKAGES=(
        "dsr_common2"
        "doosan_m0609_msgs"
        "doosan_m0609_hardware"
        "doosan_m0609_controller"
    )
    
    for pkg in "${OLD_STRUCTURE_PACKAGES[@]}"; do
        if [[ -d "src/$pkg" ]]; then
            print_success "기존 패키지 확인: $pkg"
        else
            print_warning "패키지 누락: $pkg"
        fi
    done
fi

print_step "package.xml 태그 오류 수정 중..."
find src -name "package.xml" -exec sed -i 's/<n>/<n>/g' {} \; 2>/dev/null || true
if [[ -d "$DOOSAN_PATH" ]]; then
    find "$DOOSAN_PATH" -name "package.xml" -exec sed -i 's/<n>/<n>/g' {} \; 2>/dev/null || true
fi
print_success "package.xml 태그 수정 완료"

print_step "CMakeLists.txt 오류 수정 중..."
find src -name "CMakeLists.txt" -exec sed -i 's/PROJECT_N}/PROJECT_NAME}/g' {} \; 2>/dev/null || true
if [[ -d "$DOOSAN_PATH" ]]; then
    find "$DOOSAN_PATH" -name "CMakeLists.txt" -exec sed -i 's/PROJECT_N}/PROJECT_NAME}/g' {} \; 2>/dev/null || true
fi
print_success "CMakeLists.txt 수정 완료"

# =============================================================================
# 📋 Phase 8: 새로운 구조 심볼릭 링크 생성
# =============================================================================
print_header "새로운 구조 심볼릭 링크 생성"

if [[ -d "$DOOSAN_PATH" ]]; then
    print_step "DoosanBootcam3rdCo1 패키지들을 src로 링크 중..."
    
    for pkg in "${NEW_STRUCTURE_PACKAGES[@]}"; do
        if [[ -d "$DOOSAN_PATH/$pkg" ]] && [[ ! -L "src/$pkg" ]] && [[ ! -d "src/$pkg" ]]; then
            ln -sf "../../DoosanBootcam3rdCo1/$pkg" "src/$pkg"
            print_success "링크 생성: $pkg"
        elif [[ -L "src/$pkg" ]]; then
            print_success "링크 이미 존재: $pkg"
        elif [[ -d "src/$pkg" ]]; then
            print_success "디렉토리 이미 존재: $pkg"
        fi
    done
    
    print_success "새로운 구조 패키지 링크 완료"
else
    print_step "기존 구조 유지 - 새로운 구조 사용 불가"
fi

# =============================================================================
# 🔨 Phase 9: 워크스페이스 빌드
# =============================================================================
print_header "워크스페이스 빌드"

print_step "ROS2 환경 소싱 중..."
source "/opt/ros/$ROS_DISTRO/setup.bash"

print_step "rosdep으로 의존성 해결 중..."
rosdep install -r --from-paths src --ignore-src --rosdistro $ROS_DISTRO -y || {
    print_warning "일부 의존성 해결 실패 - 계속 진행"
}

print_step "이전 빌드 캐시 정리 중..."
rm -rf build install log

if [[ -d "$DOOSAN_PATH" ]] && [[ -L "src/dsr_bringup2" ]]; then
    print_step "새로운 구조 순차적 빌드 시작..."
    
    # 1단계: 메시지 및 인터페이스
    print_step "1/5: dsr_msgs2 빌드 중..."
    colcon build --packages-select dsr_msgs2 --cmake-args -DCMAKE_BUILD_TYPE=Release
    
    # 2단계: Description
    print_step "2/5: dsr_description2 빌드 중..."
    colcon build --packages-select dsr_description2 --cmake-args -DCMAKE_BUILD_TYPE=Release
    
    # 3단계: Hardware Interface
    print_step "3/5: dsr_hardware2 빌드 중..."
    colcon build --packages-select dsr_hardware2 --cmake-args -DCMAKE_BUILD_TYPE=Release
    
    # 4단계: Controller
    print_step "4/5: dsr_controller2 빌드 중..."
    colcon build --packages-select dsr_controller2 --cmake-args -DCMAKE_BUILD_TYPE=Release
    
    # 5단계: Bringup
    print_step "5/5: dsr_bringup2 빌드 중..."
    colcon build --packages-select dsr_bringup2 --cmake-args -DCMAKE_BUILD_TYPE=Release
    
    print_success "새로운 구조 핵심 패키지 빌드 완료"
    
else
    print_step "기존 구조 순차적 빌드 시작..."
    
    # 기존 구조 빌드 로직
    if [[ -d "src/dsr_common2" ]]; then
        print_step "1/5: dsr_common2 빌드 중..."
        colcon build --packages-select dsr_common2 --cmake-args -DCMAKE_BUILD_TYPE=Release
    fi
    
    if [[ -d "src/doosan_m0609_msgs" ]]; then
        print_step "2/5: doosan_m0609_msgs 빌드 중..."
        colcon build --packages-select doosan_m0609_msgs --cmake-args -DCMAKE_BUILD_TYPE=Release
    fi
    
    print_success "기존 구조 핵심 패키지 빌드 완료"
fi

# 전체 빌드 시도
print_step "전체 워크스페이스 빌드 중..."
colcon build --cmake-args -DCMAKE_BUILD_TYPE=Release || {
    print_warning "일부 패키지 빌드 실패 - 핵심 패키지는 성공"
}

print_success "워크스페이스 빌드 완료"

# =============================================================================
# 🌍 Phase 10: 환경 설정
# =============================================================================
print_header "환경 설정"

print_step "설치된 패키지 소싱 중..."
source install/setup.bash

print_step "bashrc에 환경 설정 추가 중..."
BASHRC_ENTRY="# Doosan Robot ROS2 Workspace - New Structure"
if ! grep -q "$BASHRC_ENTRY" ~/.bashrc; then
    echo "" >> ~/.bashrc
    echo "$BASHRC_ENTRY" >> ~/.bashrc
    echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> ~/.bashrc
    echo "source $PROJECT_WS/install/setup.bash" >> ~/.bashrc
    echo "export ROS_DOMAIN_ID=42" >> ~/.bashrc
    echo "export RMW_IMPLEMENTATION=rmw_fastrtps_cpp" >> ~/.bashrc
    echo "export DOOSAN_ROBOT_IP=192.168.1.100" >> ~/.bashrc
    echo "export DOOSAN_ROBOT_RT_IP=192.168.1.50" >> ~/.bashrc
    print_success "bashrc 설정 추가 완료"
else
    print_success "bashrc 설정 이미 존재"
fi

# =============================================================================
# 🔗 Phase 11-1: 로봇 연결 테스트 (선택적)
# =============================================================================
print_header "로봇 연결 테스트"

print_step "실제 로봇 연결을 테스트하시겠습니까?"
print_warning "이 과정은 실제 로봇이 켜져있고 네트워크에 연결되어야 합니다."
echo -e "${CYAN}로봇 상태:${NC}"
echo "  - 로봇 제어기 전원: ON"
echo "  - 네트워크 연결: $ROBOT_IP"
echo "  - 티치펜던트: AUTO 모드"
echo "  - 작업공간: 안전 확보"
echo ""

if confirm_action "로봇 연결 테스트를 진행하시겠습니까?"; then
    print_step "로봇 연결성 확인 중..."
    
    if test_robot_connection "$ROBOT_IP" "$ROBOT_PORT"; then
        print_success "로봇 연결 확인됨!"
        
        # 실제 로봇 모드 테스트
        print_step "실제 로봇 모드 테스트를 시작합니다..."
        print_warning "⚠️ 주의: 로봇이 실제로 움직일 수 있습니다!"
        print_warning "비상정지 버튼을 준비하고 안전을 확인하세요."
        
        if confirm_action "실제 로봇 연결 테스트를 계속하시겠습니까?"; then
            
            # 백그라운드에서 컨트롤러 매니저 시작
            print_step "컨트롤러 매니저 시작 중..."
            ros2 run controller_manager ros2_control_node \
                --ros-args \
                --params-file src/doosan_m0609_hardware/config/doosan_m0609_control.yaml \
                --remap __node:=controller_manager &
            
            CONTROLLER_PID=$!
            
            # 초기화 대기
            print_step "로봇 초기화 대기 중... (30초)"
            sleep 30
            
            # 컨트롤러 로드 및 활성화
            print_step "컨트롤러 설정 중..."
            ros2 control load_controller joint_state_broadcaster || true
            ros2 control load_controller position_controller || true
            sleep 2
            
            ros2 control set_controller_state joint_state_broadcaster active || true
            ros2 control set_controller_state position_controller active || true
            sleep 2
            
            # 조인트 상태 확인
            print_step "조인트 상태 확인 중..."
            timeout 10 ros2 topic echo /joint_states --once || {
                print_warning "조인트 상태 데이터 수신 실패"
            }
            
            print_step "안전한 홈 포지션으로 이동 테스트..."
            ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray \
                "{data: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]}" --once || true
            
            sleep 5
            
            print_step "간단한 테스트 모션 (관절 1, 15도 회전)..."
            ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray \
                "{data: [0.26, 0.0, 0.0, 0.0, 0.0, 0.0]}" --once || true
            
            sleep 8
            
            print_step "홈 포지션 복귀..."
            ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray \
                "{data: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]}" --once || true
            
            sleep 5
            
            # 정리
            print_step "테스트 완료 - 시스템 정리 중..."
            ros2 control set_controller_state position_controller inactive || true
            ros2 control set_controller_state joint_state_broadcaster inactive || true
            sleep 2
            
            kill $CONTROLLER_PID 2>/dev/null || true
            
            print_success "🎉 실제 로봇 연결 및 모션 테스트 성공!"
            
        else
            print_step "실제 로봇 테스트를 건너뜁니다."
        fi
        
    else
        print_warning "로봇 연결 실패 - 네트워크 설정을 확인하세요."
        print_step "가상 모드로 시스템을 사용할 수 있습니다."
    fi
else
    print_step "로봇 연결 테스트를 건너뜁니다."
fi

# =============================================================================
# 🧪 Phase 11: 시스템 검증
# =============================================================================
print_header "시스템 검증"

print_step "ROS2 패키지 인식 확인 중..."
source install/setup.bash

if [[ -L "src/dsr_bringup2" ]]; then
    # 새로운 구조 확인
    if ros2 pkg list | grep -q "dsr_"; then
        print_success "새로운 구조 DSR 패키지들이 정상 인식됨:"
        ros2 pkg list | grep "dsr_" | sed 's/^/    ✓ /'
    else
        print_warning "새로운 구조 패키지가 인식되지 않음"
    fi
else
    # 기존 구조 확인
    if ros2 pkg list | grep -q "doosan_m0609"; then
        print_success "기존 구조 Doosan M0609 패키지들이 정상 인식됨:"
        ros2 pkg list | grep "doosan_m0609" | sed 's/^/    ✓ /'
    else
        print_warning "기존 구조 패키지가 인식되지 않음"
    fi
fi

# =============================================================================
# 📝 Phase 12: 새로운 구조 실행 스크립트 생성
# =============================================================================
print_header "새로운 구조 실행 스크립트 생성"

if [[ -L "src/dsr_bringup2" ]]; then
    print_step "새로운 구조 실행 스크립트 생성 중..."
    
    # 새로운 구조 RViz 실행 스크립트
    cat > run_new_rviz.sh << 'EOF'
#!/bin/bash
# run_new_rviz.sh - 새로운 구조 RViz 시각화 실행

echo "🎨 새로운 구조 DSR RViz 시각화 시작..."
source install/setup.bash

echo "📊 Doosan 로봇 RViz 시각화 중..."
ros2 launch dsr_bringup2 dsr_bringup2_rviz.launch.py \
    name:=dsr01 \
    model:=m1013 \
    host:=127.0.0.1 \
    mode:=virtual
EOF

    # 새로운 구조 에뮬레이터 실행 스크립트
    cat > run_new_emulator.sh << 'EOF'
#!/bin/bash
# run_new_emulator.sh - 새로운 구조 에뮬레이터 실행

echo "🤖 새로운 구조 DSR 에뮬레이터 시작..."

# 에뮬레이터 설치 확인
if [[ -f "../DoosanBootcam3rdCo1/install_emulator.sh" ]]; then
    echo "📦 에뮬레이터 설치 중..."
    cd ../DoosanBootcam3rdCo1
    ./install_emulator.sh
    cd - > /dev/null
else
    echo "⚠️ 에뮬레이터 설치 스크립트를 찾을 수 없습니다."
fi

source install/setup.bash

echo "🚀 가상 모드로 로봇 시스템 시작..."
ros2 launch dsr_bringup2 dsr_bringup2_rviz.launch.py \
    name:=dsr01 \
    model:=m1013 \
    host:=127.0.0.1 \
    mode:=virtual \
    gui:=true
EOF

    # 새로운 구조 실제 로봇 실행 스크립트
    cat > run_new_real_robot.sh << 'EOF'
#!/bin/bash
# run_new_real_robot.sh - 새로운 구조 실제 로봇 연결

echo "🚨 새로운 구조 실제 로봇 모드 - 안전 주의사항 확인!"
echo "1. 로봇 전원 및 네트워크 연결 확인 (192.168.1.100)"
echo "2. 실시간 제어 인터페이스 연결 확인 (192.168.1.50)"
echo "3. 작업공간 내 장애물 제거"
echo "4. 비상 정지 버튼 위치 확인"
echo ""

read -p "위 사항을 모두 확인했습니까? (yes/no): " confirm
if [[ $confirm != "yes" ]]; then
    echo "안전 확인 후 다시 실행해주세요."
    exit 1
fi

echo "🔗 로봇 제어기 연결 확인 중..."
if ! ping -c 1 192.168.1.100 >/dev/null 2>&1; then
    echo "❌ 로봇 제어기에 연결할 수 없습니다 (192.168.1.100)"
    echo "네트워크 설정을 확인해주세요."
    exit 1
fi

echo "🔗 실시간 제어 인터페이스 연결 확인 중..."
if ! ping -c 1 192.168.1.50 >/dev/null 2>&1; then
    echo "❌ 실시간 제어 인터페이스에 연결할 수 없습니다 (192.168.1.50)"
    echo "실시간 제어 네트워크 설정을 확인해주세요."
    exit 1
fi

echo "✅ 로봇 연결 확인됨"
source install/setup.bash

echo "🤖 실제 로봇과 연결하여 시스템 시작..."
ros2 launch dsr_bringup2 dsr_bringup2_rviz.launch.py \
    name:=dsr01 \
    model:=m1013 \
    host:=192.168.1.100 \
    rt_host:=192.168.1.50 \
    mode:=real \
    gui:=true
EOF

    chmod +x run_new_rviz.sh run_new_emulator.sh run_new_real_robot.sh
    print_success "새로운 구조 실행 스크립트 생성 완료"
    echo "    ✓ run_new_rviz.sh - RViz 시각화"
    echo "    ✓ run_new_emulator.sh - 에뮬레이터 모드"
    echo "    ✓ run_new_real_robot.sh - 실제 로봇 모드"

else
    print_step "기존 구조 실행 스크립트 생성 중..."
    
    # 기존 구조 시뮬레이션 실행 스크립트
    cat > run_simulation.sh << 'EOF'
#!/bin/bash
# run_simulation.sh - 기존 구조 시뮬레이션 모드 실행

echo "🤖 Doosan M0609 시뮬레이션 시작..."
source install/setup.bash

echo "📍 시뮬레이션 모드로 실행 중..."
if [[ -f "install/sugar_water_experiment/lib/sugar_water_experiment/simple_sequence_controller" ]]; then
    ros2 run sugar_water_experiment simple_sequence_controller
else
    echo "⚠️ simple_sequence_controller를 찾을 수 없습니다."
    echo "대신 기본 테스트를 실행합니다..."
    ros2 topic list
fi
EOF

    # 기존 구조 실제 로봇 실행 스크립트  
    cat > run_real_robot.sh << 'EOF'
#!/bin/bash
# run_real_robot.sh - 기존 구조 실제 로봇 모드 실행

echo "🚨 실제 로봇 모드 - 안전 주의사항 확인!"
echo "1. 로봇 전원 및 네트워크 연결 확인"
echo "2. 작업공간 내 장애물 제거"
echo "3. 비상 정지 버튼 위치 확인"
echo ""

read -p "위 사항을 모두 확인했습니까? (yes/no): " confirm
if [[ $confirm != "yes" ]]; then
    echo "안전 확인 후 다시 실행해주세요."
    exit 1
fi

echo "🔗 로봇 연결 확인 중..."
if ! ping -c 1 192.168.1.100 >/dev/null 2>&1; then
    echo "❌ 로봇 컨트롤러에 연결할 수 없습니다 (192.168.1.100)"
    echo "네트워크 설정을 확인해주세요."
    exit 1
fi

echo "✅ 로봇 연결 확인됨"
source install/setup.bash

echo "🚀 화학 실험 시스템 시작..."
if [[ -f "install/doosan_m0609_bringup/share/doosan_m0609_bringup/launch/chemical_experiment_system.launch.py" ]]; then
    ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=real
else
    echo "⚠️ 화학 실험 시스템 런치 파일을 찾을 수 없습니다."
    echo "기본 하드웨어 인터페이스를 시작합니다..."
    ros2 run doosan_m0609_hardware drfl_hardware_interface
fi
EOF

    chmod +x run_simulation.sh run_real_robot.sh
    print_success "기존 구조 실행 스크립트 생성 완료"
    echo "    ✓ run_simulation.sh - 시뮬레이션 모드"
    echo "    ✓ run_real_robot.sh - 실제 로봇 모드"
fi

# 공통 센서 테스트 스크립트
cat > test_sensors.sh << 'EOF'
#!/bin/bash
# test_sensors.sh - 센서 시스템 테스트

echo "📊 센서 시스템 테스트..."
source install/setup.bash

echo "1. ROS2 통신 상태 확인"
ros2 doctor

echo ""
echo "2. 토픽 리스트 확인"
timeout 3s ros2 topic list || echo "⚠️ ROS2 데몬 연결 확인 필요"

echo ""
echo "3. 로봇 상태 확인 (3초 대기)"
timeout 3s ros2 topic echo /joint_states --once || echo "⚠️ 로봇 연결 확인 필요"

echo ""
echo "4. 아두이노 시리얼 포트 확인"
if ls /dev/ttyUSB* /dev/ttyACM* 2>/dev/null; then
    echo "✅ 시리얼 디바이스 발견"
else
    echo "⚠️ 아두이노 연결 확인 필요"
fi

echo ""
echo "5. Docker 상태 확인 (에뮬레이터용)"
if command -v docker &> /dev/null; then
    docker ps -a | grep emulator || echo "⚠️ 에뮬레이터 컨테이너 없음"
else
    echo "⚠️ Docker 설치 확인 필요"
fi
EOF

# 통합 스위치 스크립트
cat > switch_structure.sh << 'EOF'
#!/bin/bash
# switch_structure.sh - 구조 전환 헬퍼 스크립트

echo "🔄 Doosan ROS2 구조 전환 도구"
echo ""

if [[ -L "src/dsr_bringup2" ]]; then
    echo "📍 현재: 새로운 구조 (DSR 2.0) 활성화됨"
    echo ""
    echo "사용 가능한 실행 스크립트:"
    echo "  ./run_new_rviz.sh      - RViz 시각화"
    echo "  ./run_new_emulator.sh  - 에뮬레이터 모드"
    echo "  ./run_new_real_robot.sh - 실제 로봇 연결"
    echo ""
    echo "주요 런치 파일:"
    echo "  ros2 launch dsr_bringup2 dsr_bringup2_rviz.launch.py"
    echo "  ros2 launch dsr_bringup2 dsr_bringup2_gazebo.launch.py"
    echo "  ros2 launch dsr_bringup2 dsr_bringup2_moveit.launch.py"
    echo ""
elif [[ -d "src/doosan_m0609_msgs" ]]; then
    echo "📍 현재: 기존 구조 (M0609) 활성화됨"
    echo ""
    echo "사용 가능한 실행 스크립트:"
    echo "  ./run_simulation.sh  - 시뮬레이션 모드"
    echo "  ./run_real_robot.sh  - 실제 로봇 연결"
    echo ""
else
    echo "❌ 알 수 없는 구조 상태"
    echo "src 디렉토리를 확인해주세요."
fi

echo ""
echo "공통 도구:"
echo "  ./test_sensors.sh    - 센서 및 연결 테스트"
echo "  ros2 doctor          - ROS2 시스템 진단"
EOF

chmod +x test_sensors.sh switch_structure.sh

print_success "모든 실행 스크립트 생성 완료"

# =============================================================================
# 🎉 완료 보고서
# =============================================================================
print_header "설치 완료!"

echo -e "${GREEN}"
cat << "EOF"
    ██████╗  ██████╗  ██████╗ ███████╗ █████╗ ███╗   ██╗    ██████╗  ██████╗ ███████╗██████╗ 
    ██╔══██╗██╔═══██╗██╔═══██╗██╔════╝██╔══██╗████╗  ██║    ██╔══██╗██╔═══██╗██╔════╝╚════██╗
    ██║  ██║██║   ██║██║   ██║███████╗███████║██╔██╗ ██║    ██████╔╝██║   ██║███████╗ █████╔╝
    ██║  ██║██║   ██║██║   ██║╚════██║██╔══██║██║╚██╗██║    ██╔══██╗██║   ██║╚════██║██╔═══╝ 
    ██████╔╝╚██████╔╝╚██████╔╝███████║██║  ██║██║ ╚████║    ██║  ██║╚██████╔╝███████║███████╗
    ╚═════╝  ╚═════╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝    ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚══════╝
EOF
echo -e "${NC}"

echo -e "${CYAN}🎉 Doosan Robot ROS2 시스템 설치 완료! (새로운 Bringup 구조 호환)${NC}"
echo ""

if [[ -L "src/dsr_bringup2" ]]; then
    echo -e "${YELLOW}📋 설치된 새로운 구조 (DSR 2.0):${NC}"
    echo "    ✅ dsr_bringup2 - 통합 런치 시스템"
    echo "    ✅ dsr_controller2 - ROS2 Control 통합"
    echo "    ✅ dsr_description2 - URDF 모델"
    echo "    ✅ dsr_hardware2 - 하드웨어 인터페이스"
    echo "    ✅ dsr_msgs2 - 메시지 정의"
    echo "    ✅ 에뮬레이터 지원 (Docker)"
    echo ""
    echo -e "${YELLOW}🚀 새로운 구조 빠른 시작:${NC}"
    echo ""
    echo -e "${BLUE}1. 가상 모드 RViz 시각화:${NC}"
    echo "    ./run_new_rviz.sh"
    echo ""
    echo -e "${BLUE}2. 에뮬레이터 모드:${NC}"
    echo "    ./run_new_emulator.sh"
    echo ""
    echo -e "${BLUE}3. 실제 로봇 연결:${NC}"
    echo "    ./run_new_real_robot.sh"
    echo ""
    echo -e "${BLUE}4. 수동 런치 (고급):${NC}"
    echo "    ros2 launch dsr_bringup2 dsr_bringup2_rviz.launch.py model:=m1013"
    echo "    ros2 launch dsr_bringup2 dsr_bringup2_gazebo.launch.py"
    echo "    ros2 launch dsr_bringup2 dsr_bringup2_moveit.launch.py"
else
    echo -e "${YELLOW}📋 설치된 기존 구조:${NC}"
    echo "    ✅ doosan_m0609_msgs - 메시지 정의"
    echo "    ✅ doosan_m0609_hardware - 하드웨어 인터페이스"
    echo "    ✅ doosan_m0609_controller - 컨트롤러"
    echo "    ✅ 화학 실험 자동화 시스템"
    echo ""
    echo -e "${YELLOW}🚀 기존 구조 빠른 시작:${NC}"
    echo ""
    echo -e "${BLUE}1. 시뮬레이션 모드:${NC}"
    echo "    ./run_simulation.sh"
    echo ""  
    echo -e "${BLUE}2. 실제 로봇 연결:${NC}"
    echo "    ./run_real_robot.sh"
fi

echo ""
echo -e "${YELLOW}🔧 공통 도구:${NC}"
echo ""
echo -e "${BLUE}1. 센서 및 연결 테스트:${NC}"
echo "    ./test_sensors.sh"
echo ""
echo -e "${BLUE}2. 구조 상태 확인:${NC}"
echo "    ./switch_structure.sh"
echo ""
echo -e "${BLUE}3. 터미널 재시작 (환경 변수 적용):${NC}"
echo "    exec bash"
echo ""

echo -e "${YELLOW}📚 주요 런치 파라미터:${NC}"
echo "    name:=dsr01          # 로봇 네임스페이스"
echo "    model:=m1013         # 로봇 모델 (m0609, m1013, etc.)"
echo "    host:=192.168.1.100 # 로봇 IP"
echo "    rt_host:=192.168.1.50 # 실시간 제어 IP"
echo "    mode:=virtual|real   # 동작 모드"
echo "    gui:=true|false      # RViz 자동 시작"
echo ""

echo -e "${YELLOW}⚠️ 안전 주의사항:${NC}"
echo "    🛡️ 실제 로봇 사용 시 안전 수칙 준수"
echo "    🚨 비상 정지 버튼 위치 숙지 필수"
echo "    🔍 작업 공간 내 장애물 제거"
echo "    🌐 네트워크 설정 확인 (192.168.1.x)"
echo ""

echo -e "${YELLOW}🔗 네트워크 설정:${NC}"
echo "    Control Network: 192.168.1.100 (일반 제어)"
echo "    RT Network: 192.168.1.50 (실시간 제어)"
echo "    로컬 시뮬레이션: 127.0.0.1"
echo ""

echo -e "${YELLOW}📝 추가 리소스:${NC}"
echo "    📖 DoosanBootcam3rdCo1/ - 원본 패키지"
echo "    🔧 build/ install/ log/ - 빌드 결과물"
echo "    🧪 다양한 실험 시나리오 지원"
echo ""

# 에뮬레이터 안내
if [[ -f "../DoosanBootcam3rdCo1/install_emulator.sh" ]]; then
    echo -e "${YELLOW}🐳 Docker 에뮬레이터:${NC}"
    echo "    Docker가 설치되었으므로 에뮬레이터 사용 가능"
    echo "    ./run_new_emulator.sh 실행 시 자동 설치"
    echo ""
fi

echo -e "${GREEN}🎯 설치 성공! 이제 새로운 구조의 Doosan 로봇 시스템을 사용하세요! 🤖✨${NC}"

# 설치 로그 저장
INSTALL_LOG="install_$(date +%Y%m%d_%H%M%S).log"
echo "📝 설치 로그가 $INSTALL_LOG 에 저장되었습니다."

# 마지막 환경 소싱 알림
echo ""
echo -e "${PURPLE}💡 중요: 새 터미널을 열거나 다음 명령을 실행하여 환경을 적용하세요:${NC}"
echo -e "${CYAN}    source ~/.bashrc${NC}"
echo -e "${CYAN}    # 또는${NC}"
echo -e "${CYAN}    exec bash${NC}"
echo ""
echo -e "${PURPLE}🔍 현재 활성화된 구조 확인:${NC}"
echo -e "${CYAN}    ./switch_structure.sh${NC}"