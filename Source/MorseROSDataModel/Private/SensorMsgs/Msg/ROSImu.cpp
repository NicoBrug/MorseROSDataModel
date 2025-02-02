#include "SensorMsgs/Msg/ROSImu.h"

void FROSImu::DDSToUE(const sensor_msgs_msg_Imu& InData)
{
	Header.DDSToUE(InData.header);
	ConvertUtils::DDSQuaternionToUE(InData.orientation, Orientation);
	ConvertUtils::SequenceToTArray<double, double>(InData.orientation_covariance, OrientationCovariance, 9);
	ConvertUtils::DDSVectorToUE(InData.angular_velocity, AngularVelocity);
	ConvertUtils::SequenceToTArray<double, double>(InData.angular_velocity_covariance, AngularVelocityCovariance, 9);
	ConvertUtils::DDSVectorToUE(InData.linear_acceleration, LinearAcceleration);
	ConvertUtils::SequenceToTArray<double, double>(InData.linear_acceleration_covariance, LinearAccelerationCovariance, 9);
};

void FROSImu::UEToDDS(sensor_msgs_msg_Imu& OutData)
{
	Header.UEToDDS(OutData.header);
	ConvertUtils::UEQuaternionToDDS(Orientation, OutData.orientation);
	ConvertUtils::TArrayToSequence<double, double>(OrientationCovariance,OutData.orientation_covariance, 9);
	ConvertUtils::UEVectorToDDS(AngularVelocity,OutData.angular_velocity);
	ConvertUtils::TArrayToSequence<double, double>(AngularVelocityCovariance, OutData.angular_velocity_covariance, 9);
	ConvertUtils::UEVectorToDDS(LinearAcceleration, OutData.linear_acceleration);
	ConvertUtils::TArrayToSequence<double, double>(LinearAccelerationCovariance, OutData.linear_acceleration_covariance, 9);
};

void UImu_TopicProxy::Initialize()
{
	Data = sensor_msgs_msg_Imu__alloc();
};

void UImu_TopicProxy::Terminate()
{
	sensor_msgs_msg_Imu_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UImu_TopicProxy::GetTypeDesc()
{
	return &sensor_msgs_msg_Imu_desc;
};

void* UImu_TopicProxy::Get()
{
	return Data;
};

void UImu_TopicProxy::ExecuteMessageCallback()
{
	FROSImu NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UImu_TopicProxy::GetData(FROSImu& Output)
{
	Output.DDSToUE(*Data);
};

void UImu_TopicProxy::SetData(FROSImu Input)
{
	Input.UEToDDS(*Data);
};

