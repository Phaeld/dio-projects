from setuptools import setup, find_packages

setup(
    name='image_processor',
    version='0.1',
    packages=find_packages(),
    install_requires=[
        'Pillow',
        'numpy',
        'opencv-python'
    ],
    description='A Python image processing package for intermediate-level users',
    author='Raphael',
)
