/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/geometry_msgs\msg/AccelStamped.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\geometry_msgs\msg\AccelStamped.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_ACCELSTAMPED_H_857251A7CB5978FB82040AA36A27D9F7
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_ACCELSTAMPED_H_857251A7CB5978FB82040AA36A27D9F7

#include "geometry_msgs/msg/Accel.h"

#include "std_msgs/msg/Header.h"

#include "dds/ddsc/dds_public_impl.h"
#include "CycloneRos.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef struct geometry_msgs_msg_AccelStamped
{
  struct std_msgs_msg_Header header;
  struct geometry_msgs_msg_Accel accel;
} geometry_msgs_msg_AccelStamped;

 extern CYCLONE_ROS_EXPORT const dds_topic_descriptor_t geometry_msgs_msg_AccelStamped_desc;

#define geometry_msgs_msg_AccelStamped__alloc() \
((geometry_msgs_msg_AccelStamped*) dds_alloc (sizeof (geometry_msgs_msg_AccelStamped)));

#define geometry_msgs_msg_AccelStamped_free(d,o) \
dds_sample_free ((d), &geometry_msgs_msg_AccelStamped_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_ACCELSTAMPED_H_857251A7CB5978FB82040AA36A27D9F7 */
