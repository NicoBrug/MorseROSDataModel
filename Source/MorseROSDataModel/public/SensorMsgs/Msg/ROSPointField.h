/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSPointField.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSPointField.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Utils/ConvertUtils.h"
#include "sensor_msgs/msg/PointField.h"

#include "ROSPointField.generated.h" 

UENUM()
enum class EROSPointFieldType : uint8
{
    INT8 = 1,
    UINT8 = 2,
    INT16 = 3,
    UINT16 = 4,
    INT32 = 5,
    UINT32 = 6,
    FLOAT32 = 7,
    FLOAT64 = 8
};



/** @addtogroup {NameDoxygenMessageContainer}
  * @brief {NameDoxygenMessageContainer}
  *
  * @{
  */
USTRUCT(Blueprintable)
struct FROSPointField
{
    GENERATED_BODY()

public:
    /**
    * @cond
    */
    FROSPointField()
    {

    };
    /**
     * @endcond
     */

    
    UPROPERTY(EditAnywhere)
    FString Name;
    
    UPROPERTY(EditAnywhere)
    unsigned int Offset;
    
    UPROPERTY(EditAnywhere)
    EROSPointFieldType Datatype;
    
    UPROPERTY(EditAnywhere)
    unsigned int Count;
    
    /**
     * @cond
     */
    void DDSToUE(const sensor_msgs_msg_PointField& InData)
    {
        ConvertUtils::DDSStringToUE(InData.name, Name);
        Offset = InData.offset;
        Datatype = static_cast<EROSPointFieldType>(InData.datatype);
        Count = InData.count;
    };

    void UEToDDS(sensor_msgs_msg_PointField& OutData)
    {
        ConvertUtils::UEStringToDDS(Name, OutData.name);
        OutData.offset = Offset;
        OutData.datatype = static_cast<uint8>(Datatype);
        OutData.count = Count;
    };
    
    /**
     * @endcond
     */
};
/** @} */