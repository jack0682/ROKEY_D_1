from setuptools import setup

package_name = 'puddle_viz'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/viz.launch.py']),
        ('share/' + package_name + '/config', ['config/marker_params.yaml']),
        ('share/' + package_name + '/resource', ['resource/' + package_name]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jack',
    maintainer_email='jack@example.com',
    description='Puddle marker visualizer using RViz and TF',
    license='MIT',
    entry_points={
        'console_scripts': [
            'viz_node = puddle_viz.viz_node:main'
        ],
    },
)
