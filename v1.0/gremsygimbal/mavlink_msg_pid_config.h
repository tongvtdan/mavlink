// MESSAGE PID_CONFIG PACKING

#define MAVLINK_MSG_ID_PID_CONFIG 153

typedef struct __mavlink_pid_config_t
{
 uint8_t motor_name; ///< Name of motor: ROLL_MOTOR, PITCH_MOTOR, YAW_MOTOR
 uint8_t kp_factor; ///< Specify kp factor of motor
 uint8_t ki_factor; ///< Specify ki factor of motor
 uint8_t kd_factor; ///< Specify kd factor of motor
} mavlink_pid_config_t;

#define MAVLINK_MSG_ID_PID_CONFIG_LEN 4
#define MAVLINK_MSG_ID_153_LEN 4



#define MAVLINK_MESSAGE_INFO_PID_CONFIG { \
	"PID_CONFIG", \
	4, \
	{  { "motor_name", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_pid_config_t, motor_name) }, \
         { "kp_factor", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_pid_config_t, kp_factor) }, \
         { "ki_factor", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_pid_config_t, ki_factor) }, \
         { "kd_factor", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_pid_config_t, kd_factor) }, \
         } \
}


/**
 * @brief Pack a pid_config message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param motor_name Name of motor: ROLL_MOTOR, PITCH_MOTOR, YAW_MOTOR
 * @param kp_factor Specify kp factor of motor
 * @param ki_factor Specify ki factor of motor
 * @param kd_factor Specify kd factor of motor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_config_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t motor_name, uint8_t kp_factor, uint8_t ki_factor, uint8_t kd_factor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_uint8_t(buf, 0, motor_name);
	_mav_put_uint8_t(buf, 1, kp_factor);
	_mav_put_uint8_t(buf, 2, ki_factor);
	_mav_put_uint8_t(buf, 3, kd_factor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_pid_config_t packet;
	packet.motor_name = motor_name;
	packet.kp_factor = kp_factor;
	packet.ki_factor = ki_factor;
	packet.kd_factor = kd_factor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_PID_CONFIG;
	return mavlink_finalize_message(msg, system_id, component_id, 4, 33);
}

/**
 * @brief Pack a pid_config message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param motor_name Name of motor: ROLL_MOTOR, PITCH_MOTOR, YAW_MOTOR
 * @param kp_factor Specify kp factor of motor
 * @param ki_factor Specify ki factor of motor
 * @param kd_factor Specify kd factor of motor
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pid_config_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t motor_name,uint8_t kp_factor,uint8_t ki_factor,uint8_t kd_factor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_uint8_t(buf, 0, motor_name);
	_mav_put_uint8_t(buf, 1, kp_factor);
	_mav_put_uint8_t(buf, 2, ki_factor);
	_mav_put_uint8_t(buf, 3, kd_factor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 4);
#else
	mavlink_pid_config_t packet;
	packet.motor_name = motor_name;
	packet.kp_factor = kp_factor;
	packet.ki_factor = ki_factor;
	packet.kd_factor = kd_factor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 4);
#endif

	msg->msgid = MAVLINK_MSG_ID_PID_CONFIG;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 4, 33);
}

/**
 * @brief Encode a pid_config struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pid_config C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pid_config_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pid_config_t* pid_config)
{
	return mavlink_msg_pid_config_pack(system_id, component_id, msg, pid_config->motor_name, pid_config->kp_factor, pid_config->ki_factor, pid_config->kd_factor);
}

/**
 * @brief Send a pid_config message
 * @param chan MAVLink channel to send the message
 *
 * @param motor_name Name of motor: ROLL_MOTOR, PITCH_MOTOR, YAW_MOTOR
 * @param kp_factor Specify kp factor of motor
 * @param ki_factor Specify ki factor of motor
 * @param kd_factor Specify kd factor of motor
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pid_config_send(mavlink_channel_t chan, uint8_t motor_name, uint8_t kp_factor, uint8_t ki_factor, uint8_t kd_factor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[4];
	_mav_put_uint8_t(buf, 0, motor_name);
	_mav_put_uint8_t(buf, 1, kp_factor);
	_mav_put_uint8_t(buf, 2, ki_factor);
	_mav_put_uint8_t(buf, 3, kd_factor);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_CONFIG, buf, 4, 33);
#else
	mavlink_pid_config_t packet;
	packet.motor_name = motor_name;
	packet.kp_factor = kp_factor;
	packet.ki_factor = ki_factor;
	packet.kd_factor = kd_factor;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PID_CONFIG, (const char *)&packet, 4, 33);
#endif
}

#endif

// MESSAGE PID_CONFIG UNPACKING


/**
 * @brief Get field motor_name from pid_config message
 *
 * @return Name of motor: ROLL_MOTOR, PITCH_MOTOR, YAW_MOTOR
 */
static inline uint8_t mavlink_msg_pid_config_get_motor_name(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field kp_factor from pid_config message
 *
 * @return Specify kp factor of motor
 */
static inline uint8_t mavlink_msg_pid_config_get_kp_factor(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field ki_factor from pid_config message
 *
 * @return Specify ki factor of motor
 */
static inline uint8_t mavlink_msg_pid_config_get_ki_factor(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field kd_factor from pid_config message
 *
 * @return Specify kd factor of motor
 */
static inline uint8_t mavlink_msg_pid_config_get_kd_factor(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Decode a pid_config message into a struct
 *
 * @param msg The message to decode
 * @param pid_config C-struct to decode the message contents into
 */
static inline void mavlink_msg_pid_config_decode(const mavlink_message_t* msg, mavlink_pid_config_t* pid_config)
{
#if MAVLINK_NEED_BYTE_SWAP
	pid_config->motor_name = mavlink_msg_pid_config_get_motor_name(msg);
	pid_config->kp_factor = mavlink_msg_pid_config_get_kp_factor(msg);
	pid_config->ki_factor = mavlink_msg_pid_config_get_ki_factor(msg);
	pid_config->kd_factor = mavlink_msg_pid_config_get_kd_factor(msg);
#else
	memcpy(pid_config, _MAV_PAYLOAD(msg), 4);
#endif
}
