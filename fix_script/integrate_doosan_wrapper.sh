#!/bin/bash
# integrate_doosan_wrapper.sh - 두산 로보틱스 패키지 완전 통합 스크립트

set -e

PROJECT_WS="/home/jack/project_ws"
DOOSAN_SOURCE="/home/jack/DoosanBootcam3rdCo1"

echo "🚀 두산 로보틱스 M0609 패키지 통합 시작..."
echo "📍 프로젝트 워크스페이스: $PROJECT_WS"
echo "📍 소스 패키지: $DOOSAN_SOURCE"

# 디렉토리 존재 확인
if [ ! -d "$DOOSAN_SOURCE" ]; then
    echo "❌ 오류: 소스 디렉토리 $DOOSAN_SOURCE 를 찾을 수 없습니다."
    exit 1
fi

cd $PROJECT_WS/src

# Phase 1: 핵심 패키지 복사 및 이름 변경
echo ""
echo "📦 Phase 1: 핵심 패키지 복사 중..."
echo "  - dsr_hardware2 → doosan_m0609_hardware"
cp -r $DOOSAN_SOURCE/dsr_hardware2 ./doosan_m0609_hardware

echo "  - dsr_msgs2 → doosan_m0609_msgs"  
cp -r $DOOSAN_SOURCE/dsr_msgs2 ./doosan_m0609_msgs

echo "  - dsr_bringup2 → doosan_m0609_bringup"
cp -r $DOOSAN_SOURCE/dsr_bringup2 ./doosan_m0609_bringup

echo "  - dsr_description2 → doosan_m0609_description"
cp -r $DOOSAN_SOURCE/dsr_description2 ./doosan_m0609_description

echo "  - dsr_controller2 → doosan_m0609_controller"
cp -r $DOOSAN_SOURCE/dsr_controller2 ./doosan_m0609_controller

# Phase 2: package.xml 업데이트 (M0609 전용으로)
echo ""
echo "🔧 Phase 2: 패키지 메타데이터 업데이트..."
echo "  - 패키지명 변경: dsr_ → doosan_m0609_"
find . -name "package.xml" -path "./doosan_m0609_*" -exec sed -i 's/dsr_hardware2/doosan_m0609_hardware/g' {} \;
find . -name "package.xml" -path "./doosan_m0609_*" -exec sed -i 's/dsr_msgs2/doosan_m0609_msgs/g' {} \;
find . -name "package.xml" -path "./doosan_m0609_*" -exec sed -i 's/dsr_bringup2/doosan_m0609_bringup/g' {} \;
find . -name "package.xml" -path "./doosan_m0609_*" -exec sed -i 's/dsr_description2/doosan_m0609_description/g' {} \;
find . -name "package.xml" -path "./doosan_m0609_*" -exec sed -i 's/dsr_controller2/doosan_m0609_controller/g' {} \;

echo "  - 패키지 설명 업데이트"
find . -name "package.xml" -path "./doosan_m0609_*" -exec sed -i 's/<description>.*<\/description>/<description>Doosan M0609 Robot ROS2 Wrapper for Chemical Experiments<\/description>/g' {} \;

# Phase 3: CMakeLists.txt 업데이트
echo ""
echo "🏗️ Phase 3: 빌드 설정 업데이트..."
find . -name "CMakeLists.txt" -path "./doosan_m0609_*" -exec sed -i 's/dsr_hardware2/doosan_m0609_hardware/g' {} \;
find . -name "CMakeLists.txt" -path "./doosan_m0609_*" -exec sed -i 's/dsr_msgs2/doosan_m0609_msgs/g' {} \;
find . -name "CMakeLists.txt" -path "./doosan_m0609_*" -exec sed -i 's/dsr_bringup2/doosan_m0609_bringup/g' {} \;
find . -name "CMakeLists.txt" -path "./doosan_m0609_*" -exec sed -i 's/dsr_description2/doosan_m0609_description/g' {} \;
find . -name "CMakeLists.txt" -path "./doosan_m0609_*" -exec sed -i 's/dsr_controller2/doosan_m0609_controller/g' {} \;

