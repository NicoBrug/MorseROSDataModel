/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/std_msgs\msg/Header.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\std_msgs\msg\Header.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_STD_MSGS_MSG_HEADER_H_8CAF84ECB70F7EA576927BB3A4689F5E
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_STD_MSGS_MSG_HEADER_H_8CAF84ECB70F7EA576927BB3A4689F5E

#include "builtin_interfaces/msg/Time.h"

#include "dds/ddsc/dds_public_impl.h"



#ifdef __cplusplus
extern "C" {
#endif

typedef struct std_msgs_msg_Header
{
  struct builtin_interfaces_msg_Time stamp;
  char * frame_id;
} std_msgs_msg_Header;

__declspec(dllimport) const dds_topic_descriptor_t std_msgs_msg_Header_desc;

#define std_msgs_msg_Header__alloc() \
((std_msgs_msg_Header*) dds_alloc (sizeof (std_msgs_msg_Header)));

#define std_msgs_msg_Header_free(d,o) \
dds_sample_free ((d), &std_msgs_msg_Header_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_STD_MSGS_MSG_HEADER_H_8CAF84ECB70F7EA576927BB3A4689F5E */
