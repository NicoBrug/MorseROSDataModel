#include "SensorMsgs/Msg/ROSRegionOfInterest.h"

void FROSRegionOfInterest::DDSToUE(const sensor_msgs_msg_RegionOfInterest& InData)
{
	XOffset = InData.x_offset;
	YOffset = InData.y_offset;
	Height = InData.height;
	Width = InData.width;
	DoRectify = InData.do_rectify;
};

void FROSRegionOfInterest::UEToDDS(sensor_msgs_msg_RegionOfInterest& OutData) 
{
	OutData.x_offset = XOffset;
	OutData.y_offset = YOffset;
	OutData.height = Height;
	OutData.width = Width;
	OutData.do_rectify = DoRectify;
};

void URegionOfInterest_TopicProxy::Initialize()
{
	Data = sensor_msgs_msg_RegionOfInterest__alloc();
};

void URegionOfInterest_TopicProxy::Terminate()
{
	sensor_msgs_msg_RegionOfInterest_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* URegionOfInterest_TopicProxy::GetTypeDesc()
{
	return &sensor_msgs_msg_RegionOfInterest_desc;
};

void* URegionOfInterest_TopicProxy::Get()
{
	return Data;
};

void URegionOfInterest_TopicProxy::ExecuteMessageCallback()
{
	FROSRegionOfInterest NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void URegionOfInterest_TopicProxy::GetData(FROSRegionOfInterest& Output)
{
	Output.DDSToUE(*Data);
};

void URegionOfInterest_TopicProxy::SetData(FROSRegionOfInterest Input)
{
	Input.UEToDDS(*Data);
};