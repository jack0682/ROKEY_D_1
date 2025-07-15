from launch import LaunchDescription
from launch_ros.actions import Node, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    return LaunchDescription([

        # SLAM
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(get_package_share_directory('slam_integration'), 'launch', 'slam.launch.py')
            )
        ),

        # AGSENet
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(get_package_share_directory('puddle_detection'), 'launch', 'detection.launch.py')
            )
        ),

        # Tracker
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(get_package_share_directory('puddle_tracking'), 'launch', 'tracking.launch.py')
            )
        ),

        # Viz
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(get_package_share_directory('puddle_viz'), 'launch', 'viz.launch.py')
            )
        ),
    ])
