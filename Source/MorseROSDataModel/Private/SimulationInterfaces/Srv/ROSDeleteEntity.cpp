#include "SimulationInterfaces/Srv/ROSDeleteEntity.h"





void FROSDeleteEntity_Request::DDSToUE(const simulation_interfaces_srv_DeleteEntity_Request& InData)
{
        ConvertUtils::DDSStringToUE(InData.entity, Entity);
};

void FROSDeleteEntity_Request::UEToDDS(simulation_interfaces_srv_DeleteEntity_Request& OutData) 
{
        ConvertUtils::UEStringToDDS(Entity, OutData.entity);
};

void UDeleteEntity_Request_TopicProxy::Initialize()
{
    Data = simulation_interfaces_srv_DeleteEntity_Request__alloc();
};

void UDeleteEntity_Request_TopicProxy::Terminate()
{
    simulation_interfaces_srv_DeleteEntity_Request_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UDeleteEntity_Request_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_srv_DeleteEntity_Request_desc;
};

void* UDeleteEntity_Request_TopicProxy::Get()
{
    return Data;
};

void UDeleteEntity_Request_TopicProxy::ExecuteMessageCallback()
{
    FROSDeleteEntity_Request NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UDeleteEntity_Request_TopicProxy::GetData(FROSDeleteEntity_Request& Output)
{
    Output.DDSToUE(*Data);
};

void UDeleteEntity_Request_TopicProxy::SetData(FROSDeleteEntity_Request Input)
{
    Input.UEToDDS(*Data);
};









void FROSDeleteEntity_Response::DDSToUE(const simulation_interfaces_srv_DeleteEntity_Response& InData)
{
        Result.DDSToUE(InData.result);
};

void FROSDeleteEntity_Response::UEToDDS(simulation_interfaces_srv_DeleteEntity_Response& OutData) 
{
        Result.UEToDDS(OutData.result);
};

void UDeleteEntity_Response_TopicProxy::Initialize()
{
    Data = simulation_interfaces_srv_DeleteEntity_Response__alloc();
};

void UDeleteEntity_Response_TopicProxy::Terminate()
{
    simulation_interfaces_srv_DeleteEntity_Response_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UDeleteEntity_Response_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_srv_DeleteEntity_Response_desc;
};

void* UDeleteEntity_Response_TopicProxy::Get()
{
    return Data;
};

void UDeleteEntity_Response_TopicProxy::ExecuteMessageCallback()
{
    FROSDeleteEntity_Response NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UDeleteEntity_Response_TopicProxy::GetData(FROSDeleteEntity_Response& Output)
{
    Output.DDSToUE(*Data);
};

void UDeleteEntity_Response_TopicProxy::SetData(FROSDeleteEntity_Response Input)
{
    Input.UEToDDS(*Data);
};



