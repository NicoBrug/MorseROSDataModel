/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/geometry_msgs\msg/AccelWithCovarianceStamped.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\geometry_msgs\msg\AccelWithCovarianceStamped.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_ACCELWITHCOVARIANCESTAMPED_H_5A235B32F0DB9C63341419010030FA74
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_ACCELWITHCOVARIANCESTAMPED_H_5A235B32F0DB9C63341419010030FA74

#include "geometry_msgs/msg/AccelWithCovariance.h"

#include "std_msgs/msg/Header.h"

#include "dds/ddsc/dds_public_impl.h"
#include "CycloneRos.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef struct geometry_msgs_msg_AccelWithCovarianceStamped
{
  struct std_msgs_msg_Header header;
  struct geometry_msgs_msg_AccelWithCovariance accel;
} geometry_msgs_msg_AccelWithCovarianceStamped;

 extern CYCLONE_ROS_EXPORT const dds_topic_descriptor_t geometry_msgs_msg_AccelWithCovarianceStamped_desc;

#define geometry_msgs_msg_AccelWithCovarianceStamped__alloc() \
((geometry_msgs_msg_AccelWithCovarianceStamped*) dds_alloc (sizeof (geometry_msgs_msg_AccelWithCovarianceStamped)));

#define geometry_msgs_msg_AccelWithCovarianceStamped_free(d,o) \
dds_sample_free ((d), &geometry_msgs_msg_AccelWithCovarianceStamped_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_ACCELWITHCOVARIANCESTAMPED_H_5A235B32F0DB9C63341419010030FA74 */
