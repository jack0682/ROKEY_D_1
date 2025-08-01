#!/usr/bin/env python3
"""
Real robot mode launch file for Doosan M0609
Connects to physical robot via DRFL interface

Usage:
  ros2 launch doosan_m0609_bringup m0609_real.launch.py host:=192.168.137.100
"""

import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    """Generate launch description for real robot mode"""
    
    declared_arguments = []
    
    # Robot network configuration
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
            description='Robot controller port'
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'color',
            default_value='blue',
            choices=['blue', 'white'],
            description='Robot visual color'
        )
    )
    
    declared_arguments.append(
        DeclareLaunchArgument(
            'use_rviz',
            default_value='true',
            choices=['true', 'false'], 
            description='Launch RViz'
        )
    )
    
    # Include main bringup with real mode
    main_bringup = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('doosan_m0609_bringup'),
                'launch',
                'm0609_bringup.launch.py'
            ])
        ]),
        launch_arguments={
            'mode': 'real',
            'model': 'm0609',
            'host': LaunchConfiguration('host'),
            'rt_host': LaunchConfiguration('rt_host'),
            'port': LaunchConfiguration('port'),
            'color': LaunchConfiguration('color'),
            'use_rviz': LaunchConfiguration('use_rviz'),
            'use_moveit': 'false'
        }.items()
    )
    
    return LaunchDescription(declared_arguments + [main_bringup])