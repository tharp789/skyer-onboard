#include <rclcpp/rclcpp.hpp>
#include <mavros_msgs/msg/mavlink.hpp>
#include <wire_interfaces/msg/mission.hpp>

#include "mission_decoder/mission_chunk.hpp"

#include <map>
#include <vector>
#include <set>
#include <cstring>

namespace mission_decoder
{

class MissionDecoderNode : public rclcpp::Node
{
public:
  MissionDecoderNode()
  : Node("mission_decoder")
  {
    this->declare_parameter("chunk_timeout_sec", 10.0);
    chunk_timeout_ = this->get_parameter("chunk_timeout_sec").as_double();

    mavlink_sub_ = this->create_subscription<mavros_msgs::msg::Mavlink>(
      "/mavlink/from",
      rclcpp::SensorDataQoS(),
      std::bind(&MissionDecoderNode::mavlink_callback, this, std::placeholders::_1));

    // Publisher for decoded complete missions
    mission_pub_ = this->create_publisher<wire_interfaces::msg::Mission>(
      "~/mission",
      10);

    // Timer to check for stale incomplete missions
    cleanup_timer_ = this->create_wall_timer(
      std::chrono::seconds(5),
      std::bind(&MissionDecoderNode::cleanup_stale_missions, this));

    RCLCPP_INFO(this->get_logger(), "Mission decoder node started");
    RCLCPP_INFO(this->get_logger(), "Listening for MISSION_PACKAGE_CHUNK (ID %d) on /mavlink/from",
      MAVLINK_MSG_ID_MISSION_PACKAGE_CHUNK);
  }

private:
  struct MissionAssembly
  {
    uint32_t mission_id;
    uint16_t total_waypoints;
    uint8_t total_chunks;
    std::set<uint8_t> received_chunks;
    std::vector<Waypoint> waypoints;
    rclcpp::Time last_update;
  };

  void mavlink_callback(const mavros_msgs::msg::Mavlink::SharedPtr msg)
  {
    // Check if this is our custom message
    if (msg->msgid != MAVLINK_MSG_ID_MISSION_PACKAGE_CHUNK) {
      return;
    }

    RCLCPP_DEBUG(this->get_logger(), "Received MISSION_PACKAGE_CHUNK message");

    // Decode the payload
    MissionPackageChunk chunk;
    if (!decode_chunk(msg, chunk)) {
      RCLCPP_WARN(this->get_logger(), "Failed to decode mission chunk");
      return;
    }

    // Process the chunk
    process_chunk(chunk);
  }

  bool decode_chunk(const mavros_msgs::msg::Mavlink::SharedPtr& msg, MissionPackageChunk& chunk)
  {
    // MAVLink payload is stored in payload64 as uint64_t array
    // We need to reconstruct the byte stream
    std::vector<uint8_t> payload;
    payload.reserve(msg->payload64.size() * 8);

    for (const auto& val : msg->payload64) {
      for (int i = 0; i < 8; ++i) {
        payload.push_back(static_cast<uint8_t>((val >> (i * 8)) & 0xFF));
      }
    }

    // Check payload size
    constexpr size_t expected_size = sizeof(MissionPackageChunk);
    if (payload.size() < expected_size) {
      RCLCPP_WARN(this->get_logger(), 
        "Payload too small: got %zu bytes, expected %zu", 
        payload.size(), expected_size);
      return false;
    }

    // Copy payload to struct
    std::memcpy(&chunk, payload.data(), expected_size);

    RCLCPP_DEBUG(this->get_logger(),
      "Decoded chunk: mission_id=%u, chunk=%u/%u, waypoints_in_chunk=%u",
      chunk.mission_id, chunk.chunk_index + 1, chunk.total_chunks, chunk.num_in_chunk);

    return true;
  }

