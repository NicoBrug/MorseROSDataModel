/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSPoseStamped.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSPoseStamped.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Topic/TopicProxy.h"
#include "Utils/ConvertUtils.h"


#include "geometry_msgs/msg/PoseStamped.h"

#include "GeometryMsgs/Msg/ROSPose.h"
#include "StdMsgs/Msg/ROSHeader.h"

#include "ROSPoseStamped.generated.h" 







USTRUCT(Blueprintable)
struct FROSPoseStamped
{
    GENERATED_BODY()

    FROSPoseStamped()
    {

    };

    
    UPROPERTY(EditAnywhere)
    FROSHeader Header;
    
    UPROPERTY(EditAnywhere)
    FROSPose Pose;
    

    void DDSToUE(const geometry_msgs_msg_PoseStamped& InData);
    void UEToDDS(geometry_msgs_msg_PoseStamped& OutData);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSPoseStampedCallback, const FROSPoseStamped, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API UPoseStamped_TopicProxy : public UTopicProxy
{
    GENERATED_BODY()

    UPROPERTY(BlueprintAssignable)
    FROSPoseStampedCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSPoseStamped& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSPoseStamped Input);

private:
    geometry_msgs_msg_PoseStamped* Data;
};