/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/geometry_msgs\msg/AccelWithCovariance.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\geometry_msgs\msg\AccelWithCovariance.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_ACCELWITHCOVARIANCE_H_6279C0284E0737069CC90887BDF310EF
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_ACCELWITHCOVARIANCE_H_6279C0284E0737069CC90887BDF310EF

#include "geometry_msgs/msg/Accel.h"

#include "dds/ddsc/dds_public_impl.h"
#include "CycloneRos.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef double geometry_msgs_msg_double__36[36];

#define geometry_msgs_msg_double__36__alloc() \
((geometry_msgs_msg_double__36*) dds_alloc (sizeof (geometry_msgs_msg_double__36)));

typedef struct geometry_msgs_msg_AccelWithCovariance
{
  struct geometry_msgs_msg_Accel accel;
  geometry_msgs_msg_double__36 covariance;
} geometry_msgs_msg_AccelWithCovariance;

 extern CYCLONE_ROS_EXPORT const dds_topic_descriptor_t geometry_msgs_msg_AccelWithCovariance_desc;

#define geometry_msgs_msg_AccelWithCovariance__alloc() \
((geometry_msgs_msg_AccelWithCovariance*) dds_alloc (sizeof (geometry_msgs_msg_AccelWithCovariance)));

#define geometry_msgs_msg_AccelWithCovariance_free(d,o) \
dds_sample_free ((d), &geometry_msgs_msg_AccelWithCovariance_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_ACCELWITHCOVARIANCE_H_6279C0284E0737069CC90887BDF310EF */
