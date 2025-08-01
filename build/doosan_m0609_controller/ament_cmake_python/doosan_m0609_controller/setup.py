from setuptools import find_packages
from setuptools import setup

setup(
    name='doosan_m0609_controller',
    version='1.0.0',
    packages=find_packages(
        include=('doosan_m0609_controller', 'doosan_m0609_controller.*')),
)
