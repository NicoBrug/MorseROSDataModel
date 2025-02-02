#include "BuiltinInterfaces/Msg/ROSTime.h"

void FROSTime::DDSToUE(const builtin_interfaces_msg_Time& InData)
{
	Sec = InData.sec;
	Nanosec = InData.nanosec;
};

void FROSTime::UEToDDS(builtin_interfaces_msg_Time& OutData) 
{
	OutData.sec = Sec;
	OutData.nanosec = Nanosec;
};

void UTime_TopicProxy::Initialize()
{
	Data = builtin_interfaces_msg_Time__alloc();
};

void UTime_TopicProxy::Terminate()
{
	builtin_interfaces_msg_Time_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UTime_TopicProxy::GetTypeDesc()
{
	return &builtin_interfaces_msg_Time_desc;
};

void* UTime_TopicProxy::Get()
{
	return Data;
};

void UTime_TopicProxy::ExecuteMessageCallback()
{
	FROSTime NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UTime_TopicProxy::GetData(FROSTime& Output)
{
	Output.DDSToUE(*Data);
};

void UTime_TopicProxy::SetData(FROSTime Input)
{
	Input.UEToDDS(*Data);
};
