from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Launch Arguments
    target_concentration_arg = DeclareLaunchArgument(
        'target_concentration',
        default_value='0.05',
        description='Target sugar concentration (0.0-1.0)'
    )
    
    use_real_robot_arg = DeclareLaunchArgument(
        'use_real_robot',
        default_value='false',
        description='Use real robot or simulation'
    )
    
    # Nodes
    simple_sequence_node = Node(
        package='sugar_water_experiment',
        executable='simple_sequence_controller',
        name='simple_sequence_controller',
        output='screen',
        parameters=[{
            'target_concentration': LaunchConfiguration('target_concentration'),
            'use_real_robot': LaunchConfiguration('use_real_robot')
        }]
    )
    
    full_experiment_node = Node(
        package='sugar_water_experiment',
        executable='sugar_water_experimenter_node',
        name='sugar_water_experimenter',
        output='screen',
        parameters=[{
            'target_concentration': LaunchConfiguration('target_concentration'),
            'use_real_robot': LaunchConfiguration('use_real_robot')
        }]
    )
    
    # RViz for visualization (optional)
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', '/home/jack/project_ws/src/sugar_water_experiment/config/sugar_water_experiment.rviz'],
        condition=LaunchConfiguration('use_rviz', default='false')
    )
    
    return LaunchDescription([
        target_concentration_arg,
        use_real_robot_arg,
        
        # Choose one of the following nodes:
        # simple_sequence_node,  # Uncomment for simple sequence
        full_experiment_node,    # Full automated experiment
        
        # rviz_node,  # Uncomment for visualization
    ])
