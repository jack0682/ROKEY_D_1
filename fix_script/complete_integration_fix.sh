#!/bin/bash
# complete_integration_fix.sh - 완전한 통합 및 문제 해결

set -e

echo "🚀 완전한 두산 M0609 패키지 통합 및 문제 해결 시작..."

PROJECT_WS="/home/jack/project_ws"
DOOSAN_SOURCE="/home/jack/DoosanBootcam3rdCo1"

cd $PROJECT_WS

# 1. 소스 확인
echo "📍 소스 디렉토리 확인..."
if [ ! -d "$DOOSAN_SOURCE" ]; then
    echo "❌ 오류: $DOOSAN_SOURCE 디렉토리를 찾을 수 없습니다."
    echo "💡 해결방법: 두산 소스 패키지가 올바른 위치에 있는지 확인하세요."
    exit 1
fi

echo "✅ 두산 소스 발견: $DOOSAN_SOURCE"

# 2. 기존 빌드 정리
echo ""
echo "🧹 기존 빌드 정리..."
rm -rf build/ install/ log/

# 3. 패키지 통합 (integrate_doosan_wrapper.sh 내용 직접 실행)
echo ""
echo "📦 패키지 통합 실행..."

# 핵심 패키지 복사
echo "  - dsr_hardware2 → doosan_m0609_hardware"
cp -r $DOOSAN_SOURCE/dsr_hardware2 ./src/doosan_m0609_hardware

echo "  - dsr_msgs2 → doosan_m0609_msgs"  
cp -r $DOOSAN_SOURCE/dsr_msgs2 ./src/doosan_m0609_msgs

echo "  - dsr_bringup2 → doosan_m0609_bringup"
cp -r $DOOSAN_SOURCE/dsr_bringup2 ./src/doosan_m0609_bringup

echo "  - dsr_description2 → doosan_m0609_description"
cp -r $DOOSAN_SOURCE/dsr_description2 ./src/doosan_m0609_description

echo "  - dsr_controller2 → doosan_m0609_controller"
cp -r $DOOSAN_SOURCE/dsr_controller2 ./src/doosan_m0609_controller

# 4. package.xml 업데이트
echo ""
echo "🔧 패키지 메타데이터 업데이트..."
find ./src/doosan_m0609_* -name "package.xml" -exec sed -i 's/dsr_hardware2/doosan_m0609_hardware/g' {} \;
find ./src/doosan_m0609_* -name "package.xml" -exec sed -i 's/dsr_msgs2/doosan_m0609_msgs/g' {} \;
find ./src/doosan_m0609_* -name "package.xml" -exec sed -i 's/dsr_bringup2/doosan_m0609_bringup/g' {} \;
find ./src/doosan_m0609_* -name "package.xml" -exec sed -i 's/dsr_description2/doosan_m0609_description/g' {} \;
find ./src/doosan_m0609_* -name "package.xml" -exec sed -i 's/dsr_controller2/doosan_m0609_controller/g' {} \;

# 5. CMakeLists.txt 업데이트
echo "🏗️ 빌드 설정 업데이트..."
find ./src/doosan_m0609_* -name "CMakeLists.txt" -exec sed -i 's/dsr_hardware2/doosan_m0609_hardware/g' {} \;
find ./src/doosan_m0609_* -name "CMakeLists.txt" -exec sed -i 's/dsr_msgs2/doosan_m0609_msgs/g' {} \;
find ./src/doosan_m0609_* -name "CMakeLists.txt" -exec sed -i 's/dsr_bringup2/doosan_m0609_bringup/g' {} \;
find ./src/doosan_m0609_* -name "CMakeLists.txt" -exec sed -i 's/dsr_description2/doosan_m0609_description/g' {} \;
find ./src/doosan_m0609_* -name "CMakeLists.txt" -exec sed -i 's/dsr_controller2/doosan_m0609_controller/g' {} \;

