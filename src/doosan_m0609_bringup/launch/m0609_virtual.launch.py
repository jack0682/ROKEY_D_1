#!/usr/bin/env python3
"""
Virtual/simulation mode launch file for Doosan M0609
Uses virtual controller for testing without physical robot

Usage:
  ros2 launch doosan_m0609_bringup m0609_virtual.launch.py
"""

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    """Generate launch description for virtual robot mode"""
    
    declared_arguments = []
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'color',
            default_value='white',
            choices=['blue', 'white'],
            description='Robot visual color in simulation'
        )
    )
    
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
            default_value='true',
            choices=['true', 'false'],
            description='Launch MoveIt motion planning'
        )
    )
    
    # Include main bringup with virtual mode
    main_bringup = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('doosan_m0609_bringup'),
                'launch',
                'm0609_bringup.launch.py'
            ])
        ]),
        launch_arguments={
            'mode': 'virtual',
            'model': 'm0609',
            'host': '127.0.0.1',  # Localhost for virtual mode
            'rt_host': '127.0.0.1',
            'port': '12345',
            'color': LaunchConfiguration('color'),
            'use_rviz': LaunchConfiguration('use_rviz'),
            'use_moveit': LaunchConfiguration('use_moveit')
        }.items()
    )
    
    return LaunchDescription(declared_arguments + [main_bringup])