# Sugar Water Experiment Package - Refactored (Version 2.0)

**Doosan 공식 예제 방식으로 완전히 리팩토링된 설탕물 실험 패키지**

이 패키지는 기존의 ROS2 토픽 기반 시뮬레이션 방식에서 Doosan 공식 Python 예제의 패턴을 C++로 완전히 구현한 실제 로봇 제어 시스템입니다.

## 🔄 주요 변경사항 (v1.0 → v2.0)

### ❌ 기존 문제점 (v1.0)
- ROS2 토픽 퍼블리시만으로 실제 로봇 제어 불가
- DSR_ROBOT2 API 직접 활용하지 않음
- 로봇 상태 피드백 없는 단순 시뮬레이션
- 도구 및 TCP 설정 없음

### ✅ 새로운 구조 (v2.0)
- **실제 DRFL API 직접 호출** - `CDRFLEx` 클래스 사용
- **공식 예제 패턴 구현** - Python 예제의 C++ 완전 재현
- **실제 로봇 상태 피드백** - `get_current_posx()`, `wait_motion_complete()` 
- **도구 및 TCP 설정** - `set_tool()`, `set_tcp()` 지원
- **타입 안전성** - `posx`, `posj` 타입 래퍼

## 🏗️ 새로운 아키텍처

```
sugar_water_experiment/
├── include/sugar_water_experiment/
│   └── doosan_robot_interface.hpp      # DRFL 래퍼 인터페이스
├── src/
│   ├── doosan_robot_interface.cpp      # 실제 로봇 제어 구현
│   ├── sugar_water_experiment_refactored.cpp  # 메인 실험 노드
│   └── [legacy files...]               # 기존 호환성 유지
└── launch/
    └── sugar_water_experiment_real.launch.py  # 실제 로봇 런치
```

## 🤖 DoosanRobotInterface 클래스

공식 예제의 패턴을 C++로 구현한 핵심 인터페이스:

```cpp
// 공식 예제: DR_init.__dsr__id = ROBOT_ID
DoosanRobotInterface robot("dsr01", "m0609", "192.168.1.100");

// 공식 예제: m_drfl.openConnection() + m_drfl.setRobotControl(true)  
robot.connect();

// 공식 예제: set_tool(), set_tcp()
robot.set_tool_and_tcp("Tool Weight_2FG", "2FG_TCP");

// 공식 예제: movej(JReady, vel=100, acc=100)
robot.movej({0, 0, 90, 0, 90, 0}, 100, 100);

// 공식 예제: amovel(point1, vel=100, acc=100, ra=DR_MV_RA_OVERRIDE)
robot.amovel({674.863, -10.427, 65.98, 101.889, -175.666, 109.147});

// 공식 예제: pos, _ = get_current_posx()
auto current_pos = robot.get_current_posx();
```

## 🧪 실험 시퀀스 (공식 예제 방식)

```cpp
// 1. 로봇 연결 및 제어권 확보
robot.connect();

// 2. 도구 및 TCP 설정
robot.set_tool_and_tcp("Tool Weight_2FG", "2FG_TCP");

// 3. 홈 포지션 이동 (JReady)
robot.movej({0, 0, 90, 0, 90, 0});

// 4. 실험 순서 (point1, point2, point3...)
for (auto& point : experiment_positions) {
    robot.amovel(point);  // 비동기 이동
    perform_task();       // 작업 수행
    std::this_thread::sleep_for(3s);  // 다음 동작 대기
}
```

## 🚀 사용법

### 1. 빌드
```bash
cd /home/jack/project_ws
colcon build --packages-select sugar_water_experiment
source install/setup.bash
```

### 2. 실제 로봇 실행
```bash
# 기본 설정으로 실행
ros2 launch sugar_water_experiment sugar_water_experiment_real.launch.py

# 커스텀 설정으로 실행  
ros2 launch sugar_water_experiment sugar_water_experiment_real.launch.py \
    robot_ip:=192.168.1.100 \
    velocity:=80 \
    tool_name:="Custom_Tool"
```

### 3. 직접 노드 실행
```bash
ros2 run sugar_water_experiment sugar_water_experiment_refactored \
    --ros-args \
    -p robot_ip:=192.168.1.100 \
    -p velocity:=100
```

