from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'chunk_timeout_sec',
            default_value='10.0',
            description='Timeout in seconds for incomplete mission chunks'
        ),
        
        Node(
            package='mission_decoder',
            executable='mission_decoder_node',
            name='mission_decoder',
            output='screen',
            parameters=[{
                'chunk_timeout_sec': LaunchConfiguration('chunk_timeout_sec'),
            }],
            remappings=[
                ('/mavlink/from', '/mavlink/from'),
            ],
        ),
    ])
