/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/geometry_msgs\msg/PolygonStamped.c
  Source: C:\Dev\IDLUnrealCompiler\Messages\geometry_msgs\msg\PolygonStamped.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#include "PolygonStamped.h"

static const uint32_t geometry_msgs_msg_PolygonStamped_ops [] =
{
  /* PolygonStamped */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (geometry_msgs_msg_PolygonStamped, header), (3u << 16u) + 7u /* Header */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (geometry_msgs_msg_PolygonStamped, polygon), (3u << 16u) + 15u /* Polygon */,
  DDS_OP_RTS,

  /* Header */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (std_msgs_msg_Header, stamp), (3u << 16u) + 6u /* Time */,
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (std_msgs_msg_Header, frame_id),
  DDS_OP_RTS,

  /* Time */
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_SGN, offsetof (builtin_interfaces_msg_Time, sec),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (builtin_interfaces_msg_Time, nanosec),
  DDS_OP_RTS,

  /* Polygon */
  DDS_OP_ADR | DDS_OP_TYPE_SEQ | DDS_OP_SUBTYPE_STU, offsetof (geometry_msgs_msg_Polygon, points), sizeof (geometry_msgs_msg_Point32), (4u << 16u) + 5u /* Point32 */,
  DDS_OP_RTS,

  /* Point32 */
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (geometry_msgs_msg_Point32, x),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (geometry_msgs_msg_Point32, y),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (geometry_msgs_msg_Point32, z),
  DDS_OP_RTS
};

const dds_topic_descriptor_t geometry_msgs_msg_PolygonStamped_desc =
{
  .m_size = sizeof (geometry_msgs_msg_PolygonStamped),
  .m_align = dds_alignof (geometry_msgs_msg_PolygonStamped),
  .m_flagset = 0u,
  .m_nkeys = 0u,
  .m_typename = "geometry_msgs::msg::PolygonStamped",
  .m_keys = NULL,
  .m_nops = 15,
  .m_ops = geometry_msgs_msg_PolygonStamped_ops,
  .m_meta = ""
};

