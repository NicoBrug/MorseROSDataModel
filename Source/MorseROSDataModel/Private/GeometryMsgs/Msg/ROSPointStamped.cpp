#include "GeometryMsgs/Msg/ROSPointStamped.h"

void FROSPointStamped::DDSToUE(const geometry_msgs_msg_PointStamped& InData)
{
        Header.DDSToUE(InData.header);
        Point.DDSToUE(InData.point);
};

void FROSPointStamped::UEToDDS(geometry_msgs_msg_PointStamped& OutData) 
{
        Header.UEToDDS(OutData.header);
        Point.UEToDDS(OutData.point);
};

void UPointStamped_TopicProxy::Initialize()
{
    Data = geometry_msgs_msg_PointStamped__alloc();
};

void UPointStamped_TopicProxy::Terminate()
{
    geometry_msgs_msg_PointStamped_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UPointStamped_TopicProxy::GetTypeDesc()
{
     return &geometry_msgs_msg_PointStamped_desc;
};

void* UPointStamped_TopicProxy::Get()
{
    return Data;
};

void UPointStamped_TopicProxy::ExecuteMessageCallback()
{
    FROSPointStamped NewData;
    NewData.DDSToUE(*Data);
    OnDataChanged.Broadcast(NewData);
};

void UPointStamped_TopicProxy::GetData(FROSPointStamped& Output)
{
    Output.DDSToUE(*Data);
};

void UPointStamped_TopicProxy::SetData(FROSPointStamped Input)
{
    Input.UEToDDS(*Data);
};