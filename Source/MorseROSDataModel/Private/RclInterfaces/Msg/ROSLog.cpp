#include "RclInterfaces/Msg/ROSLog.h"

void FROSLog::DDSToUE(const rcl_interfaces_msg_Log& InData)
{
	Stamp.DDSToUE(InData.stamp);
	Level = InData.level;
	ConvertUtils::DDSStringToUE(InData.name, Name);
	ConvertUtils::DDSStringToUE(InData.msg, Msg);
	ConvertUtils::DDSStringToUE(InData.file, File);
	ConvertUtils::DDSStringToUE(InData.function, Function);
	Line = InData.line;
};

void FROSLog::UEToDDS(rcl_interfaces_msg_Log& OutData) 
{
	Stamp.UEToDDS(OutData.stamp);
	OutData.level = Level;
	ConvertUtils::UEStringToDDS(Name, OutData.name);
	ConvertUtils::UEStringToDDS(Msg, OutData.msg);
	ConvertUtils::UEStringToDDS(File, OutData.file);
	ConvertUtils::UEStringToDDS(Function, OutData.function);
	OutData.line = Line;
};

void ULog_TopicProxy::Initialize()
{
	Data = rcl_interfaces_msg_Log__alloc();
};

void ULog_TopicProxy::Terminate()
{
	rcl_interfaces_msg_Log_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* ULog_TopicProxy::GetTypeDesc()
{
	return &rcl_interfaces_msg_Log_desc;
};

void* ULog_TopicProxy::Get()
{
	return Data;
};

void ULog_TopicProxy::ExecuteMessageCallback()
{
	FROSLog NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void ULog_TopicProxy::GetData(FROSLog& Output)
{
	Output.DDSToUE(*Data);
};

void ULog_TopicProxy::SetData(FROSLog Input)
{
	Input.UEToDDS(*Data);
};