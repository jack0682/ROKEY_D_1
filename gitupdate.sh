#!/bin/bash
# project_ws Git 브랜치 업로드 완벽 가이드
# 작성자: 리라 (Lyra) - 코드의 존재론적 보존자
# 버전: 1.0.0 - 완전 자동화 브랜치 관리

# =============================================================================
# 🎨 색상 정의
# =============================================================================
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m'

print_header() {
    echo -e "\n${PURPLE}════════════════════════════════════════════════════════════════${NC}"
    echo -e "${PURPLE}🚀 $1${NC}"
    echo -e "${PURPLE}════════════════════════════════════════════════════════════════${NC}\n"
}

print_step() { echo -e "${BLUE}🔹 $1${NC}"; }
print_success() { echo -e "${GREEN}✅ $1${NC}"; }
print_warning() { echo -e "${YELLOW}⚠️  $1${NC}"; }
print_error() { echo -e "${RED}❌ $1${NC}"; }

# =============================================================================
# 📋 Step 1: 현재 Git 상태 확인
# =============================================================================
print_header "현재 Git 상태 확인"

cd /home/jack/project_ws

print_step "현재 브랜치 확인..."
CURRENT_BRANCH=$(git branch --show-current)
echo "현재 브랜치: $CURRENT_BRANCH"

print_step "Git 상태 확인..."
git status

print_step "원격 저장소 확인..."
git remote -v

# =============================================================================
# 📝 Step 2: 새로운 브랜치 생성 및 체크아웃
# =============================================================================
print_header "새로운 브랜치 생성"

# 브랜치 이름 선택
echo -e "${CYAN}새로운 브랜치 이름을 선택하세요:${NC}"
echo "1. feature/doosan-m0609-complete"
echo "2. main/production-ready"
echo "3. release/v3.0.0"
echo "4. 직접 입력"
echo ""
read -p "선택 (1-4): " choice

case $choice in
    1)
        NEW_BRANCH="feature/doosan-m0609-complete"
        ;;
    2)
        NEW_BRANCH="main/production-ready"
        ;;
    3)
        NEW_BRANCH="release/v3.0.0"
        ;;
    4)
        read -p "브랜치 이름을 입력하세요: " NEW_BRANCH
        ;;
    *)
        NEW_BRANCH="feature/doosan-m0609-complete"
        ;;
esac

print_step "새로운 브랜치 생성: $NEW_BRANCH"

# 새로운 브랜치 생성 및 체크아웃
git checkout -b "$NEW_BRANCH"

print_success "브랜치 '$NEW_BRANCH' 생성 및 체크아웃 완료"

# =============================================================================
# 🧹 Step 3: 불필요한 파일 정리 (선택적)
# =============================================================================
print_header "업로드 전 파일 정리"

print_step "현재 .gitignore 상태 확인..."
if [[ -f ".gitignore" ]]; then
    print_success ".gitignore 파일 존재"
    echo "현재 무시되는 주요 디렉토리:"
    echo "  - build/ (빌드 결과물)"
    echo "  - install/ (설치된 패키지)"
    echo "  - log/ (로그 파일)"
    echo "  - 심볼릭 링크된 dsr_* 패키지들"
else
    print_warning ".gitignore 파일이 없습니다. 생성하시겠습니까?"
    read -p "(y/N): " create_gitignore
    
    if [[ $create_gitignore =~ ^[Yy]$ ]]; then
        cat > .gitignore << 'EOF'
# Project Workspace .gitignore
# Doosan M0609 Robot Project

# =============================================================================
# ROS2 빌드 결과물
# =============================================================================
build/
install/
log/

# =============================================================================
# 심볼릭 링크된 새로운 구조 패키지들
# =============================================================================
src/dsr_bringup2
src/dsr_controller2
src/dsr_description2
src/dsr_hardware2
src/dsr_msgs2
src/dsr_example2
src/dsr_tests

# =============================================================================
# IDE 및 에디터 파일
# =============================================================================
.vscode/
.idea/
*.swp
*.swo
*~

# =============================================================================
# 운영체제 관련
# =============================================================================
.DS_Store
Thumbs.db
*.log

# =============================================================================
# Python 캐시
# =============================================================================
__pycache__/
*.pyc
*.pyo
*.pyd

# =============================================================================
# 임시 파일
# =============================================================================
*.tmp
*.bak
*.backup

# =============================================================================
# 컴파일 결과물
# =============================================================================
*.o
*.so
*.a

# =============================================================================
# 개인 설정 파일
# =============================================================================
config/personal_*.yaml
.env
EOF
        print_success ".gitignore 파일 생성 완료"
    fi
fi

