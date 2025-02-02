#include "SensorMsgs/Msg/ROSPointCloud.h"

void FROSPointCloud::DDSToUE(const sensor_msgs_msg_PointCloud& InData)
{
	Header.DDSToUE(InData.header);
	ConvertUtils::SequenceToTArray<geometry_msgs_msg_Point32, FROSPoint32>(InData.points._buffer, Points, InData.points._length);
	ConvertUtils::SequenceToTArray<sensor_msgs_msg_ChannelFloat32, FROSChannelFloat32>(InData.channels._buffer, Channels, InData.channels._length);
};

void FROSPointCloud::UEToDDS(sensor_msgs_msg_PointCloud& OutData) 
{
	Header.UEToDDS(OutData.header);
	OutData.points._length = Points.Num();
	OutData.points._buffer = dds_sequence_geometry_msgs_msg_Point32_allocbuf(Points.Num());
	OutData.points._release = true;
	ConvertUtils::TArrayToSequence<geometry_msgs_msg_Point32, FROSPoint32>(Points, OutData.points._buffer, Points.Num());
	OutData.channels._length = Channels.Num();
	OutData.channels._buffer = dds_sequence_sensor_msgs_msg_ChannelFloat32_allocbuf(Channels.Num());
	OutData.channels._release = true;
	ConvertUtils::TArrayToSequence<sensor_msgs_msg_ChannelFloat32, FROSChannelFloat32>(Channels, OutData.channels._buffer, Channels.Num());
};

void UPointCloud_TopicProxy::Initialize()
{
	Data = sensor_msgs_msg_PointCloud__alloc();
};

void UPointCloud_TopicProxy::Terminate()
{
	sensor_msgs_msg_PointCloud_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UPointCloud_TopicProxy::GetTypeDesc()
{
	return &sensor_msgs_msg_PointCloud_desc;
};

void* UPointCloud_TopicProxy::Get()
{
	return Data;
};

void UPointCloud_TopicProxy::ExecuteMessageCallback()
{
	FROSPointCloud NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UPointCloud_TopicProxy::GetData(FROSPointCloud& Output)
{
	Output.DDSToUE(*Data);
};

void UPointCloud_TopicProxy::SetData(FROSPointCloud Input)
{
	Input.UEToDDS(*Data);
};