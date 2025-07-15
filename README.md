# ROKEY_D_1

---

#  GitHub 협업 매뉴얼 (Ubuntu 22.04 + ROS2 Humble 개발 환경 기준)

* 팀 전용 Git 사용법*

---

##  목적

* 팀원 간 소스코드 협업을 Git + GitHub를 통해 구조화합니다.
* 로컬에서 개발한 후, GitHub에서 브랜치 → PR → 머지 과정을 안전하고 일관되게 진행할 수 있도록 가이드합니다.
* 모든 팀원이 동일한 Git 작업 방식으로 프로젝트를 운영하도록 합니다.

---

##  0. 사전 준비

###  1. GitHub 계정 생성

* [https://github.com/](https://github.com/) 에서 **본인 이름으로 GitHub 계정** 생성
* 프로필 사진, 닉네임 등은 본인 확인이 가능한 형태로 설정

###  2. Git 설치 확인 (Ubuntu 22.04 기준)

```bash
sudo apt update
sudo apt install git
git --version  # 설치 확인
```

###  3. SSH Key 등록 (GitHub 인증용)

```bash
# SSH Key 생성
ssh-keygen -t ed25519 -C "your_email@example.com"
# 생성된 키 확인
cat ~/.ssh/id_ed25519.pub
```

* 출력된 내용을 GitHub → Settings → SSH and GPG keys → New SSH key에 붙여넣기

---

##  1. 프로젝트 처음 받기 (Clone)

```bash
cd ~/ros2_ws/src
git clone git@github.com:jack0682/ROKEY_D_1.git
cd LM_project_ver1.0
```

```bash
# 본인 이름으로 새 브랜치 만들기 (처음 1회만)
git checkout -b feature/홍길동-initial
```

---

##  2. 브랜치 전략 및 용어

| 브랜치명            | 용도                        |
| --------------- | ------------------------- |
| `main`          | 최종 안정 버전 (리더만 머지 가능)      |
| `develop`       | 개발 통합 브랜치 (모든 기능 통합 전 실험) |
| `feature/이름-기능` | 각자 작업 공간. 여기에만 푸시 가능      |
| `hotfix/이름-수정`  | 버그 수정용 브랜치 (급할 때만)        |

---

##  3. 작업 흐름 요약 (개발자 루틴)

###  A. 브랜치 생성 (처음 작업 시작할 때)

```bash
git checkout develop
git pull origin develop
git checkout -b feature/홍길동-추적기연동
```

###  B. 작업하고 커밋하기

```bash
# 파일 수정 후
git add .
git commit -m "[추적기] Panoptic 연동 기능 구현"
```

###  C. 브랜치에 푸시하기

```bash
git push origin feature/홍길동-추적기연동
```

---

##  4. Pull Request(PR) 보내기

1. GitHub 웹사이트 접속 → 본인 브랜치 클릭
2. `Compare & Pull Request` 클릭
3. 제목: `[기능명] 어떤 기능을 개발했는지 요약`
4. 내용:

```markdown
###  작업 내용 요약
- YOLOv5 wrapper 정리
- StrongSORT init 구조 개선

###  관련 파일
- csa_yolo_inference/yolov5_wrapper.py
- csa_yolo_inference/strongsort_tracker.py

###  확인 필요
- 추론 속도가 약간 느려진 것 같습니다. 개선 의견 있으면 부탁드립니다.
```

5. `base: develop`, `compare: feature/홍길동-작업명` 확인 후 → PR 생성

---

##  5. 코드 리뷰 & 머지

* PR 생성 후, 팀원 또는 리더가 리뷰합니다.
* 리뷰 후 “Approve”되면 **리더가 `develop` 브랜치에 머지**합니다.
* 머지되면 **자신의 로컬 develop 브랜치도 꼭 갱신**해야 합니다.

```bash
git checkout develop
git pull origin develop
```

---

##  6. 주의사항

| 주의사항                           | 설명                                        |
| ------------------------------ | ----------------------------------------- |
| 직접 `main`이나 `develop`에 push 금지 | 무조건 PR을 통해 merge                          |
| 항상 최신 `develop`에서 브랜치 생성       | 오래된 브랜치에서 작업 금지                           |
| 커밋 메시지 명확하게                    | "\[모듈명] 작업내용" 형태 권장                       |
| 매 작업 전에 `git pull`             | 충돌 방지                                     |
| 실험 파일은 `.gitignore`에 추가        | 예: `.bag`, `.pt`, `.npy`, `__pycache__` 등 |

---

##  7. 충돌 해결 팁

```bash
git pull origin develop
# 만약 충돌 발생 시
# 해당 파일 열어서 <<<<<<< HEAD ~ ======= ~ >>>>>>> 표시된 부분 해결
git add .
git commit -m "충돌 해결"
git push origin feature/홍길동-작업명
```

---

##  8. 협업 예시 시나리오

| 역할    | 예시 행동                            |
| ----- | -------------------------------- |
| 팀원 A  | `feature/길동-yolo연동`에서 작업 → PR 생성 |
| 팀원 B  | 코드 리뷰 후 “Approve” 누름             |
| 리더    | PR 확인 후 `develop`에 merge         |
| 전체 팀원 | `develop` pull 받아서 반영            |

---

##  9. GitHub 관련 용어 요약

| 용어               | 설명                                    |
| ---------------- | ------------------------------------- |
| Fork             | 프로젝트를 개인 계정으로 복사 (이 프로젝트는 직접 push 허용) |
| Branch           | 코드 변경을 격리하는 공간                        |
| Commit           | 변경 내용을 저장한 단위                         |
| Pull Request(PR) | 변경사항을 다른 브랜치에 합치는 요청                  |
| Merge            | 변경사항을 실제로 적용하는 행위                     |
| Conflict         | 두 변경사항이 충돌할 때 발생                      |

---

##  10. 참고 문서 및 튜토리얼

* [Git 공식 한글 문서](https://git-scm.com/book/ko/v2)
* [GitHub 초보자 가이드 (한글)](https://backlog.com/git-tutorial/kr/)
* [VSCode에서 GitHub 협업하기](https://code.visualstudio.com/docs/sourcecontrol/github)

---

#  Safety Monitoring Robot System with TurtleBot4

TurtleBot4과 RGB-D 센서, 천장 고정형 웹캠을 활용하여 **실내 위험 요소를 자율적으로 감지**하고, **실시간 모니터링과 관리자 경고 기능**을 수행하는 **ROS 2 기반 안전 관리 로봇 시스템**입니다.

---

## 1. 문제 정의

- **넓은 실내 공간의 사각지대 발생**
- **위험 요소 감지의 수동성과 지연**
- **정확한 위치 정보 부재로 인한 혼선**
- **24시간 상시 모니터링 인력 부담**
- **응급 상황 초기 대응 체계 미비**
- **위험 환경에 직접 투입되는 인력의 신체적 위험**

---

## 2. 프로젝트 목표

- 실시간 객체 탐지 및 위험 상황 인식
- 위험 요소 발견 시 즉시 경고 전송 (1초 이내)
- 자율 점검 루틴 자동 수행 (예: 5분 주기)
- 시각적 위험 경고 및 관리자 통신 기능 구현
- ROS 기반 실시간 모니터링 연동

---

## 3. 주요 기능

-  **USB & RGB-D 카메라 기반 영상 수집**
-  **YOLO 기반 객체 탐지** (사람, 위험품 등)
-  **SLAM 및 위치 추정**
-  **경로 계획 및 동적 장애물 회피**
-  **원격 제어 + 실시간 시각화 UI**
-  **비안전 상황 판단 기준 Rulebook 적용**

---

## 4. 주요 사용자

- 안전 관리자
- 공장 운영 관리자
- 응급 대응팀

---

##  5. 운영 환경

### (1) 물리적 공간

| 항목 | 내용 |
|------|------|
| 공간 크기 | 약 4m × 4m |
| 환경 조건 | 매끄러운 바닥, 형광등 조명, 책상 및 장애물 포함 |
| 가시선 확보 | RGB-D 카메라 + 천장 고정 웹캠 (Top-down View) |

### (2) 하드웨어 구성

| 항목          | 내용                               |
|---------------|------------------------------------|
| OS            | Ubuntu 22.04                       |
| ROS 2         | Humble Hawksbill                   |
| 로봇 모델     | TurtleBot4 Burger                  |
| 센서          | OAK-D pro / USB Webcam / RPLIDAR      |
| 관련 패키지   | `realsense2_camera`, `nav2_bringup`, `tf2_ros` 등 |

---

##  6. 성공 기준

- 자율 주행 도중 **위험 요소 탐지에 성공**
- **탐지된 대상의 위치 및 상태를 실시간 시각화**
- 관리자에게 경고 또는 로그 전송 기능 수행
- 전체 시스템이 ROS 2 내에서 일관되게 통합 운영됨

---

## 📂 프로젝트 구조

```bash
미정

```
