/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to C Translator
  File name: C:\Dev\DataTypes\COMPILED/simulation_interfaces\msg/TagsFilter.h
  Source: C:\Dev\DataTypes\ROS\simulation_interfaces\msg\TagsFilter.idl
  Cyclone DDS: V0.11.0

*****************************************************************/
#ifndef DDSC_C__DEV_DATATYPES_COMPILED_SIMULATION_INTERFACES_MSG_TAGSFILTER_H_011DA26E26FFC2CA02AE399906E639CF
#define DDSC_C__DEV_DATATYPES_COMPILED_SIMULATION_INTERFACES_MSG_TAGSFILTER_H_011DA26E26FFC2CA02AE399906E639CF

#include "CycloneRos.h"
#include "dds/ddsc/dds_public_impl.h"

#ifdef __cplusplus
extern "C" {
#endif

#define simulation_interfaces_msg_TagsFilter_Constants_FILTER_MODE_ANY 0
#define simulation_interfaces_msg_TagsFilter_Constants_FILTER_MODE_ALL 1
#ifndef DDS_SEQUENCE_STRING_DEFINED
#define DDS_SEQUENCE_STRING_DEFINED
typedef struct dds_sequence_string
{
  uint32_t _maximum;
  uint32_t _length;
  char **_buffer;
  bool _release;
} dds_sequence_string;

#define dds_sequence_string__alloc() \
((dds_sequence_string*) dds_alloc (sizeof (dds_sequence_string)));

#define dds_sequence_string_allocbuf(l) \
((char **) dds_alloc ((l) * sizeof (char*)))
#endif /* DDS_SEQUENCE_STRING_DEFINED */

typedef struct simulation_interfaces_msg_TagsFilter
{
  dds_sequence_string tags;
  uint8_t filter_mode;
} simulation_interfaces_msg_TagsFilter;

extern CYCLONE_ROS_EXPORT const dds_topic_descriptor_t simulation_interfaces_msg_TagsFilter_desc;

#define simulation_interfaces_msg_TagsFilter__alloc() \
((simulation_interfaces_msg_TagsFilter*) dds_alloc (sizeof (simulation_interfaces_msg_TagsFilter)));

#define simulation_interfaces_msg_TagsFilter_free(d,o) \
dds_sample_free ((d), &simulation_interfaces_msg_TagsFilter_desc, (o))

#ifdef __cplusplus
}
#endif

#endif /* DDSC_C__DEV_DATATYPES_COMPILED_SIMULATION_INTERFACES_MSG_TAGSFILTER_H_011DA26E26FFC2CA02AE399906E639CF */
