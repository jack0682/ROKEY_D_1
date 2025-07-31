#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    # Launch configuration variables
    mode = LaunchConfiguration('mode')
    model = LaunchConfiguration('model') 
    host = LaunchConfiguration('host')
    port = LaunchConfiguration('port')
    
    return LaunchDescription([
        # Launch arguments
        DeclareLaunchArgument('mode', default_value='virtual', description='Robot mode: real or virtual'),
        DeclareLaunchArgument('model', default_value='m0609', description='Robot model'),
        DeclareLaunchArgument('host', default_value='192.168.137.100', description='Robot controller IP'),
        DeclareLaunchArgument('port', default_value='12345', description='Robot controller port'),
        
        # 기본 ROS2 노드들
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            parameters=[{
                'robot_description': 'Doosan M0609 Chemical Experiment Robot'
            }]
        ),
        
        # 화학 실험 매니저 (조건부)
        Node(
            package='chemistry_experiment_manager',
            executable='experiment_coordinator',
            name='experiment_coordinator',
            parameters=[
                {'robot_model': 'm0609'},
                {'max_payload_kg': 6.0},
                {'max_reach_mm': 900.0}
            ],
            condition=launch.conditions.IfCondition(
                launch.substitutions.Command(['test -d ', PathJoinSubstitution([FindPackageShare('chemistry_experiment_manager')])])
            )
        ),
        
    ])
