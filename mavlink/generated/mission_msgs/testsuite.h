/** @file
 *    @brief MAVLink comm protocol testsuite generated from mission_msgs.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef MISSION_MSGS_TESTSUITE_H
#define MISSION_MSGS_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_mission_msgs(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_mission_msgs(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_mission_chunk(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MISSION_CHUNK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mission_chunk_t packet_in = {
        963497464,{ 45.0, 46.0, 47.0, 48.0, 49.0, 50.0, 51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0, 59.0, 60.0, 61.0, 62.0 },{ 549.0, 550.0, 551.0, 552.0, 553.0, 554.0, 555.0, 556.0, 557.0, 558.0, 559.0, 560.0, 561.0, 562.0, 563.0, 564.0, 565.0, 566.0 },{ 1053.0, 1054.0, 1055.0, 1056.0, 1057.0, 1058.0, 1059.0, 1060.0, 1061.0, 1062.0, 1063.0, 1064.0, 1065.0, 1066.0, 1067.0, 1068.0, 1069.0, 1070.0 },28675,31,98,165,{ 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249 }
    };
    mavlink_mission_chunk_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.mission_id = packet_in.mission_id;
        packet1.total_waypoints = packet_in.total_waypoints;
        packet1.total_chunks = packet_in.total_chunks;
        packet1.chunk_id = packet_in.chunk_id;
        packet1.num_in_chunk = packet_in.num_in_chunk;
        
        mav_array_memcpy(packet1.lat, packet_in.lat, sizeof(float)*18);
        mav_array_memcpy(packet1.lon, packet_in.lon, sizeof(float)*18);
        mav_array_memcpy(packet1.alt, packet_in.alt, sizeof(float)*18);
        mav_array_memcpy(packet1.camera_action, packet_in.camera_action, sizeof(uint8_t)*18);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MISSION_CHUNK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_chunk_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mission_chunk_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_chunk_pack(system_id, component_id, &msg , packet1.mission_id , packet1.total_waypoints , packet1.total_chunks , packet1.chunk_id , packet1.num_in_chunk , packet1.lat , packet1.lon , packet1.alt , packet1.camera_action );
    mavlink_msg_mission_chunk_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_chunk_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mission_id , packet1.total_waypoints , packet1.total_chunks , packet1.chunk_id , packet1.num_in_chunk , packet1.lat , packet1.lon , packet1.alt , packet1.camera_action );
    mavlink_msg_mission_chunk_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mission_chunk_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_chunk_send(MAVLINK_COMM_1 , packet1.mission_id , packet1.total_waypoints , packet1.total_chunks , packet1.chunk_id , packet1.num_in_chunk , packet1.lat , packet1.lon , packet1.alt , packet1.camera_action );
    mavlink_msg_mission_chunk_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MISSION_CHUNK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MISSION_CHUNK) != NULL);
#endif
}

static void mavlink_test_mission_chunk_ack(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MISSION_CHUNK_ACK >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mission_chunk_ack_t packet_in = {
        963497464,17,84,151
    };
    mavlink_mission_chunk_ack_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.mission_id = packet_in.mission_id;
        packet1.chunk_id = packet_in.chunk_id;
        packet1.result = packet_in.result;
        packet1.chunks_received = packet_in.chunks_received;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MISSION_CHUNK_ACK_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_chunk_ack_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mission_chunk_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_chunk_ack_pack(system_id, component_id, &msg , packet1.mission_id , packet1.chunk_id , packet1.result , packet1.chunks_received );
    mavlink_msg_mission_chunk_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_chunk_ack_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.mission_id , packet1.chunk_id , packet1.result , packet1.chunks_received );
    mavlink_msg_mission_chunk_ack_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mission_chunk_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mission_chunk_ack_send(MAVLINK_COMM_1 , packet1.mission_id , packet1.chunk_id , packet1.result , packet1.chunks_received );
    mavlink_msg_mission_chunk_ack_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MISSION_CHUNK_ACK") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MISSION_CHUNK_ACK) != NULL);
#endif
}

static void mavlink_test_mission_msgs(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_mission_chunk(system_id, component_id, last_msg);
    mavlink_test_mission_chunk_ack(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MISSION_MSGS_TESTSUITE_H
