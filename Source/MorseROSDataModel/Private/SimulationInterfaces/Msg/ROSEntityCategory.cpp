#include "SimulationInterfaces/Msg/ROSEntityCategory.h"





void FROSEntityCategory::DDSToUE(const simulation_interfaces_msg_EntityCategory& InData)
{
        Category = InData.category;
};

void FROSEntityCategory::UEToDDS(simulation_interfaces_msg_EntityCategory& OutData) 
{
        OutData.category = Category;
};

void UEntityCategory_TopicProxy::Initialize()
{
    Data = simulation_interfaces_msg_EntityCategory__alloc();
};

void UEntityCategory_TopicProxy::Terminate()
{
    simulation_interfaces_msg_EntityCategory_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UEntityCategory_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_msg_EntityCategory_desc;
};

void* UEntityCategory_TopicProxy::Get()
{
    return Data;
};

void UEntityCategory_TopicProxy::ExecuteMessageCallback()
{
    FROSEntityCategory NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UEntityCategory_TopicProxy::GetData(FROSEntityCategory& Output)
{
    Output.DDSToUE(*Data);
};

void UEntityCategory_TopicProxy::SetData(FROSEntityCategory Input)
{
    Input.UEToDDS(*Data);
};



