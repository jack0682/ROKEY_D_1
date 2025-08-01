#!/bin/bash
# post_integration_setup.sh - 통합 후 설정 및 빌드 스크립트

set -e

PROJECT_WS="/home/jack/project_ws"

echo "🔧 두산 M0609 패키지 통합 후 설정 시작..."

cd $PROJECT_WS

# 1. ROS2 환경 소싱
echo "📦 ROS2 환경 설정..."
source /opt/ros/humble/setup.bash

# 2. 의존성 업데이트 및 설치
echo "📚 의존성 설치 중..."
sudo apt-get update

# 필수 시스템 의존성
echo "🛠️ 시스템 의존성 설치..."
sudo apt-get install -y \
    libpoco-dev \
    libyaml-cpp-dev \
    wget \
    ros-humble-control-msgs \
    ros-humble-realtime-tools \
    ros-humble-xacro \
    ros-humble-joint-state-publisher-gui \
    ros-humble-ros2-control \
    ros-humble-ros2-controllers \
    ros-humble-gazebo-msgs \
    ros-humble-moveit-msgs \
    dbus-x11 \
    ros-humble-moveit-configs-utils \
    ros-humble-moveit-ros-move-group \
    ros-humble-gazebo-ros-pkgs \
    ros-humble-ros-gz-sim \
    ros-humble-ign-ros2-control

# 3. rosdep으로 ROS 의존성 자동 설치
echo "🎯 ROS 패키지 의존성 해결..."
rosdep update
rosdep install -r --from-paths src --ignore-src --rosdistro humble -y

# 4. 단계별 빌드 (의존성 순서 고려)
echo ""
echo "🏗️ 패키지 빌드 시작..."

# 첫 번째: 메시지 패키지
echo "📨 1단계: 메시지 패키지 빌드..."
colcon build --packages-select doosan_m0609_msgs

# 환경 소싱 (메시지 정의 반영)
source install/setup.bash

# 두 번째: 하드웨어 인터페이스
echo "🔌 2단계: 하드웨어 인터페이스 빌드..."
colcon build --packages-select doosan_m0609_hardware

# 환경 소싱
source install/setup.bash

# 세 번째: 설명 및 제어 패키지
echo "📝 3단계: 설명 및 제어 패키지 빌드..."
colcon build --packages-select doosan_m0609_description doosan_m0609_controller

# 환경 소싱
source install/setup.bash

# 네 번째: Bringup 패키지
echo "🚀 4단계: Bringup 패키지 빌드..."
colcon build --packages-select doosan_m0609_bringup

# 환경 소싱
source install/setup.bash

# 다섯 번째: 기존 화학 실험 패키지들
echo "🧪 5단계: 화학 실험 패키지들 빌드..."
colcon build --packages-select chemistry_experiment_manager precision_liquid_pouring arduino_loadcell_interface

# 최종 환경 소싱
source install/setup.bash

# 5. 빌드 결과 확인
echo ""
echo "✅ 빌드 완료! 결과 확인 중..."
echo "📋 설치된 패키지 목록:"
ls install/

# 6. 테스트 명령어 제공
echo ""
echo "🎯 시스템 테스트 명령어:"
echo "  가상 모드 테스트:"
echo "    ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=virtual"
echo ""
echo "  실제 로봇 연결 (IP 확인 필수):"
echo "    ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=real host:=192.168.137.100"
echo ""
echo "  개별 패키지 테스트:"
echo "    ros2 run doosan_m0609_msgs --help"
echo "    ros2 topic list | grep doosan"
echo "    ros2 service list | grep doosan"

# 7. 네트워크 설정 확인 스크립트 생성
echo ""
echo "🌐 네트워크 설정 확인 스크립트 생성..."
cat > check_robot_connection.sh << 'EOF'
#!/bin/bash
# check_robot_connection.sh - 로봇 연결 상태 확인

ROBOT_IP="192.168.137.100"
ROBOT_PORT="12345"

echo "🔍 두산 M0609 로봇 연결 상태 확인..."
echo "📍 대상 IP: $ROBOT_IP"
echo "📍 대상 포트: $ROBOT_PORT"
echo ""

# 네트워크 연결 확인
echo "🌐 네트워크 연결 확인:"
if ping -c 3 $ROBOT_IP > /dev/null 2>&1; then
    echo "  ✅ Ping 성공: $ROBOT_IP 에 연결 가능"
