from setuptools import find_packages, setup

package_name = 'chemistry_experiment_manager'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jaeho',
    maintainer_email='jack0682@github.com',
    description='Chemical Experiment Automation Manager',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'experiment_coordinator = chemistry_experiment_manager.main:main',
            'experiment_runner = chemistry_experiment_manager.experiment_runner:main',
        ],
    },
)
