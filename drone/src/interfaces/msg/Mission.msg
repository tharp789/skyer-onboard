# Complete assembled mission after all chunks received
# This message contains ALL waypoints (not chunked)

uint32 mission_id                    # Unique mission identifier
uint16 num_waypoints                 # Total number of waypoints

float64[] lat                        # Latitude of each waypoint (degrees)
float64[] lon                        # Longitude of each waypoint (degrees)
float32[] alt                        # Altitude of each waypoint (meters AMSL)
uint8[] camera_action                # Camera action at each waypoint
uint8[] yaw_increment                # Yaw increment at each waypoint (degrees)

# Camera action constants
uint8 CAMERA_ACTION_NONE=0
uint8 CAMERA_ACTION_TRIGGER=1
uint8 CAMERA_ACTION_START_VIDEO=2
uint8 CAMERA_ACTION_STOP_VIDEO=3
