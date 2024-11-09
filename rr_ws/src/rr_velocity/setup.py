from setuptools import find_packages, setup

package_name = 'rr_velocity'

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
    maintainer='orin',
    maintainer_email='thetacobytes@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        'vel_raw_pub = rr_velocity.vel_raw_pub:main',
        'odom_pub = rr_velocity.odom_pub:main',

        ],
    },
)
