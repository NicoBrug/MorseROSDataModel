#include "SensorMsgs/Msg/ROSJointState.h"

void FROSJointState::DDSToUE(const sensor_msgs_msg_JointState& InData)
{
	Header.DDSToUE(InData.header);
	ConvertUtils::StrSequenceToTArray<char*, FString>(InData.name._buffer, Name, InData.name._length);
	ConvertUtils::SequenceToTArray<double, double>(InData.position._buffer, Position, InData.position._length);
	ConvertUtils::SequenceToTArray<double, double>(InData.velocity._buffer, Velocity, InData.velocity._length);
	ConvertUtils::SequenceToTArray<double, double>(InData.effort._buffer, Effort, InData.effort._length);
}

void FROSJointState::UEToDDS(sensor_msgs_msg_JointState& OutData)
{
	Header.UEToDDS(OutData.header);
	OutData.name._length = Name.Num();
	OutData.name._buffer = dds_sequence_string_allocbuf(Name.Num());
	OutData.name._release = true;
	ConvertUtils::StrTArrayToSequence<char*, FString>(Name, OutData.name._buffer, Name.Num());
	OutData.position._length = Position.Num();
	OutData.position._buffer = dds_sequence_double_allocbuf(Position.Num());
	OutData.position._release = true;
	ConvertUtils::TArrayToSequence<double, double>(Position, OutData.position._buffer, Position.Num());
	OutData.velocity._length = Velocity.Num();
	OutData.velocity._buffer = dds_sequence_double_allocbuf(Velocity.Num());
	OutData.velocity._release = true;
	ConvertUtils::TArrayToSequence<double, double>(Velocity, OutData.velocity._buffer, Velocity.Num());
	OutData.effort._length = Effort.Num();
	OutData.effort._buffer = dds_sequence_double_allocbuf(Effort.Num());
	OutData.effort._release = true;
	ConvertUtils::TArrayToSequence<double, double>(Effort, OutData.effort._buffer, Effort.Num());
};

void UJointState_TopicProxy::Initialize()
{
	Data = sensor_msgs_msg_JointState__alloc();
};

void UJointState_TopicProxy::Terminate()
{
	sensor_msgs_msg_JointState_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UJointState_TopicProxy::GetTypeDesc()
{
	return &sensor_msgs_msg_JointState_desc;
};

void* UJointState_TopicProxy::Get()
{
	return Data;
};

void UJointState_TopicProxy::ExecuteMessageCallback()
{
	FROSJointState NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UJointState_TopicProxy::GetData(FROSJointState& Output)
{
	Output.DDSToUE(*Data);
};

void UJointState_TopicProxy::SetData(FROSJointState Input)
{
	Input.UEToDDS(*Data);
};