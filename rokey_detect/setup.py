from setuptools import find_packages, setup

package_name = 'rokey_detect'

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
    maintainer='jack',
    maintainer_email='jack0682@github.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'capture_image = rokey_pjt.1_tb4_capture_image:main',
            'cont_cap_image = rokey_pjt.2_tb4_cont_capture_image:main',
            'det_obj = rokey_detect.3_tb4_yolov8_obj_det:main',
            'det_obj_thread = rokey_detect.4_tb4_yolov8_obj_det_thread:main',
            'det_obj_track = rokey_detect.5_tb4_yolov8_obj_det_track:main',
        ],
    },
)
