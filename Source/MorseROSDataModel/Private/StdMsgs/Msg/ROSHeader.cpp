#include "StdMsgs/Msg/ROSHeader.h"

void FROSHeader::DDSToUE(const std_msgs_msg_Header& InData)
{
	Stamp.DDSToUE(InData.stamp);
	ConvertUtils::DDSStringToUE(InData.frame_id, FrameId);
};

void FROSHeader::UEToDDS(std_msgs_msg_Header& OutData) 
{
	Stamp.UEToDDS(OutData.stamp);
	ConvertUtils::UEStringToDDS(FrameId, OutData.frame_id);
};