/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/geometry_msgs\msg/Twist.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\geometry_msgs\msg\Twist.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_TWIST_H_2DB6EDBF784A2AB1D1AA523789E6C290
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_TWIST_H_2DB6EDBF784A2AB1D1AA523789E6C290

#include "geometry_msgs\msg\Vector3.h"

#include "dds/ddsc/dds_public_impl.h"



#ifdef __cplusplus
extern "C" {
#endif

typedef struct geometry_msgs_msg_Twist
{
  struct geometry_msgs_msg_Vector3 linear;
  struct geometry_msgs_msg_Vector3 angular;
} geometry_msgs_msg_Twist;

 extern const dds_topic_descriptor_t geometry_msgs_msg_Twist_desc;

#define geometry_msgs_msg_Twist__alloc() \
((geometry_msgs_msg_Twist*) dds_alloc (sizeof (geometry_msgs_msg_Twist)));

#define geometry_msgs_msg_Twist_free(d,o) \
dds_sample_free ((d), &geometry_msgs_msg_Twist_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_TWIST_H_2DB6EDBF784A2AB1D1AA523789E6C290 */
