#include "SensorMsgs/Msg/ROSNavSatStatus.h"

void FROSNavSatStatus::DDSToUE(const sensor_msgs_msg_NavSatStatus& InData)
{
	Status = InData.status;
	Service = InData.service;
}

void FROSNavSatStatus::UEToDDS(sensor_msgs_msg_NavSatStatus& OutData)
{
	OutData.status = Status;
	OutData.service = Service;
};

void UNavSatStatus_TopicProxy::Initialize()
{
    Data = sensor_msgs_msg_NavSatStatus__alloc();
};

void UNavSatStatus_TopicProxy::Terminate()
{
    sensor_msgs_msg_NavSatStatus_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UNavSatStatus_TopicProxy::GetTypeDesc()
{
     return &sensor_msgs_msg_NavSatStatus_desc;
};

void* UNavSatStatus_TopicProxy::Get()
{
    return Data;
};

void UNavSatStatus_TopicProxy::ExecuteMessageCallback()
{
    FROSNavSatStatus NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UNavSatStatus_TopicProxy::GetData(FROSNavSatStatus& Output)
{
    Output.DDSToUE(*Data);
};

void UNavSatStatus_TopicProxy::SetData(FROSNavSatStatus Input)
{
    Input.UEToDDS(*Data);
};