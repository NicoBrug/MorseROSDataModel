/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/sensor_msgs\msg/RegionOfInterest.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\sensor_msgs\msg\RegionOfInterest.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_REGIONOFINTEREST_H_0DE55D055314582B16B7F5EC44E0A355
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_REGIONOFINTEREST_H_0DE55D055314582B16B7F5EC44E0A355

#include "dds/ddsc/dds_public_impl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sensor_msgs_msg_RegionOfInterest
{
  uint32_t x_offset;
  uint32_t y_offset;
  uint32_t height;
  uint32_t width;
  bool do_rectify;
} sensor_msgs_msg_RegionOfInterest;

 __declspec(dllimport) const dds_topic_descriptor_t sensor_msgs_msg_RegionOfInterest_desc;

#define sensor_msgs_msg_RegionOfInterest__alloc() \
((sensor_msgs_msg_RegionOfInterest*) dds_alloc (sizeof (sensor_msgs_msg_RegionOfInterest)));

#define sensor_msgs_msg_RegionOfInterest_free(d,o) \
dds_sample_free ((d), &sensor_msgs_msg_RegionOfInterest_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_REGIONOFINTEREST_H_0DE55D055314582B16B7F5EC44E0A355 */
