from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    config_path = os.path.join(
        get_package_share_directory('puddle_detection'),
        'config',
        'model_config.yaml'
    )

    return LaunchDescription([
        Node(
            package='puddle_detection',
            executable='agsenet_node',
            name='agsenet_node',
            output='screen',
            parameters=[config_path]
        )
    ])
