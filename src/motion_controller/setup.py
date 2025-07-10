from setuptools import setup

package_name = 'motion_controller'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jack',
    maintainer_email='jack@example.com',
    description='Velocity control and goal-based navigation for TurtleBot4',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'goal_sender = motion_controller.goal_sender:main',
            'velocity_controller = motion_controller.velocity_controller:main',
        ],
    },
)
