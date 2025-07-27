# DRL (Doosan Robot Language) 고급 명령어 확장 가이드 – Part 2

이 문서는 "DRL Advanced Guide"의 후속편으로서, 더욱 상세하고 많은 고급 DRL 명령어와 설정 항목들을 체계적으로 정리한다. 특히, 작업환경 설정, 사용자 좌표계, 경로 제어 최적화, 상태 확인 및 진단 루틴 등을 추가 설명하며, 각 기능은 실제 작업 시나리오와 연결된다.

---

## 🔹 1. 사용자 좌표계 및 TCP 툴 설정

### `set_tcp(tcp: list)`

> 툴 중심점(TCP, Tool Center Point)을 설정한다. 이는 모든 모션 명령어의 기준점이 된다.

```drl
set_tcp([0.0, 0.0, 120.0, 0.0, 0.0, 0.0])  # Z축 120mm 지점
```

* 단위: \[X, Y, Z, Rx, Ry, Rz] (mm, deg)
* 사용 목적: 그리퍼 또는 툴 말단 오프셋 정의

### `set_tool_shape(shape: list)`

> 툴 형상을 정의하여 충돌 검사 또는 비주얼라이징에 사용

```drl
set_tool_shape([0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 50, 50, 100])
```

* \[X, Y, Z, Rx, Ry, Rz, Width, Height, Depth]

### `set_user_cart_coord(index, origin, x_vec, y_vec)`

> 사용자 정의 좌표계 등록 (예: 작업대 기준 등)

```drl
set_user_cart_coord(1, [500, 0, 300], [1,0,0], [0,1,0])
```

* `index`: 사용자 좌표계 ID (1\~9)
* `origin`: 원점 좌표 (Base 기준)
* `x_vec`, `y_vec`: 좌표계의 X, Y 방향 벡터

---

## 🔹 2. 속도 및 가속도 설정

### `set_velj(vel)` / `set_accj(acc)`

> 조인트 공간 기준 속도/가속도 설정

```drl
set_velj(30)     # deg/s
set_accj(60)     # deg/s^2
```

### `set_velx(v_tr, v_rot)` / `set_accx(a_tr, a_rot)`

> 태스크 공간 기준 속도/가속도 설정

```drl
set_velx(200, 180)     # mm/s, deg/s
set_accx(2000, 1800)   # mm/s^2, deg/s^2
```

---

## 🔹 3. 경로 블렌딩 및 Spline

### `set_spline_blending(enable: int)`

> Spline 기반의 곡선 연결 활성화

```drl
set_spline_blending(1)
```

* 연속적인 위치 이동 시 궤적을 더 부드럽게 연결

### 예제

```drl
set_blending_radius(20)
set_spline_blending(1)
movej(P1)
movej(P2)
movej(P3)
```

---

## 🔹 4. 로봇 상태 진단 및 확인

### `check_motion()`

> 로봇이 현재 움직이고 있는지 확인 (True/False)

```drl
while check_motion():
  tp_log("이동 중...")
```

### `get_current_posj()` / `get_current_posx()`

> 현재 관절 위치 / 태스크 위치 반환

```drl
jpos = get_current_posj()
xpos = get_current_posx()
```

### `get_joint_torque()`

> 각 관절별 토크 값

```drl
torque = get_joint_torque()
tp_log("Joint 3 torque: " + str(torque[2]))
```

### `get_tool_force()`

> TCP에 작용하는 힘 (Fx, Fy, Fz, Mx, My, Mz)

```drl
force = get_tool_force()
```

### `get_last_alarm()`

> 최근 알람 코드 및 메시지 확인

```drl
code, msg = get_last_alarm()
tp_log("Alarm: " + str(code) + " - " + msg)
```

---

## 🔹 5. 작업 시나리오 예제: 연속 pick-and-place

```drl
set_blending_radius(15)
set_velx(200, 180)
set_accx(1000, 1000)

P_pick = posx(500, 0, 200, 180, 0, 180)
P_place = posx(300, -200, 200, 180, 0, 180)

movejx(P_pick)
set_digital_output(1, ON)  # 흡착기 작동
mwait(0.5)

movejx(P_place)
set_digital_output(1, OFF)
mwait(0.3)
```

---

