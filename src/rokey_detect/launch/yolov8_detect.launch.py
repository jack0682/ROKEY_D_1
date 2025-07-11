from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='rokey_detect',
            executable='det_obj',
            name='yolov8_object_detector',
            output='screen',
            parameters=[
                {'model_path': '/home/jack/turtlebot_ws/best.pt'},
                {'imgsz': 640},
                {'conf_threshold': 0.25}
            ]
        )
    ])
