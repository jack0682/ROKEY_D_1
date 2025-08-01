#!/bin/bash

# 🚀 Project Workspace - Complete Build Script
# Author: Jack
# Date: 2024

echo "🏗️ Building Complete Project Workspace..."

# 작업 디렉토리로 이동
cd /home/jaeho/project_ws

# ROS2 환경 설정
source /opt/ros/humble/setup.bash

echo "📋 Available packages:"
ls -1 src/
echo ""

# 의존성 설치
echo "🔧 Installing system dependencies..."
sudo apt update
sudo apt install -y \
    ros-humble-geometry-msgs \
    ros-humble-sensor-msgs \
    ros-humble-std-msgs \
    ros-humble-ament-cmake \
    python3-colcon-common-extensions

# rosdep으로 의존성 해결
echo "📦 Resolving ROS dependencies..."
rosdep update
rosdep install --from-paths src --ignore-src -r -y

echo ""
echo "🔨 Building packages in order..."

# 1단계: 기본 메시지 패키지들 먼저 빌드
echo "1️⃣ Building message packages..."
colcon build --packages-select doosan_m0609_msgs --cmake-args -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]; then
    echo "✅ doosan_m0609_msgs built successfully"
    source install/setup.bash
else
    echo "⚠️ doosan_m0609_msgs build failed, continuing..."
fi

# 2단계: 공통 패키지들
echo "2️⃣ Building common packages..."
colcon build --packages-select dsr_common2 --cmake-args -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]; then
    echo "✅ dsr_common2 built successfully"
    source install/setup.bash
else
    echo "⚠️ dsr_common2 build failed, continuing..."
fi

# 3단계: 하드웨어 및 설명 패키지들
echo "3️⃣ Building hardware packages..."
for pkg in doosan_m0609_description doosan_m0609_hardware; do
    echo "Building $pkg..."
    colcon build --packages-select $pkg --cmake-args -DCMAKE_BUILD_TYPE=Release
    if [ $? -eq 0 ]; then
        echo "✅ $pkg built successfully"
        source install/setup.bash
    else
        echo "⚠️ $pkg build failed, continuing..."
    fi
done

# 4단계: 컨트롤러 패키지
echo "4️⃣ Building controller packages..."
colcon build --packages-select doosan_m0609_controller --cmake-args -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]; then
    echo "✅ doosan_m0609_controller built successfully"
    source install/setup.bash
else
    echo "⚠️ doosan_m0609_controller build failed, continuing..."
fi

# 5단계: Python 패키지들
echo "5️⃣ Building Python packages..."
for pkg in arduino_loadcell_interface precision_liquid_pouring chemistry_experiment_manager; do
    if [ -d "src/$pkg" ]; then
        echo "Building $pkg..."
        colcon build --packages-select $pkg
        if [ $? -eq 0 ]; then
            echo "✅ $pkg built successfully"
            source install/setup.bash
        else
            echo "⚠️ $pkg build failed, continuing..."
        fi
    else
        echo "📁 $pkg directory not found, skipping..."
    fi
done

# 6단계: Bringup 패키지
echo "6️⃣ Building bringup packages..."
colcon build --packages-select doosan_m0609_bringup --cmake-args -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]; then
    echo "✅ doosan_m0609_bringup built successfully"
    source install/setup.bash
else
    echo "⚠️ doosan_m0609_bringup build failed, continuing..."
fi

# 7단계: 마지막으로 우리 실험 패키지
echo "7️⃣ Building sugar_water_experiment..."
colcon build --packages-select sugar_water_experiment --cmake-args -DCMAKE_BUILD_TYPE=Release
if [ $? -eq 0 ]; then
    echo "✅ sugar_water_experiment built successfully"
    source install/setup.bash
else
    echo "❌ sugar_water_experiment build failed"
fi

echo ""
echo "📊 Build Summary:"
echo "=================="

# 빌드된 패키지 확인
if [ -d "install" ]; then
    echo "Successfully built packages:"
    ls -1 install/ | grep -v "_colcon_" | sed 's/^/  ✅ /'
    echo ""
    
    echo "🎯 Available executables:"
    if [ -f "install/sugar_water_experiment/lib/sugar_water_experiment/simple_sequence_controller" ]; then
        echo "  🧪 ros2 run sugar_water_experiment simple_sequence_controller"
    fi
    if [ -f "install/sugar_water_experiment/lib/sugar_water_experiment/sugar_water_experimenter_node" ]; then
        echo "  🤖 ros2 run sugar_water_experiment sugar_water_experimenter_node"
    fi
    
    echo ""
    echo "🚀 Ready to run experiments!"
    echo "💡 First run: source install/setup.bash"
    
else
    echo "❌ No packages were built successfully"
fi
