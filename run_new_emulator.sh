#!/bin/bash
# run_new_emulator.sh - 새로운 구조 에뮬레이터 실행

echo "🤖 새로운 구조 DSR 에뮬레이터 시작..."

# 에뮬레이터 설치 확인
if [[ -f "../DoosanBootcam3rdCo1/install_emulator.sh" ]]; then
    echo "📦 에뮬레이터 설치 중..."
    cd ../DoosanBootcam3rdCo1
    ./install_emulator.sh
    cd - > /dev/null
else
    echo "⚠️ 에뮬레이터 설치 스크립트를 찾을 수 없습니다."
fi

source install/setup.bash

echo "🚀 가상 모드로 로봇 시스템 시작..."
ros2 launch dsr_bringup2 dsr_bringup2_rviz.launch.py \
    name:=dsr01 \
    model:=m1013 \
    host:=127.0.0.1 \
    mode:=virtual \
    gui:=true
