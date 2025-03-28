/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/sensor_msgs\msg/JoyFeedbackArray.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\sensor_msgs\msg\JoyFeedbackArray.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_JOYFEEDBACKARRAY_H_3A84683369CC587316B0D68EDC1F875D
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_JOYFEEDBACKARRAY_H_3A84683369CC587316B0D68EDC1F875D

#include "sensor_msgs/msg/JoyFeedback.h"

#include "dds/ddsc/dds_public_impl.h"
#include "CycloneRos.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DDS_SEQUENCE_SENSOR_MSGS_MSG_JOYFEEDBACK_DEFINED
#define DDS_SEQUENCE_SENSOR_MSGS_MSG_JOYFEEDBACK_DEFINED
typedef struct dds_sequence_sensor_msgs_msg_JoyFeedback
{
  uint32_t _maximum;
  uint32_t _length;
  struct sensor_msgs_msg_JoyFeedback *_buffer;
  bool _release;
} dds_sequence_sensor_msgs_msg_JoyFeedback;

#define dds_sequence_sensor_msgs_msg_JoyFeedback__alloc() \
((dds_sequence_sensor_msgs_msg_JoyFeedback*) dds_alloc (sizeof (dds_sequence_sensor_msgs_msg_JoyFeedback)));

#define dds_sequence_sensor_msgs_msg_JoyFeedback_allocbuf(l) \
((struct sensor_msgs_msg_JoyFeedback *) dds_alloc ((l) * sizeof (struct sensor_msgs_msg_JoyFeedback)))
#endif /* DDS_SEQUENCE_SENSOR_MSGS_MSG_JOYFEEDBACK_DEFINED */

typedef struct sensor_msgs_msg_JoyFeedbackArray
{
  dds_sequence_sensor_msgs_msg_JoyFeedback array;
} sensor_msgs_msg_JoyFeedbackArray;

 extern CYCLONE_ROS_EXPORT const dds_topic_descriptor_t sensor_msgs_msg_JoyFeedbackArray_desc;

#define sensor_msgs_msg_JoyFeedbackArray__alloc() \
((sensor_msgs_msg_JoyFeedbackArray*) dds_alloc (sizeof (sensor_msgs_msg_JoyFeedbackArray)));

#define sensor_msgs_msg_JoyFeedbackArray_free(d,o) \
dds_sample_free ((d), &sensor_msgs_msg_JoyFeedbackArray_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_JOYFEEDBACKARRAY_H_3A84683369CC587316B0D68EDC1F875D */
