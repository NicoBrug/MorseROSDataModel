/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSLaserScan.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSLaserScan.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Topic/MRSTopicProxy.h"
#include "Utils/ConvertUtils.h"


#include "sensor_msgs/msg/LaserScan.h"

#include "StdMsgs/Msg/ROSHeader.h"

#include "ROSLaserScan.generated.h" 




USTRUCT(Blueprintable)
struct FROSLaserScan
{
    GENERATED_BODY()

    FROSLaserScan()
    {

    };
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FROSHeader Header;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AngleMin = 0.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AngleMax =0.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AngleIncrement = 0.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float TimeIncrement = 0.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ScanTime = 0.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RangeMin = 0.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float RangeMax = 0.0f;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<float> Ranges;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<float> Intensities;
    

    void DDSToUE (const sensor_msgs_msg_LaserScan& InData);
    void UEToDDS (sensor_msgs_msg_LaserScan& OutData);
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSLaserScanCallback, const FROSLaserScan, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API ULaserScan_TopicProxy : public UMRSTopicProxy
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintAssignable)
    FROSLaserScanCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSLaserScan& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSLaserScan Input);

private:
    sensor_msgs_msg_LaserScan* Data;
};