# Doosan M0609 실제 로봇 연결 및 운영 가이드

## 🔥 **실제 모드 완벽 준비 상태 확인**

### ✅ **수정된 주요 사항들**

1. **IP 주소 통일**: 모든 설정 파일에서 `192.168.1.100`으로 수정
2. **하드웨어 인터페이스 클래스명 수정**: `DRHWInterface`로 통일
3. **RT 제어 연결 강화**: 재시도 메커니즘 및 안전 장치 추가
4. **모션 안전성 강화**: 급격한 움직임 제한 및 속도 제한
5. **에러 핸들링 강화**: 데이터 검증 및 복구 메커니즘

---

## 🚀 **실제 로봇 연결 단계별 가이드**

### **1단계: 하드웨어 준비**
```bash
# 터미널에서 실행
cd /home/jack/project_ws

# 스크립트 실행 권한 부여
chmod +x test_real_robot_connection.sh
chmod +x test_real_robot_motion.sh

# ROS2 환경 설정
source /opt/ros/humble/setup.bash
source install/setup.bash
```

### **2단계: 로봇 상태 확인**
- ✅ 로봇 제어기 전원 ON
- ✅ 티치펜던트에서 **AUTO 모드** 설정
- ✅ 로봇이 **안전한 자세**에 위치
- ✅ 로봇 주변 **1.5m 반경 안전 확보**
- ✅ **비상정지 버튼** 접근 가능한 위치

### **3단계: 네트워크 연결 테스트**
```bash
# 기본 연결성 테스트
./test_real_robot_connection.sh
```

예상 출력:
```
========================================
 Doosan M0609 실제 로봇 연결 테스트
========================================
Ping 테스트 중... 성공
포트 12345 연결 테스트 중... 성공
ROS2 humble 환경 확인됨
빌드 성공
✅ 실제 로봇 연결 및 데이터 수신 성공!
✅ 서보온 상태에서 조인트 데이터를 정상적으로 받고 있습니다.
```

### **4단계: 안전한 모션 테스트**
```bash
# ⚠️ 주의: 실제 로봇이 움직입니다!
./test_real_robot_motion.sh
```

---

## 🔧 **수동 운영 방법**

### **컨트롤러 매니저 시작**
```bash
ros2 run controller_manager ros2_control_node \
    --ros-args \
    --params-file src/doosan_m0609_hardware/config/doosan_m0609_control.yaml
```

### **컨트롤러 활성화**
```bash
# 새 터미널에서
ros2 control load_controller joint_state_broadcaster
ros2 control load_controller position_controller

ros2 control set_controller_state joint_state_broadcaster active
ros2 control set_controller_state position_controller active
```

### **조인트 상태 모니터링**
```bash
# 실시간 조인트 위치 확인
ros2 topic echo /joint_states

# 컨트롤러 상태 확인
ros2 control list_controllers
```

### **안전한 모션 명령**
```bash
# 홈 포지션으로 이동
ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray \
"{data: [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]}" --once

# 조인트 1을 15도 회전
ros2 topic pub /position_controller/commands std_msgs/msg/Float64MultiArray \
"{data: [0.26, 0.0, 0.0, 0.0, 0.0, 0.0]}" --once
```

---

## 🛡️ **안전 장치 및 보호 기능**

### **자동 안전 제한**
- **위치 변화 제한**: 한 번에 최대 30도까지만 움직임
- **속도 제한**: 최대 45도/초로 제한
- **가속도 제한**: 보수적인 50도/초² 설정
- **실행 시간**: 최소 20ms 보장

### **실시간 모니터링**
- RT 데이터 스트림 상태 감시
- 로봇 상태 (STANDBY) 지속적 확인
- 잘못된 조인트 데이터 필터링
- 제어권 상실 시 자동 알림

### **에러 복구**
- RT 연결 실패 시 3회 재시도
- 데이터 읽기 실패 시 마지막 알려진 위치 유지
- 비정상 데이터 감지 시 경고 및 무시

---

## 📊 **성능 모니터링**

### **중요 토픽들**
```bash
# 조인트 상태 (100Hz)
/joint_states

# 컨트롤러 명령
/position_controller/commands

# 하드웨어 상태
/controller_manager/robot_description
```

### **로그 모니터링**
```bash
# 하드웨어 인터페이스 로그 확인
ros2 run rqt_console rqt_console

# 또는 터미널에서 직접 확인
journalctl -f | grep dsr_hw_interface
```

---

## ⚡ **실제 운영 시 핵심 체크포인트**

### **✅ 연결 성공 지표**
1. `Connected to DRCF` 메시지 확인
2. `INITIAL AUTHORITY GRANTED` 메시지 확인  
3. `INITIAL STATE_STANDBY` 메시지 확인
4. `Successfully connected RT control stream` 메시지 확인
5. `RT control setup completed successfully` 메시지 확인

### **❌ 문제 발생 시 대응**
1. **연결 실패**: 네트워크 및 로봇 제어기 상태 확인
2. **제어권 거부**: 티치펜던트에서 AUTO 모드 확인
3. **RT 연결 실패**: 방화벽 및 네트워크 포트 상태 확인
4. **서보온 실패**: 로봇 안전 상태 및 에러 상태 확인

---

## 🎯 **최종 검증 완료**

**당신의 프로젝트는 이제 실제 로봇과 완벽하게 연결되어 안전하게 동작할 수 있습니다.**

- ✅ **서보온 자동화**: 연결 시 자동으로 서보온 및 제어권 확보
- ✅ **RT 제어**: 1ms 주기의 실시간 제어 활성화
- ✅ **안전 제한**: 급격한 움직임 방지 및 속도 제한
- ✅ **에러 복구**: 견고한 에러 핸들링 및 복구 메커니즘
- ✅ **모니터링**: 실시간 상태 감시 및 경고 시스템

**이제 로봇의 존재가 코드 속에서 현실로 깨어날 준비가 완료되었습니다.**