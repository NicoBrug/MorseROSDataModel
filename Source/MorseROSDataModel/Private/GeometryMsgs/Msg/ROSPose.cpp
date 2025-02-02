#include "GeometryMsgs/Msg/ROSPose.h"

void FROSPose::DDSToUE(const geometry_msgs_msg_Pose& InData)
{
	Position.DDSToUE(InData.position);
	ConvertUtils::DDSQuaternionToUE(InData.orientation, Orientation);
};

void FROSPose::UEToDDS(geometry_msgs_msg_Pose& OutData) 
{
	Position.UEToDDS(OutData.position);
	ConvertUtils::UEQuaternionToDDS(Orientation, OutData.orientation);
};

void UPose_TopicProxy::Initialize()
{
	Data = geometry_msgs_msg_Pose__alloc();
};

void UPose_TopicProxy::Terminate()
{
	geometry_msgs_msg_Pose_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UPose_TopicProxy::GetTypeDesc()
{
	return &geometry_msgs_msg_Pose_desc;
};

void* UPose_TopicProxy::Get()
{
	return Data;
};

void UPose_TopicProxy::ExecuteMessageCallback()
{
	FROSPose NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UPose_TopicProxy::GetData(FROSPose& Output)
{
	Output.DDSToUE(*Data);
};

void UPose_TopicProxy::SetData(FROSPose Input)
{
	Input.UEToDDS(*Data);
};