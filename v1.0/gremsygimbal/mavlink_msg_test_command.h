// MESSAGE TEST_COMMAND PACKING

#define MAVLINK_MSG_ID_TEST_COMMAND 150

typedef struct __mavlink_test_command_t
{
 uint32_t custom_mode; ///< A bitfield for use for autopilot-specific flags.
 uint8_t type; ///< Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 uint8_t autopilot; ///< Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 uint8_t base_mode; ///< System mode bitfield, see MAV_MODE_FLAGS ENUM in mavlink/include/mavlink_types.h
 uint8_t system_status; ///< System status flag, see MAV_STATE ENUM
} mavlink_test_command_t;

#define MAVLINK_MSG_ID_TEST_COMMAND_LEN 8
#define MAVLINK_MSG_ID_150_LEN 8



#define MAVLINK_MESSAGE_INFO_TEST_COMMAND { \
	"TEST_COMMAND", \
	5, \
	{  { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_test_command_t, custom_mode) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_test_command_t, type) }, \
         { "autopilot", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_test_command_t, autopilot) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_test_command_t, base_mode) }, \
         { "system_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_test_command_t, system_status) }, \
         } \
}


/**
 * @brief Pack a test_command message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 * @param autopilot Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 * @param base_mode System mode bitfield, see MAV_MODE_FLAGS ENUM in mavlink/include/mavlink_types.h
 * @param custom_mode A bitfield for use for autopilot-specific flags.
 * @param system_status System status flag, see MAV_STATE ENUM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static uint16_t mavlink_msg_test_command_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t type, uint8_t autopilot, uint8_t base_mode, uint32_t custom_mode, uint8_t system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_uint32_t(buf, 0, custom_mode);
	_mav_put_uint8_t(buf, 4, type);
	_mav_put_uint8_t(buf, 5, autopilot);
	_mav_put_uint8_t(buf, 6, base_mode);
	_mav_put_uint8_t(buf, 7, system_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 8);
#else
	mavlink_test_command_t packet;
	packet.custom_mode = custom_mode;
	packet.type = type;
	packet.autopilot = autopilot;
	packet.base_mode = base_mode;
	packet.system_status = system_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 8);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEST_COMMAND;
	return mavlink_finalize_message(msg, system_id, component_id, 8, 119);
}

/**
 * @brief Pack a test_command message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param type Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 * @param autopilot Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 * @param base_mode System mode bitfield, see MAV_MODE_FLAGS ENUM in mavlink/include/mavlink_types.h
 * @param custom_mode A bitfield for use for autopilot-specific flags.
 * @param system_status System status flag, see MAV_STATE ENUM
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static uint16_t mavlink_msg_test_command_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t type,uint8_t autopilot,uint8_t base_mode,uint32_t custom_mode,uint8_t system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_uint32_t(buf, 0, custom_mode);
	_mav_put_uint8_t(buf, 4, type);
	_mav_put_uint8_t(buf, 5, autopilot);
	_mav_put_uint8_t(buf, 6, base_mode);
	_mav_put_uint8_t(buf, 7, system_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 8);
#else
	mavlink_test_command_t packet;
	packet.custom_mode = custom_mode;
	packet.type = type;
	packet.autopilot = autopilot;
	packet.base_mode = base_mode;
	packet.system_status = system_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 8);
#endif

	msg->msgid = MAVLINK_MSG_ID_TEST_COMMAND;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 8, 119);
}

/**
 * @brief Encode a test_command struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param test_command C-struct to read the message contents from
 */
static uint16_t mavlink_msg_test_command_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_test_command_t* test_command)
{
	return mavlink_msg_test_command_pack(system_id, component_id, msg, test_command->type, test_command->autopilot, test_command->base_mode, test_command->custom_mode, test_command->system_status);
}

/**
 * @brief Send a test_command message
 * @param chan MAVLink channel to send the message
 *
 * @param type Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 * @param autopilot Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 * @param base_mode System mode bitfield, see MAV_MODE_FLAGS ENUM in mavlink/include/mavlink_types.h
 * @param custom_mode A bitfield for use for autopilot-specific flags.
 * @param system_status System status flag, see MAV_STATE ENUM
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static void mavlink_msg_test_command_send(mavlink_channel_t chan, uint8_t type, uint8_t autopilot, uint8_t base_mode, uint32_t custom_mode, uint8_t system_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[8];
	_mav_put_uint32_t(buf, 0, custom_mode);
	_mav_put_uint8_t(buf, 4, type);
	_mav_put_uint8_t(buf, 5, autopilot);
	_mav_put_uint8_t(buf, 6, base_mode);
	_mav_put_uint8_t(buf, 7, system_status);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST_COMMAND, buf, 8, 119);
#else
	mavlink_test_command_t packet;
	packet.custom_mode = custom_mode;
	packet.type = type;
	packet.autopilot = autopilot;
	packet.base_mode = base_mode;
	packet.system_status = system_status;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST_COMMAND, (const char *)&packet, 8, 119);
#endif
}

#endif

// MESSAGE TEST_COMMAND UNPACKING


/**
 * @brief Get field type from test_command message
 *
 * @return Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
 */
static uint8_t mavlink_msg_test_command_get_type(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field autopilot from test_command message
 *
 * @return Autopilot type / class. defined in MAV_AUTOPILOT ENUM
 */
static uint8_t mavlink_msg_test_command_get_autopilot(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field base_mode from test_command message
 *
 * @return System mode bitfield, see MAV_MODE_FLAGS ENUM in mavlink/include/mavlink_types.h
 */
static uint8_t mavlink_msg_test_command_get_base_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field custom_mode from test_command message
 *
 * @return A bitfield for use for autopilot-specific flags.
 */
static uint32_t mavlink_msg_test_command_get_custom_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field system_status from test_command message
 *
 * @return System status flag, see MAV_STATE ENUM
 */
static uint8_t mavlink_msg_test_command_get_system_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Decode a test_command message into a struct
 *
 * @param msg The message to decode
 * @param test_command C-struct to decode the message contents into
 */
static void mavlink_msg_test_command_decode(const mavlink_message_t* msg, mavlink_test_command_t* test_command)
{
#if MAVLINK_NEED_BYTE_SWAP
	test_command->custom_mode = mavlink_msg_test_command_get_custom_mode(msg);
	test_command->type = mavlink_msg_test_command_get_type(msg);
	test_command->autopilot = mavlink_msg_test_command_get_autopilot(msg);
	test_command->base_mode = mavlink_msg_test_command_get_base_mode(msg);
	test_command->system_status = mavlink_msg_test_command_get_system_status(msg);
#else
	memcpy(test_command, _MAV_PAYLOAD(msg), 8);
#endif
}
