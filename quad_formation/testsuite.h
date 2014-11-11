/** @file
 *	@brief MAVLink comm protocol testsuite generated from quad_formation.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef QUAD_FORMATION_TESTSUITE_H
#define QUAD_FORMATION_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_quad_formation(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_quad_formation(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_quad_pos(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_quad_pos_t packet_in = {
		{ 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0 },{ 297.0, 298.0, 299.0, 300.0, 301.0, 302.0, 303.0, 304.0, 305.0, 306.0 },{ 577.0, 578.0, 579.0, 580.0, 581.0, 582.0, 583.0, 584.0, 585.0, 586.0 },109,176,243
    };
	mavlink_quad_pos_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.target_system = packet_in.target_system;
        	packet1.cmd_id = packet_in.cmd_id;
        	packet1.pos_no = packet_in.pos_no;
        
        	mav_array_memcpy(packet1.x, packet_in.x, sizeof(float)*10);
        	mav_array_memcpy(packet1.y, packet_in.y, sizeof(float)*10);
        	mav_array_memcpy(packet1.z, packet_in.z, sizeof(float)*10);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_quad_pos_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_quad_pos_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_quad_pos_pack(system_id, component_id, &msg , packet1.target_system , packet1.cmd_id , packet1.pos_no , packet1.x , packet1.y , packet1.z );
	mavlink_msg_quad_pos_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_quad_pos_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.target_system , packet1.cmd_id , packet1.pos_no , packet1.x , packet1.y , packet1.z );
	mavlink_msg_quad_pos_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_quad_pos_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_quad_pos_send(MAVLINK_COMM_1 , packet1.target_system , packet1.cmd_id , packet1.pos_no , packet1.x , packet1.y , packet1.z );
	mavlink_msg_quad_pos_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_quad_formation(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_quad_pos(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // QUAD_FORMATION_TESTSUITE_H
