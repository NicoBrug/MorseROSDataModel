#include "Tf2Msgs/Msg/ROSTFMessage.h"

void FROSTFMessage::DDSToUE(const tf2_msgs_msg_TFMessage& InData)
{
	ConvertUtils::SequenceToTArray<geometry_msgs_msg_TransformStamped, FROSTransformStamped>(InData.transforms._buffer, Transforms, InData.transforms._length);
};

void FROSTFMessage::UEToDDS(tf2_msgs_msg_TFMessage& OutData) 
{
	OutData.transforms._length = Transforms.Num();
	OutData.transforms._buffer = dds_sequence_geometry_msgs_msg_TransformStamped_allocbuf(Transforms.Num());
	OutData.transforms._release = true;
	ConvertUtils::TArrayToSequence<geometry_msgs_msg_TransformStamped, FROSTransformStamped>(Transforms, OutData.transforms._buffer, Transforms.Num());
};

void UTFMessage_TopicProxy::Initialize()
{
	Data = tf2_msgs_msg_TFMessage__alloc();
};

void UTFMessage_TopicProxy::Terminate()
{
	tf2_msgs_msg_TFMessage_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UTFMessage_TopicProxy::GetTypeDesc()
{
	return &tf2_msgs_msg_TFMessage_desc;
};

void* UTFMessage_TopicProxy::Get()
{
	return Data;
};

void UTFMessage_TopicProxy::ExecuteMessageCallback()
{
	FROSTFMessage NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UTFMessage_TopicProxy::GetData(FROSTFMessage& Output)
{
	Output.DDSToUE(*Data);
};

void UTFMessage_TopicProxy::SetData(FROSTFMessage Input)
{
	Input.UEToDDS(*Data);
};