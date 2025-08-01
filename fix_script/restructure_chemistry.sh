#!/bin/bash
# 정밀 화합물 농도 제조 시스템 - 디렉토리 구조 재정립 스크립트

set -e
cd /home/jaeho/project_ws

echo "🧪 정밀 화합물 농도 제조 시스템 - 디렉토리 재구성 시작"
echo "================================================================"

# =================================================================
# 1단계: 백업 생성
# =================================================================
echo "📦 1단계: 기존 구조 백업..."
BACKUP_DIR="backup_before_chemistry_$(date +%Y%m%d_%H%M%S)"
mkdir -p ${BACKUP_DIR}
cp -r src ${BACKUP_DIR}/
echo "✅ 백업 완료: ${BACKUP_DIR}/"

# =================================================================
# 2단계: 새로운 화합물 제조 시스템 구조 생성
# =================================================================
echo "🏗️  2단계: 화합물 제조 시스템 디렉토리 구조 생성..."

# 메인 src 디렉토리 백업 후 재구성
mv src src_old_$(date +%Y%m%d_%H%M%S)
mkdir -p src

# 7일 마스터플랜에 따른 패키지 구조 생성
echo "  Creating package directories..."

# 1. 기존 doosan_m0609_control 이동 (기본 로봇 제어)
if [ -d "src_old_*/doosan_m0609_control" ]; then
    cp -r src_old_*/doosan_m0609_control src/
    echo "  ✅ doosan_m0609_control 이동 완료"
fi

# 2. 새로운 화합물 제조 전용 패키지들 생성
mkdir -p src/arduino_loadcell_interface/{src,include/arduino_loadcell_interface,msg,launch,config}
mkdir -p src/hybrid_weight_measurement/{src,include/hybrid_weight_measurement,msg,srv,launch,config}
mkdir -p src/salt_concentration_calculator/{src,include/salt_concentration_calculator,srv,launch,config}
mkdir -p src/precision_liquid_pouring/{src,include/precision_liquid_pouring,action,srv,launch,config}
mkdir -p src/chemistry_experiment_manager/{src,include/chemistry_experiment_manager,action,srv,launch,config}
mkdir -p src/safety_monitoring_system/{src,include/safety_monitoring_system,msg,srv,launch,config}
mkdir -p src/chemistry_msgs/{msg,srv,action}
mkdir -p src/experiment_data_logger/{src,include/experiment_data_logger,srv,launch,config}

echo "  ✅ 모든 패키지 디렉토리 생성 완료"

# =================================================================
# 3단계: 기존 패키지 컨텐츠 재활용 및 이동
# =================================================================
echo "📁 3단계: 기존 패키지 컨텐츠 재활용..."

# pouring_controller -> precision_liquid_pouring
if [ -d "src_old_*/pouring_controller" ]; then
    echo "  🔄 pouring_controller -> precision_liquid_pouring 변환"
    cp -r src_old_*/pouring_controller/* src/precision_liquid_pouring/ 2>/dev/null || true
fi

# weight_estimator -> hybrid_weight_measurement 베이스
if [ -d "src_old_*/weight_estimator" ]; then
    echo "  🔄 weight_estimator -> hybrid_weight_measurement 베이스 활용"
    cp -r src_old_*/weight_estimator/* src/hybrid_weight_measurement/ 2>/dev/null || true
fi

# experiment_manager -> chemistry_experiment_manager
if [ -d "src_old_*/experiment_manager" ]; then
    echo "  🔄 experiment_manager -> chemistry_experiment_manager 변환"
    cp -r src_old_*/experiment_manager/* src/chemistry_experiment_manager/ 2>/dev/null || true
fi

# safety_supervisor -> safety_monitoring_system
if [ -d "src_old_*/safety_supervisor" ]; then
    echo "  🔄 safety_supervisor -> safety_monitoring_system 확장"
    cp -r src_old_*/safety_supervisor/* src/safety_monitoring_system/ 2>/dev/null || true
fi

# pouring_interfaces -> chemistry_msgs 베이스
if [ -d "src_old_*/pouring_interfaces" ]; then
    echo "  🔄 pouring_interfaces -> chemistry_msgs 베이스 활용"
    cp -r src_old_*/pouring_interfaces/* src/chemistry_msgs/ 2>/dev/null || true
fi

echo "✅ 기존 패키지 컨텐츠 재활용 완료"

echo ""
echo "🎉 화합물 농도 제조 시스템 디렉토리 재구성 완료!"
echo ""
echo "📁 새로운 구조:"
echo "  ├── src/"
echo "  │   ├── doosan_m0609_control/           # M0609 로봇 제어"
echo "  │   ├── arduino_loadcell_interface/     # Day 1: 아두이노 로드셀"
echo "  │   ├── hybrid_weight_measurement/      # Day 2: 센서 융합"
echo "  │   ├── salt_concentration_calculator/  # Day 3: 농도 계산"
echo "  │   ├── precision_liquid_pouring/       # Day 4: 정밀 주입"
echo "  │   ├── chemistry_experiment_manager/   # Day 5: 실험 관리"
echo "  │   ├── safety_monitoring_system/       # Day 6: 안전 시스템"
echo "  │   ├── chemistry_msgs/                 # 메시지 정의"
echo "  │   └── experiment_data_logger/         # Day 7: 데이터 로깅"
echo ""
echo "📋 다음 단계:"
echo "1. Git add 및 commit"
echo "2. 팀원들과 공유를 위한 push"
echo "3. Day 1 아두이노 로드셀 작업 시작!"