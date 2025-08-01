from setuptools import find_packages, setup

package_name = 'arduino_loadcell_interface'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'pyserial'],
    zip_safe=True,
    maintainer='jaeho',
    maintainer_email='jack0682@github.com',
    description='Arduino HX711 LoadCell ROS2 Interface',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'loadcell_node = arduino_loadcell_interface.ros_node:main',
            'loadcell_test = arduino_loadcell_interface.interface:main',
        ],
    },
)
