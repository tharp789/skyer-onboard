from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PythonExpression, EnvironmentVariable
from launch_xml.launch_description_sources import XMLLaunchDescriptionSource
from launch.conditions import IfCondition


def generate_launch_description():
        
    system_launch = LaunchDescription([
        # MAVROS real Node (launch if MAVROS is set and SIMULATION is false)
        IncludeLaunchDescription(
            XMLLaunchDescriptionSource([FindPackageShare('mavros'), '/launch/px4.launch']),
            launch_arguments={'fcu_url': '/dev/ttyUSB0'}.items()
        ),
        # Rosbag recording process
        Node(
            package='bag_recorder',
            executable='bag_record_node',
            name='bag_recorder',
            parameters=[
                {'cfg_path': FindPackageShare('bag_recorder').find('bag_recorder') + '/config/record_topics.yaml'},
                {'output_dir': '/root/data_collection/'},
                {'mcap_qos_dir': FindPackageShare('bag_recorder').find('bag_recorder') + '/config'}
            ],
            output='screen',
            condition=IfCondition(PythonExpression(['"', EnvironmentVariable('RECORD'), '" == "1"']))
        ),
    ])

    return system_launch
