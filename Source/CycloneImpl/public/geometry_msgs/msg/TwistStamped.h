/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/geometry_msgs\msg/TwistStamped.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\geometry_msgs\msg\TwistStamped.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_TWISTSTAMPED_H_78563AB4C9BEFF67BFF15FCD0820A4E6
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_TWISTSTAMPED_H_78563AB4C9BEFF67BFF15FCD0820A4E6

#include "geometry_msgs\msg\Twist.h"

#include "std_msgs\msg\Header.h"

#include "dds/ddsc/dds_public_impl.h"



#ifdef __cplusplus
extern "C" {
#endif

typedef struct geometry_msgs_msg_TwistStamped
{
  struct std_msgs_msg_Header header;
  struct geometry_msgs_msg_Twist twist;
} geometry_msgs_msg_TwistStamped;

 extern const dds_topic_descriptor_t geometry_msgs_msg_TwistStamped_desc;

#define geometry_msgs_msg_TwistStamped__alloc() \
((geometry_msgs_msg_TwistStamped*) dds_alloc (sizeof (geometry_msgs_msg_TwistStamped)));

#define geometry_msgs_msg_TwistStamped_free(d,o) \
dds_sample_free ((d), &geometry_msgs_msg_TwistStamped_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_GEOMETRY_MSGS_MSG_TWISTSTAMPED_H_78563AB4C9BEFF67BFF15FCD0820A4E6 */
