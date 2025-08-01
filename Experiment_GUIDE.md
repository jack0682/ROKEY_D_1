# 🧪 Doosan M0609 화학 실험 자동화 시스템 사용 가이드

> **존재의 정밀함이 기계적 울림으로 구현되는 순간**  
> 화학 반응의 미세한 변화까지 감지하는 로봇팔의 움직임 속에서,  
> 인간의 의도가 분자 단위의 정확성으로 번역됩니다.

---

## 📋 목차

- [🚀 빠른 시작](#-빠른-시작)
- [🔧 시스템 설치](#-시스템-설치)
- [🧪 실험 모드 가이드](#-실험-모드-가이드)
- [📊 모니터링 및 진단](#-모니터링-및-진단)
- [⚠️ 안전 지침](#️-안전-지침)
- [🔍 트러블슈팅](#-트러블슈팅)
- [📚 고급 사용법](#-고급-사용법)

---

## 🚀 빠른 시작

### 1. 시스템 설치 (최초 1회)

```bash
# 1. 설치 스크립트 실행 (Ubuntu 22.04 + ROS2 Humble 자동 설치)
chmod +x install_system.sh
./install_system.sh

# 2. 터미널 재시작 (환경 변수 적용)
exec bash
```

### 2. 실험 실행

```bash
# 실험 실행 스크립트 권한 설정
chmod +x run_experiment.sh

# 실험 시스템 시작
./run_experiment.sh
```

### 3. 첫 번째 실험 추천

**시뮬레이션 환경에서 시작하세요:**
1. 메뉴에서 `1. 단순 좌표 이동 테스트` 선택
2. 정상 동작 확인 후 `2. 설탕물 농도 실험` 진행

---

## 🔧 시스템 설치

### 시스템 요구사항

| 구성 요소 | 최소 사양 | 권장 사양 |
|----------|----------|----------|
| OS | Ubuntu 22.04 LTS | Ubuntu 22.04 LTS |
| 메모리 | 6GB | 8GB+ |
| 디스크 | 15GB | 20GB+ |
| CPU | 4코어 | 8코어+ |
| 네트워크 | 이더넷 | 기가비트 이더넷 |

### 설치 과정 상세

```bash
# 1. 전체 시스템 자동 설치
./install_system.sh

# 2. 개별 구성 요소 확인
source install/setup.bash
ros2 pkg list | grep doosan_m0609

# 3. 실험 패키지 확인
ros2 pkg list | grep sugar_water
ros2 pkg list | grep chemistry_experiment
```

### 수동 빌드 (필요시)

```bash
# 의존성 설치
rosdep install -r --from-paths src --ignore-src --rosdistro humble -y

# 순차 빌드
colcon build --packages-select dsr_common2
colcon build --packages-select doosan_m0609_msgs
colcon build --packages-select doosan_m0609_hardware
colcon build --packages-select doosan_m0609_controller
colcon build  # 전체 빌드
```

---

## 🧪 실험 모드 가이드

### 🔬 기본 실험 모드

#### 1. 단순 좌표 이동 테스트
- **목적**: 로봇 기본 동작 확인
- **소요 시간**: 2-3분
- **필요 장비**: 없음 (시뮬레이션)
- **실행 방법**: 메뉴에서 `1` 선택

```bash
# 직접 실행
ros2 run sugar_water_experiment simple_sequence_controller
```

#### 2. 설탕물 농도 실험
- **목적**: 정밀 용액 제조 테스트
- **농도 범위**: 0.01 (1%) ~ 0.20 (20%)
- **권장 농도**: 0.05 (5%)
- **소요 시간**: 5-10분

```bash
# 직접 실행 (농도 0.05로 예시)
ros2 launch sugar_water_experiment sugar_water_experiment.launch.py target_concentration:=0.05
```

**농도별 특성:**
- `0.01-0.03`: 저농도, 정밀도 테스트용
- `0.05-0.10`: 표준 농도, 일반적 실험용
- `0.15-0.20`: 고농도, 점성 테스트용

#### 3. 정밀 용액 제조 실험
- **목적**: 로드셀 기반 정밀 계량
- **정밀도**: ±0.1g
- **필요 장비**: 아두이노 로드셀
- **실행 방법**: 메뉴에서 `3` 선택

```bash
# 직접 실행
ros2 run precision_liquid_pouring precision_pouring_node
```

### 🚀 고급 실험 모드

#### 4. 완전 자동화 실험
- **목적**: 센서 피드백 기반 자동 제조
- **필요 장비**: 실제 로봇 + 모든 센서
- **특징**: 실시간 농도 측정 및 조정

```bash
# 직접 실행
ros2 run sugar_water_experiment sugar_water_experimenter_node
```

#### 5. 커스텀 런치 파일 실행
다양한 시스템 구성으로 실험 가능:

**시뮬레이션 모드:**
```bash
# Gazebo 시뮬레이션
ros2 launch doosan_m0609_bringup dsr_bringup2_gazebo.launch.py

# RViz 시각화
ros2 launch doosan_m0609_bringup dsr_bringup2_rviz.launch.py
```

**실제 로봇 모드:**
```bash
# 통합 시스템 (실제 로봇)
ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=real

# 시뮬레이션 모드
ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=sim
```

#### 6. 시스템 통합 테스트
- **목적**: 전체 구성 요소 연동 확인
- **범위**: 로봇 + 센서 + 안전 시스템

```bash
# 직접 실행
ros2 run chemistry_experiment_manager experiment_coordinator
```

---

## 📊 모니터링 및 진단

### 🔍 실시간 모니터링

#### 로봇 상태 확인
```bash
# 조인트 상태
ros2 topic echo /joint_states

# 로봇 포즈
ros2 topic echo /robot_pose

# 에러 상태
ros2 topic echo /robot_error
```

#### 센서 데이터 모니터링
```bash
# 로드셀 데이터
ros2 topic echo /loadcell_data

# 화학 센서 데이터
ros2 topic echo /chemical_sensor_data

# 안전 상태
ros2 topic echo /safety_status
```

#### 시스템 진단
```bash
# ROS2 시스템 진단
ros2 doctor

# 노드 상태 확인
ros2 node list

# 토픽 상태 확인
ros2 topic list
```

### 📈 데이터 로깅

**실험 데이터 자동 저장:**
```bash
# 실험 로그 디렉토리
ls ~/experiment_logs/

# 최신 실험 데이터 확인
tail -f ~/experiment_logs/latest_experiment.log
```

**ROS2 백 녹화:**
```bash
# 전체 토픽 녹화
ros2 bag record -a -o experiment_$(date +%Y%m%d_%H%M%S)

# 특정 토픽만 녹화
ros2 bag record /joint_states /loadcell_data /chemical_sensor_data
```

---

## ⚠️ 안전 지침

### 🚨 실제 로봇 사용 시 필수 확인사항

#### 작업 전 점검
- [ ] 로봇 주변 장애물 제거
- [ ] 비상 정지 버튼 위치 확인
- [ ] 작업 공간 경계 설정 확인
- [ ] 안전 장비 착용 (보안경, 장갑)

#### 화학물질 안전
- [ ] 실험용 화학물질 MSDS 확인
- [ ] 적절한 환기 시설 가동
- [ ] 화학물질 누출 대응 장비 준비
- [ ] 응급처치 키트 준비

#### 전기 안전
- [ ] 로봇 및 센서 접지 확인
- [ ] 전선 손상 여부 점검
- [ ] 습기로부터 전자 장비 보호

### 🛡️ 비상 상황 대응

#### 비상 정지 방법
1. **하드웨어**: 로봇 베이스의 빨간 비상 정지 버튼
2. **소프트웨어**: 
   ```bash
   ros2 service call /emergency_stop std_srvs/srv/Empty "{}"
   ```
3. **키보드**: 실행 중인 터미널에서 `Ctrl+C`

#### 오류 상황별 대응

**로봇 연결 오류:**
```bash
# 네트워크 연결 확인
ping 192.168.137.100

# 로봇 재시작 후 재연결
ros2 service call /reconnect_robot std_srvs/srv/Empty "{}"
```

**센서 오류:**
```bash
# USB 포트 확인
ls /dev/ttyUSB* /dev/ttyACM*

# 센서 재시작
sudo systemctl restart arduino-sensors
```

---

## 🔍 트러블슈팅

### 자주 발생하는 문제와 해결법

#### 1. 빌드 오류

**문제**: 패키지 빌드 실패
```
CMake Error: Could not find libDRFL.a
```

**해결**:
```bash
# DRFL 라이브러리 확인
ls src/dsr_common2/lib/humble/x86_64/libDRFL.a

# 권한 설정
chmod 644 src/dsr_common2/lib/humble/x86_64/libDRFL.a

# 다시 빌드
colcon build --packages-select dsr_common2
```

#### 2. 로봇 연결 실패

**문제**: 192.168.137.100에 연결할 수 없음

**해결**:
```bash
# 네트워크 설정 확인
ip addr show

# 라우팅 테이블 확인
ip route

# 방화벽 확인
sudo ufw status
```

#### 3. ROS2 환경 오류

**문제**: 패키지를 찾을 수 없음

**해결**:
```bash
# 환경 변수 확인
echo $ROS_DISTRO
echo $AMENT_PREFIX_PATH

# 환경 재설정
source /opt/ros/humble/setup.bash
source install/setup.bash
```

#### 4. 센서 데이터 오류

**문제**: 아두이노 센서 데이터 수신 불가

**해결**:
```bash
# 시리얼 포트 권한 확인
sudo usermod -a -G dialout $USER
sudo chmod 666 /dev/ttyUSB0

# 아두이노 펌웨어 확인
arduino-cli compile --fqbn arduino:avr:uno src/arduino_sensors/
```

### 로그 분석

**빌드 로그 확인:**
```bash
# 최신 빌드 로그
cat log/latest_build/*/std*.log

# 에러만 필터링
grep -i error log/latest_build/*/stderr.log
```

**실행 로그 확인:**
```bash
# ROS2 로그 위치
ls ~/.ros/log/

# 특정 노드 로그
ros2 node info /sugar_water_experimenter
```

---

## 📚 고급 사용법

### 🛠️ 커스텀 실험 개발

#### 새로운 실험 시나리오 추가

1. **실험 패키지 생성:**
```bash
cd src/
ros2 pkg create --build-type ament_cmake my_custom_experiment \
  --dependencies rclcpp std_msgs geometry_msgs doosan_m0609_msgs
```

2. **실험 노드 구현:**
```cpp
// src/my_custom_experiment/src/custom_experiment_node.cpp
#include <rclcpp/rclcpp.hpp>
#include <doosan_m0609_msgs/srv/move_j.hpp>

class CustomExperimentNode : public rclcpp::Node
{
public:
    CustomExperimentNode() : Node("custom_experiment_node")
    {
        // 실험 로직 구현
    }
};
```

3. **런치 파일 작성:**
```python
# launch/custom_experiment.launch.py
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='my_custom_experiment',
            executable='custom_experiment_node',
            name='custom_experiment',
            parameters=[{'experiment_param': 'value'}]
        )
    ])
```

### 🔬 실험 매개변수 조정

#### 로봇 동작 파라미터
```yaml
# config/robot_params.yaml
robot_speed: 0.5        # 동작 속도 (0.1-1.0)
acceleration: 0.3       # 가속도 (0.1-1.0)
precision_mode: true    # 정밀 모드 활성화
safety_distance: 0.05   # 안전 거리 (m)
```

#### 화학 실험 파라미터
```yaml
# config/chemistry_params.yaml
mixing_time: 30.0       # 혼합 시간 (초)
settling_time: 10.0     # 안정화 시간 (초)
temperature_range:      # 온도 범위
  min: 20.0
  max: 25.0
concentration_tolerance: 0.001  # 농도 허용 오차
```

### 📡 원격 모니터링 설정

#### 웹 기반 모니터링
```bash
# ROS2 웹 브리지 설치
sudo apt install ros-humble-rosbridge-suite

# 웹 서버 시작
ros2 launch rosbridge_server rosbridge_websocket.launch.py
```

#### 대시보드 접속
```bash
# 브라우저에서 접속
firefox http://localhost:9090/rosbridge
```

### 🔄 자동화 스크립트

#### 일일 실험 자동화
```bash
#!/bin/bash
# daily_experiment.sh - 매일 자동 실험 실행

# 시스템 시작
./run_experiment.sh --automated --experiment=sugar_concentration \
  --concentration=0.05 --samples=10 --log-dir=/tmp/daily_logs

# 결과 분석
python3 scripts/analyze_experiment_results.py /tmp/daily_logs/
```

#### 배치 실험 처리
```bash
#!/bin/bash
# batch_experiment.sh - 여러 농도로 연속 실험

concentrations=(0.01 0.03 0.05 0.07 0.10)

for conc in "${concentrations[@]}"; do
    echo "실험 시작: 농도 $conc"
    ./run_experiment.sh --automated --concentration=$conc
    sleep 60  # 1분 대기
done
```

---

## 🎯 실험 시나리오 예시

### 시나리오 1: 농도 정확도 테스트
**목표**: 다양한 농도에서의 제조 정확도 측정

```bash
# 실행 명령
for i in {1..5}; do
    ./run_experiment.sh --experiment=precision_test \
      --target=0.05 --repetition=$i
done
```

### 시나리오 2: 재현성 평가
**목표**: 동일 조건 반복 실험으로 재현성 확인

```bash
# 10회 반복 실험
./run_experiment.sh --experiment=reproducibility \
  --concentration=0.05 --repetitions=10
```

### 시나리오 3: 온도 영향 분석
**목표**: 온도 변화가 실험 결과에 미치는 영향 분석

```bash
# 온도별 실험
temperatures=(20 22 24 26 28)
for temp in "${temperatures[@]}"; do
    ./run_experiment.sh --experiment=temperature_study \
      --temperature=$temp --concentration=0.05
done
```

---

## 📞 지원 및 문의

### 기술 지원
- **이메일**: support@doosan-robotics.com
- **포럼**: [Doosan Robotics Developer Forum](https://developers.doosan-robotics.com)
- **문서**: [공식 매뉴얼](https://manual.doosan-robotics.com)

### 커뮤니티
- **GitHub**: [프로젝트 저장소](https://github.com/doosan-robotics/chemical-automation)
- **Discord**: [개발자 커뮤니티](https://discord.gg/doosan-robotics)

### 기여하기
이 프로젝트에 기여하고 싶으시다면:
1. 이슈 제보: GitHub Issues
2. 코드 기여: Pull Request
3. 문서 개선: Wiki 편집

---

## 📄 라이선스

이 프로젝트는 Apache 2.0 라이선스 하에 배포됩니다.  
자세한 내용은 [LICENSE](LICENSE) 파일을 참조하세요.

---

## 🎨 에필로그

> *"기계의 정밀함 속에서 인간의 창의성이 춤추고,  
> 분자의 작은 울림이 거대한 발견의 서곡이 됩니다.  
> 이 시스템은 단순한 자동화를 넘어,  
> 과학적 탐구의 새로운 지평을 여는 도구입니다."*

화학 실험의 미래가 여기서 시작됩니다. 🧪✨

---

**마지막 업데이트**: 2024년 12월  
**버전**: 1.0.0  
**작성자**: 리라 (Lyra) - 존재론적 자동화의 구현자