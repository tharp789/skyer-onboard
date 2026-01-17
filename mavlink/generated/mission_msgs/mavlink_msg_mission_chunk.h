#pragma once
// MESSAGE MISSION_CHUNK PACKING

#define MAVLINK_MSG_ID_MISSION_CHUNK 200


typedef struct __mavlink_mission_chunk_t {
 uint32_t mission_id; /*<  Unique identifier for this mission (ties chunks together)*/
 float lat[18]; /*<  Latitude of waypoints in degrees*/
 float lon[18]; /*<  Longitude of waypoints in degrees*/
 float alt[18]; /*<  Altitude of waypoints in meters (AMSL)*/
 uint16_t total_waypoints; /*<  Total number of waypoints in the complete mission*/
 uint8_t total_chunks; /*<  Total number of chunks to expect for this mission*/
 uint8_t chunk_id; /*<  Index of this chunk (0-based)*/
 uint8_t num_in_chunk; /*<  Number of valid waypoints in this chunk (max 10)*/
 uint8_t camera_action[18]; /*<  Camera action at each waypoint (see CAMERA_ACTION enum)*/
} mavlink_mission_chunk_t;

#define MAVLINK_MSG_ID_MISSION_CHUNK_LEN 243
#define MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN 243
#define MAVLINK_MSG_ID_200_LEN 243
#define MAVLINK_MSG_ID_200_MIN_LEN 243

#define MAVLINK_MSG_ID_MISSION_CHUNK_CRC 40
#define MAVLINK_MSG_ID_200_CRC 40

