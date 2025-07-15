from setuptools import setup

package_name = 'puddle_detection'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/detection.launch.py']),
        ('share/' + package_name + '/config', ['config/model_config.yaml']),
        ('share/' + package_name + '/models', ['models/best.pt']),
        ('share/' + package_name + '/resource', ['resource/' + package_name])
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jack',
    maintainer_email='jack@example.com',
    description='Puddle segmentation node using AGSENet',
    license='MIT',
    entry_points={
        'console_scripts': [
            'agsenet_node = puddle_detection.agsenet_node:main'
        ],
    },
)
