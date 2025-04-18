/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSClock.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSClock.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Topic/MRSTopicProxy.h"
#include "Utils/ConvertUtils.h"

#include "rosgraph_msgs/msg/Clock.h"

#include "BuiltinInterfaces/Msg/ROSTime.h"

#include "ROSClock.generated.h" 





USTRUCT(Blueprintable)
struct FROSClock
{
    GENERATED_BODY()

    FROSClock()
    {

    };

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FROSTime Clock;
    

    void DDSToUE(const rosgraph_msgs_msg_Clock& InData);
    void UEToDDS(rosgraph_msgs_msg_Clock& OutData);
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSClockCallback, const FROSClock, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API UClock_TopicProxy : public UMRSTopicProxy
{
    GENERATED_BODY()

public:
    
    UPROPERTY(BlueprintAssignable)
    FROSClockCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSClock& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSClock Input);

private:
    rosgraph_msgs_msg_Clock* Data;
};