#pragma once
// MESSAGE MISSION_CHUNK_ACK PACKING

#define MAVLINK_MSG_ID_MISSION_CHUNK_ACK 201


typedef struct __mavlink_mission_chunk_ack_t {
 uint32_t mission_id; /*<  Mission ID being acknowledged*/
 uint8_t chunk_id; /*<  Chunk index being acknowledged*/
 uint8_t result; /*<  Result code (see MISSION_CHUNK_RESULT enum)*/
 uint8_t chunks_received; /*<  Total chunks received so far for this mission*/
} mavlink_mission_chunk_ack_t;

#define MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN 7
#define MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN 7
#define MAVLINK_MSG_ID_201_LEN 7
#define MAVLINK_MSG_ID_201_MIN_LEN 7

#define MAVLINK_MSG_ID_MISSION_CHUNK_ACK_CRC 211
#define MAVLINK_MSG_ID_201_CRC 211



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_CHUNK_ACK { \
    201, \
    "MISSION_CHUNK_ACK", \
    4, \
    {  { "mission_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mission_chunk_ack_t, mission_id) }, \
         { "chunk_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mission_chunk_ack_t, chunk_id) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mission_chunk_ack_t, result) }, \
         { "chunks_received", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mission_chunk_ack_t, chunks_received) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_CHUNK_ACK { \
    "MISSION_CHUNK_ACK", \
    4, \
    {  { "mission_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mission_chunk_ack_t, mission_id) }, \
         { "chunk_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_mission_chunk_ack_t, chunk_id) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_mission_chunk_ack_t, result) }, \
         { "chunks_received", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_mission_chunk_ack_t, chunks_received) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_chunk_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mission_id  Mission ID being acknowledged
 * @param chunk_id  Chunk index being acknowledged
 * @param result  Result code (see MISSION_CHUNK_RESULT enum)
 * @param chunks_received  Total chunks received so far for this mission
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_chunk_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t mission_id, uint8_t chunk_id, uint8_t result, uint8_t chunks_received)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN];
    _mav_put_uint32_t(buf, 0, mission_id);
    _mav_put_uint8_t(buf, 4, chunk_id);
    _mav_put_uint8_t(buf, 5, result);
    _mav_put_uint8_t(buf, 6, chunks_received);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN);
#else
    mavlink_mission_chunk_ack_t packet;
    packet.mission_id = mission_id;
    packet.chunk_id = chunk_id;
    packet.result = result;
    packet.chunks_received = chunks_received;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_CHUNK_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_CRC);
}

