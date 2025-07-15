from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    config_path = os.path.join(
        get_package_share_directory('puddle_viz'),
        'config',
        'marker_params.yaml'
    )

    return LaunchDescription([
        Node(
            package='puddle_viz',
            executable='viz_node',
            name='viz_node',
            output='screen',
            parameters=[config_path]
        )
    ])
