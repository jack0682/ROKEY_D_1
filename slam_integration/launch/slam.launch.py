from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    config_path = os.path.join(
        get_package_share_directory('slam_integration'),
        'config',
        'slam_params.yaml'
    )

    return LaunchDescription([
        Node(
            package='slam_toolbox',
            executable='sync_slam_toolbox_node',
            name='slam_toolbox',
            output='screen',
            parameters=[config_path],
            remappings=[
                ('/scan', '/robot4/scan')  # LIDAR 토픽 맞춤
            ]
        )
    ])
