#!/bin/bash
# fix_dependency_order.sh - 의존성 순서 문제 해결
# 리라(Lyra)의 존재론적 수정 스크립트

set -e

PROJECT_WS="/home/jaeho/project_ws"
echo "🌀 의존성 순서 문제 해결 시작..."
echo "📍 워크스페이스: $PROJECT_WS"

cd $PROJECT_WS

# =============================================================================
# Phase 1: 먼저 package.xml 태그 오류 수정 (아직 안 되어있다면)
# =============================================================================
echo ""
echo "🔧 Phase 1: package.xml 태그 수정 확인..."

# doosan_m0609_controller package.xml 수정
CONTROLLER_PKG="src/doosan_m0609_controller/package.xml"
if grep -q "<n>doosan_m0609_controller</n>" $CONTROLLER_PKG; then
    echo "  🔹 doosan_m0609_controller package.xml 수정 중..."
    sed -i 's/<n>doosan_m0609_controller<\/n>/<name>doosan_m0609_controller<\/name>/g' $CONTROLLER_PKG
    echo "  ✅ doosan_m0609_controller package.xml 수정 완료"
else
    echo "  ✅ doosan_m0609_controller package.xml 이미 올바름"
fi

# doosan_m0609_hardware package.xml 수정  
HARDWARE_PKG="src/doosan_m0609_hardware/package.xml"
if grep -q "<n>doosan_m0609_hardware</n>" $HARDWARE_PKG; then
    echo "  🔹 doosan_m0609_hardware package.xml 수정 중..."
    sed -i 's/<n>doosan_m0609_hardware<\/n>/<name>doosan_m0609_hardware<\/name>/g' $HARDWARE_PKG
    echo "  ✅ doosan_m0609_hardware package.xml 수정 완료"
else
    echo "  ✅ doosan_m0609_hardware package.xml 이미 올바름"
fi

# =============================================================================
# Phase 2: doosan_m0609_hardware CMakeLists.txt 수정
# =============================================================================
echo ""
echo "⚙️ Phase 2: doosan_m0609_hardware CMakeLists.txt 수정..."

HARDWARE_CMAKE="src/doosan_m0609_hardware/CMakeLists.txt"

echo "  🔹 $HARDWARE_CMAKE 백업 생성"
cp $HARDWARE_CMAKE ${HARDWARE_CMAKE}.backup

echo "  🔹 LINK_LIBRARIES 전역 링킹 제거 (충돌 방지)"
# LINK_LIBRARIES는 전역 설정으로 문제를 일으킬 수 있음
sed -i 's/^LINK_LIBRARIES(DRFL PocoFoundation PocoNet)/#LINK_LIBRARIES(DRFL PocoFoundation PocoNet)/g' $HARDWARE_CMAKE

echo "  🔹 target_link_libraries로 직접 링킹 추가"
# doosan_m0609_hardware 타겟에 직접 DRFL 라이브러리 링크
sed -i '/target_link_libraries(doosan_m0609_hardware yaml-cpp)/a\
target_link_libraries(doosan_m0609_hardware \
    ${CMAKE_CURRENT_SOURCE_DIR}/../dsr_common2/lib/humble/x86_64/libDRFL.a \
    PocoFoundation \
    PocoNet \
    pthread \
)' $HARDWARE_CMAKE

# =============================================================================
# Phase 3: 빌드 캐시 정리
# =============================================================================
echo ""
echo "🧹 Phase 3: 빌드 캐시 정리..."

echo "  🔹 기존 빌드/설치 디렉토리 정리"
rm -rf build/doosan_m0609_hardware
rm -rf build/doosan_m0609_controller
rm -rf install/doosan_m0609_hardware
rm -rf install/doosan_m0609_controller

# =============================================================================
# Phase 4: 올바른 순서로 순차 빌드
# =============================================================================
echo ""
echo "🏗️ Phase 4: 올바른 순서로 순차 빌드..."

# ROS 환경 소싱
echo "  🔹 ROS 환경 소싱"
source /opt/ros/humble/setup.bash

echo "  🔹 1단계: dsr_common2 빌드 확인"
if [ ! -d "install/dsr_common2" ]; then
    echo "    📦 dsr_common2 빌드 중..."
    colcon build --packages-select dsr_common2
else
    echo "    ✅ dsr_common2 이미 빌드됨"
fi

echo "  🔹 2단계: doosan_m0609_msgs 빌드 확인"
if [ ! -d "install/doosan_m0609_msgs" ]; then
    echo "    📦 doosan_m0609_msgs 빌드 중..."
    colcon build --packages-select doosan_m0609_msgs