# 6. 런치 파일 업데이트
echo "🚀 런치 파일 업데이트..."
find ./src/doosan_m0609_* -name "*.launch.py" -exec sed -i 's/dsr_hardware2/doosan_m0609_hardware/g' {} \;
find ./src/doosan_m0609_* -name "*.launch.py" -exec sed -i 's/dsr_msgs2/doosan_m0609_msgs/g' {} \;
find ./src/doosan_m0609_* -name "*.launch.py" -exec sed -i 's/dsr_bringup2/doosan_m0609_bringup/g' {} \;
find ./src/doosan_m0609_* -name "*.launch.py" -exec sed -i 's/dsr_description2/doosan_m0609_description/g' {} \;
find ./src/doosan_m0609_* -name "*.launch.py" -exec sed -i 's/dsr_controller2/doosan_m0609_controller/g' {} \;

# 7. 화학 실험 통합 런치 파일 생성
echo ""
echo "🧪 화학 실험 통합 런치 파일 생성..."
mkdir -p ./src/doosan_m0609_bringup/launch

cat > ./src/doosan_m0609_bringup/launch/chemical_experiment_system.launch.py << 'EOF'
#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    # Launch configuration variables
    mode = LaunchConfiguration('mode')
    model = LaunchConfiguration('model') 
    host = LaunchConfiguration('host')
    port = LaunchConfiguration('port')
    
    return LaunchDescription([
        # Launch arguments
        DeclareLaunchArgument('mode', default_value='virtual', description='Robot mode: real or virtual'),
        DeclareLaunchArgument('model', default_value='m0609', description='Robot model'),
        DeclareLaunchArgument('host', default_value='192.168.137.100', description='Robot controller IP'),
        DeclareLaunchArgument('port', default_value='12345', description='Robot controller port'),
        
        # 기본 ROS2 노드들
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            parameters=[{
                'robot_description': 'Doosan M0609 Chemical Experiment Robot'
            }]
        ),
        
        # 화학 실험 매니저 (조건부)
        Node(
            package='chemistry_experiment_manager',
            executable='experiment_coordinator',
            name='experiment_coordinator',
            parameters=[
                {'robot_model': 'm0609'},
                {'max_payload_kg': 6.0},
                {'max_reach_mm': 900.0}
            ],
            condition=launch.conditions.IfCondition(
                launch.substitutions.Command(['test -d ', PathJoinSubstitution([FindPackageShare('chemistry_experiment_manager')])])
            )
        ),
        
    ])
EOF

chmod +x ./src/doosan_m0609_bringup/launch/chemical_experiment_system.launch.py

# 8. 필수 의존성 설치
echo ""
echo "📦 필수 의존성 설치..."
sudo apt-get update
sudo apt-get install -y \
    ros-humble-robot-state-publisher \
    ros-humble-joint-state-publisher \
    ros-humble-xacro \
    libpoco-dev \
    libyaml-cpp-dev

# 9. ROS2 환경 설정
echo ""
echo "🔄 ROS2 환경 설정..."
source /opt/ros/humble/setup.bash

# 10. 단계별 빌드
echo ""
echo "🏗️ 단계별 빌드 시작..."

echo "1️⃣ dsr_common2 빌드..."
if [ -d "src/dsr_common2" ]; then
    colcon build --packages-select dsr_common2
    source install/setup.bash
fi

echo "2️⃣ doosan_m0609_msgs 빌드..."
colcon build --packages-select doosan_m0609_msgs
source install/setup.bash

echo "3️⃣ doosan_m0609_hardware 빌드..."
colcon build --packages-select doosan_m0609_hardware
source install/setup.bash

echo "4️⃣ doosan_m0609_description 빌드..."
colcon build --packages-select doosan_m0609_description
source install/setup.bash

echo "5️⃣ doosan_m0609_controller 빌드..."
colcon build --packages-select doosan_m0609_controller
source install/setup.bash

echo "6️⃣ doosan_m0609_bringup 빌드..."
colcon build --packages-select doosan_m0609_bringup
source install/setup.bash

# 11. DSV 파일 문제 수정
echo ""
echo "🔧 DSV 파일 문제 수정..."
find install/ -name "*.dsv" -exec sed -i '/^$/d' {} \; 2>/dev/null || true

# 12. 최종 테스트
echo ""
echo "✅ 통합 및 빌드 완료!"
echo ""
echo "📦 설치된 패키지들:"
ls install/

echo ""
echo "🎯 테스트 명령어:"
echo "  source install/setup.bash"
echo "  ros2 pkg list | grep doosan"
echo "  ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=virtual"

echo ""
echo "🎉 두산 M0609 화학 실험 로봇 시스템 통합 완료!"
