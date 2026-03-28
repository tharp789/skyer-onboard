/** @file
 *  @brief MAVLink comm protocol generated from mission_msgs.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_MISSION_MSGS_H
#define MAVLINK_MISSION_MSGS_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_MISSION_MSGS.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_MISSION_MSGS_XML_HASH -8575196737014271754

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{200, 40, 243, 243, 0, 0, 0}, {201, 211, 7, 7, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_MISSION_MSGS

// ENUM DEFINITIONS


/** @brief Camera actions for mission waypoints */
#ifndef HAVE_ENUM_CAMERA_ACTION
#define HAVE_ENUM_CAMERA_ACTION
typedef enum CAMERA_ACTION
{
   CAMERA_ACTION_NONE=0, /* No camera action | */
   CAMERA_ACTION_CAPTURE=1, /* Trigger camera capture | */
   CAMERA_ACTION_START_VIDEO=2, /* Start video recording | */
   CAMERA_ACTION_STOP_VIDEO=3, /* Stop video recording | */
   PANORAMA_CAPTURE=4, /* Capture a panorama at point | */
   CAMERA_ACTION_ENUM_END=5, /*  | */
} CAMERA_ACTION;
#endif

/** @brief Result codes for mission chunk acknowledgment */
#ifndef HAVE_ENUM_MISSION_CHUNK_RESULT
#define HAVE_ENUM_MISSION_CHUNK_RESULT
typedef enum MISSION_CHUNK_RESULT
{
   MISSION_CHUNK_ACCEPTED=0, /* Chunk accepted successfully | */
   MISSION_CHUNK_ERROR=1, /* Generic error | */
   MISSION_CHUNK_OUT_OF_ORDER=2, /* Chunk received out of expected order | */
   MISSION_CHUNK_INVALID_ID=3, /* Mission ID mismatch during transfer | */
   MISSION_CHUNK_RESULT_ENUM_END=4, /*  | */
} MISSION_CHUNK_RESULT;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 1
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 1
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_mission_chunk.h"
#include "./mavlink_msg_mission_chunk_ack.h"

// base include



#if MAVLINK_MISSION_MSGS_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_MISSION_CHUNK, MAVLINK_MESSAGE_INFO_MISSION_CHUNK_ACK}
# define MAVLINK_MESSAGE_NAMES {{ "MISSION_CHUNK", 200 }, { "MISSION_CHUNK_ACK", 201 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_MISSION_MSGS_H
