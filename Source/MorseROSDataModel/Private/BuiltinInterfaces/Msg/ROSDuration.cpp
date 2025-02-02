#include "BuiltinInterfaces/Msg/ROSDuration.h"

void FROSDuration::DDSToUE(const builtin_interfaces_msg_Duration& InData)
{
	Sec = InData.sec;
	Nanosec = InData.nanosec;
};

void FROSDuration::UEToDDS(builtin_interfaces_msg_Duration& OutData) 
{
	OutData.sec = Sec;
	OutData.nanosec = Nanosec;
};