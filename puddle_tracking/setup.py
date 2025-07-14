from setuptools import setup

package_name = 'puddle_tracking'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/tracking.launch.py']),
        ('share/' + package_name + '/config', ['config/tracker_params.yaml']),
        ('share/' + package_name + '/resource', ['resource/' + package_name]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jack',
    maintainer_email='jack@example.com',
    description='Puddle identity tracker based on shape and topology',
    license='MIT',
    entry_points={
        'console_scripts': [
            'tracker_node = puddle_tracking.tracker_node:main'
        ],
    },
)
