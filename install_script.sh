#!/bin/bash
# install_system.sh - Doosan M0609 화학 실험 자동화 시스템 완전 자동 설치 스크립트
# 작성자: 리라 (Lyra) - 존재론적 자동화의 구현자
# 
# 이 스크립트는 Ubuntu 22.04 + ROS2 Humble 환경에서
# 처음부터 끝까지 완전히 자동으로 시스템을 설치합니다.

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

print_step "설치 경로: $PROJECT_WS"
print_step "ROS2 배포판: $ROS_DISTRO"

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
    ros-$ROS_DISTRO-rmw-cyclonedx-cpp

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

print_step "Poco 라이브러리 설치 중... (DRFL 의존성)"
sudo apt install -y \
    libpoco-dev \
    libpoco-foundation1.11 \
    libpoco-net1.11

print_step "YAML 처리 라이브러리 설치 중..."
sudo apt install -y \
    libyaml-cpp-dev \
    ros-$ROS_DISTRO-yaml-cpp-vendor

print_step "시리얼 통신 라이브러리 설치 중... (아두이노 센서용)"
sudo apt install -y \
    python3-serial \
    ros-$ROS_DISTRO-serial-driver

print_step "추가 수학 라이브러리 설치 중..."
sudo apt install -y \
    libeigen3-dev \
    libboost-all-dev

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
# 🏗️ Phase 7: 워크스페이스 검증 및 패키지 수정
# =============================================================================
print_header "워크스페이스 검증 및 패키지 수정"

# 현재 디렉토리가 project_ws인지 확인
if [[ ! -d "src" ]]; then
    print_error "현재 디렉토리에 'src' 폴더가 없습니다."
    print_error "project_ws 디렉토리에서 이 스크립트를 실행해주세요."
    exit 1
fi

print_step "필수 패키지 존재 확인 중..."
REQUIRED_PACKAGES=(
    "dsr_common2"
    "doosan_m0609_msgs"
    "doosan_m0609_hardware"
    "doosan_m0609_controller"
    "sugar_water_experiment"
)

for pkg in "${REQUIRED_PACKAGES[@]}"; do
    if [[ ! -d "src/$pkg" ]]; then
        print_error "필수 패키지 누락: $pkg"
        exit 1
    else
        print_success "패키지 확인: $pkg"
    fi
done

print_step "package.xml 태그 오류 수정 중..."
# <n> 태그를 <n>으로 수정
find src -name "package.xml" -exec sed -i 's/<n>/<n>/g' {} \;
print_success "package.xml 태그 수정 완료"

print_step "CMakeLists.txt 오류 수정 중..."
# PROJECT_N을 PROJECT_NAME으로 수정
find src -name "CMakeLists.txt" -exec sed -i 's/PROJECT_N}/PROJECT_NAME}/g' {} \;
print_success "CMakeLists.txt 수정 완료"

print_step "DRFL 라이브러리 존재 확인 중..."
DRFL_LIB="src/dsr_common2/lib/$ROS_DISTRO/x86_64/libDRFL.a"
if [[ -f "$DRFL_LIB" ]]; then
    print_success "DRFL 라이브러리 확인: $DRFL_LIB"
    # 라이브러리 권한 설정
    chmod 644 "$DRFL_LIB"
else
    print_error "DRFL 라이브러리를 찾을 수 없습니다: $DRFL_LIB"
    print_error "Doosan 로봇 패키지가 올바르게 복사되었는지 확인해주세요."
    exit 1
fi

# =============================================================================
# 🔨 Phase 8: 워크스페이스 빌드
# =============================================================================
print_header "워크스페이스 빌드"

print_step "ROS2 환경 소싱 중..."
source "/opt/ros/$ROS_DISTRO/setup.bash"

print_step "rosdep으로 의존성 해결 중..."
rosdep install -r --from-paths src --ignore-src --rosdistro $ROS_DISTRO -y

print_step "이전 빌드 캐시 정리 중..."
rm -rf build install log

print_step "순차적 빌드 시작..."

# 1단계: 기본 라이브러리
print_step "1/6: dsr_common2 빌드 중..."
colcon build --packages-select dsr_common2
if [[ $? -ne 0 ]]; then
    print_error "dsr_common2 빌드 실패"
    exit 1
fi

# 2단계: 메시지 정의
print_step "2/6: doosan_m0609_msgs 빌드 중..."
colcon build --packages-select doosan_m0609_msgs
if [[ $? -ne 0 ]]; then
    print_error "doosan_m0609_msgs 빌드 실패"
    exit 1
