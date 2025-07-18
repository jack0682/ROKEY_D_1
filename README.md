# ROKEY_D_1: 새로 시작합니다

1. 진행 완료 사항
   
    -YOLO + Depth 기반 객체 위치 인식
   
        RGB-D 데이터를 활용하여 객체 중심의 base_link 기준 3D 위치 추정
   
    -TF를 통한 좌표계 변환
   
        추정된 객체 위치를 base_link → map 프레임으로 변환
        tf2_ros 기반 좌표 변환
   
    -자율 주행 및 정지
   
        변환된 map 좌표를 목표지점으로 설정 후 로봇 자율 이동
        도착 후 정지 동작 정상 수행
        
3. 카메라 파라미터 오류 수정
   
    -초기 Depth to 3D 좌표 변환 시 오차 발생
   
    -내부 파라미터 계산 과정 수정을 통해 정확도 복구
   
    -좌표계 불일치 문제 해결됨

5. 향후 개발 예정 사항
   
    -YOLO의 바운딩 박스 클래스 결과를 분석, 안전모, 조끼, 안전화 모두 미착용한 객체 식별 시
         → buzzer 노드로 경고 메시지 Publish

    -회전/주행 중 포커스 손실 대응
   
        카메라의 자동 초점 유지 실패 문제 확인됨
   
        주행 중 실시간 초점 재설정 또는 이미지 안정화 기법 적용 예정


ros2 run rokey_pjt detect_with_depth_with_tf --ros-args -r /tf:=/robot1/tf -r /tf_static:=/robot1/tf_static -r __ns:=/robot1




rokey@rokey-Victus-by-HP-Laptop-16-d1xxx:~/rokey_ws$ ros2 run rokey_pjt follow_waypoints_test --ros-args -r __ns:=/robot3
🚀 === TurtleBot4 패트롤 시스템 시작 [/robot3] ===

🔄 [/robot3] MQTT 브로커 연결 시도 중...
✅ [/robot3] MQTT 브로커 연결 성공!
🧹 [/robot3] 기존 retained 메시지 클리어 완료
📡 [/robot3] 토픽 구독 완료: detect
📤 [/robot3] MQTT 이벤트 발행 성공: system_ready
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "namespace": "/robot3", "event": "system_ready", "waypoint": 0, "robot_position": [0, 0], "event_position": [0, 0], "timestamp": "2025-07-18T11:50:19.886539+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot3", "namespace": "/robot3", "event": "system_ready", "waypoint": 0, "robot_position": [0, 0], "event_position": [0, 0], "timestamp": "2025-07-18T11:50:19.886539+00:00"}
🤖 [/robot3] ROS2 노드 초기화 중...
⚠️ TF2 초기화 실패: 'NoneType' object has no attribute 'create_subscription'
Exception ignored in: <function TransformListener.__del__ at 0x744c41124820>
Traceback (most recent call last):
  File "/opt/ros/humble/lib/python3.10/site-packages/tf2_ros/transform_listener.py", line 106, in __del__
    self.unregister()
  File "/opt/ros/humble/lib/python3.10/site-packages/tf2_ros/transform_listener.py", line 112, in unregister
    self.node.destroy_subscription(self.tf_sub)
AttributeError: 'NoneType' object has no attribute 'destroy_subscription'
🗺️ [/robot3] TurtleBot4 Navigator 초기화 완료
✅ [/robot3] 도킹 기능 지원됨
🔌 [/robot3] 도킹 상태 확인 중...
✅ [/robot3] 로봇이 이미 도킹됨
📍 [/robot3] 초기 포즈 설정 중...
[INFO] [1752839424.226477375] [robot3.basic_navigator]: Publishing Initial Pose
🗺️ [/robot3] Nav2 시스템 활성화 대기 중...
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot1", "namespace": "/robot1", "event": "waypoint_arrival", "waypoint": 3, "robot_position": [0.0, 0.0], "event_position": [-1.9, -3.0], "timestamp": "2025-07-18T11:50:25.710865+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot1", "namespace": "/robot1", "event": "waypoint_arrival", "waypoint": 3, "robot_position": [0.0, 0.0], "event_position": [-1.9, -3.0], "timestamp": "2025-07-18T11:50:25.710865+00:00"}
[INFO] [1752839428.723718281] [robot3.basic_navigator]: Nav2 is ready for use!
⏱️ [/robot3] 시스템 안정화 대기...
✅ [/robot3] 네비게이션 시스템 준비 완료!
🎯 [/robot3] 패트롤 시작!
🚀 [/robot3] 언도킹 상태 확인 중...
🚀 [/robot3] 도킹 상태에서 언도킹 시작...
[INFO] [1752839431.727800453] [robot3.basic_navigator]: Undocking...
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot1", "namespace": "/robot1", "event": "rotation_complete", "waypoint": 3, "robot_position": [0.0, 0.0], "event_position": [0.0, 0.0], "timestamp": "2025-07-18T11:50:35.718215+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot1", "namespace": "/robot1", "event": "rotation_complete", "waypoint": 3, "robot_position": [0.0, 0.0], "event_position": [0.0, 0.0], "timestamp": "2025-07-18T11:50:35.718215+00:00"}
[INFO] [1752839437.415813241] [robot3.basic_navigator]: Undock succeeded
✅ [/robot3] 언도킹 완료!
⏱️ [/robot3] 언도킹 후 시스템 안정화 대기...

