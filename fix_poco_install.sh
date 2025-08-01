#!/bin/bash
# fix_poco_install.sh - Poco 라이브러리 올바른 설치

set -e

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
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

print_step "잘못된 Poco 패키지 제거 중..."
sudo apt remove -y libpoco-foundation1.11 libpoco-net1.11 2>/dev/null || true

print_step "올바른 Poco 개발 패키지 설치 중..."
sudo apt update
sudo apt install -y \
    libpoco-dev \
    pkg-config

print_step "설치된 Poco 버전 확인..."
if pkg-config --exists libpocofoundation; then
    POCO_VERSION=$(pkg-config --modversion libpocofoundation)
    print_success "Poco Foundation 버전: $POCO_VERSION"
else
    print_error "Poco Foundation pkg-config 파일을 찾을 수 없음"
fi

if pkg-config --exists libpoconet; then
    POCO_NET_VERSION=$(pkg-config --modversion libpoconet)
    print_success "Poco Net 버전: $POCO_NET_VERSION"
else
    print_error "Poco Net pkg-config 파일을 찾을 수 없음"
fi

print_step "Poco 라이브러리 파일 확인..."
if [ -f "/usr/lib/x86_64-linux-gnu/libPocoFoundation.so" ]; then
    print_success "libPocoFoundation.so 발견"
else
    print_error "libPocoFoundation.so 찾을 수 없음"
fi

if [ -f "/usr/lib/x86_64-linux-gnu/libPocoNet.so" ]; then
    print_success "libPocoNet.so 발견"
else
    print_error "libPocoNet.so 찾을 수 없음"
fi

print_success "Poco 라이브러리 수정 완료!"