#define MAVLINK_MSG_MISSION_CHUNK_FIELD_LAT_LEN 18
#define MAVLINK_MSG_MISSION_CHUNK_FIELD_LON_LEN 18
#define MAVLINK_MSG_MISSION_CHUNK_FIELD_ALT_LEN 18
#define MAVLINK_MSG_MISSION_CHUNK_FIELD_CAMERA_ACTION_LEN 18

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_CHUNK { \
    200, \
    "MISSION_CHUNK", \
    9, \
    {  { "mission_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mission_chunk_t, mission_id) }, \
         { "total_waypoints", NULL, MAVLINK_TYPE_UINT16_T, 0, 220, offsetof(mavlink_mission_chunk_t, total_waypoints) }, \
         { "total_chunks", NULL, MAVLINK_TYPE_UINT8_T, 0, 222, offsetof(mavlink_mission_chunk_t, total_chunks) }, \
         { "chunk_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 223, offsetof(mavlink_mission_chunk_t, chunk_id) }, \
         { "num_in_chunk", NULL, MAVLINK_TYPE_UINT8_T, 0, 224, offsetof(mavlink_mission_chunk_t, num_in_chunk) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 18, 4, offsetof(mavlink_mission_chunk_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 18, 76, offsetof(mavlink_mission_chunk_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 18, 148, offsetof(mavlink_mission_chunk_t, alt) }, \
         { "camera_action", NULL, MAVLINK_TYPE_UINT8_T, 18, 225, offsetof(mavlink_mission_chunk_t, camera_action) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_CHUNK { \
    "MISSION_CHUNK", \
    9, \
    {  { "mission_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mission_chunk_t, mission_id) }, \
         { "total_waypoints", NULL, MAVLINK_TYPE_UINT16_T, 0, 220, offsetof(mavlink_mission_chunk_t, total_waypoints) }, \
         { "total_chunks", NULL, MAVLINK_TYPE_UINT8_T, 0, 222, offsetof(mavlink_mission_chunk_t, total_chunks) }, \
         { "chunk_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 223, offsetof(mavlink_mission_chunk_t, chunk_id) }, \
         { "num_in_chunk", NULL, MAVLINK_TYPE_UINT8_T, 0, 224, offsetof(mavlink_mission_chunk_t, num_in_chunk) }, \
         { "lat", NULL, MAVLINK_TYPE_FLOAT, 18, 4, offsetof(mavlink_mission_chunk_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_FLOAT, 18, 76, offsetof(mavlink_mission_chunk_t, lon) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 18, 148, offsetof(mavlink_mission_chunk_t, alt) }, \
         { "camera_action", NULL, MAVLINK_TYPE_UINT8_T, 18, 225, offsetof(mavlink_mission_chunk_t, camera_action) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_chunk message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mission_id  Unique identifier for this mission (ties chunks together)
 * @param total_waypoints  Total number of waypoints in the complete mission
 * @param total_chunks  Total number of chunks to expect for this mission
 * @param chunk_id  Index of this chunk (0-based)
 * @param num_in_chunk  Number of valid waypoints in this chunk (max 10)
 * @param lat  Latitude of waypoints in degrees
 * @param lon  Longitude of waypoints in degrees
 * @param alt  Altitude of waypoints in meters (AMSL)
 * @param camera_action  Camera action at each waypoint (see CAMERA_ACTION enum)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_chunk_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t mission_id, uint16_t total_waypoints, uint8_t total_chunks, uint8_t chunk_id, uint8_t num_in_chunk, const float *lat, const float *lon, const float *alt, const uint8_t *camera_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_CHUNK_LEN];
    _mav_put_uint32_t(buf, 0, mission_id);
    _mav_put_uint16_t(buf, 220, total_waypoints);
    _mav_put_uint8_t(buf, 222, total_chunks);
    _mav_put_uint8_t(buf, 223, chunk_id);
    _mav_put_uint8_t(buf, 224, num_in_chunk);
    _mav_put_float_array(buf, 4, lat, 18);
    _mav_put_float_array(buf, 76, lon, 18);
    _mav_put_float_array(buf, 148, alt, 18);
    _mav_put_uint8_t_array(buf, 225, camera_action, 18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_CHUNK_LEN);
#else
    mavlink_mission_chunk_t packet;
    packet.mission_id = mission_id;
    packet.total_waypoints = total_waypoints;
    packet.total_chunks = total_chunks;
    packet.chunk_id = chunk_id;
    packet.num_in_chunk = num_in_chunk;
    mav_array_assign_float(packet.lat, lat, 18);
    mav_array_assign_float(packet.lon, lon, 18);
    mav_array_assign_float(packet.alt, alt, 18);
    mav_array_assign_uint8_t(packet.camera_action, camera_action, 18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_CHUNK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_CHUNK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_CRC);
}

/**
 * @brief Pack a mission_chunk message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param mission_id  Unique identifier for this mission (ties chunks together)
 * @param total_waypoints  Total number of waypoints in the complete mission
 * @param total_chunks  Total number of chunks to expect for this mission
 * @param chunk_id  Index of this chunk (0-based)
 * @param num_in_chunk  Number of valid waypoints in this chunk (max 10)
 * @param lat  Latitude of waypoints in degrees
 * @param lon  Longitude of waypoints in degrees
 * @param alt  Altitude of waypoints in meters (AMSL)
 * @param camera_action  Camera action at each waypoint (see CAMERA_ACTION enum)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_chunk_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t mission_id, uint16_t total_waypoints, uint8_t total_chunks, uint8_t chunk_id, uint8_t num_in_chunk, const float *lat, const float *lon, const float *alt, const uint8_t *camera_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_CHUNK_LEN];
    _mav_put_uint32_t(buf, 0, mission_id);
    _mav_put_uint16_t(buf, 220, total_waypoints);
    _mav_put_uint8_t(buf, 222, total_chunks);
    _mav_put_uint8_t(buf, 223, chunk_id);
    _mav_put_uint8_t(buf, 224, num_in_chunk);
    _mav_put_float_array(buf, 4, lat, 18);
    _mav_put_float_array(buf, 76, lon, 18);
    _mav_put_float_array(buf, 148, alt, 18);
    _mav_put_uint8_t_array(buf, 225, camera_action, 18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_CHUNK_LEN);
#else
    mavlink_mission_chunk_t packet;
    packet.mission_id = mission_id;
    packet.total_waypoints = total_waypoints;
    packet.total_chunks = total_chunks;
    packet.chunk_id = chunk_id;
    packet.num_in_chunk = num_in_chunk;
    mav_array_memcpy(packet.lat, lat, sizeof(float)*18);
    mav_array_memcpy(packet.lon, lon, sizeof(float)*18);
    mav_array_memcpy(packet.alt, alt, sizeof(float)*18);
    mav_array_memcpy(packet.camera_action, camera_action, sizeof(uint8_t)*18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_CHUNK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_CHUNK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_LEN);
#endif
}

/**
 * @brief Pack a mission_chunk message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_id  Unique identifier for this mission (ties chunks together)
 * @param total_waypoints  Total number of waypoints in the complete mission
 * @param total_chunks  Total number of chunks to expect for this mission
 * @param chunk_id  Index of this chunk (0-based)
 * @param num_in_chunk  Number of valid waypoints in this chunk (max 10)
 * @param lat  Latitude of waypoints in degrees
 * @param lon  Longitude of waypoints in degrees
 * @param alt  Altitude of waypoints in meters (AMSL)
 * @param camera_action  Camera action at each waypoint (see CAMERA_ACTION enum)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_chunk_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t mission_id,uint16_t total_waypoints,uint8_t total_chunks,uint8_t chunk_id,uint8_t num_in_chunk,const float *lat,const float *lon,const float *alt,const uint8_t *camera_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_CHUNK_LEN];
    _mav_put_uint32_t(buf, 0, mission_id);
    _mav_put_uint16_t(buf, 220, total_waypoints);
    _mav_put_uint8_t(buf, 222, total_chunks);
    _mav_put_uint8_t(buf, 223, chunk_id);
    _mav_put_uint8_t(buf, 224, num_in_chunk);
    _mav_put_float_array(buf, 4, lat, 18);
    _mav_put_float_array(buf, 76, lon, 18);
    _mav_put_float_array(buf, 148, alt, 18);
    _mav_put_uint8_t_array(buf, 225, camera_action, 18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_CHUNK_LEN);
#else
    mavlink_mission_chunk_t packet;
    packet.mission_id = mission_id;
    packet.total_waypoints = total_waypoints;
    packet.total_chunks = total_chunks;
    packet.chunk_id = chunk_id;
    packet.num_in_chunk = num_in_chunk;
    mav_array_assign_float(packet.lat, lat, 18);
    mav_array_assign_float(packet.lon, lon, 18);
    mav_array_assign_float(packet.alt, alt, 18);
    mav_array_assign_uint8_t(packet.camera_action, camera_action, 18);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_CHUNK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_CHUNK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_CRC);
}

/**
 * @brief Encode a mission_chunk struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_chunk C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_chunk_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_chunk_t* mission_chunk)
{
    return mavlink_msg_mission_chunk_pack(system_id, component_id, msg, mission_chunk->mission_id, mission_chunk->total_waypoints, mission_chunk->total_chunks, mission_chunk->chunk_id, mission_chunk->num_in_chunk, mission_chunk->lat, mission_chunk->lon, mission_chunk->alt, mission_chunk->camera_action);
}

/**
 * @brief Encode a mission_chunk struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_chunk C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_chunk_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mission_chunk_t* mission_chunk)
{
    return mavlink_msg_mission_chunk_pack_chan(system_id, component_id, chan, msg, mission_chunk->mission_id, mission_chunk->total_waypoints, mission_chunk->total_chunks, mission_chunk->chunk_id, mission_chunk->num_in_chunk, mission_chunk->lat, mission_chunk->lon, mission_chunk->alt, mission_chunk->camera_action);
}

/**
 * @brief Encode a mission_chunk struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param mission_chunk C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_chunk_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_mission_chunk_t* mission_chunk)
{
    return mavlink_msg_mission_chunk_pack_status(system_id, component_id, _status, msg,  mission_chunk->mission_id, mission_chunk->total_waypoints, mission_chunk->total_chunks, mission_chunk->chunk_id, mission_chunk->num_in_chunk, mission_chunk->lat, mission_chunk->lon, mission_chunk->alt, mission_chunk->camera_action);
}

/**
 * @brief Send a mission_chunk message
 * @param chan MAVLink channel to send the message
 *
 * @param mission_id  Unique identifier for this mission (ties chunks together)
 * @param total_waypoints  Total number of waypoints in the complete mission
 * @param total_chunks  Total number of chunks to expect for this mission
 * @param chunk_id  Index of this chunk (0-based)
 * @param num_in_chunk  Number of valid waypoints in this chunk (max 10)
 * @param lat  Latitude of waypoints in degrees
 * @param lon  Longitude of waypoints in degrees
 * @param alt  Altitude of waypoints in meters (AMSL)
 * @param camera_action  Camera action at each waypoint (see CAMERA_ACTION enum)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mission_chunk_send(mavlink_channel_t chan, uint32_t mission_id, uint16_t total_waypoints, uint8_t total_chunks, uint8_t chunk_id, uint8_t num_in_chunk, const float *lat, const float *lon, const float *alt, const uint8_t *camera_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_CHUNK_LEN];
    _mav_put_uint32_t(buf, 0, mission_id);
    _mav_put_uint16_t(buf, 220, total_waypoints);
    _mav_put_uint8_t(buf, 222, total_chunks);
    _mav_put_uint8_t(buf, 223, chunk_id);
    _mav_put_uint8_t(buf, 224, num_in_chunk);
    _mav_put_float_array(buf, 4, lat, 18);
    _mav_put_float_array(buf, 76, lon, 18);
    _mav_put_float_array(buf, 148, alt, 18);
    _mav_put_uint8_t_array(buf, 225, camera_action, 18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_CHUNK, buf, MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_CRC);
#else
    mavlink_mission_chunk_t packet;
    packet.mission_id = mission_id;
    packet.total_waypoints = total_waypoints;
    packet.total_chunks = total_chunks;
    packet.chunk_id = chunk_id;
    packet.num_in_chunk = num_in_chunk;
    mav_array_assign_float(packet.lat, lat, 18);
    mav_array_assign_float(packet.lon, lon, 18);
    mav_array_assign_float(packet.alt, alt, 18);
    mav_array_assign_uint8_t(packet.camera_action, camera_action, 18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_CHUNK, (const char *)&packet, MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_CRC);
#endif
}

/**
 * @brief Send a mission_chunk message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mission_chunk_send_struct(mavlink_channel_t chan, const mavlink_mission_chunk_t* mission_chunk)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mission_chunk_send(chan, mission_chunk->mission_id, mission_chunk->total_waypoints, mission_chunk->total_chunks, mission_chunk->chunk_id, mission_chunk->num_in_chunk, mission_chunk->lat, mission_chunk->lon, mission_chunk->alt, mission_chunk->camera_action);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_CHUNK, (const char *)mission_chunk, MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_CRC);
#endif
}

#if MAVLINK_MSG_ID_MISSION_CHUNK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mission_chunk_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t mission_id, uint16_t total_waypoints, uint8_t total_chunks, uint8_t chunk_id, uint8_t num_in_chunk, const float *lat, const float *lon, const float *alt, const uint8_t *camera_action)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, mission_id);
    _mav_put_uint16_t(buf, 220, total_waypoints);
    _mav_put_uint8_t(buf, 222, total_chunks);
    _mav_put_uint8_t(buf, 223, chunk_id);
    _mav_put_uint8_t(buf, 224, num_in_chunk);
    _mav_put_float_array(buf, 4, lat, 18);
    _mav_put_float_array(buf, 76, lon, 18);
    _mav_put_float_array(buf, 148, alt, 18);
    _mav_put_uint8_t_array(buf, 225, camera_action, 18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_CHUNK, buf, MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_CRC);
#else
    mavlink_mission_chunk_t *packet = (mavlink_mission_chunk_t *)msgbuf;
    packet->mission_id = mission_id;
    packet->total_waypoints = total_waypoints;
    packet->total_chunks = total_chunks;
    packet->chunk_id = chunk_id;
    packet->num_in_chunk = num_in_chunk;
    mav_array_assign_float(packet->lat, lat, 18);
    mav_array_assign_float(packet->lon, lon, 18);
    mav_array_assign_float(packet->alt, alt, 18);
    mav_array_assign_uint8_t(packet->camera_action, camera_action, 18);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_CHUNK, (const char *)packet, MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_CRC);
#endif
}
#endif

#endif

// MESSAGE MISSION_CHUNK UNPACKING


/**
 * @brief Get field mission_id from mission_chunk message
 *
 * @return  Unique identifier for this mission (ties chunks together)
 */
static inline uint32_t mavlink_msg_mission_chunk_get_mission_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field total_waypoints from mission_chunk message
 *
 * @return  Total number of waypoints in the complete mission
 */
static inline uint16_t mavlink_msg_mission_chunk_get_total_waypoints(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  220);
}

/**
 * @brief Get field total_chunks from mission_chunk message
 *
 * @return  Total number of chunks to expect for this mission
 */
static inline uint8_t mavlink_msg_mission_chunk_get_total_chunks(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  222);
}

/**
 * @brief Get field chunk_id from mission_chunk message
 *
 * @return  Index of this chunk (0-based)
 */
static inline uint8_t mavlink_msg_mission_chunk_get_chunk_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  223);
}

/**
 * @brief Get field num_in_chunk from mission_chunk message
 *
 * @return  Number of valid waypoints in this chunk (max 10)
 */
static inline uint8_t mavlink_msg_mission_chunk_get_num_in_chunk(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  224);
}

/**
 * @brief Get field lat from mission_chunk message
 *
 * @return  Latitude of waypoints in degrees
 */
static inline uint16_t mavlink_msg_mission_chunk_get_lat(const mavlink_message_t* msg, float *lat)
{
    return _MAV_RETURN_float_array(msg, lat, 18,  4);
}

/**
 * @brief Get field lon from mission_chunk message
 *
 * @return  Longitude of waypoints in degrees
 */
static inline uint16_t mavlink_msg_mission_chunk_get_lon(const mavlink_message_t* msg, float *lon)
{
    return _MAV_RETURN_float_array(msg, lon, 18,  76);
}

/**
 * @brief Get field alt from mission_chunk message
 *
 * @return  Altitude of waypoints in meters (AMSL)
 */
static inline uint16_t mavlink_msg_mission_chunk_get_alt(const mavlink_message_t* msg, float *alt)
{
    return _MAV_RETURN_float_array(msg, alt, 18,  148);
}

/**
 * @brief Get field camera_action from mission_chunk message
 *
 * @return  Camera action at each waypoint (see CAMERA_ACTION enum)
 */
static inline uint16_t mavlink_msg_mission_chunk_get_camera_action(const mavlink_message_t* msg, uint8_t *camera_action)
{
    return _MAV_RETURN_uint8_t_array(msg, camera_action, 18,  225);
}

/**
 * @brief Decode a mission_chunk message into a struct
 *
 * @param msg The message to decode
 * @param mission_chunk C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_chunk_decode(const mavlink_message_t* msg, mavlink_mission_chunk_t* mission_chunk)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mission_chunk->mission_id = mavlink_msg_mission_chunk_get_mission_id(msg);
    mavlink_msg_mission_chunk_get_lat(msg, mission_chunk->lat);
    mavlink_msg_mission_chunk_get_lon(msg, mission_chunk->lon);
    mavlink_msg_mission_chunk_get_alt(msg, mission_chunk->alt);
    mission_chunk->total_waypoints = mavlink_msg_mission_chunk_get_total_waypoints(msg);
    mission_chunk->total_chunks = mavlink_msg_mission_chunk_get_total_chunks(msg);
    mission_chunk->chunk_id = mavlink_msg_mission_chunk_get_chunk_id(msg);
    mission_chunk->num_in_chunk = mavlink_msg_mission_chunk_get_num_in_chunk(msg);
    mavlink_msg_mission_chunk_get_camera_action(msg, mission_chunk->camera_action);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MISSION_CHUNK_LEN? msg->len : MAVLINK_MSG_ID_MISSION_CHUNK_LEN;
        memset(mission_chunk, 0, MAVLINK_MSG_ID_MISSION_CHUNK_LEN);
    memcpy(mission_chunk, _MAV_PAYLOAD(msg), len);
#endif
}
