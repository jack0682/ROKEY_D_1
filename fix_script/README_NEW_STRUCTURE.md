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

