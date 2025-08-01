#!/bin/bash
# run_real_robot.sh - 실제 로봇 모드 실행

echo "🚨 실제 로봇 모드 - 안전 주의사항 확인!"
echo "1. 로봇 전원 및 네트워크 연결 확인"
echo "2. 작업공간 내 장애물 제거"
echo "3. 비상 정지 버튼 위치 확인"
echo ""

read -p "위 사항을 모두 확인했습니까? (yes/no): " confirm
if [[ $confirm != "yes" ]]; then
    echo "안전 확인 후 다시 실행해주세요."
    exit 1
fi

echo "🔗 로봇 연결 확인 중..."
if ! ping -c 1 192.168.137.100 >/dev/null 2>&1; then
    echo "❌ 로봇 컨트롤러에 연결할 수 없습니다 (192.168.137.100)"
    echo "네트워크 설정을 확인해주세요."
    exit 1
fi

echo "✅ 로봇 연결 확인됨"
source install/setup.bash

echo "🚀 화학 실험 시스템 시작..."
ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=real
