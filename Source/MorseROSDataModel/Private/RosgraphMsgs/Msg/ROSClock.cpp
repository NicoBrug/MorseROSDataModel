#include "RosgraphMsgs/Msg/ROSClock.h"

void FROSClock::DDSToUE(const rosgraph_msgs_msg_Clock& InData)
{
	Clock.DDSToUE(InData.clock);
};

void FROSClock::UEToDDS(rosgraph_msgs_msg_Clock& OutData) 
{
	Clock.UEToDDS(OutData.clock);
};

void UClock_TopicProxy::Initialize()
{
	Data = rosgraph_msgs_msg_Clock__alloc();
};

void UClock_TopicProxy::Terminate()
{
	rosgraph_msgs_msg_Clock_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UClock_TopicProxy::GetTypeDesc()
{
	return &rosgraph_msgs_msg_Clock_desc;
};

void* UClock_TopicProxy::Get()
{
	return Data;
};

void UClock_TopicProxy::ExecuteMessageCallback()
{
	FROSClock NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UClock_TopicProxy::GetData(FROSClock& Output)
{
	Output.DDSToUE(*Data);
};

void UClock_TopicProxy::SetData(FROSClock Input)
{
	Input.UEToDDS(*Data);
};