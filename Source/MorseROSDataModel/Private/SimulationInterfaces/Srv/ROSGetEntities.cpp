#include "SimulationInterfaces/Srv/ROSGetEntities.h"





void FROSGetEntities_Request::DDSToUE(const simulation_interfaces_srv_GetEntities_Request& InData)
{
        Filters.DDSToUE(InData.filters);
};

void FROSGetEntities_Request::UEToDDS(simulation_interfaces_srv_GetEntities_Request& OutData) 
{
        Filters.UEToDDS(OutData.filters);
};

void UGetEntities_Request_TopicProxy::Initialize()
{
    Data = simulation_interfaces_srv_GetEntities_Request__alloc();
};

void UGetEntities_Request_TopicProxy::Terminate()
{
    simulation_interfaces_srv_GetEntities_Request_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UGetEntities_Request_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_srv_GetEntities_Request_desc;
};

void* UGetEntities_Request_TopicProxy::Get()
{
    return Data;
};

void UGetEntities_Request_TopicProxy::ExecuteMessageCallback()
{
    FROSGetEntities_Request NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UGetEntities_Request_TopicProxy::GetData(FROSGetEntities_Request& Output)
{
    Output.DDSToUE(*Data);
};

void UGetEntities_Request_TopicProxy::SetData(FROSGetEntities_Request Input)
{
    Input.UEToDDS(*Data);
};









void FROSGetEntities_Response::DDSToUE(const simulation_interfaces_srv_GetEntities_Response& InData)
{
        Result.DDSToUE(InData.result);
        ConvertUtils::StrSequenceToTArray<char*, FString>(InData.entities._buffer, Entities, InData.entities._length);
};

void FROSGetEntities_Response::UEToDDS(simulation_interfaces_srv_GetEntities_Response& OutData) 
{
        Result.UEToDDS(OutData.result);
        OutData.entities._length = Entities.Num();
        OutData.entities._buffer = dds_sequence_string_allocbuf(Entities.Num());
        OutData.entities._release = true;
        ConvertUtils::StrTArrayToSequence<char*, FString>(Entities, OutData.entities._buffer, Entities.Num());
};

void UGetEntities_Response_TopicProxy::Initialize()
{
    Data = simulation_interfaces_srv_GetEntities_Response__alloc();
};

void UGetEntities_Response_TopicProxy::Terminate()
{
    simulation_interfaces_srv_GetEntities_Response_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UGetEntities_Response_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_srv_GetEntities_Response_desc;
};

void* UGetEntities_Response_TopicProxy::Get()
{
    return Data;
};

void UGetEntities_Response_TopicProxy::ExecuteMessageCallback()
{
    FROSGetEntities_Response NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UGetEntities_Response_TopicProxy::GetData(FROSGetEntities_Response& Output)
{
    Output.DDSToUE(*Data);
};

void UGetEntities_Response_TopicProxy::SetData(FROSGetEntities_Response Input)
{
    Input.UEToDDS(*Data);
};



