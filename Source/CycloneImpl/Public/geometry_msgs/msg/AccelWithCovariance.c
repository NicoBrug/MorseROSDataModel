/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/geometry_msgs\msg/AccelWithCovariance.c
  Source: C:\Dev\IDLUnrealCompiler\Messages\geometry_msgs\msg\AccelWithCovariance.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#include "AccelWithCovariance.h"

static const uint32_t geometry_msgs_msg_AccelWithCovariance_ops [] =
{
  /* AccelWithCovariance */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (geometry_msgs_msg_AccelWithCovariance, accel), (3u << 16u) + 7u /* Accel */,
  DDS_OP_ADR | DDS_OP_TYPE_ARR | DDS_OP_SUBTYPE_8BY | DDS_OP_FLAG_FP, offsetof (geometry_msgs_msg_AccelWithCovariance, covariance), 36u,
  DDS_OP_RTS,

  /* Accel */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (geometry_msgs_msg_Accel, linear), (3u << 16u) + 7u /* Vector3 */,
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (geometry_msgs_msg_Accel, angular), (3u << 16u) + 4u /* Vector3 */,
  DDS_OP_RTS,

  /* Vector3 */
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (geometry_msgs_msg_Vector3, x),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (geometry_msgs_msg_Vector3, y),
  DDS_OP_ADR | DDS_OP_TYPE_8BY | DDS_OP_FLAG_FP, offsetof (geometry_msgs_msg_Vector3, z),
  DDS_OP_RTS
};

const dds_topic_descriptor_t geometry_msgs_msg_AccelWithCovariance_desc =
{
  .m_size = sizeof (geometry_msgs_msg_AccelWithCovariance),
  .m_align = dds_alignof (geometry_msgs_msg_AccelWithCovariance),
  .m_flagset = DDS_TOPIC_FIXED_SIZE,
  .m_nkeys = 0u,
  .m_typename = "geometry_msgs::msg::AccelWithCovariance",
  .m_keys = NULL,
  .m_nops = 10,
  .m_ops = geometry_msgs_msg_AccelWithCovariance_ops,
  .m_meta = ""
};

