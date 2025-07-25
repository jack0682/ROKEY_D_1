

# 📐 Robot Workspace & Kinematic Planning 구조

## 1. 🦾 로봇 사양: Doosan M0609

| 항목             | 내용                                         |
| -------------- | ------------------------------------------ |
| **모델명**        | Doosan M0609                               |
| **자유도 (DOF)**  | 6축                                         |
| **최대 Reach**   | **900 mm (90 cm)**                         |
| **최대 Payload** | 6 kg                                       |
| **반복정확도**      | ±0.05 mm                                   |
| **Base Frame** | `T0` 또는 `base_link`                        |
| **Tool Frame** | `TCP` (기본적으로 `T6` 프레임)                     |
| **제어 시스템**     | Doosan DART Studio 기반, ROS2 가능             |
| **인터페이스**      | TCP/IP, RS232, Modbus, ROS 지원              |
| **사용 범위**      | Table-top, Mobile, Collaborative workspace |

---

## 2. 📏 작업 공간(Workspace) 정보

### ▪ 형태 및 크기

| 항목  | 값                      |
| --- | ---------------------- |
| 형태  | 정사각형                   |
| 사이즈 | **45 cm × 45 cm**      |
| 기준점 | 정중앙에 `floor` origin 위치 |

### ▪ 좌표계 정의

* `floor` 좌표계가 전체 작업 공간의 **기준 원점** (0, 0, 0)
* `T0`는 작업 공간 외부, **좌측 기준선에서 -27 cm 떨어진 위치**

### ▪ 시각적 구성 예시

```
Top View
──────────────────────────────
|                            |
|      ← Y+ ↑               |
|           ·               |
|           · (0,0) floor   |
|   ←-27→   ·     T0(base)  |
|                            |
|───────── X+ →─────────────|
```

---

## 3. 🧭 좌표계 구성 (TF Tree 기준)

```plaintext
/floor (global coordinate)
└── /T0 (base_link) → at (-0.27, 0.0, 0.0) [m]
     └── /link_1
         └── /link_2
             └── ...
                 └── /tool0 (TCP)
```

### ROS2 URDF 기반 TF 구성 예시

```xml
<joint name="floor_to_base" type="fixed">
  <parent link="floor"/>
  <child link="base_link"/>
  <origin xyz="-0.27 0 0" rpy="0 0 0"/>
</joint>
```

---

## 4. 📌 주요 좌표점 정보

| 명칭   | `floor` 좌표 (cm)  | `T0` 기준 상대 좌표 (cm) |
| ---- | ---------------- | ------------------ |
| 중심   | (0, 0, 0)        | (27, 0, 0)         |
| 좌상단  | (-22.5, 22.5, 0) | (4.5, 22.5, 0)     |
| 우하단  | (22.5, -22.5, 0) | (49.5, -22.5, 0)   |
| 정면중심 | (22.5, 0, 0)     | (49.5, 0, 0)       |
| 좌측끝  | (-22.5, 0, 0)    | (4.5, 0, 0)        |

> 모든 점은 로봇 기준으로 `move_group`에서 planning target으로 사용 가능.

---

## 5. 🧠 실시간 좌표 변환 (Python 예시)

```python
import numpy as np

def floor_to_robot(floor_point_cm):
    """ floor 좌표를 robot(base_link) 기준으로 변환 """
    T0_offset = np.array([-27.0, 0.0, 0.0])  # cm
    return np.array(floor_point_cm) - T0_offset

# 예시: 작업 중심 좌표
floor_center = [0.0, 0.0, 0.0]
robot_target = floor_to_robot(floor_center)
# → array([27.0, 0.0, 0.0])
```

---

## 6. 🤖 Motion Planning 구조 요약

### ① 좌표 시스템

| 좌표계               | 설명                              |
| ----------------- | ------------------------------- |
| `floor`           | 절대 전역 좌표 (전체 작업공간 중심)           |
| `T0` (base\_link) | 로봇 기준 좌표 (이동 및 회전 수행 기준점)       |
| `tool0` (TCP)     | End-effector Tool 좌표 (실제 작업 위치) |

### ② Planning 흐름

```
[픽셀 (u,v)] → Depth 적용 → [camera_frame (x,y,z)]
        ↓ tf2
[floor (X,Y,Z)] 좌표로 변환
        ↓
→ base_link 상대좌표로 변경
        ↓
→ Inverse Kinematics / MoveIt Planning
        ↓
→ trajectory 생성 및 실행
```

---

## 7. 🧰 구현 도구 및 적용 기술

| 구성 요소    | 기술                                                |
| -------- | ------------------------------------------------- |
| 좌표계 변환   | `tf2_ros`, `static_transform_publisher`           |
| 로봇 제어    | `MoveIt2`, `DART Studio`, `action interface`      |
| 비전 연동    | `OpenCV`, `YOLO`, `depth camera`                  |
| 시각화      | `RViz`, `interactive markers`, `RViz MarkerArray` |
| 코드 프레임워크 | ROS2, Python3, URDF/Xacro, TF2, NumPy             |

---

## 📌 향후 제안: 확장 가능한 좌표 기반 제어

| 확장 시나리오                    | 예시                        |
| -------------------------- | ------------------------- |
| 🔍 **비전 기반 객체 선택**         | 카메라로 특정 object 위치 인식 후 이동 |
| 🧭 **Waypoint trajectory** | 여러 위치를 순회하며 특정 작업 수행      |
| 🎨 **패턴 그리기**              | 좌표 리스트 기반 그림 그리기, 용접 등    |
| 🧰 **tool orientation 포함** | 각도(RPY) 포함 경로 생성          |
| 🛰️ **시뮬레이터 연동**           | Gazebo + MoveIt2 연동       |

---

