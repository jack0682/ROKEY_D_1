#!/bin/bash
# run_new_real_robot.sh - 새로운 구조 실제 로봇 연결

echo "🚨 새로운 구조 실제 로봇 모드 - 안전 주의사항 확인!"
echo "1. 로봇 전원 및 네트워크 연결 확인 (192.168.1.100)"
echo "2. 실시간 제어 인터페이스 연결 확인 (192.168.1.50)"
echo "3. 작업공간 내 장애물 제거"
echo "4. 비상 정지 버튼 위치 확인"
echo ""

read -p "위 사항을 모두 확인했습니까? (yes/no): " confirm
if [[ $confirm != "yes" ]]; then
    echo "안전 확인 후 다시 실행해주세요."
    exit 1
fi

echo "🔗 로봇 제어기 연결 확인 중..."
if ! ping -c 1 192.168.1.100 >/dev/null 2>&1; then
    echo "❌ 로봇 제어기에 연결할 수 없습니다 (192.168.1.100)"
    echo "네트워크 설정을 확인해주세요."
    exit 1
fi

echo "🔗 실시간 제어 인터페이스 연결 확인 중..."
if ! ping -c 1 192.168.1.50 >/dev/null 2>&1; then
    echo "❌ 실시간 제어 인터페이스에 연결할 수 없습니다 (192.168.1.50)"
    echo "실시간 제어 네트워크 설정을 확인해주세요."
    exit 1
fi

echo "✅ 로봇 연결 확인됨"
source install/setup.bash

echo "🤖 실제 로봇과 연결하여 시스템 시작..."
ros2 launch dsr_bringup2 dsr_bringup2_rviz.launch.py \
    name:=dsr01 \
    model:=m1013 \
    host:=192.168.1.100 \
    rt_host:=192.168.1.50 \
    mode:=real \
    gui:=true
