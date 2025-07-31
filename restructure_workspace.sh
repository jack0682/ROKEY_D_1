#!/bin/bash
# 전체 프로젝트 빌드 스크립트

cd /home/jaeho/project_ws

echo "🔨 Building all packages..."

# 환경 설정
source setup_project_env.sh

# 의존성 설치
echo "📦 Installing dependencies..."
rosdep update
rosdep install --from-paths src --ignore-src -r -y

# 빌드 실행
echo "🏗️  Building workspace..."
colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release

echo "✅ Build completed!"
echo "📝 Source the environment: source install/setup.bash"
EOF

chmod +x development/scripts/build_all.sh

# 개별 패키지 빌드 스크립트
cat > development/scripts/build_doosan.sh << 'EOF'
#!/bin/bash
# 두산 관련 패키지만 빌드

cd /home/jaeho/project_ws
source setup_project_env.sh

echo "🤖 Building Doosan packages..."

# 두산 커스텀 패키지 빌드
if [ -d "doosan_workspace/custom_packages/doosan_m0609_control" ]; then
    colcon build --packages-select doosan_m0609_control --symlink-install
fi

# src 내 로봇 제어 패키지 빌드
colcon build --packages-up-to robot_control --symlink-install

echo "✅ Doosan packages build completed!"
EOF

chmod +x development/scripts/build_doosan.sh

# =================================================================
# 7단계: 문서화 파일 생성
# =================================================================
echo "📚 7단계: 문서화 생성..."

cat > README_NEW_STRUCTURE.md << 'EOF'
# Project Workspace - 새 구조 안내

## 📁 디렉토리 구조

```
project_ws/
├── doosan_workspace/              # 두산 로봇 관련 통합 관리
│   ├── official_sdk/              # 공식 SDK 링크 (DoosanBootcamp_WS)
│   ├── custom_packages/           # 커스텀 ROS2 패키지들
│   │   └── doosan_m0609_control/  # 기존 커스텀 패키지
│   ├── shared_resources/          # 공유 라이브러리 (API-DRFL 링크)
│   ├── configurations/            # 로봇별 설정 파일
│   ├── documentation/             # 두산 관련 문서
│   └── examples/                  # 예제 코드
├── src/                          # 메인 ROS2 패키지들 (재구성됨)
│   ├── robot_control/            # 로봇 제어 패키지
│   ├── application_layer/        # 애플리케이션 패키지
│   │   ├── pouring_controller/   # 기존 패키지 이동됨
│   │   ├── weight_estimator/     # 기존 패키지 이동됨
│   │   └── experiment_manager/   # 기존 패키지 이동됨
│   ├── system_interfaces/        # 인터페이스 정의
│   │   ├── pouring_interfaces/   # 기존 패키지 이동됨
│   │   └── safety_supervisor/    # 기존 패키지 이동됨
│   └── utilities/                # 유틸리티 패키지
├── resources/                    # 설정 및 리소스 파일
│   ├── robot_configs/            # 로봇별 설정
│   ├── launch_files/             # 런치 파일들
│   ├── rviz_configs/             # RViz 설정
│   └── urdf_models/              # URDF 모델들
├── development/                  # 개발 도구 및 스크립트
│   ├── scripts/                  # 빌드/테스트 스크립트
│   ├── tools/                    # 개발 도구
│   ├── tests/                    # 테스트 파일
│   └── benchmarks/               # 벤치마크 테스트
├── API-DRFL/                    # 원본 DRFL API (유지)
├── DoosanBootcamp_WS/           # 공식 패키지 (유지)
├── src_old_YYYYMMDD_HHMMSS/     # 기존 src 백업
└── backup_YYYYMMDD_HHMMSS/      # 전체 백업
```

## 🚀 사용법

### 1. 환경 설정
```bash
cd /home/jaeho/project_ws
source setup_project_env.sh
```