🔄 [/robot3] === 패트롤 사이클 1 시작 ===
🎯 [/robot3] [1/4] 웨이포인트 이동: [-4.1, 0.85]
[INFO] [1752839439.420211629] [robot3.basic_navigator]: Navigating to goal: -4.1 0.85...
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot1", "namespace": "/robot1", "event": "waypoint_arrival", "waypoint": 4, "robot_position": [0.0, 0.0], "event_position": [-0.5, -2.8], "timestamp": "2025-07-18T11:50:42.383849+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot1", "namespace": "/robot1", "event": "waypoint_arrival", "waypoint": 4, "robot_position": [0.0, 0.0], "event_position": [-0.5, -2.8], "timestamp": "2025-07-18T11:50:42.383849+00:00"}
✅ [/robot3] 작업 성공: 웨이포인트 1 이동
⚠️ [/robot3] 현재 위치 획득 실패: 'TurtleBot4Navigator' object has no attribute 'getCurrentPose'
📤 [/robot3] MQTT 이벤트 발행 성공: waypoint_arrival
✅ [/robot3] 웨이포인트 1 도착!
🔄 [/robot3] 웨이포인트 1에서 360° 회전 시작
[INFO] [1752839445.284709625] [robot3.basic_navigator]: Spinning to angle 6.283185307179586....
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "namespace": "/robot3", "event": "waypoint_arrival", "waypoint": 1, "robot_position": [0.0, 0.0], "event_position": [-4.1, 0.85], "timestamp": "2025-07-18T11:50:45.283492+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot3", "namespace": "/robot3", "event": "waypoint_arrival", "waypoint": 1, "robot_position": [0.0, 0.0], "event_position": [-4.1, 0.85], "timestamp": "2025-07-18T11:50:45.283492+00:00"}
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot1", "namespace": "/robot1", "event": "rotation_complete", "waypoint": 4, "robot_position": [0.0, 0.0], "event_position": [0.0, 0.0], "timestamp": "2025-07-18T11:50:52.388565+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot1", "namespace": "/robot1", "event": "rotation_complete", "waypoint": 4, "robot_position": [0.0, 0.0], "event_position": [0.0, 0.0], "timestamp": "2025-07-18T11:50:52.388565+00:00"}
✅ [/robot3] 작업 성공: 웨이포인트 1 회전
⚠️ [/robot3] 현재 위치 획득 실패: 'TurtleBot4Navigator' object has no attribute 'getCurrentPose'
📤 [/robot3] MQTT 이벤트 발행 성공: rotation_complete
✅ [/robot3] 웨이포인트 1 회전 완료!
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "namespace": "/robot3", "event": "rotation_complete", "waypoint": 1, "robot_position": [0.0, 0.0], "event_position": [0.0, 0.0], "timestamp": "2025-07-18T11:50:52.789521+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot3", "namespace": "/robot3", "event": "rotation_complete", "waypoint": 1, "robot_position": [0.0, 0.0], "event_position": [0.0, 0.0], "timestamp": "2025-07-18T11:50:52.789521+00:00"}
🎯 [/robot3] [2/4] 웨이포인트 이동: [-5.67, 0.8]
[INFO] [1752839453.292247030] [robot3.basic_navigator]: Navigating to goal: -5.67 0.8...
✅ [/robot3] 작업 성공: 웨이포인트 2 이동
⚠️ [/robot3] 현재 위치 획득 실패: 'TurtleBot4Navigator' object has no attribute 'getCurrentPose'
📤 [/robot3] MQTT 이벤트 발행 성공: waypoint_arrival
✅ [/robot3] 웨이포인트 2 도착!
🔄 [/robot3] 웨이포인트 2에서 360° 회전 시작
[INFO] [1752839461.155762047] [robot3.basic_navigator]: Spinning to angle 6.283185307179586....
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "namespace": "/robot3", "event": "waypoint_arrival", "waypoint": 2, "robot_position": [0.0, 0.0], "event_position": [-5.67, 0.8], "timestamp": "2025-07-18T11:51:01.154847+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot3", "namespace": "/robot3", "event": "waypoint_arrival", "waypoint": 2, "robot_position": [0.0, 0.0], "event_position": [-5.67, 0.8], "timestamp": "2025-07-18T11:51:01.154847+00:00"}
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot1", "namespace": "/robot1", "event": "waypoint_arrival", "waypoint": 5, "robot_position": [0.0, 0.0], "event_position": [-1.9, -3.0], "timestamp": "2025-07-18T11:51:02.106048+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot1", "namespace": "/robot1", "event": "waypoint_arrival", "waypoint": 5, "robot_position": [0.0, 0.0], "event_position": [-1.9, -3.0], "timestamp": "2025-07-18T11:51:02.106048+00:00"}
✅ [/robot3] 작업 성공: 웨이포인트 2 회전
⚠️ [/robot3] 현재 위치 획득 실패: 'TurtleBot4Navigator' object has no attribute 'getCurrentPose'
📤 [/robot3] MQTT 이벤트 발행 성공: rotation_complete
✅ [/robot3] 웨이포인트 2 회전 완료!
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "namespace": "/robot3", "event": "rotation_complete", "waypoint": 2, "robot_position": [0.0, 0.0], "event_position": [0.0, 0.0], "timestamp": "2025-07-18T11:51:08.458387+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot3", "namespace": "/robot3", "event": "rotation_complete", "waypoint": 2, "robot_position": [0.0, 0.0], "event_position": [0.0, 0.0], "timestamp": "2025-07-18T11:51:08.458387+00:00"}
🎯 [/robot3] [3/4] 웨이포인트 이동: [-5.9, -0.8]
[INFO] [1752839468.960119271] [robot3.basic_navigator]: Navigating to goal: -5.9 -0.8...
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "type": "human3", "location": [-6.23, 0.09], "depth": 0.92, "area": 0, "timestamp": "2025-07-18T11:51:11.830083+00:00"}' from 'detect'
🚶 Human detected - processing location
[INFO] [1752839471.909069031] [robot3.basic_navigator]: Canceling current task.
🎯 목표 좌표: [-6.23, 0.09]
🚀 객체 좌표로 이동 시작...
🎯 [/robot3] 객체 감지 - 긴급 이동: [-6.23, 0.09]
[INFO] [1752839471.915987309] [robot3.basic_navigator]: Navigating to goal: -6.23 0.09...
✅ [/robot3] 작업 성공: 웨이포인트 3 이동
⚠️ [/robot3] 현재 위치 획득 실패: 'TurtleBot4Navigator' object has no attribute 'getCurrentPose'
📤 [/robot3] MQTT 이벤트 발행 성공: waypoint_arrival
✅ [/robot3] 웨이포인트 3 도착!
✅ [/robot3] 객체 이동 성공: 객체 위치 이동
🔄 [/robot3] 웨이포인트 3에서 360° 회전 시작
⚠️ [/robot3] 현재 위치 획득 실패: 'TurtleBot4Navigator' object has no attribute 'getCurrentPose'
📤 [/robot3] MQTT 이벤트 발행 성공: object_reached
✅ [/robot3] 객체 위치 도착!
✅ 객체 좌표로 이동 완료!
🚨 [/robot3] Stop flag set to: True
⏸️ 객체 위치에서 정지 상태로 전환
[INFO] [1752839471.936128655] [robot3.basic_navigator]: Spinning to angle 6.283185307179586....
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "namespace": "/robot3", "event": "waypoint_arrival", "waypoint": 3, "robot_position": [0.0, 0.0], "event_position": [-5.9, -0.8], "timestamp": "2025-07-18T11:51:11.933893+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot3", "namespace": "/robot3", "event": "waypoint_arrival", "waypoint": 3, "robot_position": [0.0, 0.0], "event_position": [-5.9, -0.8], "timestamp": "2025-07-18T11:51:11.933893+00:00"}
🚨 [/robot3] 정지 명령으로 인한 작업 취소: 웨이포인트 3 회전
[INFO] [1752839472.039155048] [robot3.basic_navigator]: Canceling current task.
❌ 웨이포인트 3 회전 실패
🚫 웨이포인트 4 이동 중 정지 명령 수신
⏸️  [/robot3] 정지 상태 - 대기 중...
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "type": "human3", "location": [-6.35, 0.1], "depth": 1.02, "area": 0, "timestamp": "2025-07-18T11:51:11.987101+00:00"}' from 'detect'
🚶 Human detected - processing location
[INFO] [1752839472.119891677] [robot3.basic_navigator]: Canceling current task.
🎯 목표 좌표: [-6.35, 0.1]
🚀 객체 좌표로 이동 시작...
🎯 [/robot3] 객체 감지 - 긴급 이동: [-6.35, 0.1]
[INFO] [1752839472.122947188] [robot3.basic_navigator]: Navigating to goal: -6.35 0.1...
❌ 객체 좌표 이동 중 오류: generator already executing
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "namespace": "/robot3", "event": "object_reached", "waypoint": 99, "robot_position": [0.0, 0.0], "event_position": [-6.23, 0.09], "timestamp": "2025-07-18T11:51:11.935456+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot3", "namespace": "/robot3", "event": "object_reached", "waypoint": 99, "robot_position": [0.0, 0.0], "event_position": [-6.23, 0.09], "timestamp": "2025-07-18T11:51:11.935456+00:00"}
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot1", "namespace": "/robot1", "event": "rotation_complete", "waypoint": 5, "robot_position": [0.0, 0.0], "event_position": [0.0, 0.0], "timestamp": "2025-07-18T11:51:12.114707+00:00"}' from 'detect'
❓ [/robot3] 알 수 없는 명령: {"robot_id": "robot1", "namespace": "/robot1", "event": "rotation_complete", "waypoint": 5, "robot_position": [0.0, 0.0], "event_position": [0.0, 0.0], "timestamp": "2025-07-18T11:51:12.114707+00:00"}
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "type": "human3", "location": [-7.44, -0.44], "depth": 2.24, "area": 0, "timestamp": "2025-07-18T11:51:12.247161+00:00"}' from 'detect'
🚶 Human detected - processing location
[INFO] [1752839473.347077800] [robot3.basic_navigator]: Canceling current task.
🎯 목표 좌표: [-7.44, -0.44]
🚀 객체 좌표로 이동 시작...
🎯 [/robot3] 객체 감지 - 긴급 이동: [-7.44, -0.44]
[INFO] [1752839473.350276193] [robot3.basic_navigator]: Navigating to goal: -7.44 -0.44...

