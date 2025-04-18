/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSRegionOfInterest.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSRegionOfInterest.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Topic/MRSTopicProxy.h"
#include "Utils/ConvertUtils.h"


#include "sensor_msgs/msg/RegionOfInterest.h"

#include "ROSRegionOfInterest.generated.h" 







USTRUCT(Blueprintable)
struct FROSRegionOfInterest
{
    GENERATED_BODY()

    FROSRegionOfInterest()
    {

    };

    
    UPROPERTY(EditAnywhere)
    unsigned int XOffset = 0;
    
    UPROPERTY(EditAnywhere)
    unsigned int YOffset = 0;
    
    UPROPERTY(EditAnywhere)
    unsigned int Height = 0;
    
    UPROPERTY(EditAnywhere)
    unsigned int Width = 0;
    
    UPROPERTY(EditAnywhere)
    bool DoRectify = false;
    

    void DDSToUE(const sensor_msgs_msg_RegionOfInterest& InData);
    void UEToDDS(sensor_msgs_msg_RegionOfInterest& OutData);
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSRegionOfInterestCallback, const FROSRegionOfInterest, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API URegionOfInterest_TopicProxy : public UMRSTopicProxy
{
    GENERATED_BODY()

    UPROPERTY(BlueprintAssignable)
    FROSRegionOfInterestCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSRegionOfInterest& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSRegionOfInterest Input);

private:
    sensor_msgs_msg_RegionOfInterest* Data;
};