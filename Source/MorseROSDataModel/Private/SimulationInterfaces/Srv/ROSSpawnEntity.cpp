#include  "SimulationInterfaces/Srv/ROSSpawnEntity.h"

void FROSSpawnEntity_Request::DDSToUE(const simulation_interfaces_srv_SpawnEntity_Request& InData)
{
        ConvertUtils::DDSStringToUE(InData.name, Name);
        AllowRenaming = InData.allow_renaming;
        ConvertUtils::DDSStringToUE(InData.uri, Uri);
        ConvertUtils::DDSStringToUE(InData.resource_string, ResourceString);
        ConvertUtils::DDSStringToUE(InData.entity_namespace, EntityNamespace);
        InitialPose.DDSToUE(InData.initial_pose);
};

void FROSSpawnEntity_Request::UEToDDS(simulation_interfaces_srv_SpawnEntity_Request& OutData) 
{
        ConvertUtils::UEStringToDDS(Name, OutData.name);
        OutData.allow_renaming = AllowRenaming;
        ConvertUtils::UEStringToDDS(Uri, OutData.uri);
        ConvertUtils::UEStringToDDS(ResourceString, OutData.resource_string);
        ConvertUtils::UEStringToDDS(EntityNamespace, OutData.entity_namespace);
        InitialPose.UEToDDS(OutData.initial_pose);
};

void USpawnEntity_Request_TopicProxy::Initialize()
{
    Data = simulation_interfaces_srv_SpawnEntity_Request__alloc();
};

void USpawnEntity_Request_TopicProxy::Terminate()
{
    simulation_interfaces_srv_SpawnEntity_Request_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* USpawnEntity_Request_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_srv_SpawnEntity_Request_desc;
};

void* USpawnEntity_Request_TopicProxy::Get()
{
    return Data;
};

void USpawnEntity_Request_TopicProxy::ExecuteMessageCallback()
{
    FROSSpawnEntity_Request NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void USpawnEntity_Request_TopicProxy::GetData(FROSSpawnEntity_Request& Output)
{
    Output.DDSToUE(*Data);
};

void USpawnEntity_Request_TopicProxy::SetData(FROSSpawnEntity_Request Input)
{
    Input.UEToDDS(*Data);
};









void FROSSpawnEntity_Response::DDSToUE(const simulation_interfaces_srv_SpawnEntity_Response& InData)
{
        Result.DDSToUE(InData.result);
        ConvertUtils::DDSStringToUE(InData.entity_name, EntityName);
};

void FROSSpawnEntity_Response::UEToDDS(simulation_interfaces_srv_SpawnEntity_Response& OutData) 
{
        Result.UEToDDS(OutData.result);
        ConvertUtils::UEStringToDDS(EntityName, OutData.entity_name);
};

void USpawnEntity_Response_TopicProxy::Initialize()
{
    Data = simulation_interfaces_srv_SpawnEntity_Response__alloc();
};

void USpawnEntity_Response_TopicProxy::Terminate()
{
    simulation_interfaces_srv_SpawnEntity_Response_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* USpawnEntity_Response_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_srv_SpawnEntity_Response_desc;
};

void* USpawnEntity_Response_TopicProxy::Get()
{
    return Data;
};

void USpawnEntity_Response_TopicProxy::ExecuteMessageCallback()
{
    FROSSpawnEntity_Response NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void USpawnEntity_Response_TopicProxy::GetData(FROSSpawnEntity_Response& Output)
{
    Output.DDSToUE(*Data);
};

void USpawnEntity_Response_TopicProxy::SetData(FROSSpawnEntity_Response Input)
{
    Input.UEToDDS(*Data);
};



