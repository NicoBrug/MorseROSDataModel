/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/geometry_msgs\msg/Polygon.c
  Source: C:\Dev\IDLUnrealCompiler\Messages\geometry_msgs\msg\Polygon.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#include "Polygon.h"

static const uint32_t geometry_msgs_msg_Polygon_ops [] =
{
  /* Polygon */
  DDS_OP_ADR | DDS_OP_TYPE_SEQ | DDS_OP_SUBTYPE_STU, offsetof (geometry_msgs_msg_Polygon, points), sizeof (geometry_msgs_msg_Point32), (4u << 16u) + 5u /* Point32 */,
  DDS_OP_RTS,

  /* Point32 */
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (geometry_msgs_msg_Point32, x),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (geometry_msgs_msg_Point32, y),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (geometry_msgs_msg_Point32, z),
  DDS_OP_RTS
};

const dds_topic_descriptor_t geometry_msgs_msg_Polygon_desc =
{
  .m_size = sizeof (geometry_msgs_msg_Polygon),
  .m_align = dds_alignof (geometry_msgs_msg_Polygon),
  .m_flagset = 0u,
  .m_nkeys = 0u,
  .m_typename = "geometry_msgs::msg::Polygon",
  .m_keys = NULL,
  .m_nops = 6,
  .m_ops = geometry_msgs_msg_Polygon_ops,
  .m_meta = ""
};

