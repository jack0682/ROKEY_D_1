
## DRL (Doosan Robot Language) 기초 문법 가이드 v2.12

### 1. 기본 구성 요소

| 구분         | 예시                            | 설명                  |
| ---------- | ----------------------------- | ------------------- |
| **좌표형 변수** | `posj(...)`, `posx(...)`      | 관절공간 / 태스크공간 위치     |
| **모션 명령어** | `movej(...)`, `movel(...)`    | 조인트 / 직선 / 곡선 이동 등  |
| **제어 흐름**  | `if`, `while`, `for`, `break` | 조건 및 반복문            |
| **상태 조회**  | `get_current_posj()`          | 현재 위치 / 속도 / 토크     |
| **입출력 제어** | `set_digital_output(1, ON)`   | DO, AI/AO, Modbus 등 |
| **함수 정의**  | `def my_func()`               | 사용자 정의 함수 가능        |

---

### 2. 위치 표현 방법

####  관절 공간 위치 (`posj`)

```drl
P1 = posj(0, 0, 90, 0, 90, 0)  # deg 단위
```

####  태스크 공간 위치 (`posx`)

```drl
P2 = posx(300, 0, 500, 180, 0, 180)  # mm, deg (x,y,z,w,p,r)
```

####  Delta 이동, 좌표 변환

```drl
P3 = trans(P2, [0, 0, 50], ref=BASE)
```

---

### 3. 모션 명령어

| 명령어                          | 설명      |
| ---------------------------- | ------- |
| `movej(P1)`                  | 관절공간 이동 |
| `movel(P2)`                  | 직선 이동   |
| `movec(P3, P4)`              | 원호 이동   |
| `movejx(...)`, `amovej(...)` | 확장 버전   |
| `mwait(time)`                | 시간 대기   |

#### 예시

```drl
P1 = posj(0, 0, 90, 0, 90, 0)
movej(P1, v=30, a=30)
mwait(1.0)
```

---

### 4.  제어 흐름 구조

####  반복문

```drl
cnt = 0
while cnt < 10:
  tp_log("Count: " + str(cnt))
  cnt = cnt + 1
```

####  조건문

```drl
if get_digital_input(1) == ON:
  movej(P1)
else:
  movej(P2)
```

####  함수 정의 및 호출

```drl
def pick():
  set_digital_output(1, ON)
  mwait(0.5)

pick()
```

---

### 5.  디지털 / 아날로그 IO

```drl
set_digital_output(1, ON)
val = get_digital_input(2)

set_analog_output(1, 2.5)       # AO 채널 1에 2.5V
val = get_analog_input(1)       # AI 채널 1의 값 읽기
```

---

### 6.  로봇 상태 조회 함수

| 함수                   | 설명               |
| -------------------- | ---------------- |
| `get_current_posj()` | 관절 위치 (deg)      |
| `get_current_posx()` | 태스크 위치 (mm, deg) |
| `get_joint_torque()` | 각 관절 토크          |
| `get_tool_force()`   | 툴에 작용하는 힘        |

####  예시

```drl
curr = get_current_posx()
tp_log("X: " + str(curr[0]))
```

---

### 7.  알람 및 예외 처리 (TP 로그)

```drl
tp_log("작업 시작")
if get_robot_mode() != AUTO:
  tp_log("로봇 모드 오류 발생", LOG_ERROR)
```

---

### 8.  연습 예제: 나선형 경로 이동

```drl
angle = 0
z = 500
while angle < 360:
  x = 300 + 50 * cos(angle)
  y = 0 + 50 * sin(angle)
  p = posx(x, y, z, 180, 0, 180)
  movel(p, v=100, a=100)
  angle = angle + 10
```

