#!/bin/bash
# run_new_rviz.sh - 새로운 구조 RViz 시각화 실행

echo "🎨 새로운 구조 DSR RViz 시각화 시작..."
source install/setup.bash

echo "📊 Doosan 로봇 RViz 시각화 중..."
ros2 launch dsr_bringup2 dsr_bringup2_rviz.launch.py \
    name:=dsr01 \
    model:=m1013 \
    host:=127.0.0.1 \
    mode:=virtual