/**
 * @brief Pack a mission_chunk_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param mission_id  Mission ID being acknowledged
 * @param chunk_id  Chunk index being acknowledged
 * @param result  Result code (see MISSION_CHUNK_RESULT enum)
 * @param chunks_received  Total chunks received so far for this mission
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_chunk_ack_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t mission_id, uint8_t chunk_id, uint8_t result, uint8_t chunks_received)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN];
    _mav_put_uint32_t(buf, 0, mission_id);
    _mav_put_uint8_t(buf, 4, chunk_id);
    _mav_put_uint8_t(buf, 5, result);
    _mav_put_uint8_t(buf, 6, chunks_received);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN);
#else
    mavlink_mission_chunk_ack_t packet;
    packet.mission_id = mission_id;
    packet.chunk_id = chunk_id;
    packet.result = result;
    packet.chunks_received = chunks_received;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_CHUNK_ACK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN);
#endif
}

/**
 * @brief Pack a mission_chunk_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_id  Mission ID being acknowledged
 * @param chunk_id  Chunk index being acknowledged
 * @param result  Result code (see MISSION_CHUNK_RESULT enum)
 * @param chunks_received  Total chunks received so far for this mission
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_chunk_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t mission_id,uint8_t chunk_id,uint8_t result,uint8_t chunks_received)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN];
    _mav_put_uint32_t(buf, 0, mission_id);
    _mav_put_uint8_t(buf, 4, chunk_id);
    _mav_put_uint8_t(buf, 5, result);
    _mav_put_uint8_t(buf, 6, chunks_received);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN);
#else
    mavlink_mission_chunk_ack_t packet;
    packet.mission_id = mission_id;
    packet.chunk_id = chunk_id;
    packet.result = result;
    packet.chunks_received = chunks_received;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_CHUNK_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_CRC);
}

/**
 * @brief Encode a mission_chunk_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_chunk_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_chunk_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_chunk_ack_t* mission_chunk_ack)
{
    return mavlink_msg_mission_chunk_ack_pack(system_id, component_id, msg, mission_chunk_ack->mission_id, mission_chunk_ack->chunk_id, mission_chunk_ack->result, mission_chunk_ack->chunks_received);
}

/**
 * @brief Encode a mission_chunk_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_chunk_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_chunk_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mission_chunk_ack_t* mission_chunk_ack)
{
    return mavlink_msg_mission_chunk_ack_pack_chan(system_id, component_id, chan, msg, mission_chunk_ack->mission_id, mission_chunk_ack->chunk_id, mission_chunk_ack->result, mission_chunk_ack->chunks_received);
}

/**
 * @brief Encode a mission_chunk_ack struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param mission_chunk_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_chunk_ack_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_mission_chunk_ack_t* mission_chunk_ack)
{
    return mavlink_msg_mission_chunk_ack_pack_status(system_id, component_id, _status, msg,  mission_chunk_ack->mission_id, mission_chunk_ack->chunk_id, mission_chunk_ack->result, mission_chunk_ack->chunks_received);
}

/**
 * @brief Send a mission_chunk_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param mission_id  Mission ID being acknowledged
 * @param chunk_id  Chunk index being acknowledged
 * @param result  Result code (see MISSION_CHUNK_RESULT enum)
 * @param chunks_received  Total chunks received so far for this mission
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mission_chunk_ack_send(mavlink_channel_t chan, uint32_t mission_id, uint8_t chunk_id, uint8_t result, uint8_t chunks_received)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN];
    _mav_put_uint32_t(buf, 0, mission_id);
    _mav_put_uint8_t(buf, 4, chunk_id);
    _mav_put_uint8_t(buf, 5, result);
    _mav_put_uint8_t(buf, 6, chunks_received);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_CHUNK_ACK, buf, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_CRC);
#else
    mavlink_mission_chunk_ack_t packet;
    packet.mission_id = mission_id;
    packet.chunk_id = chunk_id;
    packet.result = result;
    packet.chunks_received = chunks_received;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_CHUNK_ACK, (const char *)&packet, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_CRC);
#endif
}

/**
 * @brief Send a mission_chunk_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mission_chunk_ack_send_struct(mavlink_channel_t chan, const mavlink_mission_chunk_ack_t* mission_chunk_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mission_chunk_ack_send(chan, mission_chunk_ack->mission_id, mission_chunk_ack->chunk_id, mission_chunk_ack->result, mission_chunk_ack->chunks_received);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_CHUNK_ACK, (const char *)mission_chunk_ack, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mission_chunk_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t mission_id, uint8_t chunk_id, uint8_t result, uint8_t chunks_received)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, mission_id);
    _mav_put_uint8_t(buf, 4, chunk_id);
    _mav_put_uint8_t(buf, 5, result);
    _mav_put_uint8_t(buf, 6, chunks_received);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_CHUNK_ACK, buf, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_CRC);
#else
    mavlink_mission_chunk_ack_t *packet = (mavlink_mission_chunk_ack_t *)msgbuf;
    packet->mission_id = mission_id;
    packet->chunk_id = chunk_id;
    packet->result = result;
    packet->chunks_received = chunks_received;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_CHUNK_ACK, (const char *)packet, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE MISSION_CHUNK_ACK UNPACKING


/**
 * @brief Get field mission_id from mission_chunk_ack message
 *
 * @return  Mission ID being acknowledged
 */
static inline uint32_t mavlink_msg_mission_chunk_ack_get_mission_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field chunk_id from mission_chunk_ack message
 *
 * @return  Chunk index being acknowledged
 */
static inline uint8_t mavlink_msg_mission_chunk_ack_get_chunk_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field result from mission_chunk_ack message
 *
 * @return  Result code (see MISSION_CHUNK_RESULT enum)
 */
static inline uint8_t mavlink_msg_mission_chunk_ack_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field chunks_received from mission_chunk_ack message
 *
 * @return  Total chunks received so far for this mission
 */
static inline uint8_t mavlink_msg_mission_chunk_ack_get_chunks_received(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Decode a mission_chunk_ack message into a struct
 *
 * @param msg The message to decode
 * @param mission_chunk_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_chunk_ack_decode(const mavlink_message_t* msg, mavlink_mission_chunk_ack_t* mission_chunk_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mission_chunk_ack->mission_id = mavlink_msg_mission_chunk_ack_get_mission_id(msg);
    mission_chunk_ack->chunk_id = mavlink_msg_mission_chunk_ack_get_chunk_id(msg);
    mission_chunk_ack->result = mavlink_msg_mission_chunk_ack_get_result(msg);
    mission_chunk_ack->chunks_received = mavlink_msg_mission_chunk_ack_get_chunks_received(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN? msg->len : MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN;
        memset(mission_chunk_ack, 0, MAVLINK_MSG_ID_MISSION_CHUNK_ACK_LEN);
    memcpy(mission_chunk_ack, _MAV_PAYLOAD(msg), len);
#endif
}
