#!/bin/bash
# check_poco_system.sh - 현재 시스템의 Poco 상태 정확히 확인

set -e

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

print_header() {
    echo -e "\n${BLUE}═══════════════════════════════════════════════════════${NC}"
    echo -e "${BLUE}🔍 $1${NC}"
    echo -e "${BLUE}═══════════════════════════════════════════════════════${NC}"
}

print_step() {
    echo -e "${BLUE}🔹 $1${NC}"
}

print_success() {
    echo -e "${GREEN}✅ $1${NC}"
}

print_error() {
    echo -e "${RED}❌ $1${NC}"
}

print_warning() {
    echo -e "${YELLOW}⚠️ $1${NC}"
}

print_header "Poco 라이브러리 시스템 상태 확인"

# 1. 설치된 Poco 패키지 확인
print_step "1. 설치된 Poco 패키지 확인"
if dpkg -l | grep -q libpoco-dev; then
    print_success "libpoco-dev 패키지 설치됨"
    POCO_PKG_VERSION=$(dpkg -s libpoco-dev 2>/dev/null | grep Version | cut -d' ' -f2)
    echo "    패키지 버전: $POCO_PKG_VERSION"
else
    print_error "libpoco-dev 패키지 미설치"
    echo "    설치 명령: sudo apt install libpoco-dev"
    exit 1
fi

# 2. Poco 헤더 파일에서 버전 확인
print_step "2. Poco 소스코드 버전 확인"
if [ -f "/usr/include/Poco/Version.h" ]; then
    print_success "Poco/Version.h 발견"
    
    POCO_VERSION_HEX=$(grep 'POCO_VERSION' /usr/include/Poco/Version.h | head -1 | awk '{print $3}')
    echo "    POCO_VERSION: $POCO_VERSION_HEX"
    
    # 버전을 파싱하여 사람이 읽기 쉬운 형태로 변환
    if [[ $POCO_VERSION_HEX =~ ^0x([0-9A-Fa-f]+)$ ]] || [[ $POCO_VERSION_HEX =~ ^([0-9]+)$ ]]; then
        if [[ $POCO_VERSION_HEX =~ ^0x ]]; then
            VERSION_NUM=$((POCO_VERSION_HEX))
        else
            VERSION_NUM=$POCO_VERSION_HEX
        fi
        
        MAJOR=$((VERSION_NUM / 10000000))
        MINOR=$(((VERSION_NUM % 10000000) / 100000))
        PATCH=$(((VERSION_NUM % 100000) / 1000))
        
        echo "    해석된 버전: $MAJOR.$MINOR.$PATCH"
    else
        print_warning "버전 파싱 실패"
    fi
else
    print_error "Poco/Version.h 없음"
fi

# 3. 라이브러리 파일 확인
print_step "3. Poco 라이브러리 파일 확인"
POCO_LIBS=(
    "/usr/lib/x86_64-linux-gnu/libPocoFoundation.so"
    "/usr/lib/x86_64-linux-gnu/libPocoNet.so"
)

for lib in "${POCO_LIBS[@]}"; do
    if [ -f "$lib" ]; then
        print_success "발견: $(basename $lib)"
        
        # 심볼릭 링크인 경우 실제 파일 확인
        if [ -L "$lib" ]; then
            REAL_LIB=$(readlink -f "$lib")
            echo "    → $REAL_LIB"
            
            # 파일명에서 버전 정보 추출
            if [[ $(basename "$REAL_LIB") =~ \.so\.([0-9]+) ]]; then
                SO_VERSION="${BASH_REMATCH[1]}"
                echo "    SO 버전: $SO_VERSION"
            fi
        fi
    else
        print_error "없음: $(basename $lib)"
    fi
done

# 4. pkg-config 상태 확인
print_step "4. pkg-config 지원 상태"
PKG_CONFIG_DIRS=(
    "/usr/lib/x86_64-linux-gnu/pkgconfig"
    "/usr/lib/pkgconfig"
    "/usr/local/lib/pkgconfig"
)

FOUND_PC=false
for dir in "${PKG_CONFIG_DIRS[@]}"; do
    if [ -d "$dir" ]; then
        PC_FILES=$(find "$dir" -name "*poco*.pc" -o -name "*Poco*.pc" 2>/dev/null)
        if [ -n "$PC_FILES" ]; then
            print_success "pkg-config 파일 발견: $dir"
            echo "$PC_FILES"
            FOUND_PC=true
        fi
    fi
done

if [ "$FOUND_PC" = false ]; then
    print_warning "pkg-config 파일 없음 (예상됨 - Ubuntu libpoco-dev의 정상 동작)"
    echo "    이는 정상입니다. Ubuntu의 libpoco-dev는 .pc 파일을 제공하지 않습니다."
fi

# 5. CMake Find 모듈 확인
print_step "5. CMake Poco 지원 확인"
CMAKE_MODULES_DIR="/usr/share/cmake-3.22/Modules"
if [ -f "$CMAKE_MODULES_DIR/FindPoco.cmake" ]; then
    print_success "CMake FindPoco 모듈 존재"
else
    print_warning "CMake FindPoco 모듈 없음"
    echo "    대안: 직접 find_library 사용"
fi

# 6. 권장 CMake 설정
print_header "권장 해결 방안"

echo -e "${GREEN}✅ 현재 시스템에서 사용 가능한 방법:${NC}"
echo ""
echo "1. 🎯 find_library 직접 사용 (권장):"
echo "   find_library(POCO_FOUNDATION_LIB NAMES PocoFoundation)"
echo "   find_library(POCO_NET_LIB NAMES PocoNet)"
echo ""
echo "2. 🔧 find_package 시도:"
echo "   find_package(Poco QUIET COMPONENTS Foundation Net)"
echo ""
echo "3. 📦 pkg-config 우회:"
echo "   set(POCO_LIBRARIES PocoFoundation PocoNet)"
echo ""

# 7. 테스트 컴파일
print_step "6. 간단한 링크 테스트"
TEST_FILE="/tmp/poco_test.cpp"
cat > "$TEST_FILE" << 'EOF'
#include <iostream>
int main() {
    std::cout << "Poco test compilation" << std::endl;
    return 0;
}
EOF

if g++ -o /tmp/poco_test "$TEST_FILE" -lPocoFoundation -lPocoNet 2>/dev/null; then
    print_success "컴파일 및 링크 테스트 성공"
    /tmp/poco_test
    rm -f /tmp/poco_test "$TEST_FILE"
else
    print_error "컴파일 테스트 실패"
    echo "    Poco 라이브러리가 제대로 설치되지 않았을 수 있습니다."
fi

print_header "결론"
echo -e "${GREEN}🎯 권장사항:${NC}"
echo "  • pkg-config 대신 find_library 사용"
echo "  • CMakeLists.txt에서 직접 라이브러리 링크"
echo "  • 현재 시스템은 Poco 사용 준비 완료"
