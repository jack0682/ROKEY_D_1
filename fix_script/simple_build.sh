#!/bin/bash
# simple_build.sh - Poco 의존성 없이 빌드

set -e

GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

echo -e "${GREEN}🚀 Simple Build - Poco 의존성 없이 빌드${NC}"

# 1. 환경 설정
echo -e "${BLUE}🔹 환경 설정...${NC}"
source /opt/ros/humble/setup.bash

# 2. 이전 빌드 정리
echo -e "${BLUE}🔹 이전 빌드 정리...${NC}"
rm -rf build/doosan_m0609_controller install/doosan_m0609_controller

# 3. 빌드 시도
echo -e "${BLUE}🔹 빌드 시작...${NC}"
if colcon build --packages-select doosan_m0609_controller --cmake-args -DCMAKE_BUILD_TYPE=Release -DHAVE_POCO=0; then
    echo -e "${GREEN}✅ 빌드 성공!${NC}"
else
    echo -e "${RED}❌ 빌드 실패${NC}"
    echo "오류 로그:"
    cat log/latest_build/doosan_m0609_controller/stderr.log 2>/dev/null || echo "로그 파일 없음"
    exit 1
fi

# 4. 테스트
echo -e "${BLUE}🔹 빌드 결과 확인...${NC}"
source install/setup.bash

if [ -f "install/doosan_m0609_controller/lib/doosan_m0609_controller/doosan_controller_node" ]; then
    echo -e "${GREEN}✅ 실행 파일 생성됨${NC}"
    ls -la install/doosan_m0609_controller/lib/doosan_m0609_controller/
else
    echo -e "${RED}❌ 실행 파일 생성 실패${NC}"
    exit 1
fi

# 5. 간단한 실행 테스트
echo -e "${BLUE}🔹 노드 실행 테스트 (3초)...${NC}"
timeout 3s ros2 run doosan_m0609_controller doosan_controller_node --ros-args --log-level INFO || {
    if [ $? -eq 124 ]; then
        echo -e "${GREEN}✅ 노드 정상 실행됨 (타임아웃으로 종료)${NC}"
    else
        echo -e "${RED}❌ 노드 실행 실패${NC}"
        exit 1
    fi
}

echo -e "${GREEN}🎉 빌드 완료!${NC}"
echo ""
echo "사용법:"
echo "  ros2 run doosan_m0609_controller doosan_controller_node"
echo ""
echo "서비스:"
echo "  ros2 service list | grep doosan"
echo ""
echo "토픽:"
echo "  ros2 topic list | grep -E '(joint|robot)'"
