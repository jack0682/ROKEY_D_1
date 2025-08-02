#!/bin/bash
# setup_after_git_clone.sh
# Git 클론 후 새로운 환경에서 워크스페이스 설정 자동화 스크립트

set -e

# 색상 정의
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
NC='\033[0m'

print_header() {
    echo -e "\n${PURPLE}════════════════════════════════════════════════════════════════${NC}"
    echo -e "${PURPLE}🚀 $1${NC}"
    echo -e "${PURPLE}════════════════════════════════════════════════════════════════${NC}\n"
}

print_step() {
    echo -e "${BLUE}🔹 $1${NC}"
}

print_success() {
    echo -e "${GREEN}✅ $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}⚠️  $1${NC}"
}

print_error() {
    echo -e "${RED}❌ $1${NC}"
}

print_header "Git 클론 후 워크스페이스 설정"

# 현재 디렉토리 확인
if [[ ! -f "install_script.sh" ]]; then
    print_error "project_ws 루트 디렉토리에서 실행해주세요"
    exit 1
fi

print_step "현재 디렉토리: $(pwd)"

# DoosanBootcam3rdCo1 디렉토리 확인
DOOSAN_PATH="../DoosanBootcam3rdCo1"
if [[ ! -d "$DOOSAN_PATH" ]]; then
    print_warning "DoosanBootcam3rdCo1 디렉토리가 없습니다: $DOOSAN_PATH"
    echo ""
    echo "다음 중 하나를 선택하세요:"
    echo "1. DoosanBootcam3rdCo1을 별도로 다운로드/클론하여 ../DoosanBootcam3rdCo1에 위치"
    echo "2. 기존 구조만 사용 (새로운 dsr_* 패키지 없이)"
    echo ""
    read -p "계속 진행하시겠습니까? (y/N): " choice
    if [[ $choice != [yY] ]]; then
        print_error "설정을 중단합니다"
        exit 1
    fi
    print_warning "새로운 구조 패키지 없이 기존 구조만 사용합니다"
else
    print_success "DoosanBootcam3rdCo1 디렉토리 확인: $DOOSAN_PATH"
fi

# 메인 설치 스크립트 실행
print_step "메인 설치 스크립트 실행 중..."
if [[ -x "install_script.sh" ]]; then
    ./install_script.sh
else
    chmod +x install_script.sh
    ./install_script.sh
fi

print_header "설정 완료"

echo -e "${GREEN}🎉 Git 클론 후 워크스페이스 설정이 완료되었습니다!${NC}"
echo ""
echo -e "${YELLOW}다음 단계:${NC}"
echo "1. 새 터미널 열기 또는: exec bash"
echo "2. 빌드 확인: colcon build"  
echo "3. 실험 실행: ros2 launch sugar_water_experiment sugar_water_experiment_real.launch.py"
echo ""

if [[ -d "$DOOSAN_PATH" ]]; then
    print_success "새로운 구조 패키지들이 심볼릭 링크로 연결되었습니다"
    echo -e "${BLUE}심볼릭 링크 확인:${NC}"
    ls -la src/dsr_* 2>/dev/null || echo "  (dsr_* 패키지들)"
else
    print_warning "기존 구조만 사용 가능합니다"
fi

echo ""
echo -e "${PURPLE}🔍 상태 확인:${NC}"
echo "  ./switch_structure.sh  # 현재 활성화된 구조 확인"
echo "  ./test_sensors.sh      # 센서 및 연결 테스트"
