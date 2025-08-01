#!/bin/bash

# 🧪 Sugar Water Experiment - Simple Build Script
# Author: Jack
# Date: 2024

echo "🚀 Simple Build for Sugar Water Experiment..."

# 작업 디렉토리로 이동
cd /home/jaeho/project_ws

# ROS2 환경 설정
source /opt/ros/humble/setup.bash

# 기존 빌드 정리
echo "🧹 Cleaning previous build..."
rm -rf build/sugar_water_experiment install/sugar_water_experiment log/sugar_water_experiment

# 단순 빌드 (의존성 무시)
echo "📦 Building with minimal dependencies..."
colcon build --packages-select sugar_water_experiment

# 결과 확인
if [ $? -eq 0 ]; then
    echo "✅ Build successful!"
    source install/setup.bash
    
    echo ""
    echo "🎯 테스트 실행:"
    echo "ros2 run sugar_water_experiment simple_sequence_controller"
    echo ""
else
    echo "❌ Build failed. Let's try manual approach..."
    echo ""
    echo "수동 빌드를 시도해보세요:"
    echo "cd ~/project_ws"
    echo "source /opt/ros/humble/setup.bash"
    echo "colcon build --packages-select sugar_water_experiment --continue-on-error"
fi
