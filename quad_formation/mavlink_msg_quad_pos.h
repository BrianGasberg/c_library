// MESSAGE QUAD_POS PACKING

#define MAVLINK_MSG_ID_QUAD_POS 199

typedef struct __mavlink_quad_pos_t
{
 float x; ///< x-axis (float[10])
 float y; ///< y-axis (float[10])
 float z; ///< z-axis (float[10]) = -1 if coordinate is Not Available
 uint8_t target_system; ///<  The target_system is defined in enum QUAD_FORMATION_ID (Zero To anounce all quads
 uint8_t cmd_id; ///< Command ID is defined in enum QUAD_CMD (Command IDs smaller than 0 is no cmd)
 uint8_t pos_no; ///< Coordinate set number
} mavlink_quad_pos_t;

#define MAVLINK_MSG_ID_QUAD_POS_LEN 15
#define MAVLINK_MSG_ID_199_LEN 15

#define MAVLINK_MSG_ID_QUAD_POS_CRC 161
#define MAVLINK_MSG_ID_199_CRC 161



#define MAVLINK_MESSAGE_INFO_QUAD_POS { \
	"QUAD_POS", \
	6, \
	{  { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_quad_pos_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_quad_pos_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_quad_pos_t, z) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_quad_pos_t, target_system) }, \
         { "cmd_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_quad_pos_t, cmd_id) }, \
         { "pos_no", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_quad_pos_t, pos_no) }, \
         } \
}


/**
 * @brief Pack a quad_pos message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  The target_system is defined in enum QUAD_FORMATION_ID (Zero To anounce all quads
 * @param cmd_id Command ID is defined in enum QUAD_CMD (Command IDs smaller than 0 is no cmd)
 * @param pos_no Coordinate set number
 * @param x x-axis (float[10])
 * @param y y-axis (float[10])
 * @param z z-axis (float[10]) = -1 if coordinate is Not Available
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_quad_pos_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t cmd_id, uint8_t pos_no, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_QUAD_POS_LEN];
	_mav_put_float(buf, 0, x);
	_mav_put_float(buf, 4, y);
	_mav_put_float(buf, 8, z);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, cmd_id);
	_mav_put_uint8_t(buf, 14, pos_no);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_QUAD_POS_LEN);
#else
	mavlink_quad_pos_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.target_system = target_system;
	packet.cmd_id = cmd_id;
	packet.pos_no = pos_no;

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
 * @param target_system  The target_system is defined in enum QUAD_FORMATION_ID (Zero To anounce all quads
 * @param cmd_id Command ID is defined in enum QUAD_CMD (Command IDs smaller than 0 is no cmd)
 * @param pos_no Coordinate set number
 * @param x x-axis (float[10])
 * @param y y-axis (float[10])
 * @param z z-axis (float[10]) = -1 if coordinate is Not Available
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_quad_pos_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t cmd_id,uint8_t pos_no,float x,float y,float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_QUAD_POS_LEN];
	_mav_put_float(buf, 0, x);
	_mav_put_float(buf, 4, y);
	_mav_put_float(buf, 8, z);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, cmd_id);
	_mav_put_uint8_t(buf, 14, pos_no);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_QUAD_POS_LEN);
#else
	mavlink_quad_pos_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.target_system = target_system;
	packet.cmd_id = cmd_id;
	packet.pos_no = pos_no;

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
	return mavlink_msg_quad_pos_pack(system_id, component_id, msg, quad_pos->target_system, quad_pos->cmd_id, quad_pos->pos_no, quad_pos->x, quad_pos->y, quad_pos->z);
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
	return mavlink_msg_quad_pos_pack_chan(system_id, component_id, chan, msg, quad_pos->target_system, quad_pos->cmd_id, quad_pos->pos_no, quad_pos->x, quad_pos->y, quad_pos->z);
}

/**
 * @brief Send a quad_pos message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  The target_system is defined in enum QUAD_FORMATION_ID (Zero To anounce all quads
 * @param cmd_id Command ID is defined in enum QUAD_CMD (Command IDs smaller than 0 is no cmd)
 * @param pos_no Coordinate set number
 * @param x x-axis (float[10])
 * @param y y-axis (float[10])
 * @param z z-axis (float[10]) = -1 if coordinate is Not Available
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_quad_pos_send(mavlink_channel_t chan, uint8_t target_system, uint8_t cmd_id, uint8_t pos_no, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_QUAD_POS_LEN];
	_mav_put_float(buf, 0, x);
	_mav_put_float(buf, 4, y);
	_mav_put_float(buf, 8, z);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, cmd_id);
	_mav_put_uint8_t(buf, 14, pos_no);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, buf, MAVLINK_MSG_ID_QUAD_POS_LEN, MAVLINK_MSG_ID_QUAD_POS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, buf, MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif
#else
	mavlink_quad_pos_t packet;
	packet.x = x;
	packet.y = y;
	packet.z = z;
	packet.target_system = target_system;
	packet.cmd_id = cmd_id;
	packet.pos_no = pos_no;

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
static inline void mavlink_msg_quad_pos_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t cmd_id, uint8_t pos_no, float x, float y, float z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_float(buf, 0, x);
	_mav_put_float(buf, 4, y);
	_mav_put_float(buf, 8, z);
	_mav_put_uint8_t(buf, 12, target_system);
	_mav_put_uint8_t(buf, 13, cmd_id);
	_mav_put_uint8_t(buf, 14, pos_no);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, buf, MAVLINK_MSG_ID_QUAD_POS_LEN, MAVLINK_MSG_ID_QUAD_POS_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_QUAD_POS, buf, MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif
#else
	mavlink_quad_pos_t *packet = (mavlink_quad_pos_t *)msgbuf;
	packet->x = x;
	packet->y = y;
	packet->z = z;
	packet->target_system = target_system;
	packet->cmd_id = cmd_id;
	packet->pos_no = pos_no;

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
 * @return  The target_system is defined in enum QUAD_FORMATION_ID (Zero To anounce all quads
 */
static inline uint8_t mavlink_msg_quad_pos_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field cmd_id from quad_pos message
 *
 * @return Command ID is defined in enum QUAD_CMD (Command IDs smaller than 0 is no cmd)
 */
static inline uint8_t mavlink_msg_quad_pos_get_cmd_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field pos_no from quad_pos message
 *
 * @return Coordinate set number
 */
static inline uint8_t mavlink_msg_quad_pos_get_pos_no(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field x from quad_pos message
 *
 * @return x-axis (float[10])
 */
static inline float mavlink_msg_quad_pos_get_x(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from quad_pos message
 *
 * @return y-axis (float[10])
 */
static inline float mavlink_msg_quad_pos_get_y(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field z from quad_pos message
 *
 * @return z-axis (float[10]) = -1 if coordinate is Not Available
 */
static inline float mavlink_msg_quad_pos_get_z(const mavlink_message_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
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
	quad_pos->x = mavlink_msg_quad_pos_get_x(msg);
	quad_pos->y = mavlink_msg_quad_pos_get_y(msg);
	quad_pos->z = mavlink_msg_quad_pos_get_z(msg);
	quad_pos->target_system = mavlink_msg_quad_pos_get_target_system(msg);
	quad_pos->cmd_id = mavlink_msg_quad_pos_get_cmd_id(msg);
	quad_pos->pos_no = mavlink_msg_quad_pos_get_pos_no(msg);
#else
	memcpy(quad_pos, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_QUAD_POS_LEN);
#endif
}
