/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSHeader.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSHeader.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 

#include "std_msgs/msg/Header.h"

#include "BuiltinInterfaces/Msg/ROSTime.h"

#include "ROSHeader.generated.h"

USTRUCT(Blueprintable)
struct FROSHeader
{
	GENERATED_BODY()

	FROSHeader()
	{

	};

    
	UPROPERTY(EditAnywhere)
	FROSTime Stamp;
    
	UPROPERTY(EditAnywhere)
	FString FrameId;
    

	void DDSToUE(const std_msgs_msg_Header& InData);
	void UEToDDS(std_msgs_msg_Header& OutData);
};