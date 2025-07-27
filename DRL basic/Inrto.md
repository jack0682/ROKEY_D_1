
##  **Level 1: DRL의 기본 개념**

### **프로그램 구조**
DRL 프로그램은 크게 **3단계**로 구성됩니다:

```drl
# 1. 초기화 (Setup)
def main():
    # 2. 작업 수행 (Task Execution)
    
    # 3. 종료 (Cleanup)
    
end
```

### **좌표계 이해**
DRL에서는 **2가지 좌표계**를 사용합니다:

1. **Joint Space (관절 좌표계)**
   - 각 관절의 각도로 위치 표현
   - `[J1, J2, J3, J4, J5, J6]` (단위: degree)

2. **Cartesian Space (데카르트 좌표계)**
   - 3차원 공간의 위치와 자세
   - `[X, Y, Z, RX, RY, RZ]` (위치: mm, 자세: degree)

---

## **Level 2: 기본 이동 명령어**

### **1. movej() - 관절 이동**
각 관절을 개별적으로 움직여 목표 위치에 도달

```drl
# 기본 문법
movej(target_position, vel=60, acc=30)

# 예제 1: 관절 좌표로 이동
movej([0, 0, 90, 0, 90, 0], vel=60, acc=30)

# 예제 2: 데카르트 좌표로 이동
target_pos = [400, 100, 300, 0, 180, 0]
movej(target_pos, vel=60, acc=30)
```

**특징:**
- 가장 빠른 이동 방식
- 경로가 직선이 아님 (각 관절이 독립적으로 움직임)
- 단순한 포인트-투-포인트 이동에 적합

### **2. movel() - 직선 이동**
로봇의 툴이 직선 경로를 따라 이동

```drl
# 기본 문법
movel(target_position, vel=250, acc=400)

# 예제: 직선으로 이동
start_pos = [400, 100, 300, 0, 180, 0]
end_pos = [400, 200, 300, 0, 180, 0]

movej(start_pos)  # 시작 위치로 관절 이동
movel(end_pos)    # 직선으로 목표까지 이동
```

**특징:**
- 툴의 경로가 3차원 공간에서 직선
- 정밀한 작업에 적합 (용접, 그리기 등)
- movej()보다 느림

### **3. movec() - 원호 이동**
중간점을 거쳐 원호를 그리며 이동

```drl
# 기본 문법
movec(via_position, target_position, vel=250, acc=400)

# 예제: 반원 그리기
center = [400, 100, 300, 0, 180, 0]
via_point = [400, 200, 350, 0, 180, 0]  # 중간점
end_point = [400, 300, 300, 0, 180, 0]  # 끝점

movec(via_point, end_point, vel=100, acc=200)
```

---

## **Level 3: 실제 작업 프로그래밍**

### **변수와 좌표 저장**

```drl
def main():
    # 좌표 변수 정의
    home_pos = [0, 0, 90, 0, 90, 0]
    pick_pos = [400, 100, 200, 0, 180, 0]
    place_pos = [400, -100, 200, 0, 180, 0]
    
    # 속도와 가속도 설정
    joint_vel = 60
    linear_vel = 250
    
    # 홈 위치로 이동
    movej(home_pos, vel=joint_vel)
    
end
```

### **반복 작업**

```drl
def main():
    pick_pos = [400, 100, 200, 0, 180, 0]
    place_pos = [400, -100, 200, 0, 180, 0]
    
    # 10번 반복하는 픽앤플레이스
    for i in range(10):
        # 픽업 위치로 이동
        movej(pick_pos)
        
        # 그리퍼로 잡기 (실제로는 I/O 신호)
        # set_digital_output(1, True)
        
        # 플레이스 위치로 이동
        movej(place_pos)
        
        # 그리퍼 열기
        # set_digital_output(1, False)
        
    end
end
```

### **조건문과 센서 활용**

```drl
def main():
    target_pos = [400, 100, 200, 0, 180, 0]
    
    # 목표 위치로 이동
    movej(target_pos)
    
    # 디지털 입력 확인 (센서 신호)
    if get_digital_input(1) == True:
        # 센서가 감지되면 다른 작업 수행
        movel([400, 150, 200, 0, 180, 0])
    else:
        # 센서가 감지되지 않으면 대기
        wait(1.0)  # 1초 대기
    end
    
end
```

---

## **Level 4: 안전 기능과 에러 처리**

### **안전 영역 설정**

```drl
def main():
    # 작업 영역 제한 설정
    # set_safety_zone(...)
    
    # 속도 제한 설정
    set_joint_vel_limit(50)  # 최대 관절 속도 50%
    set_tcp_vel_limit(200)   # 최대 TCP 속도 200mm/s
    
end
```

### **에러 처리**

```drl
def main():
    target_pos = [400, 100, 200, 0, 180, 0]
    
    try:
        movej(target_pos)
    except:
        # 이동 실패 시 안전 위치로 복귀
        movej([0, 0, 90, 0, 90, 0])
        wait(2.0)
    end
    
end
```

