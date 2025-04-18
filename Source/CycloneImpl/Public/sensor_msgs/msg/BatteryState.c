/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/sensor_msgs\msg/BatteryState.c
  Source: C:\Dev\IDLUnrealCompiler\Messages\sensor_msgs\msg\BatteryState.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#include "BatteryState.h"

static const uint32_t sensor_msgs_msg_BatteryState_ops [] =
{
  /* BatteryState */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (sensor_msgs_msg_BatteryState, header), (3u << 16u) + 34u /* Header */,
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sensor_msgs_msg_BatteryState, voltage),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sensor_msgs_msg_BatteryState, temperature),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sensor_msgs_msg_BatteryState, current),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sensor_msgs_msg_BatteryState, charge),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sensor_msgs_msg_BatteryState, capacity),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sensor_msgs_msg_BatteryState, design_capacity),
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_FP, offsetof (sensor_msgs_msg_BatteryState, percentage),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (sensor_msgs_msg_BatteryState, power_supply_status),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (sensor_msgs_msg_BatteryState, power_supply_health),
  DDS_OP_ADR | DDS_OP_TYPE_1BY, offsetof (sensor_msgs_msg_BatteryState, power_supply_technology),
  DDS_OP_ADR | DDS_OP_TYPE_BLN, offsetof (sensor_msgs_msg_BatteryState, present),
  DDS_OP_ADR | DDS_OP_TYPE_SEQ | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_FP, offsetof (sensor_msgs_msg_BatteryState, cell_voltage),
  DDS_OP_ADR | DDS_OP_TYPE_SEQ | DDS_OP_SUBTYPE_4BY | DDS_OP_FLAG_FP, offsetof (sensor_msgs_msg_BatteryState, cell_temperature),
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (sensor_msgs_msg_BatteryState, location),
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (sensor_msgs_msg_BatteryState, serial_number),
  DDS_OP_RTS,

  /* Header */
  DDS_OP_ADR | DDS_OP_TYPE_EXT, offsetof (std_msgs_msg_Header, stamp), (3u << 16u) + 6u /* Time */,
  DDS_OP_ADR | DDS_OP_TYPE_STR, offsetof (std_msgs_msg_Header, frame_id),
  DDS_OP_RTS,

  /* Time */
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_SGN, offsetof (builtin_interfaces_msg_Time, sec),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (builtin_interfaces_msg_Time, nanosec),
  DDS_OP_RTS
};

const dds_topic_descriptor_t sensor_msgs_msg_BatteryState_desc =
{
  .m_size = sizeof (sensor_msgs_msg_BatteryState),
  .m_align = dds_alignof (sensor_msgs_msg_BatteryState),
  .m_flagset = 0u,
  .m_nkeys = 0u,
  .m_typename = "sensor_msgs::msg::BatteryState",
  .m_keys = NULL,
  .m_nops = 23,
  .m_ops = sensor_msgs_msg_BatteryState_ops,
  .m_meta = ""
};

