#include "SensorMsgs/Msg/ROSPointField.h"

void FROSPointField::DDSToUE(const sensor_msgs_msg_PointField& InData)
{
	ConvertUtils::DDSStringToUE(InData.name, Name);
	Offset = InData.offset;
	Datatype = static_cast<EROSPointFieldType>(InData.datatype);
	Count = InData.count;
}

void FROSPointField::UEToDDS(sensor_msgs_msg_PointField& OutData)
{
    ConvertUtils::UEStringToDDS(Name, OutData.name);
    OutData.offset = Offset;
    OutData.datatype = static_cast<uint8>(Datatype);
    OutData.count = Count;
};
