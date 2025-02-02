#include "GeometryMsgs/Msg/ROSPoseStamped.h"

void FROSPoseStamped::DDSToUE(const geometry_msgs_msg_PoseStamped& InData)
{
	Header.DDSToUE(InData.header);
	Pose.DDSToUE(InData.pose);
};

void FROSPoseStamped::UEToDDS(geometry_msgs_msg_PoseStamped& OutData) 
{
	Header.UEToDDS(OutData.header);
	Pose.UEToDDS(OutData.pose);
};

void UPoseStamped_TopicProxy::Initialize()
{
	Data = geometry_msgs_msg_PoseStamped__alloc();
};

void UPoseStamped_TopicProxy::Terminate()
{
	geometry_msgs_msg_PoseStamped_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UPoseStamped_TopicProxy::GetTypeDesc()
{
	return &geometry_msgs_msg_PoseStamped_desc;
};

void* UPoseStamped_TopicProxy::Get()
{
	return Data;
};

void UPoseStamped_TopicProxy::ExecuteMessageCallback()
{
	FROSPoseStamped NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UPoseStamped_TopicProxy::GetData(FROSPoseStamped& Output)
{
	Output.DDSToUE(*Data);
};

void UPoseStamped_TopicProxy::SetData(FROSPoseStamped Input)
{
	Input.UEToDDS(*Data);
};