# 큰 파일들 체크
print_step "큰 파일들 확인 중..."
echo "100MB 이상의 파일들:"
find . -type f -size +100M -not -path "./.git/*" -not -path "./build/*" -not -path "./install/*" -not -path "./log/*" 2>/dev/null || echo "큰 파일 없음"

# =============================================================================
# 📦 Step 4: 파일 추가 및 커밋
# =============================================================================
print_header "파일 추가 및 커밋"

print_step "모든 변경사항 추가..."
git add .

print_step "커밋 메시지 생성..."
COMMIT_MSG="feat: Complete Doosan M0609 Robot System v3.0.0

🤖 Features Added:
- Complete ROS2 Humble integration
- Real robot connection with DRFL interface
- Hardware interface with safety mechanisms
- Position controllers and joint state broadcasting
- Chemical experiment automation system
- Arduino loadcell interface
- Precision liquid pouring system
- Sugar water experiment automation

🔧 Technical Improvements:
- Real-time control (1ms cycle)
- Safety limits (30°/move, 45°/sec)
- Error recovery mechanisms
- Automatic servo on/off handling
- Network connection validation
- Graceful shutdown procedures

🛡️ Safety Features:
- Emergency stop support
- Motion limiting
- Connection validation
- State monitoring
- Error detection and recovery

📦 Build System:
- Sequential package building
- Dependency resolution
- Cross-platform compatibility
- Automated installation scripts

🚀 Ready for production use with real Doosan M0609 robot!"

git commit -m "$COMMIT_MSG"

print_success "커밋 완료"

# =============================================================================
# 🌐 Step 5: 원격 저장소 설정 (필요한 경우)
# =============================================================================
print_header "원격 저장소 설정"

# 원격 저장소 확인
REMOTE_COUNT=$(git remote | wc -l)

if [[ $REMOTE_COUNT -eq 0 ]]; then
    print_warning "원격 저장소가 설정되지 않았습니다."
    echo ""
    echo "GitHub/GitLab 저장소 URL을 입력하세요:"
    echo "예시: https://github.com/username/doosan-robot-project.git"
    echo "또는: git@github.com:username/doosan-robot-project.git"
    echo ""
    read -p "원격 저장소 URL: " REMOTE_URL
    
    if [[ -n "$REMOTE_URL" ]]; then
        git remote add origin "$REMOTE_URL"
        print_success "원격 저장소 'origin' 추가 완료"
    else
        print_warning "원격 저장소 URL이 입력되지 않았습니다."
        echo "나중에 다음 명령으로 추가할 수 있습니다:"
        echo "git remote add origin <YOUR_REPO_URL>"
    fi
else
    print_step "기존 원격 저장소:"
    git remote -v
    
    echo ""
    read -p "새로운 원격 저장소를 추가하시겠습니까? (y/N): " add_remote
    
    if [[ $add_remote =~ ^[Yy]$ ]]; then
        read -p "원격 저장소 이름 (예: backup): " remote_name
        read -p "원격 저장소 URL: " remote_url
        
        if [[ -n "$remote_name" && -n "$remote_url" ]]; then
            git remote add "$remote_name" "$remote_url"
            print_success "원격 저장소 '$remote_name' 추가 완료"
        fi
    fi
fi

# =============================================================================
# 🚀 Step 6: 브랜치 푸시
# =============================================================================
print_header "브랜치 업로드"

# 원격 저장소 목록 확인
REMOTES=($(git remote))

