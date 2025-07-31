from setuptools import find_packages
from setuptools import setup

setup(
    name='doosan_m0609_msgs',
    version='1.1.0',
    packages=find_packages(
        include=('doosan_m0609_msgs', 'doosan_m0609_msgs.*')),
)
