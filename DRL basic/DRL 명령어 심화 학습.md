# DRL (Doosan Robot Language) 공간 무한 메서드: 심판 문법 학습 가이드

현재 목적은 **Doosan Robotics M0609** 로벌에서 사용되는 **DRL (Doosan Robot Language)** 명령어 중 가장 고급적으로 사용되는 명령어들을 상세하게 나열하고, 방안적 개발을 위해 각 명령어의 함수적 구조, 역할, 관련 대상 사용 논리를 가진다.

---

## 통치 구조 및 논리 구도

### 1. 협업 단계 가장 가능한 **고급 목적**

| 굴림       | 명령어                                                                 | 가능             | 사용 논리             |
| -------- | ------------------------------------------------------------------- | -------------- | ----------------- |
| 고급 목전    | `movejx`, `amovej`, `movesj`, `move_spiral`, `move_periodic`        | 구로/자랑 개발/자동 통근 | 시계/상태 배반/재정지 가능   |
| 블렌딩      | `set_blending_radius`, `set_spline_blending`                        | 목적과 목적 이상 연결   | 하위 분위치/고분보안 또한 감지 |
| 히름/컨팔라인스 | `task_compliance_ctrl`, `set_stiffnessx`, `release_compliance_ctrl` | 연화가능, 히름지적 통지  | 방어 목적/재도작 가능      |
| 사용자 자판/툴 | `set_tcp`, `set_user_cart_coord`, `set_tool_shape`                  | TCP, 규칙자판      | 타겟 위치 검색/변환       |
| 로벌설정     | `set_velx`, `set_accx`, `set_safety_mode`, `set_safe_zone_data`     | 전구/로컬 속도/안전도   | 로벌 개수 제어          |
| 상태 확인    | `check_motion`, `get_last_alarm`, `get_joint_torque`                | 목적지 확인         | 대기/통신오류 보관        |

---

## 해당 명령어 상세 설명

### 1. `movejx()`

> **객체가 모여진 두 객의 상당 목적지가 같을 경우**, 스토리 디게이션이 다르다면, 고정 지정

```drl
P1 = posx(300, 0, 500, 180, 0, 180)
movejx(P1, sol=DR_SOL_TOP, v=100, a=100)
```

* `sol=`: DR\_SOL\_TOP / BOTTOM / AUTO(255)
* 경\uub85c 중 목적지와 같은 디정이 없다면 자동계산 추가

### 2. `amovej()` / `amovel()`

> 자동 경로 계획(필요가는 환경 설정이나 DRD 목록)

```drl
P1 = posj(0, 30, 90, 0, 90, 0)
amovej(P1, v=50, a=50)
```

* 가령시 아무 역할 없이 필드 출력 가능
* 그래프 현재 행동 포트의 자동 건너뛰기 가능

### 3. `move_spiral()`

> 계속되는 수정, 유가가 필요한 이동(음식/잡기/건너뛰기)

```drl
center = get_current_posx()
move_spiral(center=center, max_radius=30, max_length=20, revolution=3, v=50, a=50)
```

* 범위점: center
* 보수적 복귀: 경로범위 및 범로 모양
* direction: `INWARD`, `OUTWARD`

### 4. `move_periodic()`

> 티켓/검사 건너뛰기 / 수정 현황에 사용

```drl
move_periodic(amp=[10,0,0,0,0,0], period=1.0, atime=0.5, repeat=3)
```

* amp: 진동 진폭 (mm)
* period: 진동 1회 주기 시간 (초)
* repeat: 반복 횟수

### 5. `set_blending_radius()`

> 명령의 연결에서 가장 간단한 경로 가능

```drl
set_blending_radius(10)
movej(P1)
movej(P2)
movej(P3)
```

---

## 히름/컨팔라인스 목적

### `task_compliance_ctrl()`

```drl
task_compliance_ctrl(1, [500,500,500,100,100,100])
```

* enable: 1 (enable), 0 (disable)
* stiffness: 각 방향에 대한 강성 (X Y Z Rx Ry Rz)

### `release_compliance_ctrl()`

> 히름 제어, 상태를 다시 가만 조정

```drl
release_compliance_ctrl()
```

---

