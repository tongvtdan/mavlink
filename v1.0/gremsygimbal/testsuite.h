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


static void mavlink_test_test_command(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_test_command_t packet_in = {
		963497464,
	17,
	84,
	151,
	218,
	};
	mavlink_test_command_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.custom_mode = packet_in.custom_mode;
        	packet1.type = packet_in.type;
        	packet1.autopilot = packet_in.autopilot;
        	packet1.base_mode = packet_in.base_mode;
        	packet1.system_status = packet_in.system_status;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_test_command_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_test_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_test_command_pack(system_id, component_id, &msg , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status );
	mavlink_msg_test_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_test_command_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status );
	mavlink_msg_test_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_test_command_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_test_command_send(MAVLINK_COMM_1 , packet1.type , packet1.autopilot , packet1.base_mode , packet1.custom_mode , packet1.system_status );
	mavlink_msg_test_command_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_adc_value(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_adc_value_t packet_in = {
		5,
	72,
	};
	mavlink_adc_value_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.channel1 = packet_in.channel1;
        	packet1.channel2 = packet_in.channel2;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_value_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_adc_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_value_pack(system_id, component_id, &msg , packet1.channel1 , packet1.channel2 );
	mavlink_msg_adc_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_value_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.channel1 , packet1.channel2 );
	mavlink_msg_adc_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_adc_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_adc_value_send(MAVLINK_COMM_1 , packet1.channel1 , packet1.channel2 );
	mavlink_msg_adc_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_temperature_value(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_temperature_value_t packet_in = {
		5,
	72,
	};
	mavlink_temperature_value_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.temp1_value = packet_in.temp1_value;
        	packet1.temp2_value = packet_in.temp2_value;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_temperature_value_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_temperature_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_temperature_value_pack(system_id, component_id, &msg , packet1.temp1_value , packet1.temp2_value );
	mavlink_msg_temperature_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_temperature_value_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.temp1_value , packet1.temp2_value );
	mavlink_msg_temperature_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_temperature_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_temperature_value_send(MAVLINK_COMM_1 , packet1.temp1_value , packet1.temp2_value );
	mavlink_msg_temperature_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_gremsygimbal(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_test_command(system_id, component_id, last_msg);
	mavlink_test_adc_value(system_id, component_id, last_msg);
	mavlink_test_temperature_value(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // GREMSYGIMBAL_TESTSUITE_H
