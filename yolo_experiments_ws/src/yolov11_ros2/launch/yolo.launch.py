# yolov8_ros2/launch/yolo.launch.py 예시
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='yolov11_ros2',
            executable='yolo_infer_node',
            name='yolov11_node',
            output='screen',
            remappings=[
                ('/image_raw', '/robot1/oakd/rgb/image_raw'),
                ('/bounding_boxes', '/bounding_boxes')
            ]
        )
    ])
