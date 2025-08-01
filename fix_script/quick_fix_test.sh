#!/bin/bash

# 🔧 Quick Build Test Script
# Author: Jack
# Date: 2024

echo "🧪 Testing build fixes for project_ws..."

# 작업 디렉토리로 이동
cd /home/jaeho/project_ws

# ROS2 환경 설정
source /opt/ros/humble/setup.bash

echo "📋 Testing specific packages that had errors..."

# 1. Description 패키지 테스트
echo "1️⃣ Testing doosan_m0609_description..."
colcon build --packages-select doosan_m0609_description --cmake-args -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]; then
    echo "✅ doosan_m0609_description build SUCCESS"
else
    echo "❌ doosan_m0609_description build FAILED"
fi

echo ""

# 2. Controller 패키지 테스트
echo "2️⃣ Testing doosan_m0609_controller..."
colcon build --packages-select doosan_m0609_controller --cmake-args -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]; then
    echo "✅ doosan_m0609_controller build SUCCESS"
else
    echo "❌ doosan_m0609_controller build FAILED"
fi

echo ""

# 3. Sugar water experiment 테스트
echo "3️⃣ Testing sugar_water_experiment..."
colcon build --packages-select sugar_water_experiment --cmake-args -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]; then
    echo "✅ sugar_water_experiment build SUCCESS"
else
    echo "❌ sugar_water_experiment build FAILED"
fi

echo ""
echo "🎯 Quick test completed!"
echo "💡 If all passed, run full build with: ./complete_build.sh"
