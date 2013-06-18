// MESSAGE TEMPERATURE_VALUE PACKING

#define MAVLINK_MSG_ID_TEMPERATURE_VALUE 152

typedef struct __mavlink_temperature_value_t
{
 uint8_t temp1_value; ///< temperature value of channel1
 uint8_t temp2_value; ///< temperature value of channel2
} mavlink_temperature_value_t;

#define MAVLINK_MSG_ID_TEMPERATURE_VALUE_LEN 2
#define MAVLINK_MSG_ID_152_LEN 2



#define MAVLINK_MESSAGE_INFO_TEMPERATURE_VALUE { \
	"TEMPERATURE_VALUE", \
	2, \
	{  { "temp1_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_temperature_value_t, temp1_value) }, \
         { "temp2_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_temperature_value_t, temp2_value) }, \
         } \
}


/**
 * @brief Pack a temperature_value message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param temp1_value temperature value of channel1
 * @param temp2_value temperature value of channel2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static uint16_t mavlink_msg_temperature_value_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t temp1_value, uint8_t temp2_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, temp1_value);
	_mav_put_uint8_t(buf, 1, temp2_value);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_temperature_value_t packet;
	packet.temp1_value = temp1_value;
	packet.temp2_value = temp2_value;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEMPERATURE_VALUE;
	return mavlink_finalize_message(msg, system_id, component_id, 2, 5);
}

/**
 * @brief Pack a temperature_value message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param temp1_value temperature value of channel1
 * @param temp2_value temperature value of channel2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static uint16_t mavlink_msg_temperature_value_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t temp1_value,uint8_t temp2_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, temp1_value);
	_mav_put_uint8_t(buf, 1, temp2_value);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
	mavlink_temperature_value_t packet;
	packet.temp1_value = temp1_value;
	packet.temp2_value = temp2_value;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEMPERATURE_VALUE;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 2, 5);
}

/**
 * @brief Encode a temperature_value struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param temperature_value C-struct to read the message contents from
 */
static uint16_t mavlink_msg_temperature_value_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_temperature_value_t* temperature_value)
{
	return mavlink_msg_temperature_value_pack(system_id, component_id, msg, temperature_value->temp1_value, temperature_value->temp2_value);
}

/**
 * @brief Send a temperature_value message
 * @param chan MAVLink channel to send the message
 *
 * @param temp1_value temperature value of channel1
 * @param temp2_value temperature value of channel2
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static void mavlink_msg_temperature_value_send(mavlink_channel_t chan, uint8_t temp1_value, uint8_t temp2_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[2];
	_mav_put_uint8_t(buf, 0, temp1_value);
	_mav_put_uint8_t(buf, 1, temp2_value);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEMPERATURE_VALUE, buf, 2, 5);
#else
	mavlink_temperature_value_t packet;
	packet.temp1_value = temp1_value;
	packet.temp2_value = temp2_value;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEMPERATURE_VALUE, (const char *)&packet, 2, 5);
#endif
}

#endif

// MESSAGE TEMPERATURE_VALUE UNPACKING


/**
 * @brief Get field temp1_value from temperature_value message
 *
 * @return temperature value of channel1
 */
static uint8_t mavlink_msg_temperature_value_get_temp1_value(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field temp2_value from temperature_value message
 *
 * @return temperature value of channel2
 */
static uint8_t mavlink_msg_temperature_value_get_temp2_value(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a temperature_value message into a struct
 *
 * @param msg The message to decode
 * @param temperature_value C-struct to decode the message contents into
 */
static void mavlink_msg_temperature_value_decode(const mavlink_message_t* msg, mavlink_temperature_value_t* temperature_value)
{
#if MAVLINK_NEED_BYTE_SWAP
	temperature_value->temp1_value = mavlink_msg_temperature_value_get_temp1_value(msg);
	temperature_value->temp2_value = mavlink_msg_temperature_value_get_temp2_value(msg);
#else
	memcpy(temperature_value, _MAV_PAYLOAD(msg), 2);
#endif
}