else
    echo "  ❌ Ping 실패: $ROBOT_IP 에 연결 불가"
    echo "  💡 해결책:"
    echo "    1. 로봇 제어기 전원 확인"
    echo "    2. 네트워크 케이블 연결 확인"
    echo "    3. IP 주소 설정 확인"
    exit 1
fi

# 포트 연결 확인
echo "🔌 포트 연결 확인:"
if timeout 5 bash -c "</dev/tcp/$ROBOT_IP/$ROBOT_PORT" > /dev/null 2>&1; then
    echo "  ✅ 포트 $ROBOT_PORT 연결 성공"
else
    echo "  ❌ 포트 $ROBOT_PORT 연결 실패"
    echo "  💡 해결책:"
    echo "    1. 로봇 제어기 소프트웨어 실행 확인"
    echo "    2. 방화벽 설정 확인"
    echo "    3. 포트 번호 확인 (기본값: 12345)"
fi

echo ""
echo "📊 네트워크 인터페이스 정보:"
ip addr show | grep -E "inet.*192.168"

echo ""
echo "🎯 로봇 연결이 성공적이면 다음 명령으로 시스템을 시작하세요:"
echo "ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py mode:=real host:=$ROBOT_IP"
EOF

chmod +x check_robot_connection.sh

# 8. 안전 체크리스트 생성
echo ""
echo "🛡️ 안전 체크리스트 생성..."
cat > safety_checklist.md << 'EOF'
# 🛡️ 두산 M0609 화학 실험 로봇 안전 체크리스트

## 🚨 시스템 가동 전 필수 확인사항

### 1. 하드웨어 안전 점검
- [ ] 로봇 주변 안전 구역 확보 (반경 1m 이상)
- [ ] Emergency Stop 버튼 작동 확인
- [ ] 로봇 암 관절 상태 육안 점검
- [ ] 케이블 연결 상태 확인
- [ ] 그리퍼/엔드이펙터 장착 상태 확인

### 2. 소프트웨어 안전 설정
- [ ] 충돌 감지 민감도 설정 (0.2N)
- [ ] 최대 속도 제한 설정
- [ ] 작업 영역 제한 설정 (900mm 반경)
- [ ] 페이로드 제한 확인 (최대 6kg)

### 3. 화학 실험 특화 안전사항
- [ ] 후드 또는 환기 시설 작동 확인
- [ ] 화학물질 안전 데이터 시트(MSDS) 확인
- [ ] 적절한 개인보호장비(PPE) 착용
- [ ] 화학물질 호환성 확인
- [ ] 스필 킷(Spill Kit) 준비

### 4. 네트워크 및 통신
- [ ] 로봇 제어기 IP 연결 확인 (192.168.137.100)
- [ ] ROS2 노드 간 통신 확인
- [ ] 센서 데이터 수신 확인
- [ ] 로드셀 칼리브레이션 확인

## 🚩 비상시 대응 절차

1. **즉시 정지**: Emergency Stop 버튼 누르기
2. **전원 차단**: 로봇 제어기 전원 OFF
3. **안전 확보**: 작업 영역에서 대피
4. **상황 보고**: 관리자에게 즉시 연락

## 📞 비상 연락처
- 로봇 기술 지원: [연락처 입력]
- 안전 관리자: [연락처 입력]
- 응급실: 119

## 📝 작업 로그
| 날짜 | 작업자 | 작업 내용 | 안전 점검 | 이상 사항 |
|------|--------|-----------|-----------|----------|
|      |        |           |           |          |

EOF

echo ""
echo "🎉 두산 M0609 패키지 통합 및 설정 완료!"
echo ""
echo "📁 생성된 파일들:"
echo "  - check_robot_connection.sh (로봇 연결 확인)"
echo "  - safety_checklist.md (안전 체크리스트)"
echo ""
echo "🚀 다음 단계:"
echo "  1. 안전 체크리스트 검토: cat safety_checklist.md"
echo "  2. 로봇 연결 확인: ./check_robot_connection.sh"
echo "  3. 시스템 테스트: ros2 launch doosan_m0609_bringup chemical_experiment_system.launch.py"
echo ""
echo "⚠️ 중요: 실제 로봇 작업 전 반드시 안전 교육을 이수하세요!"
