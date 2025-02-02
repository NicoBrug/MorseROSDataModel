#include "SensorMsgs/Msg/ROSPointCloud2.h"

void FROSPointCloud2::DDSToUE(const sensor_msgs_msg_PointCloud2& InData)
{
	Header.DDSToUE(InData.header);
	Height = InData.height;
	Width = InData.width;
	ConvertUtils::SequenceToTArray<sensor_msgs_msg_PointField, FROSPointField>(InData.fields._buffer, Fields, InData.fields._length);
	IsBigendian = InData.is_bigendian;
	PointStep = InData.point_step;
	RowStep = InData.row_step;
	ConvertUtils::SequenceToTArray<uint8, uint8>(InData.data._buffer, Data, InData.data._length);
	IsDense = InData.is_dense;
};

void FROSPointCloud2::UEToDDS(sensor_msgs_msg_PointCloud2& OutData) 
{
	Header.UEToDDS(OutData.header);
	OutData.height = Height;
	OutData.width = Width;
	OutData.fields._length = Fields.Num();
	OutData.fields._buffer = dds_sequence_sensor_msgs_msg_PointField_allocbuf(Fields.Num());
	OutData.fields._release = true;
	ConvertUtils::TArrayToSequence<sensor_msgs_msg_PointField, FROSPointField>(Fields, OutData.fields._buffer, Fields.Num());
	OutData.is_bigendian = IsBigendian;
	OutData.point_step = PointStep;
	OutData.row_step = RowStep;
	OutData.data._length = Data.Num();
	OutData.data._buffer = dds_sequence_uint8_allocbuf(Data.Num());
	OutData.data._release = true;
	ConvertUtils::TArrayToSequence<uint8, uint8>(Data, OutData.data._buffer, Data.Num());
	OutData.is_dense = IsDense;
};

void UPointCloud2_TopicProxy::Initialize()
{
	Data = sensor_msgs_msg_PointCloud2__alloc();
};

void UPointCloud2_TopicProxy::Terminate()
{
	sensor_msgs_msg_PointCloud2_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UPointCloud2_TopicProxy::GetTypeDesc()
{
	return &sensor_msgs_msg_PointCloud2_desc;
};

void* UPointCloud2_TopicProxy::Get()
{
	return Data;
};

void UPointCloud2_TopicProxy::ExecuteMessageCallback()
{
	FROSPointCloud2 NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UPointCloud2_TopicProxy::GetData(FROSPointCloud2& Output)
{
	Output.DDSToUE(*Data);
};

void UPointCloud2_TopicProxy::SetData(FROSPointCloud2 Input)
{
	Input.UEToDDS(*Data);
};