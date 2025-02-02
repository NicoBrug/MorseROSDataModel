/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSPoseWithCovariance.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSPoseWithCovariance.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Topic/TopicProxy.h"
#include "Utils/ConvertUtils.h"


#include "geometry_msgs/msg/PoseWithCovariance.h"
#include "GeometryMsgs/Msg/ROSPose.h"

#include "ROSPoseWithCovariance.generated.h" 







USTRUCT(Blueprintable)
struct FROSPoseWithCovariance
{
    GENERATED_BODY()
    
    FROSPoseWithCovariance()
    {

    };

    
    UPROPERTY(EditAnywhere)
    FROSPose Pose;
    
    UPROPERTY(EditAnywhere)
    TArray<double> Covariance;
    

    void DDSToUE(const geometry_msgs_msg_PoseWithCovariance& InData);
    void UEToDDS(geometry_msgs_msg_PoseWithCovariance& OutData);
};




DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSPoseWithCovarianceCallback, const FROSPoseWithCovariance, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API UPoseWithCovariance_TopicProxy : public UTopicProxy
{
    GENERATED_BODY()

    UPROPERTY(BlueprintAssignable)
    FROSPoseWithCovarianceCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSPoseWithCovariance& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSPoseWithCovariance Input);

private:
    geometry_msgs_msg_PoseWithCovariance* Data;
};