### 2. 전체 빌드
```bash
./development/scripts/build_all.sh
```

### 3. 두산 패키지만 빌드
```bash
./development/scripts/build_doosan.sh
```

### 4. 개별 패키지 빌드
```bash
colcon build --packages-select 패키지명
```

## 🔧 개발 워크플로우

### 새 두산 관련 패키지 개발
```bash
cd doosan_workspace/custom_packages/
ros2 pkg create --build-type ament_cmake my_new_doosan_package
```

### 애플리케이션 패키지 개발
```bash
cd src/application_layer/
ros2 pkg create --build-type ament_cmake my_new_app
```

### 설정 파일 관리
- 로봇 설정: `resources/robot_configs/`
- 런치 파일: `resources/launch_files/`
- RViz 설정: `resources/rviz_configs/`

## 📋 주요 장점

1. **분리된 관심사**: 두산 관련 / 애플리케이션 / 시스템 인터페이스 분리
2. **중앙화된 리소스**: API-DRFL, 설정파일, 문서 중앙 관리
3. **백업 및 버전관리**: 자동 백업, 기존 구조 보존
4. **개발 도구**: 빌드, 테스트, 배포 스크립트 통합
5. **확장성**: 새 패키지 추가 용이

## 🛠️ 트러블슈팅

### 빌드 에러 발생시
```bash
# 클린 빌드
rm -rf build/ install/ log/
./development/scripts/build_all.sh
```

### DRFL 라이브러리 문제
```bash
# 환경 변수 확인
echo $DRFL_ROOT
echo $LD_LIBRARY_PATH

# 라이브러리 파일 확인
ls -la $DRFL_ROOT/library/Linux/64bits/amd64/22.04/
```

### 패키지 의존성 문제
```bash
# 의존성 재설치
rosdep update
rosdep install --from-paths src --ignore-src -r -y
```

## 📝 마이그레이션 체크리스트

- [ ] 기존 코드 백업 확인
- [ ] 환경 변수 설정 (`source setup_project_env.sh`)
- [ ] DRFL 라이브러리 링크 확인
- [ ] 전체 빌드 테스트
- [ ] 개별 패키지 빌드 테스트
- [ ] 런타임 테스트 (실제 로봇 연결)

EOF

# 개발자 가이드 생성
cat > doosan_workspace/documentation/DEVELOPER_GUIDE.md << 'EOF'
# 두산 로봇 개발 가이드

## 🏗️ 아키텍처 개요

이 워크스페이스는 두산 M0609 로봇을 위한 ROS2 기반 제어 시스템입니다.

### 주요 구성요소

1. **DRFL API**: 두산에서 제공하는 로봇 제어 라이브러리
2. **ROS2 Wrapper**: DRFL을 ROS2 환경에서 사용할 수 있게 하는 래퍼
3. **Application Layer**: 실제 태스크를 수행하는 애플리케이션들

## 🔧 DRFL API 사용법

### 기본 연결 및 초기화
```cpp
#include "DRFL.h"
using namespace DRAFramework;

// 로봇 연결
CDRFL robot;
bool connected = robot.OpenConnection("192.168.137.100");

// 제어권 획득
robot.ManageAccessControl(MANAGE_ACCESS_CONTROL_FORCE_REQUEST);

// 로봇 모드 설정
robot.SetRobotMode(ROBOT_MODE_AUTONOMOUS);
robot.SetRobotSystem(ROBOT_SYSTEM_REAL);
```

### 관절 제어
```cpp
// 관절 이동
float joint_pos[6] = {0, 0, 90, 0, 90, 0}; // 도 단위
float vel = 30.0;  // 속도
float acc = 30.0;  // 가속도

robot.movej(joint_pos, vel, acc);
```

### 상태 읽기
```cpp
// 현재 관절 위치
LPROBOT_POSE current_joint = robot.GetCurrentPose(ROBOT_SPACE_JOINT);

// 현재 태스크 위치
LPROBOT_POSE current_task = robot.GetCurrentPosx();
```

