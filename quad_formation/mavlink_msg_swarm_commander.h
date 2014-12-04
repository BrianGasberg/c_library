// MESSAGE SWARM_COMMANDER PACKING

#define MAVLINK_MSG_ID_SWARM_COMMANDER 200

typedef struct __mavlink_swarm_commander_t
{
 uint8_t target_system; ///<  The target_system is defined in enum QUAD_FORMATION_ID (Zero To announce all quads
 uint8_t cmd_id; ///< Command ID is defined in ENUM QUAD_CMD (Command IDs smaller than 0 is no command)
} mavlink_swarm_commander_t;

#define MAVLINK_MSG_ID_SWARM_COMMANDER_LEN 2
#define MAVLINK_MSG_ID_200_LEN 2

#define MAVLINK_MSG_ID_SWARM_COMMANDER_CRC 43
#define MAVLINK_MSG_ID_200_CRC 43



#define MAVLINK_MESSAGE_INFO_SWARM_COMMANDER { \
	"SWARM_COMMANDER", \
	2, \
	{  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_swarm_commander_t, target_system) }, \
         { "cmd_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_swarm_commander_t, cmd_id) }, \
         } \
}


/**
 * @brief Pack a swarm_commander message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  The target_system is defined in enum QUAD_FORMATION_ID (Zero To announce all quads
 * @param cmd_id Command ID is defined in ENUM QUAD_CMD (Command IDs smaller than 0 is no command)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_commander_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t target_system, uint8_t cmd_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SWARM_COMMANDER_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, cmd_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#else
	mavlink_swarm_commander_t packet;
	packet.target_system = target_system;
	packet.cmd_id = cmd_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SWARM_COMMANDER;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN, MAVLINK_MSG_ID_SWARM_COMMANDER_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#endif
}

/**
 * @brief Pack a swarm_commander message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  The target_system is defined in enum QUAD_FORMATION_ID (Zero To announce all quads
 * @param cmd_id Command ID is defined in ENUM QUAD_CMD (Command IDs smaller than 0 is no command)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_swarm_commander_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t target_system,uint8_t cmd_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SWARM_COMMANDER_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, cmd_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#else
	mavlink_swarm_commander_t packet;
	packet.target_system = target_system;
	packet.cmd_id = cmd_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_SWARM_COMMANDER;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN, MAVLINK_MSG_ID_SWARM_COMMANDER_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#endif
}

/**
 * @brief Encode a swarm_commander struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param swarm_commander C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_commander_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_swarm_commander_t* swarm_commander)
{
	return mavlink_msg_swarm_commander_pack(system_id, component_id, msg, swarm_commander->target_system, swarm_commander->cmd_id);
}

/**
 * @brief Encode a swarm_commander struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param swarm_commander C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_swarm_commander_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_swarm_commander_t* swarm_commander)
{
	return mavlink_msg_swarm_commander_pack_chan(system_id, component_id, chan, msg, swarm_commander->target_system, swarm_commander->cmd_id);
}

/**
 * @brief Send a swarm_commander message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  The target_system is defined in enum QUAD_FORMATION_ID (Zero To announce all quads
 * @param cmd_id Command ID is defined in ENUM QUAD_CMD (Command IDs smaller than 0 is no command)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_swarm_commander_send(mavlink_channel_t chan, uint8_t target_system, uint8_t cmd_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_SWARM_COMMANDER_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, cmd_id);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_COMMANDER, buf, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN, MAVLINK_MSG_ID_SWARM_COMMANDER_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_COMMANDER, buf, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#endif
#else
	mavlink_swarm_commander_t packet;
	packet.target_system = target_system;
	packet.cmd_id = cmd_id;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_COMMANDER, (const char *)&packet, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN, MAVLINK_MSG_ID_SWARM_COMMANDER_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_COMMANDER, (const char *)&packet, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_SWARM_COMMANDER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_swarm_commander_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t cmd_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, cmd_id);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_COMMANDER, buf, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN, MAVLINK_MSG_ID_SWARM_COMMANDER_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_COMMANDER, buf, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#endif
#else
	mavlink_swarm_commander_t *packet = (mavlink_swarm_commander_t *)msgbuf;
	packet->target_system = target_system;
	packet->cmd_id = cmd_id;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_COMMANDER, (const char *)packet, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN, MAVLINK_MSG_ID_SWARM_COMMANDER_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SWARM_COMMANDER, (const char *)packet, MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE SWARM_COMMANDER UNPACKING


/**
 * @brief Get field target_system from swarm_commander message
 *
 * @return  The target_system is defined in enum QUAD_FORMATION_ID (Zero To announce all quads
 */
static inline uint8_t mavlink_msg_swarm_commander_get_target_system(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field cmd_id from swarm_commander message
 *
 * @return Command ID is defined in ENUM QUAD_CMD (Command IDs smaller than 0 is no command)
 */
static inline uint8_t mavlink_msg_swarm_commander_get_cmd_id(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a swarm_commander message into a struct
 *
 * @param msg The message to decode
 * @param swarm_commander C-struct to decode the message contents into
 */
static inline void mavlink_msg_swarm_commander_decode(const mavlink_message_t* msg, mavlink_swarm_commander_t* swarm_commander)
{
#if MAVLINK_NEED_BYTE_SWAP
	swarm_commander->target_system = mavlink_msg_swarm_commander_get_target_system(msg);
	swarm_commander->cmd_id = mavlink_msg_swarm_commander_get_cmd_id(msg);
#else
	memcpy(swarm_commander, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_SWARM_COMMANDER_LEN);
#endif
}
