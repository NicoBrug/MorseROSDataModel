/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/builtin_interfaces\msg/Duration.c
  Source: C:\Dev\IDLUnrealCompiler\Messages\builtin_interfaces\msg\Duration.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#include "Duration.h"

static const uint32_t builtin_interfaces_msg_Duration_ops [] =
{
  /* Duration */
  DDS_OP_ADR | DDS_OP_TYPE_4BY | DDS_OP_FLAG_SGN, offsetof (builtin_interfaces_msg_Duration, sec),
  DDS_OP_ADR | DDS_OP_TYPE_4BY, offsetof (builtin_interfaces_msg_Duration, nanosec),
  DDS_OP_RTS
};

const dds_topic_descriptor_t builtin_interfaces_msg_Duration_desc =
{
  .m_size = sizeof (builtin_interfaces_msg_Duration),
  .m_align = dds_alignof (builtin_interfaces_msg_Duration),
  .m_flagset = DDS_TOPIC_FIXED_SIZE,
  .m_nkeys = 0u,
  .m_typename = "builtin_interfaces::msg::Duration",
  .m_keys = NULL,
  .m_nops = 3,
  .m_ops = builtin_interfaces_msg_Duration_ops,
  .m_meta = ""
};

