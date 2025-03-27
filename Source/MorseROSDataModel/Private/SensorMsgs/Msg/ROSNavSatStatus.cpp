#include "SensorMsgs/Msg/ROSNavSatStatus.h"

void FROSNavSatStatus::DDSToUE(const sensor_msgs_msg_NavSatStatus& InData)
{
    switch(InData.status)
    {
        case ROSNavSatStatus::STATUS_NO_FIX: Status = EROSNavSatStatus::NoFix; break;
        case ROSNavSatStatus::STATUS_FIX: Status = EROSNavSatStatus::Fix; break;
        case ROSNavSatStatus::STATUS_SBAS_FIX: Status = EROSNavSatStatus::SBASFix; break;
        case ROSNavSatStatus::STATUS_GBAS_FIX: Status = EROSNavSatStatus::GBASFix; break;
        default: Status = EROSNavSatStatus::NoFix; break;
    };

    switch(InData.service)
    {
        case ROSNavSatService::SERVICE_GPS: Service = EROSNavSatService::GPS; break;
        case ROSNavSatService::SERVICE_COMPASS: Service = EROSNavSatService::Compass; break;
        case ROSNavSatService::SERVICE_GALILEO: Service = EROSNavSatService::Galileo; break;
        case ROSNavSatService::SERVICE_GLONASS: Service = EROSNavSatService::GLONASS; break;
        default: Service = EROSNavSatService::GPS; break;
    };
};

void FROSNavSatStatus::UEToDDS(sensor_msgs_msg_NavSatStatus& OutData)
{
    switch(Status)
    {
        case EROSNavSatStatus::NoFix: OutData.status = ROSNavSatStatus::STATUS_NO_FIX; break;
        case EROSNavSatStatus::Fix: OutData.status = ROSNavSatStatus::STATUS_FIX; break;
        case EROSNavSatStatus::SBASFix: OutData.status = ROSNavSatStatus::STATUS_SBAS_FIX; break;
        case EROSNavSatStatus::GBASFix: OutData.status = ROSNavSatStatus::STATUS_GBAS_FIX; break;
        default: OutData.status = ROSNavSatStatus::STATUS_NO_FIX; break;
    };

    switch(Service)
    {
        case EROSNavSatService::GPS: OutData.service = ROSNavSatService::SERVICE_GPS; break;
        case EROSNavSatService::Compass: OutData.service = ROSNavSatService::SERVICE_COMPASS; break;
        case EROSNavSatService::Galileo: OutData.service = ROSNavSatService::SERVICE_GALILEO; break;
        case EROSNavSatService::GLONASS: OutData.service = ROSNavSatService::SERVICE_GLONASS; break;
        default: OutData.service= ROSNavSatService::SERVICE_GPS; break;
    };
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