# Phase 4: 런치 파일 업데이트
echo ""
echo "🚀 Phase 4: 런치 파일 업데이트..."
find ./doosan_m0609_* -name "*.launch.py" -exec sed -i 's/dsr_hardware2/doosan_m0609_hardware/g' {} \;
find ./doosan_m0609_* -name "*.launch.py" -exec sed -i 's/dsr_msgs2/doosan_m0609_msgs/g' {} \;
find ./doosan_m0609_* -name "*.launch.py" -exec sed -i 's/dsr_bringup2/doosan_m0609_bringup/g' {} \;
find ./doosan_m0609_* -name "*.launch.py" -exec sed -i 's/dsr_description2/doosan_m0609_description/g' {} \;
find ./doosan_m0609_* -name "*.launch.py" -exec sed -i 's/dsr_controller2/doosan_m0609_controller/g' {} \;

# Phase 5: C++ 소스 코드 네임스페이스 업데이트
echo ""
echo "💻 Phase 5: C++ 네임스페이스 업데이트..."
find ./doosan_m0609_* -name "*.hpp" -o -name "*.cpp" -o -name "*.h" | xargs sed -i 's/namespace dsr_hardware2/namespace doosan_m0609_hardware/g' 
find ./doosan_m0609_* -name "*.hpp" -o -name "*.cpp" -o -name "*.h" | xargs sed -i 's/dsr_hardware2::/doosan_m0609_hardware::/g'

# Phase 6: 화학 실험 통합 런치 파일 생성
echo ""
echo "🧪 Phase 6: 화학 실험 통합 런치 파일 생성..."
cat > ./doosan_m0609_bringup/launch/chemical_experiment_system.launch.py << 'EOF'
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
        
        # M0609 로봇 기본 시스템
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                PathJoinSubstitution([
                    FindPackageShare('doosan_m0609_bringup'),
                    'launch',
                    'dsr_bringup2_rviz.launch.py'
                ])
            ]),
            launch_arguments={
                'mode': mode,
                'model': model,
                'host': host,
                'port': port,
                'color': 'white'
            }.items()
        ),
        
        # 화학 실험 매니저 (기존 패키지와 통합)
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
                launch.substitutions.LaunchConfiguration('enable_chemistry_manager', default='true')
            )
        ),
        
        # 정밀 액체 처리 시스템
        Node(
            package='precision_liquid_pouring',
            executable='precision_controller', 
            name='precision_controller',
            parameters=[
                {'collision_sensitivity': 0.2},  # M0609 특화 설정
                {'force_threshold_n': 5.0}
            ],
            condition=launch.conditions.IfCondition(
                launch.substitutions.LaunchConfiguration('enable_liquid_handling', default='true')
            )
        ),
        
        # 아두이노 로드셀 인터페이스
        Node(
            package='arduino_loadcell_interface',
            executable='loadcell_reader',
            name='loadcell_reader',
            parameters=[
                {'serial_port': '/dev/ttyUSB0'},
                {'baud_rate': 115200}
            ],
            condition=launch.conditions.IfCondition(
                launch.substitutions.LaunchConfiguration('enable_loadcell', default='true')
            )
        )
    ])
EOF

echo "  ✅ 화학 실험 통합 런치 파일 생성 완료"

# Phase 7: 실행 권한 설정
echo ""
echo "🔐 Phase 7: 실행 권한 설정..."
chmod +x ./doosan_m0609_bringup/launch/chemical_experiment_system.launch.py

# Phase 8: dsr_common2 병합 확인
echo ""
echo "🔍 Phase 8: 기존 dsr_common2와 충돌 확인..."
if [ -d "dsr_common2" ] && [ -d "$DOOSAN_SOURCE/dsr_common2" ]; then
    echo "  ⚠️ 기존 dsr_common2와 새로운 버전 발견. 수동 병합이 필요할 수 있습니다."
    echo "  💡 다음 명령으로 차이점을 확인하세요:"
    echo "      diff -r dsr_common2 $DOOSAN_SOURCE/dsr_common2"
else
    echo "  ✅ dsr_common2 충돌 없음"
fi

echo ""
echo "✅ 두산 로보틱스 M0609 패키지 통합 완료!"
echo ""
echo "🔧 다음 단계:"
echo "  1. 의존성 설치: cd $PROJECT_WS && rosdep install -r --from-paths src --ignore-src --rosdistro humble -y"
echo "  2. 빌드: colcon build"
echo "  3. 환경 설정: source install/setup.bash"
echo "  4. 시스템 실행: ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py"
echo ""
echo "🚨 주의사항:"
echo "  - 로봇 제어기 IP가 올바른지 확인 (기본값: 192.168.137.100)"
echo "  - 실제 로봇 연결 시 mode:=real 파라미터 사용"
echo "  - 화학물질 취급 시 안전 수칙 준수"
echo ""
echo "🎉 M0609 화학 실험 로봇 시스템 준비 완료!"
