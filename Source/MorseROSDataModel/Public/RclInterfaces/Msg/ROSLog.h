/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSLog.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSLog.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Utils/ConvertUtils.h"
#include "BuiltinInterfaces/Msg/ROSTime.h"

#include "rcl_interfaces/msg/Log.h"

#include "ROSLog.generated.h" 

#define RCL_INTERFACES_MSG_LOG_CONSTANTS__DEBUG 10
#define RCL_INTERFACES_MSG_LOG_CONSTANTS__INFO 20
#define RCL_INTERFACES_MSG_LOG_CONSTANTS__WARN 30
#define RCL_INTERFACES_MSG_LOG_CONSTANTS__ERROR 40
#define RCL_INTERFACES_MSG_LOG_CONSTANTS__FATAL 50




USTRUCT(Blueprintable)
struct FROSLog
{
    GENERATED_BODY()

    FROSLog()
    {

    };

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FROSTime Stamp;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    uint8 Level = 0;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Msg;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString File;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Function;
    
    UPROPERTY(EditAnywhere)
    unsigned int Line = 0;
    

    void DDSToUE(const rcl_interfaces_msg_Log& InData);
    void UEToDDS(rcl_interfaces_msg_Log& OutData);
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSLogCallback, const FROSLog, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API ULog_TopicProxy : public UMRSTopicProxy
{
    GENERATED_BODY()

    UPROPERTY(BlueprintAssignable)
    FROSLogCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSLog& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSLog Input);

private:
    rcl_interfaces_msg_Log* Data;
};