#include "GeometryMsgs/Msg/ROSTransform.h"

void FROSTransform::DDSToUE(const geometry_msgs_msg_Transform& InData)
{
	ConvertUtils::DDSVectorToUE(InData.translation, Translation);
	ConvertUtils::DDSQuaternionToUE(InData.rotation, Rotation);
};

void FROSTransform::UEToDDS(geometry_msgs_msg_Transform& OutData) 
{
	ConvertUtils::UEVectorToDDS(Translation, OutData.translation);
	ConvertUtils::UEQuaternionToDDS(Rotation, OutData.rotation);
};