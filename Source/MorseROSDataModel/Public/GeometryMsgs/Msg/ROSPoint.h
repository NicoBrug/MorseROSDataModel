/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSPoint.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSPoint.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Topic/TopicProxy.h"
#include "Utils/ConvertUtils.h"


#include "geometry_msgs/msg/Point.h"

#include "ROSPoint.generated.h" 







USTRUCT(Blueprintable)
struct FROSPoint
{
    GENERATED_BODY()

    FROSPoint()
    {

    };

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    double X;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    double Y;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    double Z;
    

    void DDSToUE(const geometry_msgs_msg_Point& InData);
    void UEToDDS(geometry_msgs_msg_Point& OutData);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSPointCallback, const FROSPoint, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API UPoint_TopicProxy : public UTopicProxy
{
    GENERATED_BODY()

    UPROPERTY(BlueprintAssignable)
    FROSPointCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSPoint& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSPoint Input);

private:
    geometry_msgs_msg_Point* Data;
};