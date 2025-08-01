#!/bin/bash
# run_simulation.sh - 시뮬레이션 모드 실행

echo "🤖 Doosan M0609 시뮬레이션 시작..."
source install/setup.bash

echo "📍 10개 좌표 순차 실행 중..."
ros2 run sugar_water_experiment simple_sequence_controller
