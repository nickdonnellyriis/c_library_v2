#pragma once
// MESSAGE VIDEO_STREAM_TARGET PACKING

#define MAVLINK_MSG_ID_VIDEO_STREAM_TARGET 269

MAVPACKED(
typedef struct __mavlink_video_stream_target_t {
 uint8_t camera_id; /*< Camera ID if there are multiple*/
 char url[250]; /*< Video stream target URL*/
}) mavlink_video_stream_target_t;

#define MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN 251
#define MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_MIN_LEN 251
#define MAVLINK_MSG_ID_269_LEN 251
#define MAVLINK_MSG_ID_269_MIN_LEN 251

#define MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_CRC 233
#define MAVLINK_MSG_ID_269_CRC 233

#define MAVLINK_MSG_VIDEO_STREAM_TARGET_FIELD_URL_LEN 250

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_TARGET { \
    269, \
    "VIDEO_STREAM_TARGET", \
    2, \
    {  { "camera_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_video_stream_target_t, camera_id) }, \
         { "url", NULL, MAVLINK_TYPE_CHAR, 250, 1, offsetof(mavlink_video_stream_target_t, url) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_TARGET { \
    "VIDEO_STREAM_TARGET", \
    2, \
    {  { "camera_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_video_stream_target_t, camera_id) }, \
         { "url", NULL, MAVLINK_TYPE_CHAR, 250, 1, offsetof(mavlink_video_stream_target_t, url) }, \
         } \
}
#endif

/**
 * @brief Pack a video_stream_target message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param camera_id Camera ID if there are multiple
 * @param url Video stream target URL
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_target_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t camera_id, const char *url)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN];
    _mav_put_uint8_t(buf, 0, camera_id);
    _mav_put_char_array(buf, 1, url, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN);
#else
    mavlink_video_stream_target_t packet;
    packet.camera_id = camera_id;
    mav_array_memcpy(packet.url, url, sizeof(char)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_TARGET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_CRC);
}

/**
 * @brief Pack a video_stream_target message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param camera_id Camera ID if there are multiple
 * @param url Video stream target URL
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_target_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t camera_id,const char *url)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN];
    _mav_put_uint8_t(buf, 0, camera_id);
    _mav_put_char_array(buf, 1, url, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN);
#else
    mavlink_video_stream_target_t packet;
    packet.camera_id = camera_id;
    mav_array_memcpy(packet.url, url, sizeof(char)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_TARGET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_CRC);
}

/**
 * @brief Encode a video_stream_target struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_target_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_video_stream_target_t* video_stream_target)
{
    return mavlink_msg_video_stream_target_pack(system_id, component_id, msg, video_stream_target->camera_id, video_stream_target->url);
}

/**
 * @brief Encode a video_stream_target struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_target C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_target_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_video_stream_target_t* video_stream_target)
{
    return mavlink_msg_video_stream_target_pack_chan(system_id, component_id, chan, msg, video_stream_target->camera_id, video_stream_target->url);
}

/**
 * @brief Send a video_stream_target message
 * @param chan MAVLink channel to send the message
 *
 * @param camera_id Camera ID if there are multiple
 * @param url Video stream target URL
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_video_stream_target_send(mavlink_channel_t chan, uint8_t camera_id, const char *url)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN];
    _mav_put_uint8_t(buf, 0, camera_id);
    _mav_put_char_array(buf, 1, url, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET, buf, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_CRC);
#else
    mavlink_video_stream_target_t packet;
    packet.camera_id = camera_id;
    mav_array_memcpy(packet.url, url, sizeof(char)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET, (const char *)&packet, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_CRC);
#endif
}

/**
 * @brief Send a video_stream_target message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_video_stream_target_send_struct(mavlink_channel_t chan, const mavlink_video_stream_target_t* video_stream_target)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_video_stream_target_send(chan, video_stream_target->camera_id, video_stream_target->url);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET, (const char *)video_stream_target, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_CRC);
#endif
}

#if MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_video_stream_target_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t camera_id, const char *url)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, camera_id);
    _mav_put_char_array(buf, 1, url, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET, buf, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_CRC);
#else
    mavlink_video_stream_target_t *packet = (mavlink_video_stream_target_t *)msgbuf;
    packet->camera_id = camera_id;
    mav_array_memcpy(packet->url, url, sizeof(char)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET, (const char *)packet, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_CRC);
#endif
}
#endif

#endif

// MESSAGE VIDEO_STREAM_TARGET UNPACKING


/**
 * @brief Get field camera_id from video_stream_target message
 *
 * @return Camera ID if there are multiple
 */
static inline uint8_t mavlink_msg_video_stream_target_get_camera_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field url from video_stream_target message
 *
 * @return Video stream target URL
 */
static inline uint16_t mavlink_msg_video_stream_target_get_url(const mavlink_message_t* msg, char *url)
{
    return _MAV_RETURN_char_array(msg, url, 250,  1);
}

/**
 * @brief Decode a video_stream_target message into a struct
 *
 * @param msg The message to decode
 * @param video_stream_target C-struct to decode the message contents into
 */
static inline void mavlink_msg_video_stream_target_decode(const mavlink_message_t* msg, mavlink_video_stream_target_t* video_stream_target)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    video_stream_target->camera_id = mavlink_msg_video_stream_target_get_camera_id(msg);
    mavlink_msg_video_stream_target_get_url(msg, video_stream_target->url);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN? msg->len : MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN;
        memset(video_stream_target, 0, MAVLINK_MSG_ID_VIDEO_STREAM_TARGET_LEN);
    memcpy(video_stream_target, _MAV_PAYLOAD(msg), len);
#endif
}
