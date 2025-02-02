#include "GeometryMsgs/Msg/ROSPoint.h"

void FROSPoint::DDSToUE(const geometry_msgs_msg_Point& InData)
{
	X = InData.x;
	Y = InData.y;
	Z = InData.z;
};

void FROSPoint::UEToDDS(geometry_msgs_msg_Point& OutData) 
{
	OutData.x = X;
	OutData.y = Y;
	OutData.z = Z;
};

void UPoint_TopicProxy::Initialize()
{
	Data = geometry_msgs_msg_Point__alloc();
};

void UPoint_TopicProxy::Terminate()
{
	geometry_msgs_msg_Point_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UPoint_TopicProxy::GetTypeDesc()
{
	return &geometry_msgs_msg_Point_desc;
};

void* UPoint_TopicProxy::Get()
{
	return Data;
};

void UPoint_TopicProxy::ExecuteMessageCallback()
{
	FROSPoint NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UPoint_TopicProxy::GetData(FROSPoint& Output)
{
	Output.DDSToUE(*Data);
};

void UPoint_TopicProxy::SetData(FROSPoint Input)
{
	Input.UEToDDS(*Data);
};