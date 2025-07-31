#!/bin/bash
# Day 1 패키지들만 빌드

cd /home/jaeho/project_ws
source /opt/ros/humble/setup.bash

echo "🔨 Day 1 패키지 빌드: chemistry_msgs + arduino_loadcell_interface"

colcon build --packages-select \
    chemistry_msgs \
    arduino_loadcell_interface

echo "✅ Day 1 빌드 완료!"
source install/setup.bash
