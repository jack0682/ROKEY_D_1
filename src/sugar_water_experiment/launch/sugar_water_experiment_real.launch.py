#!/usr/bin/env python3
"""
sugar_water_experiment_real.launch.py
실제 로봇을 사용한 설탕물 실험 런치 파일 (Doosan 공식 예제 방식)
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.conditions import IfCondition


def generate_launch_description():
    # Launch Arguments 선언
    arguments = [
        DeclareLaunchArgument(
            'robot_id',
            default_value='dsr01',
            description='로봇 ID (네임스페이스)'
        ),
        DeclareLaunchArgument(
            'robot_model', 
            default_value='m0609',
            description='로봇 모델'
        ),
        DeclareLaunchArgument(
            'robot_ip',
            default_value='192.168.1.100',
            description='로봇 IP 주소'
        ),
        DeclareLaunchArgument(
            'velocity',
            default_value='100',
            description='로봇 이동 속도'
        ),
        DeclareLaunchArgument(
            'acceleration', 
            default_value='100',
            description='로봇 가속도'
        ),
        DeclareLaunchArgument(
            'tool_name',
            default_value='Tool Weight_2FG',
            description='도구 이름'
        ),
        DeclareLaunchArgument(
            'tcp_name',
            default_value='2FG_TCP', 
            description='TCP 이름'
        ),
        DeclareLaunchArgument(
            'use_refactored',
            default_value='true',
            description='리팩토링된 노드 사용 여부 (true: 공식 예제 방식, false: 기존 방식)'
        )
    ]
    
    # 리팩토링된 실험 노드 (공식 예제 방식)
    refactored_experiment_node = Node(
        package='sugar_water_experiment',
        executable='sugar_water_experiment_refactored',
        name='sugar_water_experiment_refactored',
        namespace=LaunchConfiguration('robot_id'),
        parameters=[{
            'robot_id': LaunchConfiguration('robot_id'),
            'robot_model': LaunchConfiguration('robot_model'),
            'robot_ip': LaunchConfiguration('robot_ip'),
            'velocity': LaunchConfiguration('velocity'),
            'acceleration': LaunchConfiguration('acceleration'),
            'tool_name': LaunchConfiguration('tool_name'),
            'tcp_name': LaunchConfiguration('tcp_name')
        }],
        output='screen',
        condition=IfCondition(LaunchConfiguration('use_refactored'))
    )
    
    # 기존 실험 노드 (호환성용)
    legacy_experiment_node = Node(
        package='sugar_water_experiment',
        executable='simple_sequence_controller',
        name='simple_sequence_controller',
        namespace=LaunchConfiguration('robot_id'),
        output='screen',
        condition=IfCondition('false')  # 기본적으로 비활성화
    )
    
    # 시작 메시지
    start_message = LogInfo(
        msg=[
            '🚀 Doosan M0609 설탕물 실험 시작\n',
            '   로봇 ID: ', LaunchConfiguration('robot_id'), '\n',
            '   로봇 모델: ', LaunchConfiguration('robot_model'), '\n', 
            '   로봇 IP: ', LaunchConfiguration('robot_ip'), '\n',
            '   속도/가속도: ', LaunchConfiguration('velocity'), '/', LaunchConfiguration('acceleration'), '\n',
            '   도구: ', LaunchConfiguration('tool_name'), '\n',
            '   TCP: ', LaunchConfiguration('tcp_name'), '\n',
            '   방식: Doosan 공식 예제 기반 (DRFL 직접 호출)\n'
        ]
    )
    
    return LaunchDescription(
        arguments + [
            start_message,
            refactored_experiment_node,
            legacy_experiment_node
        ]
    )
