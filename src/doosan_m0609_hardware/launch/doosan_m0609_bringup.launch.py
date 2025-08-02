#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import os

def generate_launch_description():
    
    # Declare launch arguments
    robot_ip_arg = DeclareLaunchArgument(
        'robot_ip',
        default_value='192.168.1.100',
        description='IP address of the Doosan robot controller'
    )
    
    # Configuration file path
    config_file = PathJoinSubstitution([
        FindPackageShare('doosan_m0609_hardware'),
        'config',
        'doosan_m0609_control.yaml'
    ])
    
    # Robot description (minimal URDF)
    robot_description_content = """
    <?xml version="1.0"?>
    <robot name="doosan_m0609">
      <!-- Base link -->
      <link name="base_link"/>
      
      <!-- Joint definitions -->
      <joint name="joint1" type="revolute">
        <parent link="base_link"/>
        <child link="link1"/>
        <origin xyz="0 0 0.16" rpy="0 0 0"/>
        <axis xyz="0 0 1"/>
        <limit lower="-6.28" upper="6.28" effort="100" velocity="3.14"/>
      </joint>
      <link name="link1"/>
      
      <joint name="joint2" type="revolute">
        <parent link="link1"/>
        <child link="link2"/>
        <origin xyz="0 0 0" rpy="1.57 0 0"/>  
        <axis xyz="0 0 1"/>
        <limit lower="-6.28" upper="6.28" effort="100" velocity="3.14"/>
      </joint>
      <link name="link2"/>
      
      <joint name="joint3" type="revolute">
        <parent link="link2"/>
        <child link="link3"/>
        <origin xyz="0 -0.24 0" rpy="0 0 0"/>
        <axis xyz="0 0 1"/>
        <limit lower="-2.97" upper="2.97" effort="100" velocity="3.14"/>
      </joint>
      <link name="link3"/>
      
      <joint name="joint4" type="revolute">
        <parent link="link3"/>
        <child link="link4"/>
        <origin xyz="0 0 0.21" rpy="1.57 0 0"/>
        <axis xyz="0 0 1"/>
        <limit lower="-6.28" upper="6.28" effort="100" velocity="3.14"/>
      </joint>
      <link name="link4"/>
      
      <joint name="joint5" type="revolute">
        <parent link="link4"/>
        <child link="link5"/>
        <origin xyz="0 0.06 0.18" rpy="-1.57 0 0"/>
        <axis xyz="0 0 1"/>
        <limit lower="-2.09" upper="2.09" effort="100" velocity="3.14"/>
      </joint>
      <link name="link5"/>
      
      <joint name="joint6" type="revolute">
        <parent link="link5"/>
        <child link="link6"/>
        <origin xyz="0 0 0.04" rpy="1.57 0 0"/>
        <axis xyz="0 0 1"/>
        <limit lower="-6.28" upper="6.28" effort="100" velocity="3.14"/>
      </joint>
      <link name="link6"/>
      
      <!-- ROS2 Control hardware interface -->
      <ros2_control name="doosan_m0609_hardware" type="system">
        <hardware>
          <plugin>doosan_m0609_hardware/DRHWInterface</plugin>
          <param name="host">192.168.1.100</param>
          <param name="rt_host">192.168.1.100</param>
          <param name="port">12345</param>
          <param name="mode">real</param>
          <param name="model">m0609</param>
        </hardware>
        
        <joint name="joint1">
          <command_interface name="position"/>
          <state_interface name="position"/>
          <state_interface name="velocity"/>
        </joint>
        <joint name="joint2">
          <command_interface name="position"/>
          <state_interface name="position"/>
          <state_interface name="velocity"/>
        </joint>
        <joint name="joint3">
          <command_interface name="position"/>
          <state_interface name="position"/>
          <state_interface name="velocity"/>
        </joint>
        <joint name="joint4">
          <command_interface name="position"/>
          <state_interface name="position"/>
          <state_interface name="velocity"/>
        </joint>
        <joint name="joint5">
          <command_interface name="position"/>
          <state_interface name="position"/>
          <state_interface name="velocity"/>
        </joint>
        <joint name="joint6">
          <command_interface name="position"/>
          <state_interface name="position"/>
          <state_interface name="velocity"/>
        </joint>
      </ros2_control>
    </robot>
    """
    
    # Robot state publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[
            {'robot_description': robot_description_content}
        ]
    )
    
    # Controller manager
    controller_manager = Node(
        package='controller_manager',
        executable='ros2_control_node',
        parameters=[config_file],
        output='both',
        remappings=[
            ('~/robot_description', '/robot_description'),
        ]
    )
    
    # Joint state broadcaster spawner
    joint_state_broadcaster_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster'],
        output='screen'
    )
    
    # Position controller spawner
    position_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['position_controller'],
        output='screen'
    )
    
    return LaunchDescription([
        robot_ip_arg,
        robot_state_publisher,
        controller_manager,
        joint_state_broadcaster_spawner,
        position_controller_spawner,
    ])