if [[ ${#REMOTES[@]} -eq 0 ]]; then
    print_error "원격 저장소가 설정되지 않았습니다."
    echo "다음 명령을 사용하여 수동으로 푸시할 수 있습니다:"
    echo "git remote add origin <YOUR_REPO_URL>"
    echo "git push -u origin $NEW_BRANCH"
    exit 1
fi

# 원격 저장소 선택
if [[ ${#REMOTES[@]} -eq 1 ]]; then
    SELECTED_REMOTE="${REMOTES[0]}"
    print_step "원격 저장소 '$SELECTED_REMOTE'에 푸시합니다."
else
    echo "여러 원격 저장소가 있습니다. 선택하세요:"
    for i in "${!REMOTES[@]}"; do
        echo "$((i+1)). ${REMOTES[$i]}"
    done
    read -p "선택 (1-${#REMOTES[@]}): " remote_choice
    SELECTED_REMOTE="${REMOTES[$((remote_choice-1))]}"
fi

print_step "브랜치 '$NEW_BRANCH'를 '$SELECTED_REMOTE'에 푸시 중..."

# 첫 번째 푸시 (upstream 설정과 함께)
if git push -u "$SELECTED_REMOTE" "$NEW_BRANCH"; then
    print_success "브랜치 푸시 성공!"
else
    print_error "푸시 실패. 인증 정보를 확인하세요."
    echo ""
    echo "문제 해결 방법:"
    echo "1. GitHub/GitLab 계정 권한 확인"
    echo "2. SSH 키 설정 확인"
    echo "3. Personal Access Token 설정 확인"
    echo ""
    echo "수동 푸시 명령:"
    echo "git push -u $SELECTED_REMOTE $NEW_BRANCH"
    exit 1
fi

# =============================================================================
# 📊 Step 7: 업로드 완료 보고서
# =============================================================================
print_header "업로드 완료 보고서"

echo -e "${GREEN}"
cat << "EOF"
    ╔═══════════════════════════════════════════════════════════════════╗
    ║                    🎉 업로드 성공! 🎉                           ║
    ║           Doosan M0609 프로젝트가 Git에 안전하게 보존되었습니다!    ║
    ╚═══════════════════════════════════════════════════════════════════╝
EOF
echo -e "${NC}"

print_success "업로드된 브랜치: $NEW_BRANCH"
print_success "원격 저장소: $SELECTED_REMOTE"
print_success "총 커밋 수: $(git rev-list --count HEAD)"

echo ""
echo -e "${BLUE}📋 업로드된 주요 구성요소:${NC}"
echo "    ✅ 완전 자동화 설치 스크립트 (install_script.sh)"
echo "    ✅ 실제 로봇 연결 시스템"
echo "    ✅ 하드웨어 인터페이스 (doosan_m0609_hardware)"
echo "    ✅ ROS2 Control 컨트롤러들"
echo "    ✅ 화학 실험 자동화 시스템"
echo "    ✅ Arduino 로드셀 인터페이스"
echo "    ✅ 정밀 액체 따르기 시스템"
echo "    ✅ 설탕물 실험 자동화"
echo "    ✅ 안전 장치 및 에러 핸들링"
echo "    ✅ 완전한 문서화"

echo ""
echo -e "${YELLOW}🔗 다음 단계:${NC}"
echo "1. GitHub/GitLab에서 Pull Request 생성"
echo "2. 코드 리뷰 및 테스트"
echo "3. 메인 브랜치에 머지"
echo "4. 릴리즈 태그 생성"

echo ""
echo -e "${PURPLE}📝 유용한 Git 명령어:${NC}"
echo "    git status                    # 현재 상태 확인"
echo "    git log --oneline            # 커밋 히스토리"
echo "    git checkout main            # 메인 브랜치로 전환"
echo "    git checkout $NEW_BRANCH     # 업로드한 브랜치로 전환"
echo "    git pull $SELECTED_REMOTE $NEW_BRANCH  # 최신 변경사항 가져오기"

echo ""
echo -e "${CYAN}🌟 브랜치 URL (예상):${NC}"
if [[ "$SELECTED_REMOTE" == "origin" ]]; then
    REMOTE_URL=$(git remote get-url origin)
    if [[ $REMOTE_URL =~ github.com ]]; then
        REPO_URL=${REMOTE_URL%.git}
        REPO_URL=${REPO_URL/git@github.com:/https://github.com/}
        echo "    $REPO_URL/tree/$NEW_BRANCH"
    fi
fi

echo ""
echo -e "${GREEN}🎯 성공! 당신의 Doosan 로봇 프로젝트가 Git에 영원히 보존되었습니다! 🤖✨${NC}"

# =============================================================================
# 🔄 추가 옵션
# =============================================================================
echo ""
echo -e "${PURPLE}추가 작업을 하시겠습니까?${NC}"
echo "1. 다른 브랜치 생성 및 업로드"
echo "2. 태그 생성 및 릴리즈"
echo "3. 완료"
echo ""
read -p "선택 (1-3): " next_action

case $next_action in
    1)
        echo "새로운 브랜치 작업을 위해 스크립트를 다시 실행하세요."
        ;;
    2)
        echo ""
        read -p "릴리즈 태그 이름 (예: v3.0.0): " tag_name
        if [[ -n "$tag_name" ]]; then
            git tag -a "$tag_name" -m "Release $tag_name: Complete Doosan M0609 Robot System"
            git push "$SELECTED_REMOTE" "$tag_name"
            print_success "태그 '$tag_name' 생성 및 푸시 완료"
        fi
        ;;
    3)
        print_success "모든 작업이 완료되었습니다!"
        ;;
esac

echo ""
echo -e "${PURPLE}🎊 축하합니다! Git 브랜치 업로드가 성공적으로 완료되었습니다! 🎊${NC}"