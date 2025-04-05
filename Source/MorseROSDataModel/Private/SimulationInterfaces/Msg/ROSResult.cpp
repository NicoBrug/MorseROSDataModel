#include "SimulationInterfaces/Msg/ROSResult.h"





void FROSResult::DDSToUE(const simulation_interfaces_msg_Result& InData)
{
        Result = InData.result;
        ConvertUtils::DDSStringToUE(InData.error_message, ErrorMessage);
};

void FROSResult::UEToDDS(simulation_interfaces_msg_Result& OutData) 
{
        OutData.result = Result;
        ConvertUtils::UEStringToDDS(ErrorMessage, OutData.error_message);
};

void UResult_TopicProxy::Initialize()
{
    Data = simulation_interfaces_msg_Result__alloc();
};

void UResult_TopicProxy::Terminate()
{
    simulation_interfaces_msg_Result_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UResult_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_msg_Result_desc;
};

void* UResult_TopicProxy::Get()
{
    return Data;
};

void UResult_TopicProxy::ExecuteMessageCallback()
{
    FROSResult NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UResult_TopicProxy::GetData(FROSResult& Output)
{
    Output.DDSToUE(*Data);
};

void UResult_TopicProxy::SetData(FROSResult Input)
{
    Input.UEToDDS(*Data);
};



