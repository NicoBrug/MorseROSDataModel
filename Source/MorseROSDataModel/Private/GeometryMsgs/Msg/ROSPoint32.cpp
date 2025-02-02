#include "GeometryMsgs/Msg/ROSPoint32.h"

void FROSPoint32::DDSToUE(const geometry_msgs_msg_Point32& InData)
{
	X = InData.x;
	Y = InData.y;
	Z = InData.z;
};

void FROSPoint32::UEToDDS(geometry_msgs_msg_Point32& OutData) 
{
	OutData.x = X;
	OutData.y = Y;
	OutData.z = Z;
};

void UPoint32_TopicProxy::Initialize()
{
	Data = geometry_msgs_msg_Point32__alloc();
};

void UPoint32_TopicProxy::Terminate()
{
	geometry_msgs_msg_Point32_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UPoint32_TopicProxy::GetTypeDesc()
{
	return &geometry_msgs_msg_Point32_desc;
};

void* UPoint32_TopicProxy::Get()
{
	return Data;
};

void UPoint32_TopicProxy::ExecuteMessageCallback()
{
	FROSPoint32 NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UPoint32_TopicProxy::GetData(FROSPoint32& Output)
{
	Output.DDSToUE(*Data);
};

void UPoint32_TopicProxy::SetData(FROSPoint32 Input)
{
	Input.UEToDDS(*Data);
};