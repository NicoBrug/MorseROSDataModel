/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/builtin_interfaces\msg/Time.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\builtin_interfaces\msg\Time.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_BUILTIN_INTERFACES_MSG_TIME_H_4ADD12306D43A59DC20099EF6386D747
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_BUILTIN_INTERFACES_MSG_TIME_H_4ADD12306D43A59DC20099EF6386D747

#include "dds/ddsc/dds_public_impl.h"
#include "CycloneRos.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct builtin_interfaces_msg_Time
{
  int32_t sec;
  uint32_t nanosec;
} builtin_interfaces_msg_Time;

extern CYCLONE_ROS_EXPORT const dds_topic_descriptor_t builtin_interfaces_msg_Time_desc;

#define builtin_interfaces_msg_Time__alloc() \
((builtin_interfaces_msg_Time*) dds_alloc (sizeof (builtin_interfaces_msg_Time)));

#define builtin_interfaces_msg_Time_free(d,o) \
dds_sample_free ((d), &builtin_interfaces_msg_Time_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_BUILTIN_INTERFACES_MSG_TIME_H_4ADD12306D43A59DC20099EF6386D747 */
