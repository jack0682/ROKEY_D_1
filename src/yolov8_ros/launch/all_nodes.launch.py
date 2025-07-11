from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='yolov8_ros',
            executable='image_pub',
            name='image_pub',
            output='screen'
        ),
        Node(
            package='yolov8_ros',
            executable='image_sub',
            name='image_sub',
            output='screen'
        ),
        Node(
            package='yolov8_ros',
            executable='data_pub',
            name='data_pub',
            output='screen'
        ),
        Node(
            package='yolov8_ros',
            executable='data_sub',
            name='data_sub',
            output='screen'
        ),
        Node(
            package='yolov8_ros',
            executable='yolo_pub',
            name='yolo_pub',
            output='screen'
        ),
        Node(
            package='yolov8_ros',
            executable='yolo_sub',
            name='yolo_sub',
            output='screen'
        ),
        Node(
            package='yolov8_ros',
            executable='image_capture',
            name='image_capture',
            output='screen'
        ),
    ])