  void process_chunk(const MissionPackageChunk& chunk)
  {
    auto& assembly = missions_[chunk.mission_id];
    
    // Initialize if this is a new mission
    if (assembly.waypoints.empty()) {
      assembly.mission_id = chunk.mission_id;
      assembly.total_waypoints = chunk.total_waypoints;
      assembly.total_chunks = chunk.total_chunks;
      assembly.waypoints.resize(chunk.total_waypoints);
      
      RCLCPP_INFO(this->get_logger(),
        "Started receiving mission %u: %u waypoints in %u chunks",
        chunk.mission_id, chunk.total_waypoints, chunk.total_chunks);
    }

    // Validate chunk belongs to this mission
    if (chunk.total_waypoints != assembly.total_waypoints ||
        chunk.total_chunks != assembly.total_chunks) {
      RCLCPP_WARN(this->get_logger(),
        "Chunk metadata mismatch for mission %u, ignoring", chunk.mission_id);
      return;
    }

    // Check for duplicate chunk
    if (assembly.received_chunks.count(chunk.chunk_index) > 0) {
      RCLCPP_DEBUG(this->get_logger(),
        "Duplicate chunk %u for mission %u, updating", chunk.chunk_index, chunk.mission_id);
    }

    // Calculate starting waypoint index for this chunk
    size_t start_idx = chunk.chunk_index * 10;

    // Extract waypoints from chunk
    for (uint8_t i = 0; i < chunk.num_in_chunk; ++i) {
      size_t wp_idx = start_idx + i;
      if (wp_idx >= assembly.waypoints.size()) {
        RCLCPP_WARN(this->get_logger(), "Waypoint index out of bounds: %zu", wp_idx);
        break;
      }

      assembly.waypoints[wp_idx] = Waypoint{
        .lat = chunk.lat[i],
        .lon = chunk.lon[i],
        .alt = chunk.alt[i],
        .camera_action = chunk.camera_action[i],
        .yaw_increment = chunk.yaw_increment[i]
      };
    }

    assembly.received_chunks.insert(chunk.chunk_index);
    assembly.last_update = this->now();

    RCLCPP_INFO(this->get_logger(),
      "Mission %u: received chunk %u/%u (%zu/%u chunks total)",
      chunk.mission_id, 
      chunk.chunk_index + 1, 
      chunk.total_chunks,
      assembly.received_chunks.size(),
      chunk.total_chunks);

    // Check if mission is complete
    if (assembly.received_chunks.size() == assembly.total_chunks) {
      publish_complete_mission(assembly);
      missions_.erase(chunk.mission_id);
    }
  }

  void publish_complete_mission(const MissionAssembly& assembly)
  {
    RCLCPP_INFO(this->get_logger(),
      "Mission %u complete! Publishing %u waypoints",
      assembly.mission_id, assembly.total_waypoints);

    // Create mission message with all waypoints
    wire_interfaces::msg::Mission msg;
    msg.mission_id = assembly.mission_id;
    msg.num_waypoints = assembly.total_waypoints;

    // Resize arrays to hold all waypoints
    msg.lat.resize(assembly.waypoints.size());
    msg.lon.resize(assembly.waypoints.size());
    msg.alt.resize(assembly.waypoints.size());
    msg.camera_action.resize(assembly.waypoints.size());
    msg.yaw_increment.resize(assembly.waypoints.size());

    // Copy all waypoints
    for (size_t i = 0; i < assembly.waypoints.size(); ++i) {
      msg.lat[i] = static_cast<double>(assembly.waypoints[i].lat);
      msg.lon[i] = static_cast<double>(assembly.waypoints[i].lon);
      msg.alt[i] = assembly.waypoints[i].alt;
      msg.camera_action[i] = assembly.waypoints[i].camera_action;
      msg.yaw_increment[i] = assembly.waypoints[i].yaw_increment;
    }

    mission_pub_->publish(msg);

    // Log all waypoints
    for (size_t i = 0; i < assembly.waypoints.size(); ++i) {
      const auto& wp = assembly.waypoints[i];
      RCLCPP_INFO(this->get_logger(),
        "  WP[%zu]: lat=%.6f, lon=%.6f, alt=%.1f, cam=%u, yaw=%u",
        i, wp.lat, wp.lon, wp.alt, wp.camera_action, wp.yaw_increment);
    }
  }

  void cleanup_stale_missions()
  {
    auto now = this->now();
    std::vector<uint32_t> to_remove;

    for (const auto& [mission_id, assembly] : missions_) {
      double age = (now - assembly.last_update).seconds();
      if (age > chunk_timeout_) {
        RCLCPP_WARN(this->get_logger(),
          "Mission %u timed out after %.1fs with %zu/%u chunks received",
          mission_id, age, assembly.received_chunks.size(), assembly.total_chunks);
        to_remove.push_back(mission_id);
      }
    }

    for (auto id : to_remove) {
      missions_.erase(id);
    }
  }

  // Subscribers and publishers
  rclcpp::Subscription<mavros_msgs::msg::Mavlink>::SharedPtr mavlink_sub_;
  rclcpp::Publisher<wire_interfaces::msg::Mission>::SharedPtr mission_pub_;
  rclcpp::TimerBase::SharedPtr cleanup_timer_;

  // Mission assembly state
  std::map<uint32_t, MissionAssembly> missions_;
  
  // Parameters
  double chunk_timeout_;
};

}  // namespace mission_decoder

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<mission_decoder::MissionDecoderNode>());
  rclcpp::shutdown();
  return 0;
}
