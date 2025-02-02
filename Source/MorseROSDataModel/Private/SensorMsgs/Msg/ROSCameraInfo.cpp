#include "SensorMsgs/Msg/ROSCameraInfo.h"

void FROSCameraInfo::DDSToUE(const sensor_msgs_msg_CameraInfo& InData)
{
	Header.DDSToUE(InData.header);
	Height = InData.height;
	Width = InData.width;
	ConvertUtils::DDSStringToUE(InData.distortion_model, DistortionModel);
	ConvertUtils::SequenceToTArray<double, double>(InData.d._buffer, D, InData.d._length);
	ConvertUtils::SequenceToTArray<double, double>(InData.k, K, 9);
	ConvertUtils::SequenceToTArray<double, double>(InData.r, R, 9);
	ConvertUtils::SequenceToTArray<double, double>(InData.p, P, 9);
	BinningX = InData.binning_x;
	BinningY = InData.binning_y;
	Roi.DDSToUE(InData.roi);
}

void FROSCameraInfo::UEToDDS(sensor_msgs_msg_CameraInfo& OutData)
{
	Header.UEToDDS(OutData.header);
	OutData.height = Height;
	OutData.width = Width;
	ConvertUtils::UEStringToDDS(DistortionModel, OutData.distortion_model);
	OutData.d._length = D.Num();
	OutData.d._buffer = dds_sequence_double_allocbuf(D.Num());
	OutData.d._release = true;
	ConvertUtils::TArrayToSequence<double, double>(D, OutData.d._buffer, D.Num());
	ConvertUtils::TArrayToSequence<double, double>(K,OutData.k, 9);
	ConvertUtils::TArrayToSequence<double, double>(R,OutData.r, 9);
	ConvertUtils::TArrayToSequence<double, double>(P,OutData.p, 9);
	OutData.binning_x = BinningX;
	OutData.binning_y = BinningY;
	Roi.UEToDDS(OutData.roi);
}

void UCameraInfo_TopicProxy::Initialize()
{
	Data = sensor_msgs_msg_CameraInfo__alloc();
};

void UCameraInfo_TopicProxy::Terminate()
{
	sensor_msgs_msg_CameraInfo_free(Data, DDS_FREE_ALL);
};

const dds_topic_descriptor_t* UCameraInfo_TopicProxy::GetTypeDesc()
{
	return &sensor_msgs_msg_CameraInfo_desc;
};

void* UCameraInfo_TopicProxy::Get()
{
	return Data;
};

void UCameraInfo_TopicProxy::ExecuteMessageCallback()
{
	FROSCameraInfo NewData;
	NewData.DDSToUE(*Data);
	OnDataChanged.Broadcast(NewData);
};

void UCameraInfo_TopicProxy::GetData(FROSCameraInfo& Output)
{
	Output.DDSToUE(*Data);
};

void UCameraInfo_TopicProxy::SetData(FROSCameraInfo Input)
{
	Input.UEToDDS(*Data);
};

