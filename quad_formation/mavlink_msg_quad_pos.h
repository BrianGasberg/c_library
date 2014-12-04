// MESSAGE QUAD_POS PACKING

#define MAVLINK_MSG_ID_QUAD_POS 199

typedef struct __mavlink_quad_pos_t
{
 float x[3]; ///< x-axis (float[3])
 float y[3]; ///< y-axis (float[3])
 float z[3]; ///< z-axis (float[3]) -1 if coordinate is not available
 uint8_t target_system; ///<  The target_system is defined in ENUM QUAD_FORMATION_ID (Zero To announce all quads)
} mavlink_quad_pos_t;

#define MAVLINK_MSG_ID_QUAD_POS_LEN 37
#define MAVLINK_MSG_ID_199_LEN 37

#define MAVLINK_MSG_ID_QUAD_POS_CRC 229
#define MAVLINK_MSG_ID_199_CRC 229

#define MAVLINK_MSG_QUAD_POS_FIELD_X_LEN 3
#define MAVLINK_MSG_QUAD_POS_FIELD_Y_LEN 3
#define MAVLINK_MSG_QUAD_POS_FIELD_Z_LEN 3

#define MAVLINK_MESSAGE_INFO_QUAD_POS { \
	"QUAD_POS", \
	4, \
	{  { "x", NULL, MAVLINK_TYPE_FLOAT, 3, 0, offsetof(mavlink_quad_pos_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 3, 12, offsetof(mavlink_quad_pos_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 3, 24, offsetof(mavlink_quad_pos_t, z) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_quad_pos_t, target_system) }, \
         } \
}


/**
 * @brief Pack a quad_pos message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  The target_system is defined in ENUM QUAD_FORMATION_ID (Zero To announce all quads)
 * @param x x-axis (float[3])
 * @param y y-axis (float[3])
 * @param z z-axis (float[3]) -1 if coordinate is not available
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_quad_pos_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, const float *x, const float *y, const float *z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_QUAD_POS_LEN];
	_mav_put_uint8_t(buf, 36, target_system);
	_mav_put_float_array(buf, 0, x, 3);
	_mav_put_float_array(buf, 12, y, 3);
	_mav_put_float_array(buf, 24, z, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_QUAD_POS_LEN);
#else
	mavlink_quad_pos_t packet;
	packet.target_system = target_system;
	mav_array_memcpy(packet.x, x, sizeof(float)*3);
	mav_array_memcpy(packet.y, y, sizeof(float)*3);
	mav_array_memcpy(packet.z, z, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_QUAD_POS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_QUAD_POS_LEN, MAVLINK_MSG_ID_QUAD_POS_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif
}

/**
 * @brief Pack a quad_pos message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  The target_system is defined in ENUM QUAD_FORMATION_ID (Zero To announce all quads)
 * @param x x-axis (float[3])
 * @param y y-axis (float[3])
 * @param z z-axis (float[3]) -1 if coordinate is not available
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_quad_pos_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,const float *x,const float *y,const float *z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_QUAD_POS_LEN];
	_mav_put_uint8_t(buf, 36, target_system);
	_mav_put_float_array(buf, 0, x, 3);
	_mav_put_float_array(buf, 12, y, 3);
	_mav_put_float_array(buf, 24, z, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_QUAD_POS_LEN);
#else
	mavlink_quad_pos_t packet;
	packet.target_system = target_system;
	mav_array_memcpy(packet.x, x, sizeof(float)*3);
	mav_array_memcpy(packet.y, y, sizeof(float)*3);
	mav_array_memcpy(packet.z, z, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_QUAD_POS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_QUAD_POS_LEN, MAVLINK_MSG_ID_QUAD_POS_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif
}

/**
 * @brief Encode a quad_pos struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param quad_pos C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_quad_pos_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_quad_pos_t* quad_pos)
{
	return mavlink_msg_quad_pos_pack(system_id, component_id, msg, quad_pos->target_system, quad_pos->x, quad_pos->y, quad_pos->z);
}

/**
 * @brief Encode a quad_pos struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param quad_pos C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_quad_pos_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_quad_pos_t* quad_pos)
{
	return mavlink_msg_quad_pos_pack_chan(system_id, component_id, chan, msg, quad_pos->target_system, quad_pos->x, quad_pos->y, quad_pos->z);
}

/**
 * @brief Send a quad_pos message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  The target_system is defined in ENUM QUAD_FORMATION_ID (Zero To announce all quads)
 * @param x x-axis (float[3])
 * @param y y-axis (float[3])
 * @param z z-axis (float[3]) -1 if coordinate is not available
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_quad_pos_send(mavlink_channel_t chan, uint8_t target_system, const float *x, const float *y, const float *z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_QUAD_POS_LEN];
	_mav_put_uint8_t(buf, 36, target_system);
	_mav_put_float_array(buf, 0, x, 3);
	_mav_put_float_array(buf, 12, y, 3);
	_mav_put_float_array(buf, 24, z, 3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, buf, MAVLINK_MSG_ID_QUAD_POS_LEN, MAVLINK_MSG_ID_QUAD_POS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, buf, MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif
#else
	mavlink_quad_pos_t packet;
	packet.target_system = target_system;
	mav_array_memcpy(packet.x, x, sizeof(float)*3);
	mav_array_memcpy(packet.y, y, sizeof(float)*3);
	mav_array_memcpy(packet.z, z, sizeof(float)*3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, (const char *)&packet, MAVLINK_MSG_ID_QUAD_POS_LEN, MAVLINK_MSG_ID_QUAD_POS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, (const char *)&packet, MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_QUAD_POS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_quad_pos_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, const float *x, const float *y, const float *z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 36, target_system);
	_mav_put_float_array(buf, 0, x, 3);
	_mav_put_float_array(buf, 12, y, 3);
	_mav_put_float_array(buf, 24, z, 3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, buf, MAVLINK_MSG_ID_QUAD_POS_LEN, MAVLINK_MSG_ID_QUAD_POS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, buf, MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif
#else
	mavlink_quad_pos_t *packet = (mavlink_quad_pos_t *)msgbuf;
	packet->target_system = target_system;
	mav_array_memcpy(packet->x, x, sizeof(float)*3);
	mav_array_memcpy(packet->y, y, sizeof(float)*3);
	mav_array_memcpy(packet->z, z, sizeof(float)*3);
#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, (const char *)packet, MAVLINK_MSG_ID_QUAD_POS_LEN, MAVLINK_MSG_ID_QUAD_POS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, (const char *)packet, MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE QUAD_POS UNPACKING


/**
 * @brief Get field target_system from quad_pos message
 *
 * @return  The target_system is defined in ENUM QUAD_FORMATION_ID (Zero To announce all quads)
 */
