#include "SimulationInterfaces/Msg/ROSBounds.h"





void FROSBounds::DDSToUE(const simulation_interfaces_msg_Bounds& InData)
{
        Type = InData.type;
        ConvertUtils::VectorSequenceToTArray(InData.points._buffer, Points, InData.points._length);
};

void FROSBounds::UEToDDS(simulation_interfaces_msg_Bounds& OutData) 
{
        OutData.type = Type;
        OutData.points._length = Points.Num();
        OutData.points._buffer = dds_sequence_geometry_msgs_msg_Vector3_allocbuf(Points.Num());
        OutData.points._release = true;
        ConvertUtils::VectorTArrayToSequence(Points, OutData.points._buffer, Points.Num());
};

void UBounds_TopicProxy::Initialize()
{
    Data = simulation_interfaces_msg_Bounds__alloc();
};

void UBounds_TopicProxy::Terminate()
{
    simulation_interfaces_msg_Bounds_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UBounds_TopicProxy::GetTypeDesc()
{
     return &simulation_interfaces_msg_Bounds_desc;
};

void* UBounds_TopicProxy::Get()
{
    return Data;
};

void UBounds_TopicProxy::ExecuteMessageCallback()
{
    FROSBounds NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UBounds_TopicProxy::GetData(FROSBounds& Output)
{
    Output.DDSToUE(*Data);
};

void UBounds_TopicProxy::SetData(FROSBounds Input)
{
    Input.UEToDDS(*Data);
};