## 📊 상태 모니터링

### 토픽 구독
```bash
# 실험 상태 모니터링
ros2 topic echo /dsr01/experiment_status

# 현재 관절 상태
ros2 topic echo /dsr01/current_joint_state  

# 현재 Cartesian 위치
ros2 topic echo /dsr01/current_pose
```

### 상태 메시지
- `EXPERIMENT_STARTED` - 실험 시작
- `CONNECTING_ROBOT` - 로봇 연결 중
- `SETTING_TOOL_TCP` - 도구/TCP 설정 중
- `MOVING_TO_HOME` - 홈 포지션 이동
- `MOVING_TO_POSITION_X` - X번 위치로 이동
- `PERFORMING_TASK_X` - X번 작업 수행
- `EXPERIMENT_COMPLETED` - 실험 완료

## ⚙️ 파라미터

| 파라미터 | 기본값 | 설명 |
|----------|--------|------|
| `robot_id` | "dsr01" | 로봇 ID (네임스페이스) |
| `robot_model` | "m0609" | 로봇 모델 |
| `robot_ip` | "192.168.1.100" | 로봇 IP 주소 |
| `velocity` | 100 | 이동 속도 |
| `acceleration` | 100 | 가속도 |
| `tool_name` | "Tool Weight_2FG" | 도구 이름 |
| `tcp_name` | "2FG_TCP" | TCP 이름 |

## 🛡️ 안전 기능

- **연결 상태 검증** - 로봇 연결 전 네트워크 확인
- **로봇 상태 확인** - 제어 전 로봇 준비 상태 검증  
- **비상 정지** - 예외 발생 시 자동 비상 정지
- **모션 완료 대기** - 각 동작 완료 후 다음 동작 실행
- **상태 피드백** - 실시간 로봇 상태 모니터링

## 🔧 트러블슈팅

### 연결 실패
```bash
# 네트워크 연결 확인
ping 192.168.1.100

# 로봇 제어기 상태 확인
# 티치펜던트에서 원격 제어 모드 활성화 필요
```

### 빌드 실패  
```bash
# DRFL 라이브러리 확인
ls -la src/dsr_common2/lib/humble/x86_64/libDRFL.a

# Poco 라이브러리 설치
sudo apt install libpoco-dev
```

### 실행 오류
```bash
# 로그 확인
ros2 run sugar_water_experiment sugar_water_experiment_refactored --ros-args --log-level debug

# 로봇 상태 확인
# 티치펜던트에서 로봇 모드, 서보 상태 확인
```

## 📈 성능 비교

| 항목 | 기존 (v1.0) | 리팩토링 (v2.0) |
|------|-------------|-----------------|
| 실제 로봇 제어 | ❌ 토픽만 퍼블리시 | ✅ DRFL 직접 호출 |  
| 상태 피드백 | ❌ 시뮬레이션 | ✅ 실시간 피드백 |
| 도구 설정 | ❌ 없음 | ✅ 완전 지원 |
| 안전성 | ❌ 낮음 | ✅ 높음 |
| 공식 예제 호환성 | ❌ 없음 | ✅ 완전 호환 |

## 🔮 향후 확장 계획

- [ ] MoveIt2 통합 - 경로 계획 및 충돌 회피
- [ ] 힘 제어 - 접촉 작업을 위한 힘/토크 제어  
- [ ] 비젼 시스템 - 카메라 기반 객체 인식
- [ ] 다중 로봇 - 여러 로봇 협업 제어
- [ ] GUI 도구 - 실험 모니터링 대시보드

## 📞 지원

문제 발생 시 다음을 확인해주세요:

1. **로봇 연결** - IP, 네트워크 설정
2. **DRFL 라이브러리** - 버전 및 경로 확인  
3. **로봇 상태** - 티치펜던트 모드 확인
4. **로그 메시지** - 상세 오류 정보 확인

---

**🎯 이제 당신의 설탕물 실험 패키지는 Doosan 공식 예제와 동일한 방식으로 실제 로봇을 제어할 수 있습니다!** 🤖✨
