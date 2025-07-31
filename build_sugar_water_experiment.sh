#!/bin/bash

# 🧪 Sugar Water Experiment - Build and Run Script (Fixed)
# Author: Jack
# Date: 2024

echo "🚀 Building Sugar Water Experiment Package..."

# 작업 디렉토리로 이동
cd /home/jack/project_ws

# ROS2 환경 설정
source /opt/ros/humble/setup.bash

# 의존성 설치 (필요한 경우)
echo "📋 Installing dependencies..."
sudo apt update
sudo apt install -y ros-humble-geometry-msgs ros-humble-sensor-msgs ros-humble-std-msgs

# rosdep으로 의존성 해결
echo "🔧 Resolving dependencies with rosdep..."
rosdep update
rosdep install --from-paths src --ignore-src -r -y

# 특정 패키지만 빌드 (의존성 없이)
echo "📦 Building sugar_water_experiment package..."
colcon build --packages-select sugar_water_experiment --cmake-args -DCMAKE_BUILD_TYPE=Release

if [ $? -eq 0 ]; then
    echo "✅ Build successful!"
    
    # 빌드된 패키지 환경 설정
    source install/setup.bash
    
    echo ""
    echo "🧪 Available executables:"
    echo "  1. simple_sequence_controller - Simple pose sequence execution"
    echo "  2. sugar_water_experimenter_node - Full automated experiment"
    echo ""
    echo "📋 Usage examples:"
    echo "  # Run simple sequence controller:"
    echo "  ros2 run sugar_water_experiment simple_sequence_controller"
    echo ""
    echo "  # Run full experiment:"
    echo "  ros2 run sugar_water_experiment sugar_water_experimenter_node"
    echo ""
    echo "  # Run with launch file:"
    echo "  ros2 launch sugar_water_experiment sugar_water_experiment.launch.py"
    echo ""
    echo "  # Check available topics:"
    echo "  ros2 topic list"
    echo ""
    
    # 실행 권한 확인
    if [ -f "install/sugar_water_experiment/lib/sugar_water_experiment/simple_sequence_controller" ]; then
        chmod +x install/sugar_water_experiment/lib/sugar_water_experiment/simple_sequence_controller
        echo "✅ simple_sequence_controller executable ready"
    fi
    
    if [ -f "install/sugar_water_experiment/lib/sugar_water_experiment/sugar_water_experimenter_node" ]; then
        chmod +x install/sugar_water_experiment/lib/sugar_water_experiment/sugar_water_experimenter_node
        echo "✅ sugar_water_experimenter_node executable ready"
    fi
    
    echo ""
    echo "🎯 Ready to run experiment!"
    echo "💡 Tip: 먼저 'simple_sequence_controller'로 테스트해보세요!"
    
else
    echo "❌ Build failed! Checking common issues..."
    echo ""
    echo "🔍 Troubleshooting steps:"
    echo "1. Check ROS2 installation:"
    echo "   ros2 --version"
    echo ""
    echo "2. Verify dependencies:"
    echo "   apt list --installed | grep ros-humble"
    echo ""
    echo "3. Clean build and retry:"
    echo "   rm -rf build/ install/ log/"
    echo "   colcon build --packages-select sugar_water_experiment"
    echo ""
    exit 1
fi
