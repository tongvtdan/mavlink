/** @file
 *	@brief MAVLink comm protocol testsuite generated from gremsygimbal.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef GREMSYGIMBAL_TESTSUITE_H
#define GREMSYGIMBAL_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_gremsygimbal(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_gremsygimbal(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_motor_config(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_motor_config_t packet_in = {
		5,
	72,
	139,
	206,
	17,
	};
	mavlink_motor_config_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.motor_name = packet_in.motor_name;
        	packet1.power = packet_in.power;
        	packet1.poles = packet_in.poles;
        	packet1.up_limit = packet_in.up_limit;
        	packet1.down_limit = packet_in.down_limit;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_config_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_motor_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_config_pack(system_id, component_id, &msg , packet1.motor_name , packet1.power , packet1.poles , packet1.up_limit , packet1.down_limit );
	mavlink_msg_motor_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_config_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.motor_name , packet1.power , packet1.poles , packet1.up_limit , packet1.down_limit );
	mavlink_msg_motor_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_motor_config_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_motor_config_send(MAVLINK_COMM_1 , packet1.motor_name , packet1.power , packet1.poles , packet1.up_limit , packet1.down_limit );
	mavlink_msg_motor_config_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_pid_config(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_pid_config_t packet_in = {
		5,
	72,
	139,
	206,
	};
	mavlink_pid_config_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.motor_name = packet_in.motor_name;
        	packet1.kp_factor = packet_in.kp_factor;
        	packet1.ki_factor = packet_in.ki_factor;
        	packet1.kd_factor = packet_in.kd_factor;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pid_config_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_pid_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pid_config_pack(system_id, component_id, &msg , packet1.motor_name , packet1.kp_factor , packet1.ki_factor , packet1.kd_factor );
	mavlink_msg_pid_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pid_config_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.motor_name , packet1.kp_factor , packet1.ki_factor , packet1.kd_factor );
	mavlink_msg_pid_config_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_pid_config_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_pid_config_send(MAVLINK_COMM_1 , packet1.motor_name , packet1.kp_factor , packet1.ki_factor , packet1.kd_factor );
	mavlink_msg_pid_config_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gremsygimbal(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_motor_config(system_id, component_id, last_msg);
	mavlink_test_pid_config(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // GREMSYGIMBAL_TESTSUITE_H