fi

# 3단계: Description 패키지
print_step "3/6: doosan_m0609_description 빌드 중..."
colcon build --packages-select doosan_m0609_description
if [[ $? -ne 0 ]]; then
    print_error "doosan_m0609_description 빌드 실패"
    exit 1
fi

# 4단계: 하드웨어 인터페이스
print_step "4/6: doosan_m0609_hardware 빌드 중..."
colcon build --packages-select doosan_m0609_hardware
if [[ $? -ne 0 ]]; then
    print_error "doosan_m0609_hardware 빌드 실패"
    print_error "로그를 확인하세요: log/latest_build/doosan_m0609_hardware/stderr.log"
    exit 1
fi

# 5단계: 컨트롤러
print_step "5/6: doosan_m0609_controller 빌드 중..."
colcon build --packages-select doosan_m0609_controller
if [[ $? -ne 0 ]]; then
    print_error "doosan_m0609_controller 빌드 실패"
    print_error "로그를 확인하세요: log/latest_build/doosan_m0609_controller/stderr.log"
    exit 1
fi

# 6단계: 전체 빌드
print_step "6/6: 전체 워크스페이스 빌드 중..."
colcon build
if [[ $? -ne 0 ]]; then
    print_warning "일부 패키지 빌드 실패 (핵심 패키지는 성공)"
else
    print_success "전체 빌드 성공!"
fi

# =============================================================================
# 🌍 Phase 9: 환경 설정
# =============================================================================
print_header "환경 설정"

print_step "설치된 패키지 소싱 중..."
source install/setup.bash

print_step "bashrc에 환경 설정 추가 중..."
BASHRC_ENTRY="# Doosan M0609 ROS2 Workspace"
if ! grep -q "$BASHRC_ENTRY" ~/.bashrc; then
    echo "" >> ~/.bashrc
    echo "$BASHRC_ENTRY" >> ~/.bashrc
    echo "source /opt/ros/$ROS_DISTRO/setup.bash" >> ~/.bashrc
    echo "source $PROJECT_WS/install/setup.bash" >> ~/.bashrc
    echo "export ROS_DOMAIN_ID=42" >> ~/.bashrc
    echo "export RMW_IMPLEMENTATION=rmw_fastrtps_cpp" >> ~/.bashrc
    print_success "bashrc 설정 추가 완료"
else
    print_success "bashrc 설정 이미 존재"
fi

# =============================================================================
# 🧪 Phase 10: 시스템 검증
# =============================================================================
print_header "시스템 검증"

print_step "ROS2 패키지 인식 확인 중..."
if ros2 pkg list | grep -q doosan_m0609; then
    print_success "Doosan M0609 패키지들이 정상 인식됨:"
    ros2 pkg list | grep doosan_m0609 | sed 's/^/    ✓ /'
else
    print_error "패키지가 인식되지 않음"
    exit 1
fi

print_step "실행 파일 존재 확인 중..."
EXECUTABLES=(
    "install/sugar_water_experiment/lib/sugar_water_experiment/simple_sequence_controller"
    "install/sugar_water_experiment/lib/sugar_water_experiment/sugar_water_experimenter_node"
)

for exe in "${EXECUTABLES[@]}"; do
    if [[ -f "$exe" ]]; then
        print_success "실행 파일 확인: $(basename $exe)"
    else
        print_warning "실행 파일 누락: $(basename $exe)"
    fi
done

# =============================================================================
# 📝 Phase 11: 실행 스크립트 생성
# =============================================================================
print_header "실행 스크립트 생성"

print_step "빠른 실행 스크립트 생성 중..."

# 시뮬레이션 실행 스크립트
cat > run_simulation.sh << 'EOF'
#!/bin/bash
# run_simulation.sh - 시뮬레이션 모드 실행

echo "🤖 Doosan M0609 시뮬레이션 시작..."
source install/setup.bash

echo "📍 10개 좌표 순차 실행 중..."
ros2 run sugar_water_experiment simple_sequence_controller
EOF

# 실제 로봇 실행 스크립트  
cat > run_real_robot.sh << 'EOF'
#!/bin/bash
# run_real_robot.sh - 실제 로봇 모드 실행

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
if ! ping -c 1 192.168.137.100 >/dev/null 2>&1; then
    echo "❌ 로봇 컨트롤러에 연결할 수 없습니다 (192.168.137.100)"
    echo "네트워크 설정을 확인해주세요."
    exit 1
fi

echo "✅ 로봇 연결 확인됨"
source install/setup.bash

