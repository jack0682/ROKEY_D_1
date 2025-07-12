from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction, RegisterEventHandler, LogInfo
from launch.event_handlers import OnProcessExit
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition


def generate_launch_description():
    # ⚙️ Node 1: YOLOv7
    yolov7_node = Node(
        package='yolov7_ros2',
        executable='yolov7_infer_node',
        name='yolov7_eval',
        parameters=[{
            'model_path': '/home/jack/yolo_experiments_ws/models/yolov7.pt',
            'image_topic': '/robot1/oakd/rgb/image_raw',
            'conf_threshold': 0.3,
            'imgsz': 640
        }],
        output='screen'
    )

    # ⚙️ Node 2: YOLOv8
    yolov8_node = Node(
        package='yolov8_ros2',
        executable='yolov8_infer_node',
        name='yolov8_eval',
        parameters=[{
            'model_path': '/home/jack/yolo_experiments_ws/models/yolov8.pt',
            'image_topic': '/robot1/oakd/rgb/image_raw',
            'conf_threshold': 0.3,
            'imgsz': 640
        }],
        output='screen'
    )

    # ⚙️ Node 3: YOLOv11
    yolov11_node = Node(
        package='yolov11_ros2',
        executable='yolov11_infer_node',
        name='yolov11_eval',
        parameters=[{
            'model_path': '/home/jack/yolo_experiments_ws/models/yolov11.pt',
            'image_topic': '/robot1/oakd/rgb/image_raw',
            'conf_threshold': 0.3,
            'imgsz': 640
        }],
        output='screen'
    )

    return LaunchDescription([
        LogInfo(msg='🚀 [YOLOv7] 30초간 추론 평가 시작...'),
        yolov7_node,

        RegisterEventHandler(
            OnProcessExit(
                target_action=yolov7_node,
                on_exit=[LogInfo(msg='✅ YOLOv7 평가 종료 → YOLOv8 시작'), yolov8_node]
            )
        ),

        RegisterEventHandler(
            OnProcessExit(
                target_action=yolov8_node,
                on_exit=[LogInfo(msg='✅ YOLOv8 평가 종료 → YOLOv11 시작'), yolov11_node]
            )
        ),

        RegisterEventHandler(
            OnProcessExit(
                target_action=yolov11_node,
                on_exit=[LogInfo(msg='✅ YOLOv11 평가 종료 → 전체 평가 종료 🎯')]
            )
        )
    ])
