#!/bin/bash
# switch_structure.sh - 구조 전환 헬퍼 스크립트

echo "🔄 Doosan ROS2 구조 전환 도구"
echo ""

if [[ -L "src/dsr_bringup2" ]]; then
    echo "📍 현재: 새로운 구조 (DSR 2.0) 활성화됨"
    echo ""
    echo "사용 가능한 실행 스크립트:"
    echo "  ./run_new_rviz.sh      - RViz 시각화"
    echo "  ./run_new_emulator.sh  - 에뮬레이터 모드"
    echo "  ./run_new_real_robot.sh - 실제 로봇 연결"
    echo ""
    echo "주요 런치 파일:"
    echo "  ros2 launch dsr_bringup2 dsr_bringup2_rviz.launch.py"
    echo "  ros2 launch dsr_bringup2 dsr_bringup2_gazebo.launch.py"
    echo "  ros2 launch dsr_bringup2 dsr_bringup2_moveit.launch.py"
    echo ""
elif [[ -d "src/doosan_m0609_msgs" ]]; then
    echo "📍 현재: 기존 구조 (M0609) 활성화됨"
    echo ""
    echo "사용 가능한 실행 스크립트:"
    echo "  ./run_simulation.sh  - 시뮬레이션 모드"
    echo "  ./run_real_robot.sh  - 실제 로봇 연결"
    echo ""
else
    echo "❌ 알 수 없는 구조 상태"
    echo "src 디렉토리를 확인해주세요."
fi

echo ""
echo "공통 도구:"
echo "  ./test_sensors.sh    - 센서 및 연결 테스트"
echo "  ros2 doctor          - ROS2 시스템 진단"
