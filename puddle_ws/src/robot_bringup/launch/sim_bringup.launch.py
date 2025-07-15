from launch import LaunchDescription
from launch_ros.actions import SetParameter
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    use_sim_time = SetParameter(name='use_sim_time', value=True)

    return LaunchDescription([
        use_sim_time,
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(get_package_share_directory('robot_bringup'), 'launch', 'bringup.launch.py')
            )
        )
    ])
