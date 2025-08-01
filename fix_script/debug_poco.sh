#!/bin/bash
# debug_poco.sh - Poco 라이브러리 상세 진단

set -e

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

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

echo -e "${BLUE}🔍 Poco 라이브러리 상세 진단${NC}"

# 1. 설치된 Poco 패키지 확인
print_step "1. 설치된 Poco 패키지 확인..."
dpkg -l | grep poco || print_warning "poco 패키지 없음"

# 2. Poco 라이브러리 파일 확인
print_step "2. Poco 라이브러리 파일 확인..."
POCO_PATHS=(
    "/usr/lib/x86_64-linux-gnu/libPocoFoundation.so"
    "/usr/lib/x86_64-linux-gnu/libPocoNet.so"
    "/usr/lib/libPocoFoundation.so"
    "/usr/lib/libPocoNet.so"
    "/usr/local/lib/libPocoFoundation.so"
    "/usr/local/lib/libPocoNet.so"
)

for path in "${POCO_PATHS[@]}"; do
    if [ -f "$path" ]; then
        print_success "  발견: $path"
        ls -la "$path"
    else
        print_warning "  없음: $path"
    fi
done

# 3. pkg-config 파일 확인
print_step "3. pkg-config 파일 확인..."
PKG_CONFIG_PATHS=(
    "/usr/lib/x86_64-linux-gnu/pkgconfig/libpocofoundation.pc"
    "/usr/lib/pkgconfig/libpocofoundation.pc"
    "/usr/local/lib/pkgconfig/libpocofoundation.pc"
)

for path in "${PKG_CONFIG_PATHS[@]}"; do
    if [ -f "$path" ]; then
        print_success "  발견: $path"
        cat "$path"
    else
        print_warning "  없음: $path"
    fi
done

# 4. pkg-config 테스트
print_step "4. pkg-config 테스트..."
if pkg-config --exists libpocofoundation; then
    print_success "libpocofoundation pkg-config 사용 가능"
    echo "  버전: $(pkg-config --modversion libpocofoundation)"
    echo "  CFLAGS: $(pkg-config --cflags libpocofoundation)"
    echo "  LIBS: $(pkg-config --libs libpocofoundation)"
else
    print_error "libpocofoundation pkg-config 사용 불가"
fi

if pkg-config --exists libpoconet; then
    print_success "libpoconet pkg-config 사용 가능"
    echo "  버전: $(pkg-config --modversion libpoconet)"
    echo "  CFLAGS: $(pkg-config --cflags libpoconet)"
    echo "  LIBS: $(pkg-config --libs libpoconet)"
else
    print_error "libpoconet pkg-config 사용 불가"
fi

# 5. 추천 해결 방안
echo ""
echo -e "${YELLOW}📋 추천 해결 방안:${NC}"
echo "1. Poco 개발 패키지 재설치:"
echo "   sudo apt remove libpoco-dev"
echo "   sudo apt install libpoco-dev pkg-config"
echo ""
echo "2. 또는 소스에서 빌드:"
echo "   wget https://pocoproject.org/releases/poco-1.12.4/poco-1.12.4-all.tar.gz"
echo ""
echo "3. 또는 CMake에서 pkg-config 없이 직접 라이브러리 링크"
