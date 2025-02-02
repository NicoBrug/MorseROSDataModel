#include "GeometryMsgs/Msg/ROSTransformStamped.h"

void FROSTransformStamped::DDSToUE(const geometry_msgs_msg_TransformStamped& InData)
{
	Header.DDSToUE(InData.header);
	ConvertUtils::DDSStringToUE( InData.child_frame_id, ChildFrameId);
	Transform.DDSToUE(InData.transform);
};

void FROSTransformStamped::UEToDDS(geometry_msgs_msg_TransformStamped& OutData) 
{
	Header.UEToDDS(OutData.header);
	ConvertUtils::UEStringToDDS(ChildFrameId, OutData.child_frame_id );
	Transform.UEToDDS(OutData.transform);
};