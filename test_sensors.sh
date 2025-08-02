#!/bin/bash
# test_sensors.sh - 센서 시스템 테스트

echo "📊 센서 시스템 테스트..."
source install/setup.bash

echo "1. ROS2 통신 상태 확인"
ros2 doctor

echo ""
echo "2. 토픽 리스트 확인"
timeout 3s ros2 topic list || echo "⚠️ ROS2 데몬 연결 확인 필요"

echo ""
echo "3. 로봇 상태 확인 (3초 대기)"
timeout 3s ros2 topic echo /joint_states --once || echo "⚠️ 로봇 연결 확인 필요"

echo ""
echo "4. 아두이노 시리얼 포트 확인"
if ls /dev/ttyUSB* /dev/ttyACM* 2>/dev/null; then
    echo "✅ 시리얼 디바이스 발견"
else
    echo "⚠️ 아두이노 연결 확인 필요"
fi

echo ""
echo "5. Docker 상태 확인 (에뮬레이터용)"
if command -v docker &> /dev/null; then
    docker ps -a | grep emulator || echo "⚠️ 에뮬레이터 컨테이너 없음"
else
    echo "⚠️ Docker 설치 확인 필요"
fi