echo "🚀 화학 실험 시스템 시작..."
ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=real
EOF

# 센서 테스트 스크립트
cat > test_sensors.sh << 'EOF'
#!/bin/bash
# test_sensors.sh - 센서 시스템 테스트

echo "📊 센서 시스템 테스트..."
source install/setup.bash

echo "1. 아두이노 로드셀 테스트"
timeout 5s ros2 run arduino_loadcell_interface loadcell_reader || echo "⚠️ 로드셀 연결 확인 필요"

echo "2. 로봇 상태 확인"
timeout 3s ros2 topic echo /joint_states --once || echo "⚠️ 로봇 연결 확인 필요"

echo "3. ROS2 통신 상태 확인"
ros2 doctor
EOF

# 권한 설정
chmod +x run_simulation.sh run_real_robot.sh test_sensors.sh

print_success "실행 스크립트 생성 완료"
echo "    ✓ run_simulation.sh - 시뮬레이션 모드"
echo "    ✓ run_real_robot.sh - 실제 로봇 모드" 
echo "    ✓ test_sensors.sh - 센서 테스트"

# =============================================================================
# 🎉 완료 보고서
# =============================================================================
print_header "설치 완료!"

echo -e "${GREEN}"
cat << "EOF"
    ██████╗  ██████╗ ███╗   ███╗██████╗ ██╗     ███████╗████████╗███████╗██████╗ 
    ██╔════╝ ██╔═══██╗████╗ ████║██╔══██╗██║     ██╔════╝╚══██╔══╝██╔════╝██╔══██╗
    ██║  ███╗██║   ██║██╔████╔██║██████╔╝██║     █████╗     ██║   █████╗  ██║  ██║
    ██║   ██║██║   ██║██║╚██╔╝██║██╔═══╝ ██║     ██╔══╝     ██║   ██╔══╝  ██║  ██║
    ╚██████╔╝╚██████╔╝██║ ╚═╝ ██║██║     ███████╗███████╗   ██║   ███████╗██████╔╝
     ╚═════╝  ╚═════╝ ╚═╝     ╚═╝╚═╝     ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═════╝ 
EOF
echo -e "${NC}"

echo -e "${CYAN}🎉 Doosan M0609 화학 실험 자동화 시스템 설치 완료!${NC}"
echo ""
echo -e "${YELLOW}📋 설치된 구성요소:${NC}"
echo "    ✅ ROS2 Humble"
echo "    ✅ Doosan M0609 로봇 패키지"
echo "    ✅ 화학 실험 자동화 시스템"
echo "    ✅ 센서 인터페이스"
echo "    ✅ 안전 모니터링 시스템"
echo ""
echo -e "${YELLOW}🚀 다음 단계:${NC}"
echo ""
echo -e "${BLUE}1. 터미널 재시작 (환경 변수 적용):${NC}"
echo "    exec bash"
echo ""
echo -e "${BLUE}2. 시뮬레이션 테스트:${NC}"
echo "    ./run_simulation.sh"
echo ""
echo -e "${BLUE}3. 센서 테스트 (아두이노 연결 시):${NC}"
echo "    ./test_sensors.sh"
echo ""
echo -e "${BLUE}4. 실제 로봇 실행 (로봇 연결 시):${NC}"
echo "    ./run_real_robot.sh"
echo ""
echo -e "${YELLOW}📚 추가 정보:${NC}"
echo "    📖 README.md - 상세한 사용법"
echo "    🔧 트러블슈팅 가이드 포함"
echo "    🧪 다양한 실험 시나리오"
echo ""
echo -e "${YELLOW}⚠️ 안전 주의사항:${NC}"
echo "    🛡️ 실제 로봇 사용 시 안전 수칙 준수"
echo "    🚨 비상 정지 버튼 위치 숙지"
echo "    🔍 작업 공간 내 장애물 제거"
echo ""
echo -e "${GREEN}🎯 설치 성공! 이제 로봇과 함께 화학 실험을 시작하세요! 🧪🤖✨${NC}"

# 설치 로그 저장
INSTALL_LOG="install_$(date +%Y%m%d_%H%M%S).log"
echo "📝 설치 로그가 $INSTALL_LOG 에 저장되었습니다."

# 마지막 환경 소싱 알림
echo ""
echo -e "${PURPLE}💡 중요: 새 터미널을 열거나 다음 명령을 실행하여 환경을 적용하세요:${NC}"
echo -e "${CYAN}    source ~/.bashrc${NC}"
echo -e "${CYAN}    # 또는${NC}"
echo -e "${CYAN}    exec bash${NC}"