else
    echo "    ✅ doosan_m0609_msgs 이미 빌드됨"
fi

echo "  🔹 3단계: doosan_m0609_hardware 빌드 (핵심!)"
colcon build --packages-select doosan_m0609_hardware

if [ $? -eq 0 ]; then
    echo "    ✅ doosan_m0609_hardware 빌드 성공!"
    
    echo "  🔹 4단계: doosan_m0609_controller 빌드"
    colcon build --packages-select doosan_m0609_controller
    
    if [ $? -eq 0 ]; then
        echo "    ✅ doosan_m0609_controller 빌드 성공!"
        
        echo "  🔹 5단계: 전체 워크스페이스 빌드"
        colcon build
        
        if [ $? -eq 0 ]; then
            echo "    🎉 전체 빌드 성공!"
        else
            echo "    ⚠️ 전체 빌드 중 일부 패키지 실패 (핵심 패키지는 성공)"
        fi
    else
        echo "    ❌ doosan_m0609_controller 빌드 실패"
        echo "    🔍 로그 확인: log/latest_build/doosan_m0609_controller/stderr.log"
    fi
else
    echo "    ❌ doosan_m0609_hardware 빌드 실패"
    echo "    🔍 로그 확인: log/latest_build/doosan_m0609_hardware/stderr.log"
    echo ""
    echo "    💡 가능한 원인:"
    echo "       - DRFL 라이브러리 경로 문제"
    echo "       - Poco 라이브러리 누락"
    echo "       - 컴파일러 버전 호환성 문제"
    exit 1
fi

# =============================================================================
# Phase 5: 환경 설정 및 검증
# =============================================================================
echo ""
echo "🌍 Phase 5: 환경 설정 및 검증..."

echo "  🔹 설치된 패키지 소싱"
source install/setup.bash

echo "  🔹 패키지 인식 확인"
if ros2 pkg list | grep -q doosan_m0609; then
    echo "  ✅ Doosan M0609 패키지들이 정상 인식됨:"
    ros2 pkg list | grep doosan_m0609 | sed 's/^/    /'
else
    echo "  ⚠️ 패키지가 아직 인식되지 않음"
fi

# =============================================================================
# Phase 6: 실행 테스트
# =============================================================================
echo ""
echo "🚀 Phase 6: 실행 테스트..."

echo "  🔹 sugar_water_experiment 노드 테스트"
if [ -f "install/sugar_water_experiment/lib/sugar_water_experiment/simple_sequence_controller" ]; then
    echo "  ✅ simple_sequence_controller 실행 파일 존재"
    echo "  💡 테스트 실행 방법:"
    echo "     source install/setup.bash"
    echo "     ros2 run sugar_water_experiment simple_sequence_controller"
else
    echo "  ⚠️ simple_sequence_controller 실행 파일 누락"
    echo "  🔧 sugar_water_experiment 재빌드 필요"
fi

# =============================================================================
# 완료 보고서
# =============================================================================
echo ""
echo "📋 =========================================="
echo "🎉 의존성 순서 문제 해결 완료!"
echo "📋 =========================================="
echo ""
echo "✅ 해결된 문제들:"
echo "  - package.xml 태그 오류 수정"
echo "  - doosan_m0609_hardware 우선 빌드"
echo "  - DRFL 라이브러리 링킹 수정"
echo "  - 의존성 순서 정렬"
echo ""
echo "🏗️ 성공한 빌드 순서:"
echo "  1. dsr_common2 ✅"
echo "  2. doosan_m0609_msgs ✅"
echo "  3. doosan_m0609_hardware ✅" 
echo "  4. doosan_m0609_controller ✅"
echo ""
echo "🔄 다음 실행 단계:"
echo "  1. 환경 소싱: source install/setup.bash"
echo "  2. 패키지 확인: ros2 pkg list | grep doosan"
echo "  3. 실험 실행: ros2 run sugar_water_experiment simple_sequence_controller"
echo ""
echo "🚨 실제 로봇 연결 시 주의사항:"
echo "  - 로봇 컨트롤러 IP 확인 (기본: 192.168.137.100)"
echo "  - 네트워크 연결 상태 확인"
echo "  - 안전 장치 및 비상 정지 버튼 준비"
echo "  - 작업 공간 내 장애물 제거"
echo ""
echo "💾 백업 파일:"
echo "  - ${HARDWARE_CMAKE}.backup"
echo ""
echo "🎯 수정 완료! 이제 의존성 문제가 해결되었습니다."