## 🚀 ROS2 통합 패턴

### Publisher 패턴
```cpp
class RobotStatePublisher : public rclcpp::Node {
private:
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    CDRFL robot_;
    
public:
    RobotStatePublisher() : Node("robot_state_publisher") {
        joint_pub_ = create_publisher<sensor_msgs::msg::JointState>("/joint_states", 10);
        timer_ = create_wall_timer(100ms, std::bind(&RobotStatePublisher::publish_states, this));
    }
    
    void publish_states() {
        auto msg = sensor_msgs::msg::JointState();
        auto pose = robot_.GetCurrentPose(ROBOT_SPACE_JOINT);
        // 메시지 채우기 및 퍼블리시
        joint_pub_->publish(msg);
    }
};
```

### Service 패턴
```cpp
class MoveJService : public rclcpp::Node {
private:
    rclcpp::Service<custom_msgs::srv::MoveJ>::SharedPtr service_;
    CDRFL robot_;
    
public:
    MoveJService() : Node("movej_service") {
        service_ = create_service<custom_msgs::srv::MoveJ>(
            "/movej", std::bind(&MoveJService::handle_movej, this, _1, _2));
    }
    
    void handle_movej(const std::shared_ptr<custom_msgs::srv::MoveJ::Request> request,
                      std::shared_ptr<custom_msgs::srv::MoveJ::Response> response) {
        float pos[6];
        for(int i = 0; i < 6; i++) {
            pos[i] = request->joint_position[i] * 180.0 / M_PI; // 라디안 -> 도
        }
        
        bool success = robot_.movej(pos, request->velocity, request->acceleration);
        response->success = success;
    }
};
```

## 🔒 안전 고려사항

1. **연결 확인**: 항상 연결 상태를 확인한 후 명령 실행
2. **제어권 관리**: 동시에 여러 노드가 제어권을 요청하지 않도록 주의
3. **비상 정지**: 안전 센서나 외부 신호에 의한 비상 정지 구현
4. **속도 제한**: 안전한 속도 범위 내에서 동작

## 🧪 테스트 가이드

### 단위 테스트
```bash
cd development/tests/
colcon test --packages-select doosan_m0609_control
```

### 통합 테스트
```bash
# 시뮬레이션 환경에서 테스트
ros2 launch doosan_workspace test_simulation.launch.py

# 실제 로봇 테스트 (주의!)
ros2 launch doosan_workspace test_real_robot.launch.py
```

## 🐛 디버깅 팁

1. **로그 레벨 설정**
   ```bash
   ros2 run doosan_m0609_control robot_node --ros-args --log-level debug
   ```

2. **네트워크 확인**
   ```bash
   ping 192.168.137.100
   telnet 192.168.137.100 12345
   ```

3. **라이브러리 확인**
   ```bash
   ldd build/doosan_m0609_control/robot_node
   ```

EOF

echo ""
echo "🎉 워크스페이스 재구성 완료!"
echo ""
echo "📋 다음 단계:"
echo "1. source setup_project_env.sh"
echo "2. ./development/scripts/build_all.sh"
echo "3. README_NEW_STRUCTURE.md 참조"
echo ""
echo "📁 주요 변경사항:"
echo "  - 기존 src/ → src_old_$(date +%Y%m%d_%H%M%S)/"
echo "  - 새 구조화된 src/ 생성"
echo "  - doosan_workspace/ 통합 관리 디렉토리 생성"
echo "  - 개발 도구 및 스크립트 추가"
echo "  - 문서화 및 가이드 생성"
EOF

chmod +x restructure_workspace.sh

echo "✅ 워크스페이스 재구성 스크립트 생성 완료!"
echo ""
echo "🚀 실행하려면:"
echo "cd /home/jaeho/project_ws"
echo "./restructure_workspace.sh"