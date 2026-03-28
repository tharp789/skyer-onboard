#!/bin/bash
set -e

source /root/dependencies_ws/install/setup.bash
source /root/ros2_ws/install/setup.bash
export ROS_DOMAIN_ID=68
ros2 launch system_bringup bringup.launch.py