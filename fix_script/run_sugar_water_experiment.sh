#!/bin/bash

# 🧪 Sugar Water Experiment - Quick Run Script
# Author: Jack
# Date: 2024

echo "🧪 Starting Sugar Water Experiment..."

# 환경 설정
cd /home/jaeho/project_ws
source /opt/ros/humble/setup.bash
source install/setup.bash

# 사용자 선택
echo ""
echo "실행할 실험을 선택하세요:"
echo "1) Simple Sequence Controller (단순 좌표 시퀀스)"
echo "2) Full Automated Experiment (완전 자동화 실험)"
echo "3) Launch File with Parameters (매개변수가 있는 런치)"
echo ""
read -p "선택 (1-3): " choice

case $choice in
    1)
        echo "🎯 Starting Simple Sequence Controller..."
        ros2 run sugar_water_experiment simple_sequence_controller
        ;;
    2)
        echo "🤖 Starting Full Automated Experiment..."
        ros2 run sugar_water_experiment sugar_water_experimenter_node
        ;;
    3)
        echo "농도를 입력하세요 (0.01-0.20, 기본값: 0.05):"
        read -p "Target concentration: " concentration
        if [ -z "$concentration" ]; then
            concentration="0.05"
        fi
        
        echo "🚀 Starting experiment with ${concentration} concentration..."
        ros2 launch sugar_water_experiment sugar_water_experiment.launch.py target_concentration:=${concentration}
        ;;
    *)
        echo "❌ Invalid selection. Exiting..."
        exit 1
        ;;
esac
