#!/usr/bin/env python3
# ~/project_ws/src/doosan_m0609_bringup/launch/chemical_experiment_complete.launch.py

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, Command
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.conditions import IfCondition

def generate_launch_description():
    
    # Launch arguments
    robot_mode_arg = DeclareLaunchArgument(
        'robot_mode', default_value='virtual',
        description='Robot mode: real or virtual'
    )
    
    robot_ip_arg = DeclareLaunchArgument(
        'robot_ip', default_value='192.168.137.100',
        description='Robot controller IP address'
    )
    
    loadcell_port_arg = DeclareLaunchArgument(
        'loadcell_port', default_value='/dev/ttyUSB0',
        description='Arduino loadcell serial port'
    )
    
    enable_hardware_arg = DeclareLaunchArgument(
        'enable_hardware', default_value='false',
        description='Enable physical hardware (loadcell, robot)'
    )
    
    # Robot URDF
    pkg_description = FindPackageShare('doosan_m0609_description')
    xacro_file = PathJoinSubstitution([pkg_description, 'xacro', 'm0609.urdf.xacro'])
    
    robot_description = Command([
        'xacro', ' ', xacro_file,
        ' host:=', LaunchConfiguration('robot_ip'),
        ' rt_host:=', LaunchConfiguration('robot_ip'),
        ' port:=12345',
        ' mode:=', LaunchConfiguration('robot_mode'),
        ' model:=m0609'
    ])
    
    # Robot State Publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        parameters=[{
            'robot_description': robot_description,
            'use_sim_time': False
        }],
        output='screen'
    )
    
    # Controller Manager
    controller_manager = Node(
        package='controller_manager',
        executable='ros2_control_node',
        parameters=[{
            'robot_description': robot_description,
            'update_rate': 100
        }],
        condition=IfCondition(LaunchConfiguration('enable_hardware')),
        output='screen'
    )
    
    # Joint State Broadcaster
    joint_state_broadcaster = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'joint_state_broadcaster'],
        condition=IfCondition(LaunchConfiguration('enable_hardware')),
        output='screen'
    )
    
    # Position Controller
    position_controller = ExecuteProcess(
        cmd=['ros2', 'control', 'load_controller', '--set-state', 'active', 'position_controller'],
        condition=IfCondition(LaunchConfiguration('enable_hardware')),
        output='screen'
    )
    
    # Arduino Loadcell Interface
    loadcell_node = Node(
        package='arduino_loadcell_interface',
        executable='loadcell_node',
        name='loadcell_interface',
        parameters=[{
            'port': LaunchConfiguration('loadcell_port'),
            'baudrate': 38400,
            'publish_topic': '/loadcell/weight',
            'publish_rate': 20.0
        }],
        condition=IfCondition(LaunchConfiguration('enable_hardware')),
        output='screen'
    )
    
    # Chemistry Experiment Manager
    experiment_manager = Node(
        package='chemistry_experiment_manager',
        executable='experiment_coordinator',
        name='experiment_coordinator',
        parameters=[{
            'robot_model': 'm0609',
            'max_payload_kg': 6.0,
            'max_reach_mm': 900.0,
            'target_concentrations': [0.5, 1.0, 1.5, 2.0],
            'num_trials': 5,
            'tolerance_percent': 0.05
        }],
        output='screen'
    )
    
    # Precision Liquid Pouring Controller
    pouring_controller = Node(
        package='precision_liquid_pouring',
        executable='pour_control_node',
        name='pouring_controller',
        parameters=[{
            'fixed_salt_grams': 15.0,
            'target_concentration_percent': 3.0,
            'tolerance_percent': 0.05,
            'scale_topic': '/loadcell/weight'
        }],
        output='screen'
    )
    
    # RViz for visualization
    rviz_config = PathJoinSubstitution([
        FindPackageShare('doosan_m0609_description'),
        'rviz', 'default.rviz'
    ])
    
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        arguments=['-d', rviz_config],
        output='screen'
    )
    
    # Delayed controller spawning
    delayed_joint_broadcaster = TimerAction(
        period=3.0,
        actions=[joint_state_broadcaster],
        condition=IfCondition(LaunchConfiguration('enable_hardware'))
    )
    
    delayed_position_controller = TimerAction(
        period=5.0,
        actions=[position_controller],
        condition=IfCondition(LaunchConfiguration('enable_hardware'))
    )
    
    return LaunchDescription([
        # Arguments
        robot_mode_arg,
        robot_ip_arg,  
        loadcell_port_arg,
        enable_hardware_arg,
        
        # Core nodes
        robot_state_publisher,
        controller_manager,
        loadcell_node,
        experiment_manager,
        pouring_controller,
        rviz_node,
        
        # Delayed controller spawning
        delayed_joint_broadcaster,
        delayed_position_controller,
    ])