❌ 패트롤 중 오류 발생: generator already executing
🧹 시스템 정리 중...
📤 [/robot3] MQTT 이벤트 발행 성공: system_shutdown
⏰ [/robot3] 객체 이동 타임아웃: 객체 위치 이동
[INFO] [1752839503.418797881] [robot3.basic_navigator]: Canceling current task.
❌ 객체 좌표로 이동 실패 - 패트롤 재개
📩 [/robot3] MQTT 메시지 수신: '{"robot_id": "robot3", "type": "human3", "location": [-7.49, -0.34], "depth": 2.24, "area": 0, "timestamp": "2025-07-18T11:51:12.470648+00:00"}' from 'detect'
🚶 Human detected - processing location
[INFO] [1752839503.422597024] [robot3.basic_navigator]: Canceling current task.
🎯 목표 좌표: [-7.49, -0.34]
🚀 객체 좌표로 이동 시작...
🎯 [/robot3] 객체 감지 - 긴급 이동: [-7.49, -0.34]
[INFO] [1752839503.425143810] [robot3.basic_navigator]: Navigating to goal: -7.49 -0.34...
✅ [/robot3] 객체 이동 성공: 객체 위치 이동
⚠️ [/robot3] 현재 위치 획득 실패: 'TurtleBot4Navigator' object has no attribute 'getCurrentPose'
📤 [/robot3] MQTT 이벤트 발행 성공: object_reached
✅ [/robot3] 객체 위치 도착!
✅ 객체 좌표로 이동 완료!
🚨 [/robot3] Stop flag set to: True
⏸️ 객체 위치에서 정지 상태로 전환
🔌 [/robot3] MQTT 연결 끊어짐, code: 0
✅ MQTT 연결 종료
[INFO] [1752839504.789991195] [robot3.basic_navigator]: Canceling current task.
✅ 네비게이션 작업 취소
🏁 시스템 정리 완료
👋 [/robot3] 프로그램 종료