static inline uint8_t mavlink_msg_quad_pos_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field x from quad_pos message
 *
 * @return x-axis (float[3])
 */
static inline uint16_t mavlink_msg_quad_pos_get_x(const mavlink_message_t* msg, float *x)
{
	return _MAV_RETURN_float_array(msg, x, 3,  0);
}

/**
 * @brief Get field y from quad_pos message
 *
 * @return y-axis (float[3])
 */
static inline uint16_t mavlink_msg_quad_pos_get_y(const mavlink_message_t* msg, float *y)
{
	return _MAV_RETURN_float_array(msg, y, 3,  12);
}

/**
 * @brief Get field z from quad_pos message
 *
 * @return z-axis (float[3]) -1 if coordinate is not available
 */
static inline uint16_t mavlink_msg_quad_pos_get_z(const mavlink_message_t* msg, float *z)
{
	return _MAV_RETURN_float_array(msg, z, 3,  24);
}

/**
 * @brief Decode a quad_pos message into a struct
 *
 * @param msg The message to decode
 * @param quad_pos C-struct to decode the message contents into
 */
static inline void mavlink_msg_quad_pos_decode(const mavlink_message_t* msg, mavlink_quad_pos_t* quad_pos)
{
#if MAVLINK_NEED_BYTE_SWAP
	mavlink_msg_quad_pos_get_x(msg, quad_pos->x);
	mavlink_msg_quad_pos_get_y(msg, quad_pos->y);
	mavlink_msg_quad_pos_get_z(msg, quad_pos->z);
	quad_pos->target_system = mavlink_msg_quad_pos_get_target_system(msg);
#else
	memcpy(quad_pos, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif
}
