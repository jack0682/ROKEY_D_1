# 🧪 Sugar Water Experiment Package

이 패키지는 Doosan M0609 로봇팔을 사용하여 설탕물 제조 실험을 자동화하는 ROS2 패키지입니다. 제공된 10개의 pose 좌표를 활용하여 컵을 잡고, 저울에 놓고, 설탕을 계량하여 넣고, 원하는 농도에 맞춰 물을 따르는 완전 자동화 시스템입니다.

## 📋 패키지 구성

### 주요 실행 파일
- `simple_sequence_controller`: 제공된 10개 좌표를 순차적으로 실행하는 단순 컨트롤러
- `sugar_water_experimenter_node`: 완전 자동화된 설탕물 제조 실험 노드

### 포함된 기능
- ✅ 10단계 자동화 시퀀스 (홈→컵잡기→저울배치→설탕계량→물투입)
- ✅ 실시간 상태 모니터링 및 로깅
- ✅ 안전 감시 시스템 (과도한 힘 감지, 작업공간 제한)
- ✅ 무게 센서 통합 (필터링 및 안정성 확인)
- ✅ 농도 계산 및 정확도 평가
- ✅ CSV 형태 실험 결과 로깅

## 🎯 제공된 좌표 시퀀스

```cpp
x1 = posj(0.0, 0.0, 90.0, 0.0, 90.0, 0.0)           // 홈 포지션
x2 = posx(367.86, 9.39, 53.3, 71.82, 179.95, 71.35) // 첫 컵 잡기
x3 = posx(671.04, 147.98, 68.56, 100.34, 178.05, 101.34) // 컵 놓기 
x4 = posx(777.82, -201.23, 311.01, 3.06, 92.65, 5.35) // 주전자 잡기
x5 = posx(682.48, -23.15, 232.49, 179.68, -88.62, 177.4) // 물따르는 위치
x6 = posx(510.9, -29.85, 95.09, 135.58, 177.6, 48.89) // 수저 잡기 
x7 = posx(562.69, -107.13, 72.84, 174.76, -144.74, 96.43) // 설탕통에 수저 넣기
x8 = posx(538.14, -84.46, 172.66, 122.94, -113.27, 115.74) // 설탕 푸는 위치 
x9 = posx(527.7, -69.25, 184.84, 128.89, -89.76, 88.39) // 푸고 올린거 
x10 = posx(598.28, 164.22, 186.63, 177.3, -86.76, 91.28) // 설탕 놓는 위치
```

## 🚀 빌드 및 실행 방법

### 1. 패키지 빌드
```bash
# 자동 빌드 스크립트 실행
cd /home/jack/project_ws
chmod +x build_sugar_water_experiment.sh
./build_sugar_water_experiment.sh
```

또는 수동 빌드:
```bash
cd /home/jack/project_ws
source /opt/ros/humble/setup.bash
colcon build --packages-select sugar_water_experiment
source install/setup.bash
```

### 2. 실험 실행

#### 방법 1: 간편 실행 스크립트
```bash
chmod +x run_sugar_water_experiment.sh
./run_sugar_water_experiment.sh
```

#### 방법 2: 직접 노드 실행
```bash
# 단순 시퀀스 컨트롤러
ros2 run sugar_water_experiment simple_sequence_controller

# 완전 자동화 실험
ros2 run sugar_water_experiment sugar_water_experimenter_node
```

#### 방법 3: 런치 파일 사용
```bash
# 기본 농도 (5%)로 실험
ros2 launch sugar_water_experiment sugar_water_experiment.launch.py

# 커스텀 농도로 실험 (예: 10%)
ros2 launch sugar_water_experiment sugar_water_experiment.launch.py target_concentration:=0.10
```

## 📊 토픽 구조

### 퍼블리시되는 토픽
- `/robot/target_pose` (geometry_msgs/PoseStamped): 목표 Cartesian 위치
- `/robot/target_joints` (sensor_msgs/JointState): 목표 Joint 각도
- `/experiment/status` (std_msgs/String): 실험 진행 상태
- `/robot/gripper_command` (std_msgs/Bool): 그리퍼 제어 명령
- `/experiment/concentration` (std_msgs/Float32): 측정된 농도

