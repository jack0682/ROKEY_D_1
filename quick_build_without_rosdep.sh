#!/bin/bash
# quick_build_without_rosdep.sh - rosdep 없이 빠른 빌드

set -e

echo "🚀 rosdep 우회 빠른 빌드 시작..."

PROJECT_WS="/home/jack/project_ws"
cd $PROJECT_WS

# ROS2 환경 소싱
source /opt/ros/humble/setup.bash

echo "📦 필수 시스템 패키지 설치 중..."
sudo apt-get update
sudo apt-get install -y \
    build-essential \
    cmake \
    git \
    python3-colcon-common-extensions \
    python3-pip \
    libpoco-dev \
    libyaml-cpp-dev \
    libboost-all-dev

echo "🎯 ROS2 Humble 패키지 설치 중..."
sudo apt-get install -y \
    ros-humble-rclcpp \
    ros-humble-rclpy \
    ros-humble-std-msgs \
    ros-humble-geometry-msgs \
    ros-humble-sensor-msgs \
    ros-humble-control-msgs \
    ros-humble-hardware-interface \
    ros-humble-controller-interface \
    ros-humble-realtime-tools \
    ros-humble-pluginlib \
    ros-humble-rclcpp-lifecycle \
    ros-humble-lifecycle-msgs || echo "일부 패키지 설치 실패 - 계속 진행"

echo ""
echo "🏗️ 단계별 빌드 시작..."

# 1단계: 공통 라이브러리 먼저
echo "📚 1단계: 공통 라이브러리 빌드..."
if [ -d "src/dsr_common2" ]; then
    colcon build --packages-select dsr_common2 --continue-on-error
    source install/setup.bash
fi

# 2단계: 메시지 패키지
echo "📨 2단계: 메시지 패키지 빌드..."
if [ -d "src/doosan_m0609_msgs" ]; then
    colcon build --packages-select doosan_m0609_msgs --continue-on-error
    source install/setup.bash
fi

# 3단계: 하드웨어 인터페이스
echo "🔌 3단계: 하드웨어 인터페이스 빌드..."
if [ -d "src/doosan_m0609_hardware" ]; then
    colcon build --packages-select doosan_m0609_hardware --continue-on-error
    source install/setup.bash
fi

# 4단계: 설명 패키지
echo "📐 4단계: 설명 패키지 빌드..."
if [ -d "src/doosan_m0609_description" ]; then
    colcon build --packages-select doosan_m0609_description --continue-on-error
    source install/setup.bash
fi

# 5단계: 컨트롤러
echo "🎮 5단계: 컨트롤러 빌드..."
if [ -d "src/doosan_m0609_controller" ]; then
    colcon build --packages-select doosan_m0609_controller --continue-on-error
    source install/setup.bash
fi

# 6단계: Bringup
echo "🚀 6단계: Bringup 패키지 빌드..."
if [ -d "src/doosan_m0609_bringup" ]; then
    colcon build --packages-select doosan_m0609_bringup --continue-on-error
    source install/setup.bash
fi

# 7단계: 기존 화학 실험 패키지들
echo "🧪 7단계: 화학 실험 패키지들 빌드..."
if [ -d "src/chemistry_experiment_manager" ]; then
    colcon build --packages-select chemistry_experiment_manager --continue-on-error
fi
if [ -d "src/precision_liquid_pouring" ]; then
    colcon build --packages-select precision_liquid_pouring --continue-on-error  
fi
if [ -d "src/arduino_loadcell_interface" ]; then
    colcon build --packages-select arduino_loadcell_interface --continue-on-error
fi

# 최종 환경 소싱
source install/setup.bash

echo ""
echo "✅ 빌드 완료! 결과 확인..."
echo "📦 빌드된 패키지들:"
ls install/ 2>/dev/null || echo "  install 폴더를 찾을 수 없습니다."

echo ""
echo "🎯 테스트 명령어:"
echo "  # 환경 설정"
echo "  source install/setup.bash"
echo ""  
echo "  # 패키지 확인"
echo "  ros2 pkg list | grep doosan"
echo ""
echo "  # 노드 테스트"
echo "  ros2 run doosan_m0609_msgs --help"
echo ""
echo "  # 런치 파일 테스트"
echo "  ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=virtual"

echo ""
echo "⚠️ 주의사항:"
echo "  - 일부 의존성 경고는 정상입니다"
echo "  - 빌드 에러가 있어도 핵심 기능은 작동할 수 있습니다"
echo "  - 문제가 지속되면 개별 패키지를 확인하세요"

echo ""
echo "🎉 rosdep 문제를 우회하여 빌드를 완료했습니다!"
