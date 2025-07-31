# 🧪 정밀 화합물 농도 제조 시스템
## M0609 + 로드셀 하이브리드 정밀 농도 제조 프로젝트

### 🎯 프로젝트 목표
- **농도 정확도**: ±0.05% (5% 목표 농도에서 4.95-5.05%)
- **반복 정밀도**: 20회 연속 제조 시 표준편차 ±0.03%
- **시스템 성공률**: 연속 50회 실험에서 95% 성공
- **실험 속도**: 단일 샘플 제조 평균 4분 이내

```bash
cd /home/jack/project_ws
chmod +x complete_build.sh
./complete_build.sh
```

### 📂 패키지 구조
```
src/
├── doosan_m0609_control/           # M0609 로봇 기본 제어
├── arduino_loadcell_interface/     # 아두이노 HX711 로드셀 통신
├── hybrid_weight_measurement/      # M0609 토크 + 로드셀 융합 측정
├── salt_concentration_calculator/  # 소금물 농도 계산 엔진
├── precision_liquid_pouring/       # 정밀 액체 주입 제어
├── chemistry_experiment_manager/   # 실험 시퀀스 총괄
├── safety_monitoring_system/       # 안전 감시 및 비상 대응
├── chemistry_msgs/                 # 커스텀 메시지/서비스 정의
└── experiment_data_logger/         # 데이터 기록 및 성능 분석
```

### ⏰ 7일 개발 일정
- **Day 1**: 아두이노 로드셀 + M0609 토크센서 기본 캘리브레이션
- **Day 2**: 하이브리드 센서 융합 시스템 구현
- **Day 3**: 소금물 농도 계산 엔진 + 물리적 모델링
- **Day 4**: 정밀 액체 제어 시스템 구현
- **Day 5**: 실험 자동화 및 배치 시퀀스 관리
- **Day 6**: 안전 시스템 + 성능 최적화
- **Day 7**: 성능 검증 및 최종 통합 테스트

### 🚀 빠른 시작
```bash
# 환경 설정
source /opt/ros/humble/setup.bash
cd /home/jaeho/project_ws

# 디렉토리 구조 재정립 (최초 1회)
chmod +x restructure_chemistry.sh
./restructure_chemistry.sh

# 의존성 설치
sudo apt-get install -y libpoco-dev libyaml-cpp-dev libserial-dev

# Day 1 패키지 빌드
chmod +x development/scripts/build_day1.sh
./development/scripts/build_day1.sh

# 환경 소싱
source install/setup.bash
```

### 🔧 하드웨어 요구사항
- Doosan M0609 로봇 (내장 6축 토크센서)
- Arduino Uno + HX711 + 5kg 로드셀
- 표준 실험 도구 (비커, 저울, 표준 분동)

### 📊 성능 목표
- **로드셀 분해능**: 0.01g
- **토크센서 분해능**: 0.2N  
- **융합 후 실효 분해능**: 0.005g
- **농도 계산 정확도**: 99.95%

### 📅 현재 진행 상태
- [x] Day 0: 디렉토리 구조 재정립 완료
- [ ] Day 1: 아두이노 로드셀 시스템 구축
- [ ] Day 2: 센서 융합 및 정밀 무게 측정
- [ ] Day 3: 농도 계산 엔진 및 화학 모델링
- [ ] Day 4: 정밀 액체 제어 시스템
- [ ] Day 5: 실험 자동화 및 시퀀스 관리
- [ ] Day 6: 안전 시스템 및 성능 최적화
- [ ] Day 7: 성능 검증 및 최종 테스트

### 🛠️ 개발 도구
```bash
# Day별 빌드 스크립트
./development/scripts/build_day1.sh
./development/scripts/build_all_chemistry.sh

# 전체 시스템 테스트
ros2 launch chemistry_experiment_manager full_system.launch.py

# 개별 패키지 테스트
ros2 run arduino_loadcell_interface loadcell_node
ros2 run precision_liquid_pouring pour_control_node
```

### 🔗 관련 문서
- [7일 완전 실행 마스터플랜](7DAY_MASTERPLAN.md)
- [하드웨어 설정 가이드](docs/HARDWARE_SETUP.md)
- [API 문서](docs/API_REFERENCE.md)