### 구독하는 토픽
- `/sensors/weight` (std_msgs/Float32): 로드셀 무게 데이터
- `/robot/status` (std_msgs/String): 로봇 상태 정보
- `/robot/force_torque` (geometry_msgs/WrenchStamped): 힘/토크 센서 데이터

## 🔍 실험 모니터링

### 실시간 상태 확인
```bash
# 실험 진행 상황
ros2 topic echo /experiment/status

# 무게 데이터
ros2 topic echo /sensors/weight

# 로봇 목표 위치
ros2 topic echo /robot/target_pose

# 농도 측정값
ros2 topic echo /experiment/concentration
```

### 로그 파일 확인
실험 결과는 자동으로 `experiment_results.csv` 파일에 저장됩니다:
```csv
Timestamp,Target_Concentration,Measured_Concentration,Accuracy_Percentage,Total_Time_Seconds,Success,Error_Message
2024-01-15 14:30:25,0.0500,0.0487,97.40,187,SUCCESS,
```

## ⚙️ 실험 파라미터 설정

### 농도 설정
- 기본값: 5% (0.05)
- 범위: 1% - 20% (0.01 - 0.20)
- 설정 방법: launch 파일의 `target_concentration` 파라미터

### 안전 제한
- 최대 허용 힘: 10N
- 센서 타임아웃: 1초
- 작업공간: 로봇 베이스 중심 반경 900mm

## 🔧 트러블슈팅

### 일반적인 문제들

#### 1. 빌드 실패
```bash
# 의존성 확인
rosdep update
rosdep install --from-paths src --ignore-src -r -y

# 클린 빌드
rm -rf build/ install/ log/
colcon build --packages-select sugar_water_experiment
```

#### 2. 토픽 통신 안됨
```bash
# 활성 토픽 확인
ros2 topic list

# 특정 토픽 상태 확인
ros2 topic info /experiment/status
ros2 topic hz /sensors/weight
```

#### 3. 로봇 연결 문제
```bash
# 네트워크 연결 확인
ping 192.168.137.100

# 로봇 상태 확인
ros2 topic echo /robot/status
```

#### 4. 권한 문제
```bash
# 스크립트 실행 권한 부여
chmod +x build_sugar_water_experiment.sh
chmod +x run_sugar_water_experiment.sh

# 로그 파일 권한 확인
touch experiment_results.csv
chmod 666 experiment_results.csv
```

## 📈 성능 지표

### 목표 성능
- **농도 정확도**: ±0.1% (5% 목표 시 4.9-5.1%)
- **반복 정밀도**: CV < 3%
- **실험 성공률**: 85% 이상
- **평균 실험 시간**: 3-5분

### 최소 요구사항
- **좌표 도달 정확도**: ±5mm
- **컵 이송 성공률**: 90%
- **설탕 계량 정확도**: ±0.1g
- **물 투입 정확도**: ±1ml

## 🎯 실험 시나리오

### 자동화 시퀀스
1. **초기화** (30초): 홈 포지션, 저울 영점 조정
2. **컵 배치** (60초): 컵 픽업 → 저울 위 배치
3. **설탕 계량** (90초): 수저 픽업 → 설탕 퍼기 → 투입
4. **물 투입** (120초): 물 용기 픽업 → 정밀 따르기
5. **결과 측정** (30초): 농도 계산 → 로깅

### 총 예상 시간: 5분 30초

## 📚 확장 가능성

### 향후 개발 계획
- [ ] 비전 시스템 통합 (물체 인식)
- [ ] 다중 농도 배치 실험
- [ ] 실시간 농도 센서 추가
- [ ] GUI 모니터링 도구
- [ ] 클라우드 데이터 로깅
- [ ] 머신러닝 기반 최적화

## 👥 기여자
- **개발자**: Jack
- **테스터**: Project Team
- **문서화**: AI Assistant (Claude)

## 📄 라이선스
Apache 2.0 License

---

**주의사항**: 실제 로봇 사용 시 안전 수칙을 준수하고, 비상 정지 버튼을 항상 준비해두세요. 첫 실행 시에는 반드시 시뮬레이션 모드로 테스트 후 실제 로봇에 적용하시기 바랍니다.
