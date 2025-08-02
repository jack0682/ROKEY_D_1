# Project Workspace - Doosan M0609 Sugar Water Experiment

**Doosan M0609 로봇을 사용한 설탕물 농도 실험 자동화 시스템**

이 워크스페이스는 두 가지 구조를 지원합니다:
- **기존 구조**: project_ws 자체 패키지들 (완전 포함)
- **새로운 구조**: DoosanBootcam3rdCo1의 최신 패키지들 (심볼릭 링크)

## 🏗️ **워크스페이스 구조**

```
project_ws/
├── src/
│   ├── [자체 개발 패키지 - Git 관리]
│   │   ├── sugar_water_experiment/      # 🧪 메인 실험 패키지 (v2.0 리팩토링)
│   │   ├── doosan_m0609_msgs/           # 🔗 M0609 메시지 정의
│   │   ├── doosan_m0609_hardware/       # 🤖 하드웨어 인터페이스
│   │   ├── doosan_m0609_controller/     # 🎮 로봇 컨트롤러
│   │   ├── arduino_loadcell_interface/  # ⚖️ 로드셀 인터페이스
│   │   └── chemistry_experiment_manager/ # ⚗️ 화학 실험 매니저
│   │
│   └── [외부 패키지 - 심볼릭 링크, Git 제외]
│       ├── dsr_bringup2 → ../../DoosanBootcam3rdCo1/dsr_bringup2
│       ├── dsr_controller2 → ../../DoosanBootcam3rdCo1/dsr_controller2
│       └── ... (다른 dsr_* 패키지들)
│
├── install_script.sh                    # 🚀 자동 설치 스크립트
└── README.md                           # 📖 프로젝트 문서
```

## 🚀 **빠른 시작**

### 1. **저장소 클론**
```bash
git clone <your-repo-url> project_ws
cd project_ws
```

### 2. **의존성 설치 및 심볼릭 링크 생성**
```bash
# 모든 의존성 자동 설치 + 새로운 구조 패키지 링크
chmod +x install_script.sh
./install_script.sh
```

### 3. **워크스페이스 빌드**
```bash
colcon build
source install/setup.bash
```

### 4. **실험 실행**
```bash
# 리팩토링된 실제 로봇 제어 (권장)
ros2 launch sugar_water_experiment sugar_water_experiment_real.launch.py

# 기존 시뮬레이션 모드
ros2 run sugar_water_experiment simple_sequence_controller
```

## 📦 **패키지 설명**

### 🧪 **sugar_water_experiment (v2.0)**
- **Doosan 공식 예제 방식**으로 완전히 리팩토링
- **실제 DRFL API 직접 호출**로 진짜 로봇 제어
- 설탕물 농도 실험 10단계 자동화

### 🤖 **doosan_m0609_***
- M0609 로봇 전용 ROS2 패키지들
- 하드웨어 인터페이스, 메시지, 컨트롤러 포함

### ⚖️ **arduino_loadcell_interface**
- 아두이노 기반 로드셀 무게 측정
- 실시간 무게 데이터 ROS2 토픽 퍼블리시

## 🔧 **개발 환경 설정**

### **필수 요구사항**
- Ubuntu 22.04 LTS
- ROS2 Humble
- Doosan M0609 로봇 (또는 시뮬레이터)
- Arduino (로드셀용, 선택사항)

### **새로운 구조 패키지 (DoosanBootcam3rdCo1)**
이 워크스페이스는 최신 Doosan 패키지들을 심볼릭 링크로 참조합니다:

1. **DoosanBootcam3rdCo1 디렉토리가 필요합니다:**
   ```
   /home/jack/
   ├── project_ws/          # 이 저장소
   └── DoosanBootcam3rdCo1/ # Doosan 공식 패키지 (별도 확보 필요)
   ```

2. **install_script.sh 실행 시 자동으로 링크 생성됩니다**

3. **수동 링크 생성 (필요시):**
   ```bash
   cd project_ws/src
   ln -sf ../../DoosanBootcam3rdCo1/dsr_bringup2 .
   ln -sf ../../DoosanBootcam3rdCo1/dsr_controller2 .
   # ... 기타 패키지들
   ```

## 🎮 **사용법**

### **실제 로봇 연결**
```bash
# 로봇 IP 확인 및 네트워크 연결
ping 192.168.1.100

# 실험 실행
ros2 launch sugar_water_experiment sugar_water_experiment_real.launch.py \
    robot_ip:=192.168.1.100 \
    velocity:=80
```

### **시뮬레이션 모드**
```bash
# 가상 로봇으로 시뮬레이션
ros2 run sugar_water_experiment simple_sequence_controller
```

### **상태 모니터링**
```bash
# 실험 진행 상황
ros2 topic echo /dsr01/experiment_status

# 로봇 위치
ros2 topic echo /dsr01/current_pose

# 무게 측정 (로드셀 연결시)
ros2 topic echo /loadcell/weight
```

## 🔄 **Git 워크플로우**

### **이 저장소에 포함되는 것**
- ✅ 자체 개발 패키지들 (`sugar_water_experiment` 등)
- ✅ 설정 파일들 (launch, config, CMakeLists.txt)
- ✅ 설치 스크립트 (`install_script.sh`)
- ✅ 문서 (README, 사용법)

### **이 저장소에 포함되지 않는 것**
- ❌ 심볼릭 링크된 외부 패키지들 (`dsr_*`)
- ❌ 빌드 결과물 (`build/`, `install/`, `log/`)
- ❌ IDE 설정 파일들

### **새로운 환경에서 설정하기**
1. **이 저장소 클론**
2. **DoosanBootcam3rdCo1 확보** (별도 다운로드/클론)
3. **install_script.sh 실행** → 자동으로 모든 설정 완료

## 🛡️ **안전 주의사항**

- **실제 로봇 사용 시 반드시 안전 교육 이수**
- **비상 정지 버튼 위치 숙지**
- **작업 공간 내 장애물 제거**
- **로봇 동작 반경 내 사람 접근 금지**

## 🐛 **트러블슈팅**

### **심볼릭 링크 오류**
```bash
# 링크 상태 확인
ls -la src/dsr_*

# 링크 재생성
cd src
rm dsr_*  # 기존 링크 제거
ln -sf ../../DoosanBootcam3rdCo1/dsr_bringup2 .
```

### **빌드 오류**
```bash
# 의존성 재설치
rosdep install --reinstall --from-paths src

# 클린 빌드
rm -rf build install log
colcon build
```

### **로봇 연결 실패**
```bash
# 네트워크 연결 확인
ping 192.168.1.100

# 로봇 컨트롤러 상태 확인 (티치펜던트)
# - 원격 제어 모드 활성화
# - 서보 ON 상태 확인
```

## 📈 **버전 히스토리**

- **v2.0** - Doosan 공식 예제 방식 완전 리팩토링
- **v1.0** - 초기 ROS2 토픽 기반 시뮬레이션

## 📞 **지원**

문제 발생 시:
1. **로그 확인**: `ros2 run <package> <node> --ros-args --log-level debug`
2. **이슈 등록**: GitHub Issues 활용
3. **문서 참조**: 각 패키지의 README.md

---

**🎯 이제 당신의 설탕물 실험이 완전 자동화됩니다!** 🧪🤖✨
