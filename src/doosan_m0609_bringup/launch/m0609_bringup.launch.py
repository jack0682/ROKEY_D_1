#!/usr/bin/env python3
"""
Main bringup launch file for Doosan M0609 robot
Supports both real robot and virtual mode

Usage:
  ros2 launch doosan_m0609_bringup m0609_bringup.launch.py mode:=real
  ros2 launch doosan_m0609_bringup m0609_bringup.launch.py mode:=virtual
"""

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, OpaqueFunction
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, Command
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from ament_index_python.packages import get_package_share_directory


def launch_setup(context, *args, **kwargs):
    """Dynamic launch setup based on parameters"""
    
    # Get launch arguments
    mode = LaunchConfiguration('mode')
    model = LaunchConfiguration('model')
    host = LaunchConfiguration('host')
    rt_host = LaunchConfiguration('rt_host')
    port = LaunchConfiguration('port')
    use_rviz = LaunchConfiguration('use_rviz')
    use_moveit = LaunchConfiguration('use_moveit')
    color = LaunchConfiguration('color')
    
    # Package directories
    bringup_pkg = get_package_share_directory('doosan_m0609_bringup')
    description_pkg = get_package_share_directory('dsr_description2')
    
    # URDF/XACRO file
    robot_description_file = PathJoinSubstitution([
        description_pkg, 'xacro', f'{model.perform(context)}.urdf.xacro'
    ])
    
    # Robot description
    robot_description_content = Command([
        'xacro ', robot_description_file,
        ' color:=', color,
        ' mode:=', mode,
        ' host:=', host,
        ' rt_host:=', rt_host,
        ' port:=', port
    ])
    
    robot_description = {'robot_description': robot_description_content}
    
    # Robot state publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[robot_description]
    )
    
    # Controller manager configuration
    controllers_config = PathJoinSubstitution([
        bringup_pkg, 'config', 'ros2_controllers.yaml'
    ])
    
    # Controller manager node  
    controller_manager = Node(
        package='controller_manager',
        executable='ros2_control_node',
        name='controller_manager',
        output='screen',
        parameters=[
            robot_description,
            controllers_config
        ]
    )
    
    # Joint state broadcaster spawner
    joint_state_broadcaster_spawner = Node(
        package='controller_manager',
        executable='spawner',
        name='joint_state_broadcaster_spawner',
        arguments=['joint_state_broadcaster', '--controller-manager', '/controller_manager'],
        output='screen'
    )
    
    # Joint trajectory controller spawner  
    joint_trajectory_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        name='joint_trajectory_controller_spawner',
        arguments=['joint_trajectory_controller', '--controller-manager', '/controller_manager'],
        output='screen'
    )
    
    # RViz node (conditional)
    rviz_config = PathJoinSubstitution([
        bringup_pkg, 'rviz', 'm0609.rviz'
    ])
    
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config],
        condition=IfCondition(use_rviz),
        parameters=[robot_description]
    )
    
    # MoveIt launch (conditional)
    moveit_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('dsr_moveit_config_m0609'),
                'launch',
                'start.launch.py'
            ])
        ]),
        launch_arguments={
            'mode': mode,
            'model': model,
            'color': color,
            'host': host,
            'rt_host': rt_host,
            'port': port
        }.items(),
        condition=IfCondition(use_moveit)
    )
    
    nodes_to_start = [
        robot_state_publisher,
        controller_manager, 
        joint_state_broadcaster_spawner,
        joint_trajectory_controller_spawner,
        rviz_node,
        moveit_launch
    ]
    
    return nodes_to_start


def generate_launch_description():
    """Generate launch description with arguments"""
    
    declared_arguments = []
    
    # Robot configuration arguments
    declared_arguments.append(
        DeclareLaunchArgument(
            'mode',
            default_value='virtual',
            choices=['real', 'virtual'],
            description='Robot connection mode: real hardware or virtual simulation'
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'model', 
            default_value='m0609',
            description='Robot model name'
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'color',
            default_value='blue', 
            choices=['blue', 'white'],
            description='Robot color scheme'
        )
    )
    
    # Network configuration arguments
    declared_arguments.append(
        DeclareLaunchArgument(
            'host',
            default_value='192.168.137.100',
            description='Robot controller IP address'
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'rt_host',
            default_value='192.168.137.100',
            description='Robot real-time control IP address'  
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'port',
            default_value='12345',
            description='Robot controller port number'
        )
    )
    
    # Feature toggle arguments
    declared_arguments.append(
        DeclareLaunchArgument(
            'use_rviz',
            default_value='true',
            choices=['true', 'false'],
            description='Launch RViz visualization'
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'use_moveit',
            default_value='false', 
            choices=['true', 'false'],
            description='Launch MoveIt motion planning'
        )
    )
    
    return LaunchDescription(declared_arguments + [OpaqueFunction(function=launch_setup)])