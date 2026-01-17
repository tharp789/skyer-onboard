#ifndef MISSION_DECODER__MISSION_CHUNK_HPP_
#define MISSION_DECODER__MISSION_CHUNK_HPP_

#include <cstdint>
#include <array>

namespace mission_decoder
{

// Custom MAVLink message ID
constexpr uint32_t MAVLINK_MSG_ID_MISSION_PACKAGE_CHUNK = 200;

// Camera action enum values
enum CameraAction : uint8_t
{
  CAMERA_ACTION_NONE = 0,
  CAMERA_ACTION_TRIGGER = 1,
  CAMERA_ACTION_START_VIDEO = 2,
  CAMERA_ACTION_STOP_VIDEO = 3
};

// Struct matching the MAVLink MISSION_PACKAGE_CHUNK message
struct __attribute__((packed)) MissionPackageChunk
{
  uint32_t mission_id;
  uint16_t total_waypoints;
  uint8_t total_chunks;
  uint8_t chunk_index;
  uint8_t num_in_chunk;
  std::array<float, 10> lat;
  std::array<float, 10> lon;
  std::array<float, 10> alt;
  std::array<uint8_t, 10> camera_action;
  std::array<uint8_t, 10> yaw_increment;
};

// Single waypoint structure for assembled mission
struct Waypoint
{
  float lat;
  float lon;
  float alt;
  uint8_t camera_action;
  uint8_t yaw_increment;
};

}  // namespace mission_decoder

#endif  // MISSION_DECODER__MISSION_CHUNK_HPP_
