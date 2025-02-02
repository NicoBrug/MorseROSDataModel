#include "SensorMsgs/Msg/ROSNavSatFix.h"

void FROSNavSatFix::DDSToUE(const sensor_msgs_msg_NavSatFix& InData)
{
	Header.DDSToUE(InData.header);
	Status.DDSToUE(InData.status);
	Latitude = InData.latitude;
	Longitude = InData.longitude;
	Altitude = InData.altitude;
	ConvertUtils::SequenceToTArray<double, double>(InData.position_covariance, PositionCovariance, 9);
	PositionCovarianceType = InData.position_covariance_type;
};

void FROSNavSatFix::UEToDDS(sensor_msgs_msg_NavSatFix& OutData)
{
    Header.UEToDDS(OutData.header);
    Status.UEToDDS(OutData.status);
    OutData.latitude = Latitude;
    OutData.longitude = Longitude;
    OutData.altitude = Altitude;
    ConvertUtils::TArrayToSequence<double, double>(PositionCovariance,OutData.position_covariance, 9);
    OutData.position_covariance_type = PositionCovarianceType;
};

void UNavSatFix_TopicProxy::Initialize()
{
	Data = sensor_msgs_msg_NavSatFix__alloc();
};

void UNavSatFix_TopicProxy::Terminate()
{
	sensor_msgs_msg_NavSatFix_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UNavSatFix_TopicProxy::GetTypeDesc()
{
	return &sensor_msgs_msg_NavSatFix_desc;
};

void* UNavSatFix_TopicProxy::Get()
{
	return Data;
};

void UNavSatFix_TopicProxy::ExecuteMessageCallback()
{
	FROSNavSatFix NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UNavSatFix_TopicProxy::GetData(FROSNavSatFix& Output)
{
	Output.DDSToUE(*Data);
};

void UNavSatFix_TopicProxy::SetData(FROSNavSatFix Input)
{
	Input.UEToDDS(*Data);
};