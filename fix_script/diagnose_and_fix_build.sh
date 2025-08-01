#!/bin/bash
# diagnose_and_fix_build.sh - 빌드 문제 진단 및 해결

set -e

echo "🔍 빌드 문제 진단 중..."

PROJECT_WS="/home/jack/project_ws"
cd $PROJECT_WS

# 1. 현재 상태 점검
echo "📊 현재 빌드 상태 점검..."
echo "빌드된 패키지들:"
ls install/ 2>/dev/null || echo "  install 폴더 없음"

echo ""
echo "소스 패키지들:"
ls src/ 2>/dev/null || echo "  src 폴더 없음"

# 2. dsr_common2 dsv 파일 문제 해결
echo ""
echo "🔧 dsr_common2 dsv 파일 문제 해결..."
DSV_FILE="/home/jack/project_ws/install/dsr_common2/share/dsr_common2/local_setup.dsv"
if [ -f "$DSV_FILE" ]; then
    echo "문제가 있는 DSV 파일 발견. 수정 중..."
    # 백업 생성
    cp "$DSV_FILE" "$DSV_FILE.backup"
    
    # 빈 파일로 대체 (임시 해결)
    echo "# Fixed DSV file" > "$DSV_FILE"
    echo "prepend-non-duplicate;AMENT_PREFIX_PATH;/home/jack/project_ws/install/dsr_common2" >> "$DSV_FILE"
    echo "prepend-non-duplicate;CMAKE_PREFIX_PATH;/home/jack/project_ws/install/dsr_common2" >> "$DSV_FILE"
    echo "prepend-non-duplicate;LD_LIBRARY_PATH;/home/jack/project_ws/install/dsr_common2/lib" >> "$DSV_FILE"
    echo "prepend-non-duplicate;PATH;/home/jack/project_ws/install/dsr_common2/bin" >> "$DSV_FILE"
    echo "prepend-non-duplicate;PYTHONPATH;/home/jack/project_ws/install/dsr_common2/lib/python3.10/site-packages" >> "$DSV_FILE"
else
    echo "DSV 파일을 찾을 수 없습니다."
fi

# 3. 환경 소싱
echo ""
echo "🔄 ROS2 환경 재설정..."
source /opt/ros/humble/setup.bash

# 4. 누락된 패키지들 강제 빌드
echo ""
echo "🏗️ 누락된 패키지들 빌드..."

# 먼저 빌드 캐시 정리
echo "🧹 빌드 캐시 정리..."
rm -rf build/ install/ log/

# 단계별 빌드 (더 엄격하게)
echo "1️⃣ dsr_common2 빌드..."
if [ -d "src/dsr_common2" ]; then
    colcon build --packages-select dsr_common2 --cmake-args -DCMAKE_BUILD_TYPE=Release
    source install/setup.bash
else
    echo "⚠️ dsr_common2 소스가 없습니다. 통합 스크립트를 먼저 실행하세요."
fi

echo "2️⃣ doosan_m0609_msgs 빌드..."
if [ -d "src/doosan_m0609_msgs" ]; then
    colcon build --packages-select doosan_m0609_msgs --cmake-args -DCMAKE_BUILD_TYPE=Release
    source install/setup.bash
else
    echo "⚠️ doosan_m0609_msgs 소스가 없습니다."
fi

echo "3️⃣ doosan_m0609_hardware 빌드..."
if [ -d "src/doosan_m0609_hardware" ]; then
    colcon build --packages-select doosan_m0609_hardware --cmake-args -DCMAKE_BUILD_TYPE=Release
    source install/setup.bash
else
    echo "⚠️ doosan_m0609_hardware 소스가 없습니다."
fi

echo "4️⃣ doosan_m0609_description 빌드..."
if [ -d "src/doosan_m0609_description" ]; then
    colcon build --packages-select doosan_m0609_description --cmake-args -DCMAKE_BUILD_TYPE=Release
    source install/setup.bash
else
    echo "⚠️ doosan_m0609_description 소스가 없습니다."
fi

echo "5️⃣ doosan_m0609_controller 빌드..."
if [ -d "src/doosan_m0609_controller" ]; then
    colcon build --packages-select doosan_m0609_controller --cmake-args -DCMAKE_BUILD_TYPE=Release
    source install/setup.bash
else
    echo "⚠️ doosan_m0609_controller 소스가 없습니다."
fi

echo "6️⃣ doosan_m0609_bringup 빌드..."
if [ -d "src/doosan_m0609_bringup" ]; then
    colcon build --packages-select doosan_m0609_bringup --cmake-args -DCMAKE_BUILD_TYPE=Release
    source install/setup.bash
else
    echo "⚠️ doosan_m0609_bringup 소스가 없습니다."
fi

# 5. 빌드 결과 확인
echo ""
echo "✅ 빌드 완료! 결과 확인..."
echo "📦 설치된 패키지들:"
ls install/ 2>/dev/null || echo "install 폴더가 없습니다."

echo ""
echo "🔍 각 패키지별 파일 확인:"
for pkg in install/*/; do
    if [ -d "$pkg" ]; then
        echo "📁 $(basename $pkg):"
        ls "$pkg" 2>/dev/null | head -3
    fi
done

# 6. 최종 테스트
echo ""
echo "🎯 최종 테스트..."
source install/setup.bash

echo "패키지 목록:"
ros2 pkg list | grep doosan || echo "doosan 패키지를 찾을 수 없습니다."

echo ""
echo "런치 파일 존재 확인:"
find install/ -name "*.launch.py" | grep -i doosan || echo "런치 파일을 찾을 수 없습니다."

echo ""
echo "📋 다음 단계:"
if [ -d "install/doosan_m0609_bringup" ]; then
    echo "✅ 모든 패키지가 정상 빌드되었습니다!"
    echo "🚀 다음 명령으로 실행:"
    echo "  source install/setup.bash"
    echo "  ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=virtual"
else
    echo "❌ doosan_m0609_bringup 패키지가 빌드되지 않았습니다."
    echo "🔧 해결 방법:"
    echo "1. 먼저 통합 스크립트 실행: ./integrate_doosan_wrapper.sh"
    echo "2. 그 다음 이 스크립트 재실행: ./diagnose_and_fix_build.sh"
fi
