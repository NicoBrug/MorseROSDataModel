#include "SensorMsgs/Msg/ROSLaserScan.h"

void FROSLaserScan::DDSToUE(const sensor_msgs_msg_LaserScan& InData)
{
	Header.DDSToUE(InData.header);
	AngleMin = InData.angle_min;
	AngleMax = InData.angle_max;
	AngleIncrement = InData.angle_increment;
	TimeIncrement = InData.time_increment;
	ScanTime = InData.scan_time;
	RangeMin = InData.range_min;
	RangeMax = InData.range_max;
	ConvertUtils::SequenceToTArray<float, float>(InData.ranges._buffer, Ranges, InData.ranges._length);
	ConvertUtils::SequenceToTArray<float, float>(InData.intensities._buffer, Intensities, InData.intensities._length);
};

void FROSLaserScan::UEToDDS(sensor_msgs_msg_LaserScan& OutData) 
{
	Header.UEToDDS(OutData.header);
	OutData.angle_min = AngleMin;
	OutData.angle_max = AngleMax;
	OutData.angle_increment = AngleIncrement;
	OutData.time_increment = TimeIncrement;
	OutData.scan_time = ScanTime;
	OutData.range_min = RangeMin;
	OutData.range_max = RangeMax;
	OutData.ranges._length = Ranges.Num();
	OutData.ranges._buffer = dds_sequence_float_allocbuf(Ranges.Num());
	OutData.ranges._release = true;
	ConvertUtils::TArrayToSequence<float, float>(Ranges, OutData.ranges._buffer, Ranges.Num());
	OutData.intensities._length = Intensities.Num();
	OutData.intensities._buffer = dds_sequence_float_allocbuf(Intensities.Num());
	OutData.intensities._release = true;
	ConvertUtils::TArrayToSequence<float, float>(Intensities, OutData.intensities._buffer, Intensities.Num());
};

void ULaserScan_TopicProxy::Initialize()
{
	Data = sensor_msgs_msg_LaserScan__alloc();
};

void ULaserScan_TopicProxy::Terminate()
{
	sensor_msgs_msg_LaserScan_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* ULaserScan_TopicProxy::GetTypeDesc()
{
	return &sensor_msgs_msg_LaserScan_desc;
};

void* ULaserScan_TopicProxy::Get()
{
	return Data;
};

void ULaserScan_TopicProxy::ExecuteMessageCallback()
{
	FROSLaserScan NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void ULaserScan_TopicProxy::GetData(FROSLaserScan& Output)
{
	Output.DDSToUE(*Data);
};

void ULaserScan_TopicProxy::SetData(FROSLaserScan Input)
{
	Input.UEToDDS(*Data);
};