#include "SimulationInterfaces/Msg/ROSTagsFilter.h"





void FROSTagsFilter::DDSToUE(const simulation_interfaces_msg_TagsFilter& InData)
{
        ConvertUtils::StrSequenceToTArray<char*, FString>(InData.tags._buffer, Tags, InData.tags._length);
        FilterMode = InData.filter_mode;
};

void FROSTagsFilter::UEToDDS(simulation_interfaces_msg_TagsFilter& OutData) 
{
        OutData.tags._length = Tags.Num();
        OutData.tags._buffer = dds_sequence_string_allocbuf(Tags.Num());
        OutData.tags._release = true;
        ConvertUtils::StrTArrayToSequence<char*, FString>(Tags, OutData.tags._buffer, Tags.Num());
        OutData.filter_mode = FilterMode;
};

void UTagsFilter_TopicProxy::Initialize()
{
    Data = simulation_interfaces_msg_TagsFilter__alloc();
};

void UTagsFilter_TopicProxy::Terminate()
{
    simulation_interfaces_msg_TagsFilter_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UTagsFilter_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_msg_TagsFilter_desc;
};

void* UTagsFilter_TopicProxy::Get()
{
    return Data;
};

void UTagsFilter_TopicProxy::ExecuteMessageCallback()
{
    FROSTagsFilter NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UTagsFilter_TopicProxy::GetData(FROSTagsFilter& Output)
{
    Output.DDSToUE(*Data);
};

void UTagsFilter_TopicProxy::SetData(FROSTagsFilter Input)
{
    Input.UEToDDS(*Data);
};



