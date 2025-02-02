#include "GeometryMsgs/Msg/ROSPoseWithCovarianceStamped.h"

void FROSPoseWithCovarianceStamped::DDSToUE(const geometry_msgs_msg_PoseWithCovarianceStamped& InData)
{
	Header.DDSToUE(InData.header);
	Pose.DDSToUE(InData.pose);
};

void FROSPoseWithCovarianceStamped::UEToDDS(geometry_msgs_msg_PoseWithCovarianceStamped& OutData) 
{
	Header.UEToDDS(OutData.header);
	Pose.UEToDDS(OutData.pose);
};

void UPoseWithCovarianceStamped_TopicProxy::Initialize()
{
	Data = geometry_msgs_msg_PoseWithCovarianceStamped__alloc();
};

void UPoseWithCovarianceStamped_TopicProxy::Terminate()
{
	geometry_msgs_msg_PoseWithCovarianceStamped_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UPoseWithCovarianceStamped_TopicProxy::GetTypeDesc()
{
	return &geometry_msgs_msg_PoseWithCovarianceStamped_desc;
};

void* UPoseWithCovarianceStamped_TopicProxy::Get()
{
	return Data;
};

void UPoseWithCovarianceStamped_TopicProxy::ExecuteMessageCallback()
{
	FROSPoseWithCovarianceStamped NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UPoseWithCovarianceStamped_TopicProxy::GetData(FROSPoseWithCovarianceStamped& Output)
{
	Output.DDSToUE(*Data);
};

void UPoseWithCovarianceStamped_TopicProxy::SetData(FROSPoseWithCovarianceStamped Input)
{
	Input.UEToDDS(*Data);
};