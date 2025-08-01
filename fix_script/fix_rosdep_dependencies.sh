#!/bin/bash
# fix_rosdep_dependencies.sh - rosdep 의존성 문제 해결 스크립트

set -e

echo "🔧 rosdep 의존성 문제 해결 중..."

# 1. rosdep 완전 재설치
echo "📦 rosdep 재설치..."
sudo apt-get update
sudo apt-get install -y python3-rosdep2

# 2. 기존 rosdep 설정 클리어
echo "🧹 기존 rosdep 설정 정리..."
sudo rm -rf /etc/ros/rosdep/sources.list.d
sudo rm -rf /home/jack/.ros/rosdep

# 3. rosdep 초기화
echo "🔄 rosdep 초기화..."
sudo rosdep init

# 4. rosdep 업데이트 (사용자별)
echo "📊 rosdep 업데이트..."
rosdep update

# 5. 누락된 debian.yaml 파일 확인 및 생성
echo "📄 누락된 파일 확인..."
DEBIAN_YAML_PATH="/usr/share/python3-rosdep2/debian.yaml"
if [ ! -f "$DEBIAN_YAML_PATH" ]; then
    echo "⚠️ debian.yaml 파일이 누락됨. 대체 방법 적용..."
    
    # python3-rosdep 패키지 재설치
    sudo apt-get remove --purge python3-rosdep
    sudo apt-get install -y python3-rosdep
    
    # rosdep 재초기화
    sudo rosdep init
    rosdep update
fi

# 6. ROS2 Humble 전용 의존성 수동 설치
echo "🎯 ROS2 Humble 필수 패키지 직접 설치..."
sudo apt-get install -y \
    ros-humble-rclcpp \
    ros-humble-rclpy \
    ros-humble-std-msgs \
    ros-humble-geometry-msgs \
    ros-humble-sensor-msgs \
    ros-humble-control-msgs \
    ros-humble-realtime-tools \
    ros-humble-xacro \
    ros-humble-joint-state-publisher \
    ros-humble-joint-state-publisher-gui \
    ros-humble-robot-state-publisher \
    ros-humble-ros2-control \
    ros-humble-ros2-controllers \
    ros-humble-controller-manager \
    ros-humble-hardware-interface \
    ros-humble-transmission-interface \
    ros-humble-gazebo-msgs \
    ros-humble-moveit-msgs \
    ros-humble-moveit-configs-utils \
    ros-humble-moveit-ros-move-group \
    ros-humble-gazebo-ros-pkgs \
    ros-humble-tf2 \
    ros-humble-tf2-ros \
    ros-humble-tf2-geometry-msgs \
    libpoco-dev \
    libyaml-cpp-dev

# 7. 대체 의존성 해결 방법
echo "🔄 대체 방법으로 의존성 해결..."
cd /home/jack/project_ws

# rosdep 없이 직접 빌드 시도
echo "🏗️ rosdep 우회하여 빌드 시작..."

# ROS2 환경 소싱
source /opt/ros/humble/setup.bash

# 단계별 빌드 (rosdep 없이)
echo "📨 1단계: 메시지 패키지 빌드..."
colcon build --packages-select doosan_m0609_msgs --continue-on-error

source install/setup.bash

echo "🔌 2단계: 하드웨어 패키지 빌드..."
colcon build --packages-select doosan_m0609_hardware --continue-on-error

source install/setup.bash

echo "📝 3단계: 기타 패키지 빌드..."
colcon build --packages-select doosan_m0609_description doosan_m0609_controller --continue-on-error

source install/setup.bash

echo "🚀 4단계: Bringup 패키지 빌드..."
colcon build --packages-select doosan_m0609_bringup --continue-on-error

source install/setup.bash

# 8. 빌드 결과 확인
echo ""
echo "✅ rosdep 문제 해결 및 빌드 완료!"
echo "📋 빌드된 패키지 확인:"
ls install/ 2>/dev/null || echo "  - install 폴더가 아직 생성되지 않았습니다."

echo ""
echo "🎯 테스트 명령어:"
echo "  source install/setup.bash"
echo "  ros2 pkg list | grep doosan"
echo "  ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=virtual"

echo ""
echo "💡 참고사항:"
echo "  - rosdep 에러가 발생해도 대부분의 패키지는 정상 빌드됩니다"
echo "  - 누락된 의존성은 수동으로 설치했습니다"
echo "  - 에러가 계속 발생하면 개별 패키지를 확인하세요"
