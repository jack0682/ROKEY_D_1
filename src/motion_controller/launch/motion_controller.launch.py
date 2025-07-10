from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Goal sender node
        Node(
            package='motion_controller',
            executable='goal_sender',
            name='goal_sender_node',
            output='screen'
        ),

        # Velocity controller node (필요 시 주석 해제)
        # Node(
        #     package='motion_controller',
        #     executable='velocity_controller',
        #     name='velocity_controller_node',
        #     output='screen'
        # ),
    ])
