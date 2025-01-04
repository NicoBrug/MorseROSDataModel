/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/sensor_msgs\msg/RelativeHumidity.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\sensor_msgs\msg\RelativeHumidity.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_RELATIVEHUMIDITY_H_4350B1FAFC395C05C7E7413ABF76ACF7
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_RELATIVEHUMIDITY_H_4350B1FAFC395C05C7E7413ABF76ACF7

#include "std_msgs\msg\Header.h"

#include "dds/ddsc/dds_public_impl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sensor_msgs_msg_RelativeHumidity
{
  struct std_msgs_msg_Header header;
  double relative_humidity;
  double variance;
} sensor_msgs_msg_RelativeHumidity;

 extern const dds_topic_descriptor_t sensor_msgs_msg_RelativeHumidity_desc;

#define sensor_msgs_msg_RelativeHumidity__alloc() \
((sensor_msgs_msg_RelativeHumidity*) dds_alloc (sizeof (sensor_msgs_msg_RelativeHumidity)));

#define sensor_msgs_msg_RelativeHumidity_free(d,o) \
dds_sample_free ((d), &sensor_msgs_msg_RelativeHumidity_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_RELATIVEHUMIDITY_H_4350B1FAFC395C05C7E7413ABF76ACF7 */
