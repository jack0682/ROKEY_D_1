#!/bin/bash
# package_debug.sh - 패키지별 상세 진단 스크립트

set -e

# 색상 정의
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

print_header() {
    echo -e "\n${BLUE}═══════════════════════════════════════════════════════${NC}"
    echo -e "${BLUE}🔍 $1${NC}"
    echo -e "${BLUE}═══════════════════════════════════════════════════════${NC}"
}

print_error() {
    echo -e "${RED}❌ $1${NC}"
}

print_success() {
    echo -e "${GREEN}✅ $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}⚠️ $1${NC}"
}

print_header "ROS2 패키지 상세 진단"

# 1. ROS2 환경 확인
echo "🔍 ROS2 환경 확인..."
if [ -f "/opt/ros/humble/setup.bash" ]; then
    source "/opt/ros/humble/setup.bash"
    print_success "ROS2 Humble 환경 로드됨"
    echo "ROS_DISTRO: $ROS_DISTRO"
    echo "ROS_VERSION: $ROS_VERSION"
else
    print_error "ROS2 Humble이 설치되지 않음"
    exit 1
fi

# 2. 문제가 되는 패키지 확인
echo -e "\n🔍 문제 패키지 확인..."
PROBLEM_PACKAGES=(
    "ros-humble-rmw-cyclonedx-cpp"
    "ros-humble-moveit-simple-controller-manager"
    "ros-humble-serial-driver"
    "ros-humble-yaml-cpp-vendor"
)

for pkg in "${PROBLEM_PACKAGES[@]}"; do
    if apt list --installed 2>/dev/null | grep -q "$pkg"; then
        print_success "$pkg 설치됨"
    else
        print_warning "$pkg 설치되지 않음"
        
        # 올바른 패키지명 제안
        case "$pkg" in
            "ros-humble-rmw-cyclonedx-cpp")
                echo "  → 올바른 패키지명: ros-humble-rmw-cyclonedds-cpp"
                ;;
            "ros-humble-moveit-simple-controller-manager")
                echo "  → 대안: ros-humble-moveit-simple-controller-manager는 별도 설치 불필요"
                ;;
            "ros-humble-serial-driver")
                echo "  → 대안: python3-serial 사용"
                ;;
        esac
    fi
done

# 3. 실제 사용 가능한 패키지 확인
echo -e "\n🔍 대체 패키지 확인..."
ALTERNATIVE_PACKAGES=(
    "ros-humble-rmw-cyclonedds-cpp"
    "ros-humble-moveit"
    "python3-serial"
    "libyaml-cpp-dev"
)

for pkg in "${ALTERNATIVE_PACKAGES[@]}"; do
    if apt-cache show "$pkg" >/dev/null 2>&1; then
        print_success "$pkg 사용 가능"
        if apt list --installed 2>/dev/null | grep -q "$pkg"; then
            echo "  ✓ 이미 설치됨"
        else
            echo "  → 설치 가능"
        fi
    else
        print_error "$pkg 사용 불가능"
    fi
done

# 4. 워크스페이스 구조 확인
echo -e "\n🔍 워크스페이스 구조 확인..."
if [ -d "src" ]; then
    print_success "src 디렉토리 존재"
    echo "패키지 목록:"
    for pkg_dir in src/*/; do
        if [ -d "$pkg_dir" ]; then
            pkg_n=$(basename "$pkg_dir")
            if [ -f "$pkg_dir/package.xml" ]; then
                print_success "  📦 $pkg_n (package.xml 존재)"
            else
                print_warning "  📦 $pkg_n (package.xml 없음)"
            fi
        fi
    done
else
    print_error "src 디렉토리가 없음"
fi

# 5. 빌드 테스트 (안전한 패키지만)
echo -e "\n🔍 안전한 패키지 빌드 테스트..."
SAFE_PACKAGES=(
    "doosan_m0609_description"
    "chemistry_experiment_manager" 
    "precision_liquid_pouring"
)

for pkg in "${SAFE_PACKAGES[@]}"; do
    if [ -d "src/$pkg" ]; then
        echo "테스트: $pkg"
        if colcon build --packages-select "$pkg" --cmake-args -DCMAKE_BUILD_TYPE=Release >/dev/null 2>&1; then
            print_success "  $pkg 빌드 성공"
        else
            print_warning "  $pkg 빌드 실패"
            echo "  → 로그 확인: log/latest_build/$pkg/stderr.log"
        fi
    else
        print_warning "  $pkg 패키지 없음"
    fi
done

# 6. 의존성 체크
echo -e "\n🔍 의존성 체크..."
if command -v rosdep >/dev/null 2>&1; then
    print_success "rosdep 사용 가능"
    echo "누락된 의존성 확인 중..."
    if rosdep check --from-paths src --ignore-src 2>/dev/null; then
        print_success "모든 의존성 만족"
    else
        print_warning "일부 의존성 누락"
        echo "누락된 패키지를 설치하려면:"
        echo "  rosdep install --from-paths src --ignore-src -y"
    fi
else
    print_error "rosdep이 설치되지 않음"
fi

# 7. 추천 수정 사항
print_header "추천 수정 사항"

echo "1. 문제가 있는 패키지 교체:"
echo "   ❌ ros-humble-rmw-cyclonedx-cpp"
echo "   ✅ ros-humble-rmw-cyclonedds-cpp"
echo ""

echo "2. 선택적 패키지를 필수에서 제외:"
echo "   - MoveIt2 (복잡한 의존성)"
echo "   - serial-driver (python3-serial로 대체)"
echo ""

echo "3. 단계별 빌드 시도:"
echo "   colcon build --packages-select doosan_m0609_description"
echo "   colcon build --packages-select chemistry_experiment_manager"
echo "   colcon build --packages-select precision_liquid_pouring"
echo ""

echo "4. 로그 확인 방법:"
echo "   cat log/latest_build/*/stderr.log | grep -i error"
echo ""

print_success "진단 완료!"
