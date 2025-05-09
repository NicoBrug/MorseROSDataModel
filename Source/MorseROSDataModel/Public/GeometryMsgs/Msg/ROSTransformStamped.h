/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSTransformStamped.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSTransformStamped.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Utils/ConvertUtils.h"


#include "geometry_msgs/msg/TransformStamped.h"


#include "GeometryMsgs/Msg/ROSTransform.h"
#include "StdMsgs/Msg/ROSHeader.h"

#include "ROSTransformStamped.generated.h" 



USTRUCT(Blueprintable)
struct FROSTransformStamped
{
	GENERATED_BODY()

	FROSTransformStamped()
	{

	};

    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FROSHeader Header;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChildFrameId;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FROSTransform Transform;

	
	void DDSToUE(const geometry_msgs_msg_TransformStamped& InData);
	void UEToDDS(geometry_msgs_msg_TransformStamped& OutData);
};
