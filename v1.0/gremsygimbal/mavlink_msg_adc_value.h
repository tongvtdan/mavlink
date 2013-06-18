// MESSAGE ADC_VALUE PACKING

#define MAVLINK_MSG_ID_ADC_VALUE 151

typedef struct __mavlink_adc_value_t
{
 uint8_t channel1; ///< ADC value of channel1
 uint8_t channel2; ///< ADC value of channel2
} mavlink_adc_value_t;

#define MAVLINK_MSG_ID_ADC_VALUE_LEN 2
#define MAVLINK_MSG_ID_151_LEN 2



#define MAVLINK_MESSAGE_INFO_ADC_VALUE { \
    "ADC_VALUE", \
    2, \
    {  { "channel1", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_adc_value_t, channel1) }, \
         { "channel2", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_adc_value_t, channel2) }, \
         } \
}


/**
 * @brief Pack a adc_value message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param channel1 ADC value of channel1
 * @param channel2 ADC value of channel2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static uint16_t mavlink_msg_adc_value_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t channel1, uint8_t channel2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[2];
    _mav_put_uint8_t(buf, 0, channel1);
    _mav_put_uint8_t(buf, 1, channel2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
    mavlink_adc_value_t packet;
    packet.channel1 = channel1;
    packet.channel2 = channel2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

    msg->msgid = MAVLINK_MSG_ID_ADC_VALUE;
    return mavlink_finalize_message(msg, system_id, component_id, 2, 149);
}

/**
 * @brief Pack a adc_value message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param channel1 ADC value of channel1
 * @param channel2 ADC value of channel2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static uint16_t mavlink_msg_adc_value_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t channel1,uint8_t channel2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[2];
    _mav_put_uint8_t(buf, 0, channel1);
    _mav_put_uint8_t(buf, 1, channel2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 2);
#else
    mavlink_adc_value_t packet;
    packet.channel1 = channel1;
    packet.channel2 = channel2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 2);
#endif

    msg->msgid = MAVLINK_MSG_ID_ADC_VALUE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 2, 149);
}

/**
 * @brief Encode a adc_value struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param adc_value C-struct to read the message contents from
 */
static uint16_t mavlink_msg_adc_value_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_adc_value_t* adc_value)
{
    return mavlink_msg_adc_value_pack(system_id, component_id, msg, adc_value->channel1, adc_value->channel2);
}

/**
 * @brief Send a adc_value message
 * @param chan MAVLink channel to send the message
 *
 * @param channel1 ADC value of channel1
 * @param channel2 ADC value of channel2
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static void mavlink_msg_adc_value_send(mavlink_channel_t chan, uint8_t channel1, uint8_t channel2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[2];
    _mav_put_uint8_t(buf, 0, channel1);
    _mav_put_uint8_t(buf, 1, channel2);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_VALUE, buf, 2, 149);
#else
    mavlink_adc_value_t packet;
    packet.channel1 = channel1;
    packet.channel2 = channel2;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ADC_VALUE, (const char *)&packet, 2, 149);
#endif
}

#endif

// MESSAGE ADC_VALUE UNPACKING


/**
 * @brief Get field channel1 from adc_value message
 *
 * @return ADC value of channel1
 */
static uint8_t mavlink_msg_adc_value_get_channel1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field channel2 from adc_value message
 *
 * @return ADC value of channel2
 */
static uint8_t mavlink_msg_adc_value_get_channel2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a adc_value message into a struct
 *
 * @param msg The message to decode
 * @param adc_value C-struct to decode the message contents into
 */
static void mavlink_msg_adc_value_decode(const mavlink_message_t* msg, mavlink_adc_value_t* adc_value)
{
#if MAVLINK_NEED_BYTE_SWAP
    adc_value->channel1 = mavlink_msg_adc_value_get_channel1(msg);
    adc_value->channel2 = mavlink_msg_adc_value_get_channel2(msg);
#else
    memcpy(adc_value, _MAV_PAYLOAD(msg), 2);
#endif
}
