from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    config_path = os.path.join(
        get_package_share_directory('puddle_tracking'),
        'config',
        'tracker_params.yaml'
    )

    return LaunchDescription([
        Node(
            package='puddle_tracking',
            executable='tracker_node',
            name='topo_moment_tracker',
            output='screen',
            parameters=[config_path]
        )
    ])
