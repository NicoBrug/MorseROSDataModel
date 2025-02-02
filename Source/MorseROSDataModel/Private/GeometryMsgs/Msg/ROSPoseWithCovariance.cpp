#include "GeometryMsgs/Msg/ROSPoseWithCovariance.h"

void FROSPoseWithCovariance::DDSToUE(const geometry_msgs_msg_PoseWithCovariance& InData)
{
	Pose.DDSToUE(InData.pose);
	ConvertUtils::SequenceToTArray<double, double>(InData.covariance, Covariance, 36);
}

void FROSPoseWithCovariance::UEToDDS(geometry_msgs_msg_PoseWithCovariance& OutData)
{
    Pose.UEToDDS(OutData.pose);
    ConvertUtils::TArrayToSequence<double, double>(Covariance,OutData.covariance, 36);
};

void UPoseWithCovariance_TopicProxy::Initialize()
{
	Data = geometry_msgs_msg_PoseWithCovariance__alloc();
};

void UPoseWithCovariance_TopicProxy::Terminate()
{
	geometry_msgs_msg_PoseWithCovariance_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UPoseWithCovariance_TopicProxy::GetTypeDesc()
{
	return &geometry_msgs_msg_PoseWithCovariance_desc;
};

void* UPoseWithCovariance_TopicProxy::Get()
{
	return Data;
};

void UPoseWithCovariance_TopicProxy::ExecuteMessageCallback()
{
	FROSPoseWithCovariance NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UPoseWithCovariance_TopicProxy::GetData(FROSPoseWithCovariance& Output)
{
	Output.DDSToUE(*Data);
};

void UPoseWithCovariance_TopicProxy::SetData(FROSPoseWithCovariance Input)
{
	Input.UEToDDS(*Data);
};