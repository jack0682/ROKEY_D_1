
##  `README.md`


# 🛰 MQTT-Dashboard-Influx

ROS2 기반 로봇의 토픽 데이터를 **EMQX MQTT 브로커를 통해 수집**하고,  
**InfluxDB에 저장 및 React 대시보드로 시각화**하는 통합 모니터링 시스템입니다.

---

##  프로젝트 구조

```bash

mqtt-dashboard-influx/
├── config/
│   └── settings.yaml            # MQTT & InfluxDB 설정
├── backend/
│   ├── mqtt-to-influx.py        # MQTT → InfluxDB 브리지
│   └── requirements.txt         # 백엔드 의존성
├── frontend/
│   ├── src/
│   │   ├── App.js               # React 주요 UI 구성
│   │   ├── App.css              # 스타일 정의
│   │   ├── mqttClient.js        # MQTT 클라이언트
│   │   └── components/
│   │       ├── StatusBar.jsx
│   │       ├── TopicLog.jsx
│   │       ├── TopicSelector.jsx
│   │       └── RealtimeChart.jsx
│   └── package.json             # 프론트엔드 의존성
├── ros2-mqtt.py                 # ROS2 → MQTT 브리지 (다른 LAN에서 실행됨)
├── setup.sh                     # 전체 초기 설정 스크립트
├── run-backend.sh               # 백엔드 실행 스크립트
├── run-frontend.sh              # 프론트엔드 실행 스크립트
└── README.md                    #  이 파일

````

---

## 🌐 주요 구성 요소

### 1. `ros2-mqtt.py`  
- ROS2 로봇이 퍼블리시하는 토픽 데이터를 MQTT로 퍼블리시합니다.
- **각 로봇이 있는 별도의 LAN 환경에서 실행**되어야 합니다.
- 예: `/robot1/odom`, `/robot3/scan` 등 여러 네임스페이스 토픽 전송 가능

### 2. `mqtt-to-influx.py`
- MQTT 브로커로부터 메시지를 구독하고, 필요한 항목을 **InfluxDB에 저장**합니다.

### 3. React 대시보드
- 실시간 상태(StatusBar), 차트(RealtimeChart), 로그(TopicLog), 선택기(TopicSelector)를 포함한 UI 제공

---

##  사전 준비 사항

- Node.js (v18+)
- Python 3.8+
- MQTT 브로커 (예: EMQX TLS)
- InfluxDB Cloud

---

##  설정 정보 예시 (`config/settings.yaml`)

```yaml
mqtt:
  host: "p021f2cb.ala.asia-southeast1.emqxsl.com"
  port: 8883
  username: "Rokey"
  password: "1234567"
  tls: true

influxdb:
  url: "https://us-east-1-1.aws.cloud2.influxdata.com"
  org: "rokey"
  bucket: "robot-data"
  token: "QcaqkOPwSxQvkYP9pyD98_87m4a3BY-yU4XI-ifcXr3jV8FVjSrKGcac3axNr_kPznWt6SG1wSQbQiW8_BoL8A=="
````

---

##  설치 방법

```bash
# 1. 저장소 클론
git clone https://github.com/your-id/mqtt-dashboard-influx.git
cd mqtt-dashboard-influx

# 2. 전체 초기 세팅
./setup.sh
```

---

##  실행 방법

### 백엔드 실행 (MQTT → InfluxDB)

```bash
./run-backend.sh
```

### 프론트엔드 실행 (React UI)

```bash
./run-frontend.sh
```

### ROS2 → MQTT 퍼블리셔 실행 (다른 LAN PC에서)

```bash
python3 ros2-mqtt.py
```

> **주의:** `ros2-mqtt.py`는 각 로봇이 위치한 PC에서 실행해야 하며,
> 그 PC는 ROS2 토픽을 구독 가능한 네트워크 안에 있어야 합니다.
> MQTT를 통해 중앙 서버로 안전하게 데이터를 전달합니다.

---

##  주요 시각화 대상 토픽 예시

* `/robot1/odom`, `/robot1/scan`, `/robot1/battery_state`
* `/robot3/odom`, `/robot3/scan` 등
* → 모두 실시간 그래프 & 로그로 확인 가능

---

##  활용 예

* ROS2 기반 순찰 로봇들의 실시간 상태 모니터링
* 다중 LAN 환경에서의 로봇 협업 로그 수집
* 안전 이벤트 감지 및 시각화 기반 대응 시스템 구축

---

## 👨 기여자

* **Oh Jaehong (a.k.a Jack)** – 시스템 설계 및 전반 구축

---

