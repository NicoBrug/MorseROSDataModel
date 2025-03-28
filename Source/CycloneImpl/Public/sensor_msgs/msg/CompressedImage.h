/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\IDLUnrealCompiler\Generated/sensor_msgs\msg/CompressedImage.h
  Source: C:\Dev\IDLUnrealCompiler\Messages\sensor_msgs\msg\CompressedImage.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_COMPRESSEDIMAGE_H_C2C5F9B3F4056CC5AE70AF7749E62BFB
#define DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_COMPRESSEDIMAGE_H_C2C5F9B3F4056CC5AE70AF7749E62BFB

#include "std_msgs/msg/Header.h"

#include "dds/ddsc/dds_public_impl.h"
#include "CycloneRos.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DDS_SEQUENCE_UINT8_DEFINED
#define DDS_SEQUENCE_UINT8_DEFINED
typedef struct dds_sequence_uint8
{
  uint32_t _maximum;
  uint32_t _length;
  uint8_t *_buffer;
  bool _release;
} dds_sequence_uint8;

#define dds_sequence_uint8__alloc() \
((dds_sequence_uint8*) dds_alloc (sizeof (dds_sequence_uint8)));

#define dds_sequence_uint8_allocbuf(l) \
((uint8_t *) dds_alloc ((l) * sizeof (uint8_t)))
#endif /* DDS_SEQUENCE_UINT8_DEFINED */

typedef struct sensor_msgs_msg_CompressedImage
{
  struct std_msgs_msg_Header header;
  char * format;
  dds_sequence_uint8 data;
} sensor_msgs_msg_CompressedImage;

 extern CYCLONE_ROS_EXPORT const dds_topic_descriptor_t sensor_msgs_msg_CompressedImage_desc;

#define sensor_msgs_msg_CompressedImage__alloc() \
((sensor_msgs_msg_CompressedImage*) dds_alloc (sizeof (sensor_msgs_msg_CompressedImage)));

#define sensor_msgs_msg_CompressedImage_free(d,o) \
dds_sample_free ((d), &sensor_msgs_msg_CompressedImage_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_IDLUNREALCOMPILER_GENERATED_SENSOR_MSGS_MSG_COMPRESSEDIMAGE_H_C2C5F9B3F4056CC5AE70AF7749E62BFB */
