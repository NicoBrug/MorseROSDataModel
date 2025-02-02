#include "SensorMsgs/Msg/ROSChannelFloat32.h"

void FROSChannelFloat32::DDSToUE (const sensor_msgs_msg_ChannelFloat32& InData)
{
	ConvertUtils::DDSStringToUE(InData.name, Name);
	ConvertUtils::SequenceToTArray<float, float>(InData.values._buffer, Values, InData.values._length);
};

void FROSChannelFloat32::UEToDDS(sensor_msgs_msg_ChannelFloat32& OutData) 
{
	ConvertUtils::UEStringToDDS(Name, OutData.name );
	OutData.values._length = Values.Num();
	OutData.values._buffer = dds_sequence_float_allocbuf(Values.Num());
	OutData.values._release = true;
	ConvertUtils::TArrayToSequence<float, float>(Values, OutData.values._buffer, Values.Num());
};
