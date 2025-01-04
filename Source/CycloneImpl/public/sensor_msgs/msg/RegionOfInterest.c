/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/sensor_msgs\msg/RegionOfInterest.c
  Source: C:\Dev\IDLUnrealCompiler\Messages\sensor_msgs\msg\RegionOfInterest.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#include "RegionOfInterest.h"

static const uint32_t sensor_msgs_msg_RegionOfInterest_ops [] =
{
  /* RegionOfInterest */
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (sensor_msgs_msg_RegionOfInterest, x_offset),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (sensor_msgs_msg_RegionOfInterest, y_offset),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (sensor_msgs_msg_RegionOfInterest, height),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (sensor_msgs_msg_RegionOfInterest, width),
  DDS_OP_ADR | DDS_OP_TYPE_BLN, offsetof (sensor_msgs_msg_RegionOfInterest, do_rectify),
  DDS_OP_RTS
};

const dds_topic_descriptor_t sensor_msgs_msg_RegionOfInterest_desc =
{
  .m_size = sizeof (sensor_msgs_msg_RegionOfInterest),
  .m_align = dds_alignof (sensor_msgs_msg_RegionOfInterest),
  .m_flagset = DDS_TOPIC_FIXED_SIZE,
  .m_nkeys = 0u,
  .m_typename = "sensor_msgs::msg::dds_::RegionOfInterest_",
  .m_keys = NULL,
  .m_nops = 6,
  .m_ops = sensor_msgs_msg_RegionOfInterest_ops,
  .m_meta = ""
};

