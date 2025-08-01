#!/bin/bash
# test_sensors.sh - 센서 시스템 테스트

echo "📊 센서 시스템 테스트..."
source install/setup.bash

echo "1. 아두이노 로드셀 테스트"
timeout 5s ros2 run arduino_loadcell_interface loadcell_reader || echo "⚠️ 로드셀 연결 확인 필요"

echo "2. 로봇 상태 확인"
timeout 3s ros2 topic echo /joint_states --once || echo "⚠️ 로봇 연결 확인 필요"

echo "3. ROS2 통신 상태 확인"
ros2 doctor
