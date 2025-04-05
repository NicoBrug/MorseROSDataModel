#include "SimulationInterfaces/Msg/ROSEntityFilters.h"





void FROSEntityFilters::DDSToUE(const simulation_interfaces_msg_EntityFilters& InData)
{
        ConvertUtils::DDSStringToUE(InData.filter, Filter);
        ConvertUtils::SequenceToTArray<simulation_interfaces_msg_EntityCategory, FROSEntityCategory>(InData.categories._buffer, Categories, InData.categories._length);
        Tags.DDSToUE(InData.tags);
        Bounds.DDSToUE(InData.bounds);
};

void FROSEntityFilters::UEToDDS(simulation_interfaces_msg_EntityFilters& OutData) 
{
        ConvertUtils::UEStringToDDS(Filter, OutData.filter);
        OutData.categories._length = Categories.Num();
        OutData.categories._buffer = dds_sequence_simulation_interfaces_msg_EntityCategory_allocbuf(Categories.Num());
        OutData.categories._release = true;
        ConvertUtils::TArrayToSequence<simulation_interfaces_msg_EntityCategory, FROSEntityCategory>(Categories, OutData.categories._buffer, Categories.Num());
        Tags.UEToDDS(OutData.tags);
        Bounds.UEToDDS(OutData.bounds);
};

void UEntityFilters_TopicProxy::Initialize()
{
    Data = simulation_interfaces_msg_EntityFilters__alloc();
};

void UEntityFilters_TopicProxy::Terminate()
{
    simulation_interfaces_msg_EntityFilters_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UEntityFilters_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_msg_EntityFilters_desc;
};

void* UEntityFilters_TopicProxy::Get()
{
    return Data;
};

void UEntityFilters_TopicProxy::ExecuteMessageCallback()
{
    FROSEntityFilters NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UEntityFilters_TopicProxy::GetData(FROSEntityFilters& Output)
{
    Output.DDSToUE(*Data);
};

void UEntityFilters_TopicProxy::SetData(FROSEntityFilters Input)
{
    Input.UEToDDS(*Data);
};



