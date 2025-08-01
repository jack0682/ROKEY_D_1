# Scale Bridge ROS2 Python Instructions

이 문서는 Arduino에서 HX711 로드셀 센서로 측정한 무게 데이터를 ROS2 퍼블리셔(Scale Publisher)와 서브스크라이버(Scale Subscriber) 노드를 통해 실시간으로 퍼블리시·구독하는 과정을 처음부터 설명합니다.

---

## 1. 전제 조건 (Prerequisites)

- **운영체제**: Ubuntu 20.04 (또는 ROS2 Humble 지원 환경)
- **ROS2 Humble** 설치 및 환경 설정
  ```bash
  source /opt/ros/humble/setup.bash
  ```
- **Python3**, **pip**, **pyserial**
- **Arduino** 개발 환경 (IDE 또는 arduino-cli)

---

## 2. Arduino CLI 설치 및 라이브러리 준비

### 2.1 arduino-cli 설치

아래 방법 중 하나로 `arduino-cli`를 설치합니다.

- **Homebrew**
  ```bash
  brew update
  brew install arduino-cli
  ```
- **설치 스크립트**
  ```bash
  curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
  ```
- **Snap**
  ```bash
  sudo snap install arduino-cli
  ```

설치 후 버전 확인:

```bash
arduino-cli version
```

### 2.2 HX711 라이브러리 설치

HX711 드라이버 헤더(`HX711.h`)가 없다는 오류가 발생할 경우, 아래 명령으로 표준 Arduino 라이브러리 폴더에 설치하세요.

```bash
arduino-cli lib update-index
arduino-cli lib install "HX711"
```

- **수동 설치**: GitHub 저장소에서 클론 후 `~/Arduino/libraries`에 복사
  ```bash
  cd ~/Arduino/libraries
  git clone https://github.com/bogde/HX711.git HX711
  ```

### 2.3 스케치 폴더 구조

`ros2_ws` 내에 Arduino 폴더를 만들고, 스케치 디렉토리 이름과 `.ino` 파일명을 **동일**하게 맞춥니다.

```
~/ros2_ws/
└── arduino/
    └── MySketch/        # 스케치 디렉토리
        └── MySketch.ino # 메인 스케치 파일
```

- `MySketch.ino` 안에는 0.1초마다 소수점 셋째 자리까지 측정값을 출력하는 코드가 위치해야 합니다.

---

## 3. ROS2 패키지 복제 및 Python 의존성 설치

1. `scale_bridge` 패키지 복제:
   ```bash
   cd ~/ros2_ws/src
   git clone <YOUR_REPO_URL> scale_bridge
   ```
2. Python 의존성 설치:
   ```bash
   python3 -m pip install --user pyserial
   ```

---

## 4. ROS2 빌드 및 환경 설정

1. 워크스페이스 루트에서 빌드:
   ```bash
   cd ~/ros2_ws
   colcon build --packages-select scale_bridge
   ```
2. 설치 환경 소스:
   ```bash
   source install/setup.bash
   ```

---

## 5. 리눅스 시리얼 권한 설정

시리얼 포트(`/dev/ttyACM0` 등)에 접근하기 위해, 사용자 계정을 `dialout` 그룹에 추가:

```bash
sudo usermod -aG dialout $USER
# 로그아웃 후 재로그인
```

임시 권한 적용:

```bash
sudo chmod a+rw /dev/ttyACM0
```

---

## 6. 노드 실행 방법

### 6.1 퍼블리셔 실행

```bash
ros2 run scale_bridge scale_publisher
```

- 토픽: `/scale_weight`
- 시리얼 포트: `/dev/ttyACM0` (필요 시 `scale_publisher.py` 내 수정)

### 6.2 서브스크라이버 실행

```bash
ros2 run scale_bridge scale_subscriber
```

- 퍼블리셔가 발행한 `/scale_weight` 토픽의 값을 출력합니다.

---

## 7. 맞춤 설정

- **시리얼 포트 변경**: `scale_bridge/scale_bridge/scale_publisher.py`에서 `serial.Serial('포트', 38400)` 수정
- **메시지 타입 변경**: `package.xml` 및 코드 내 타입 참조 수정
- **발행 빈도 조정**: `node.create_timer()` 주기 변경

---

## 8. 문제 해결 가이드

- **Permission denied**: 5장 권한 설정 확인
- **HX711.h not found**: 2장 라이브러리 설치 확인
- **upload/compile 오류**: 2장 CLI 설치 및 스케치 빌드 순서 재확인

---

이제 위 단계를 따라 하시면, Arduino 스케치를 CLI로 빌드·업로드하고, ROS2 토픽으로 실시간 무게 데이터를 퍼블리시·구독할 수 있습니다. Happy Hacking!

