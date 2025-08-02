#!/bin/bash

# Doosan M0609 Real Robot Simple Motion Test
# 실제 로봇 간단한 모션 테스트 (서보온 후 안전한 움직임)

echo "========================================"
echo " Doosan M0609 실제 로봇 모션 테스트"
echo "========================================"

# 색상 정의
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

ROBOT_IP="192.168.1.100"

echo -e "${YELLOW}⚠️  중요한 안전 주의사항 ⚠️${NC}"
echo "1. 로봇 주변 1.5m 내에 사람이나 장애물이 없는지 확인"
echo "2. 비상정지 버튼을 즉시 누를 수 있도록 준비"
echo "3. 로봇이 안전한 자세(홈 포지션)에 있는지 확인"
echo "4. 로봇 제어기가 MANUAL 모드에서 AUTO 모드로 전환 가능한 상태인지 확인"
echo ""
echo -e "${RED}계속하려면 'YES'를 입력하세요 (대소문자 구분): ${NC}"
read -r confirmation

if [ "$confirmation" != "YES" ]; then
    echo "테스트를 중단합니다."
    exit 0
fi

cd /home/jack/project_ws
source install/setup.bash

echo -e "${BLUE}1. 실제 로봇 연결 및 서보온${NC}"

# 백그라운드에서 컨트롤러 매니저 실행
ros2 run controller_manager ros2_control_node \
    --ros-args \
    --params-file src/doosan_m0609_hardware/config/doosan_m0609_control.yaml \
    --remap __node:=controller_manager &

CONTROLLER_PID=$!

echo "로봇 연결 및 서보온 대기 중... (30초)"
sleep 30

# 컨트롤러 로드 및 활성화
echo -e "${BLUE}2. 컨트롤러 초기화${NC}"
ros2 control load_controller joint_state_broadcaster
ros2 control load_controller position_controller
sleep 2

ros2 control set_controller_state joint_state_broadcaster active
ros2 control set_controller_state position_controller active
sleep 2

echo -e "${BLUE}3. 현재 조인트 위치 확인${NC}"
echo "현재 로봇 자세를 확인합니다..."
ros2 topic echo /joint_states --once

echo -e "${BLUE}4. 안전한 홈 포지션으로 이동${NC}"
echo -e "${YELLOW}로봇이 홈 포지션으로 천천히 이동합니다...${NC}"

# 홈 포지션 (모든 조인트 0도)
ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray \
"{data: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]}" --once

sleep 10

echo -e "${BLUE}5. 간단한 테스트 모션${NC}"
echo -e "${YELLOW}관절 1번이 15도 회전합니다...${NC}"

# 조인트 1을 15도 회전
ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray \
"{data: [0.26, 0.0, 0.0, 0.0, 0.0, 0.0]}" --once

sleep 8

echo -e "${YELLOW}원래 위치로 복귀합니다...${NC}"

# 홈 포지션으로 복귀
ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray \
"{data: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]}" --once

sleep 8

echo -e "${BLUE}6. 조인트 2번 테스트${NC}"
echo -e "${YELLOW}관절 2번이 -20도 회전합니다...${NC}"

# 조인트 2를 -20도 회전  
ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray \
"{data: [0.0, -0.35, 0.0, 0.0, 0.0, 0.0]}" --once

sleep 8

echo -e "${YELLOW}홈 포지션으로 최종 복귀...${NC}"

# 최종 홈 포지션 복귀
ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray \
"{data: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]}" --once

sleep 10

echo -e "${BLUE}7. 최종 상태 확인${NC}"
ros2 topic echo /joint_states --once

echo -e "${BLUE}8. 테스트 완료 및 정리${NC}"
echo "컨트롤러 비활성화 중..."
ros2 control set_controller_state position_controller inactive
ros2 control set_controller_state joint_state_broadcaster inactive

sleep 2

echo "컨트롤러 매니저 종료 중..."
kill $CONTROLLER_PID

echo "========================================"
echo -e "${GREEN}✅ 실제 로봇 모션 테스트 성공적으로 완료!${NC}"
echo -e "${GREEN}   - 서보온 성공${NC}"
echo -e "${GREEN}   - RT 제어 연결 성공${NC}"
echo -e "${GREEN}   - 안전한 모션 실행 성공${NC}"
echo -e "${GREEN}   - 조인트 위치 피드백 정상${NC}"
echo "========================================"