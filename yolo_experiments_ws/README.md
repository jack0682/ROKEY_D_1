
##  실험 자동화 시스템 설명서

아래는 /home/jack/yolo_experiments_ws/를 기준으로, 만들어졌습니다. 환경에 맞게 세팅해주세요

---

#  YOLOv7 / YOLOv8 / YOLOv11 ROS2 실험 자동화 시스템

본 프로젝트는 YOLOv7, YOLOv8, YOLOv11 모델을 각각 ROS2 패키지로 구성하여,  
TurtleBot4의 OAK-D RGB 카메라로부터 실시간 영상을 입력받아 객체 검출을 수행하고,  
각 모델의 추론 성능(FPS, 평균 추론 시간, 검출 수)을 1분간 비교하는 자동화 실험을 제공합니다.

---

##  디렉토리 구조

```bash

yolo\_experiments\_ws/
├── src/
│   ├── yolov7\_ros2/
│   ├── yolov8\_ros2/
│   ├── yolov11\_ros2/
│   └── common\_msgs/         # 메시지 정의: BoundingBox, CrackEstimate 등
├── models/
│   ├── yolov7.pt
│   ├── yolov8.pt
│   └── yolov11.pt
├── launch/
│   └── batch\_eval.launch.py # 세 모델을 순차 실행
├── logs/                    # 프레임별 성능 로그 자동 저장
└── README.md

```

---

##  빌드 방법

ROS2 Foxy 이상 환경에서 아래 명령어로 빌드합니다:

```bash
cd ~/yolo_experiments_ws
colcon build --symlink-install
source install/setup.bash
````

빌드가 정상 완료되었는지 확인하세요:

```bash
ros2 pkg list | grep yolov
```

---

##  실험 실행 방법

### 1. 로봇 및 카메라 준비

* TurtleBot4 전원 ON
* OAK-D가 `/robot1/oakd/rgb/image_raw`로 퍼블리시 중인지 확인:

```bash
ros2 topic echo /robot1/oakd/rgb/image_raw
```

---

### 2. 모델 평가 실행 (1분 × 3 모델 자동)

```bash
ros2 launch yolo_experiments_ws batch_eval.launch.py
```

* YOLOv7 → YOLOv8 → YOLOv11 순서로 60초씩 실행됨
* 결과는 각 패키지 노드에서 자동 종료 후 로그로 저장됩니다

---

##  성능 결과 확인

### 1. 로그 위치

```bash
/home/jack/yolo_experiments_ws/logs/
├── YOLOv7_eval_20250712_1503.csv
├── YOLOv8_eval_20250712_1504.csv
└── YOLOv11_eval_20250712_1505.csv
```

### 2. 로그 내용

```csv
frame_id,timestamp,infer_time_ms,num_detections
1,15:23:11.103,48.77,3
2,15:23:11.164,50.92,2
...
```

### 3. 결과 요약 예시 (콘솔 출력)

```
[YOLOv8] 총 1123 프레임 | 평균 추론 시간: 0.0538초 | FPS: 18.65
```

---

##  주의 사항

* `image_topic`, `model_path`는 각 노드에서 파라미터로 선언되어 있으며, launch 파일에서 지정 가능합니다
* 성능 평가는 **GPU 사양**, **입력 프레임 해상도**, **네트워크 지연** 등에 따라 달라질 수 있습니다
* 로그 저장 디렉토리는 기본 `/logs`이며, 없는 경우 자동 생성됩니다

---

##  확장 가능성

* `/depth/image_raw`를 활용한 Crack 실면적 계산 (CrackEstimate.msg)
* 로그 비교를 위한 시각화 스크립트 추가
* 실시간 RViz2 마커 연동
* `rosbag record`를 통한 전체 추론 기록

---



