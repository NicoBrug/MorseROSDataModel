/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/sensor_msgs\msg/Joy.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\sensor_msgs\msg\Joy.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_JOY_H_0ACFA54649AD340A086C0744A66B9A41
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_JOY_H_0ACFA54649AD340A086C0744A66B9A41

#include "std_msgs/msg/Header.h"

#include "dds/ddsc/dds_public_impl.h"
#include "CycloneRos.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DDS_SEQUENCE_FLOAT_DEFINED
#define DDS_SEQUENCE_FLOAT_DEFINED
typedef struct dds_sequence_float
{
  uint32_t _maximum;
  uint32_t _length;
  float *_buffer;
  bool _release;
} dds_sequence_float;

#define dds_sequence_float__alloc() \
((dds_sequence_float*) dds_alloc (sizeof (dds_sequence_float)));

#define dds_sequence_float_allocbuf(l) \
((float *) dds_alloc ((l) * sizeof (float)))
#endif /* DDS_SEQUENCE_FLOAT_DEFINED */

#ifndef DDS_SEQUENCE_INT32_DEFINED
#define DDS_SEQUENCE_INT32_DEFINED
typedef struct dds_sequence_int32
{
  uint32_t _maximum;
  uint32_t _length;
  int32_t *_buffer;
  bool _release;
} dds_sequence_int32;

#define dds_sequence_int32__alloc() \
((dds_sequence_int32*) dds_alloc (sizeof (dds_sequence_int32)));

#define dds_sequence_int32_allocbuf(l) \
((int32_t *) dds_alloc ((l) * sizeof (int32_t)))
#endif /* DDS_SEQUENCE_INT32_DEFINED */

typedef struct sensor_msgs_msg_Joy
{
  struct std_msgs_msg_Header header;
  dds_sequence_float axes;
  dds_sequence_int32 buttons;
} sensor_msgs_msg_Joy;

 extern CYCLONE_ROS_EXPORT const dds_topic_descriptor_t sensor_msgs_msg_Joy_desc;

#define sensor_msgs_msg_Joy__alloc() \
((sensor_msgs_msg_Joy*) dds_alloc (sizeof (sensor_msgs_msg_Joy)));

#define sensor_msgs_msg_Joy_free(d,o) \
dds_sample_free ((d), &sensor_msgs_msg_Joy_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_JOY_H_0ACFA54649AD340A086C0744A66B9A41 */
