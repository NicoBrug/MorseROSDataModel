/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSPose.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSPose.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Topic/TopicProxy.h"
#include "Utils/ConvertUtils.h"


#include "geometry_msgs/msg/Pose.h"

#include "GeometryMsgs/Msg/ROSPoint.h"
#include "ROSPose.generated.h" 







USTRUCT(Blueprintable)
struct FROSPose
{
    GENERATED_BODY()

    FROSPose()
    {

    };

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FROSPoint Position;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FQuat Orientation;
    

    void DDSToUE(const geometry_msgs_msg_Pose& InData);
    void UEToDDS(geometry_msgs_msg_Pose& OutData);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSPoseCallback, const FROSPose, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API UPose_TopicProxy : public UTopicProxy
{
    GENERATED_BODY()

    UPROPERTY(BlueprintAssignable)
    FROSPoseCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSPose& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSPose Input);

private:
    geometry_msgs_msg_Pose* Data;
};