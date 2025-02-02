#include "SensorMsgs/Msg/ROSImage.h"


void FROSImage::DDSToUE(const sensor_msgs_msg_Image& InData)
{
	Header.DDSToUE(InData.header);
	Height = InData.height;
	Width = InData.width;
	ConvertUtils::DDSStringToUE(InData.encoding, Encoding);
	IsBigendian = InData.is_bigendian;
	Step = InData.step;
	ConvertUtils::SequenceToTArray<uint8, uint8>(InData.data._buffer, Data, InData.data._length);
};

void FROSImage::UEToDDS(sensor_msgs_msg_Image& OutData) 
{
	Header.UEToDDS(OutData.header);
	OutData.height = Height;
	OutData.width = Width;
	ConvertUtils::UEStringToDDS(Encoding, OutData.encoding);
	OutData.is_bigendian = IsBigendian;
	OutData.step = Step;
	OutData.data._length = Data.Num();
	OutData.data._buffer = dds_sequence_uint8_allocbuf(Data.Num());
	OutData.data._release = true;
	ConvertUtils::TArrayToSequence<uint8, uint8>(Data, OutData.data._buffer, Data.Num());
};

void UImage_TopicProxy::Initialize()
{
	Data = sensor_msgs_msg_Image__alloc();
};

void UImage_TopicProxy::Terminate()
{
	sensor_msgs_msg_Image_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UImage_TopicProxy::GetTypeDesc()
{
	return &sensor_msgs_msg_Image_desc;
};

void* UImage_TopicProxy::Get()
{
	return Data;
};

void UImage_TopicProxy::ExecuteMessageCallback()
{
	FROSImage NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UImage_TopicProxy::GetData(FROSImage& Output)
{
	Output.DDSToUE(*Data);
};

void UImage_TopicProxy::SetData(FROSImage Input)
{
	Input.UEToDDS(*Data);
};