---

##  **Level 5: I/O 제어와 외부 장치 연동**

### **디지털 I/O 제어**

```drl
def main():
    # 디지털 출력 제어 (그리퍼, 밸브 등)
    set_digital_output(1, True)   # 1번 출력을 HIGH로
    wait(0.5)                     # 0.5초 대기
    set_digital_output(1, False)  # 1번 출력을 LOW로
    
    # 디지털 입력 읽기 (센서, 스위치 등)
    sensor_state = get_digital_input(1)
    
    if sensor_state == True:
        # 센서가 감지된 경우의 동작
    end
    
end
```

### **아날로그 I/O 제어**

```drl
def main():
    # 아날로그 출력 설정 (0~10V)
    set_analog_output(1, 5.0)  # 1번 아날로그 출력을 5V로
    
    # 아날로그 입력 읽기
    pressure = get_analog_input(1)  # 압력 센서 값 읽기
    
    if pressure > 7.5:
        # 압력이 높으면 정지
        stop()
    end
    
end
```

---

## **Level 6: 고급 기능**

### **Force Control (힘 제어)**

```drl
def main():
    contact_pos = [400, 100, 200, 0, 180, 0]
    
    # 힘 제어 시작
    task_compliance_ctrl(stiffness=[500, 500, 500, 100, 100, 100])
    
    # 부드럽게 접촉하며 이동
    movel(contact_pos, vel=50, acc=100)
    
    # 힘 제어 종료
    set_task_compliance_ctrl(mode=0)
    
end
```

### **Vision 연동**

```drl
def main():
    # 비전 시스템에서 좌표 받기
    vision_pos = get_vision_data()  # 사용자 정의 함수
    
    if vision_pos != None:
        # 비전으로 찾은 위치로 이동
        movej(vision_pos)
    else:
        # 객체를 찾지 못한 경우
        wait(1.0)
    end
    
end
```

---

## **실전 예제: 완전한 픽앤플레이스 프로그램**

```drl
# 실제 산업현장에서 사용하는 픽앤플레이스 예제

def main():
    # 좌표 정의
    home_pos = [0, 0, 90, 0, 90, 0]
    approach_pos = [400, 100, 300, 0, 180, 0]  # 접근 위치
    pick_pos = [400, 100, 200, 0, 180, 0]      # 픽업 위치
    place_approach = [400, -100, 300, 0, 180, 0] # 플레이스 접근
    place_pos = [400, -100, 200, 0, 180, 0]    # 플레이스 위치
    
    # 속도 설정
    fast_speed = 80
    slow_speed = 30
    
    # 초기화
    movej(home_pos, vel=fast_speed)
    set_digital_output(1, False)  # 그리퍼 열기
    
    # 메인 작업 루프
    for cycle in range(5):  # 5회 반복
        
        # 1. 픽업 위치로 이동
        movej(approach_pos, vel=fast_speed)      # 빠르게 접근
        movel(pick_pos, vel=slow_speed, acc=100) # 천천히 하강
        
        # 2. 그리퍼로 잡기
        set_digital_output(1, True)
        wait(0.5)  # 그리퍼가 닫힐 때까지 대기
        
        # 3. 물체 확인
        if get_digital_input(1) == False:  # 그립 센서 확인
            # 물체를 잡지 못한 경우
            set_digital_output(1, False)
            continue  # 다음 사이클로
        end
        
        # 4. 플레이스 위치로 이동
        movel(approach_pos, vel=slow_speed)      # 천천히 상승
        movej(place_approach, vel=fast_speed)    # 빠르게 이동
        movel(place_pos, vel=slow_speed)         # 천천히 하강
        
        # 5. 물체 놓기
        set_digital_output(1, False)
        wait(0.3)
        
        # 6. 복귀
        movel(place_approach, vel=slow_speed)
        
    end
    
    # 작업 완료 후 홈 위치로
    movej(home_pos, vel=fast_speed)
    
end
```

---

## **Level 7: 개발 환경과 디버깅**

### **DART-Studio 사용법**

1. **프로젝트 생성**: DART-Studio에서 새 DRL 프로젝트 생성
2. **시뮬레이션**: 실제 로봇 없이 코드 테스트
3. **디버깅**: 단계별 실행으로 문제점 찾기
4. **실제 로봇 연결**: 시뮬레이션 완료 후 실제 로봇에 업로드

### **일반적인 에러와 해결법**

```drl
# 에러 1: 도달 불가능한 위치
target = [1000, 1000, 1000, 0, 180, 0]  # 로봇 작업 영역 밖
# 해결: 로봇 스펙 확인 후 적절한 좌표 사용

# 에러 2: 너무 빠른 속도
movej(target, vel=100, acc=1000)  # 과도한 가속도
# 해결: 적절한 속도/가속도 설정

# 에러 3: 충돌 위험
movel([400, 100, 50, 0, 180, 0])  # 테이블과 충돌 위험
# 해결: 안전한 경로 계획
```

---
