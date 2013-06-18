// MESSAGE MOTOR_CONFIG PACKING

#define MAVLINK_MSG_ID_MOTOR_CONFIG 152

typedef struct __mavlink_motor_config_t
{
 uint8_t motor_name; ///< Name of motor: ROLL_MOTOR, PITCH_MOTOR, YAW_MOTOR
 uint8_t power; ///< Specify maximun power of motor
 uint8_t poles; ///< Specify number of poles of motor
 uint8_t up_limit; ///< Specify up limit of motor
 uint8_t down_limit; ///< Specify down limit of motor
} mavlink_motor_config_t;

#define MAVLINK_MSG_ID_MOTOR_CONFIG_LEN 5
#define MAVLINK_MSG_ID_152_LEN 5



#define MAVLINK_MESSAGE_INFO_MOTOR_CONFIG { \
	"MOTOR_CONFIG", \
	5, \
	{  { "motor_name", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_motor_config_t, motor_name) }, \
         { "power", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_motor_config_t, power) }, \
         { "poles", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_motor_config_t, poles) }, \
         { "up_limit", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_motor_config_t, up_limit) }, \
         { "down_limit", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_motor_config_t, down_limit) }, \
         } \
}


/**
 * @brief Pack a motor_config message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param motor_name Name of motor: ROLL_MOTOR, PITCH_MOTOR, YAW_MOTOR
 * @param power Specify maximun power of motor
 * @param poles Specify number of poles of motor
 * @param up_limit Specify up limit of motor
 * @param down_limit Specify down limit of motor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_motor_config_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t motor_name, uint8_t power, uint8_t poles, uint8_t up_limit, uint8_t down_limit)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[5];
	_mav_put_uint8_t(buf, 0, motor_name);
	_mav_put_uint8_t(buf, 1, power);
	_mav_put_uint8_t(buf, 2, poles);
	_mav_put_uint8_t(buf, 3, up_limit);
	_mav_put_uint8_t(buf, 4, down_limit);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 5);
#else
	mavlink_motor_config_t packet;
	packet.motor_name = motor_name;
	packet.power = power;
	packet.poles = poles;
	packet.up_limit = up_limit;
	packet.down_limit = down_limit;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 5);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTOR_CONFIG;
	return mavlink_finalize_message(msg, system_id, component_id, 5, 239);
}

/**
 * @brief Pack a motor_config message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_name Name of motor: ROLL_MOTOR, PITCH_MOTOR, YAW_MOTOR
 * @param power Specify maximun power of motor
 * @param poles Specify number of poles of motor
 * @param up_limit Specify up limit of motor
 * @param down_limit Specify down limit of motor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static __inline uint16_t mavlink_msg_motor_config_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t motor_name,uint8_t power,uint8_t poles,uint8_t up_limit,uint8_t down_limit)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[5];
	_mav_put_uint8_t(buf, 0, motor_name);
	_mav_put_uint8_t(buf, 1, power);
	_mav_put_uint8_t(buf, 2, poles);
	_mav_put_uint8_t(buf, 3, up_limit);
	_mav_put_uint8_t(buf, 4, down_limit);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 5);
#else
	mavlink_motor_config_t packet;
	packet.motor_name = motor_name;
	packet.power = power;
	packet.poles = poles;
	packet.up_limit = up_limit;
	packet.down_limit = down_limit;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 5);
#endif

	msg->msgid = MAVLINK_MSG_ID_MOTOR_CONFIG;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 5, 239);
}

/**
 * @brief Encode a motor_config struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motor_config C-struct to read the message contents from
 */
static __inline uint16_t mavlink_msg_motor_config_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motor_config_t* motor_config)
{
	return mavlink_msg_motor_config_pack(system_id, component_id, msg, motor_config->motor_name, motor_config->power, motor_config->poles, motor_config->up_limit, motor_config->down_limit);
}

/**
 * @brief Send a motor_config message
 * @param chan MAVLink channel to send the message
 *
 * @param motor_name Name of motor: ROLL_MOTOR, PITCH_MOTOR, YAW_MOTOR
 * @param power Specify maximun power of motor
 * @param poles Specify number of poles of motor
 * @param up_limit Specify up limit of motor
 * @param down_limit Specify down limit of motor
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static __inline void mavlink_msg_motor_config_send(mavlink_channel_t chan, uint8_t motor_name, uint8_t power, uint8_t poles, uint8_t up_limit, uint8_t down_limit)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[5];
	_mav_put_uint8_t(buf, 0, motor_name);
	_mav_put_uint8_t(buf, 1, power);
	_mav_put_uint8_t(buf, 2, poles);
	_mav_put_uint8_t(buf, 3, up_limit);
	_mav_put_uint8_t(buf, 4, down_limit);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_CONFIG, buf, 5, 239);
#else
	mavlink_motor_config_t packet;
	packet.motor_name = motor_name;
	packet.power = power;
	packet.poles = poles;
	packet.up_limit = up_limit;
	packet.down_limit = down_limit;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MOTOR_CONFIG, (const char *)&packet, 5, 239);
#endif
}

#endif

// MESSAGE MOTOR_CONFIG UNPACKING


/**
 * @brief Get field motor_name from motor_config message
 *
 * @return Name of motor: ROLL_MOTOR, PITCH_MOTOR, YAW_MOTOR
 */
static __inline uint8_t mavlink_msg_motor_config_get_motor_name(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field power from motor_config message
 *
 * @return Specify maximun power of motor
 */
static __inline uint8_t mavlink_msg_motor_config_get_power(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field poles from motor_config message
 *
 * @return Specify number of poles of motor
 */
static __inline uint8_t mavlink_msg_motor_config_get_poles(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field up_limit from motor_config message
 *
 * @return Specify up limit of motor
 */
static __inline uint8_t mavlink_msg_motor_config_get_up_limit(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field down_limit from motor_config message
 *
 * @return Specify down limit of motor
 */
static __inline uint8_t mavlink_msg_motor_config_get_down_limit(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a motor_config message into a struct
 *
 * @param msg The message to decode
 * @param motor_config C-struct to decode the message contents into
 */
static __inline void mavlink_msg_motor_config_decode(const mavlink_message_t* msg, mavlink_motor_config_t* motor_config)
{
#if MAVLINK_NEED_BYTE_SWAP
	motor_config->motor_name = mavlink_msg_motor_config_get_motor_name(msg);
	motor_config->power = mavlink_msg_motor_config_get_power(msg);
	motor_config->poles = mavlink_msg_motor_config_get_poles(msg);
	motor_config->up_limit = mavlink_msg_motor_config_get_up_limit(msg);
	motor_config->down_limit = mavlink_msg_motor_config_get_down_limit(msg);
#else
	memcpy(motor_config, _MAV_PAYLOAD(msg), 5);
#endif
}
