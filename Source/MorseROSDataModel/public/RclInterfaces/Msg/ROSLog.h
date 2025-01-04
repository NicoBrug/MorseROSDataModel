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




/** @addtogroup {NameDoxygenMessageContainer}
  * @brief {NameDoxygenMessageContainer}
  *
  * @{
  */
USTRUCT(Blueprintable, BlueprintType)
struct FROSLog
{
    GENERATED_BODY()

public:
    /**
    * @cond
    */
    FROSLog()
    {

    };
    /**
     * @endcond
     */

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FROSTime Stamp;
    
    UPROPERTY(EditAnywhere)
    uint8 Level;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Msg;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString File;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Function;
    
    UPROPERTY(EditAnywhere)
    unsigned int Line;
    

    /**
     * @cond
     */
    void DDSToUE (const rcl_interfaces_msg_Log& InData) 
    {
        Stamp.DDSToUE(InData.stamp);
        Level = InData.level;
        ConvertUtils::DDSStringToUE( InData.name, Name);
        ConvertUtils::DDSStringToUE( InData.msg, Msg);
        ConvertUtils::DDSStringToUE( InData.file, File);
        ConvertUtils::DDSStringToUE( InData.function, Function);
        Line = InData.line;
    };

    void UEToDDS (rcl_interfaces_msg_Log& OutData) 
    {
        Stamp.UEToDDS(OutData.stamp);
        OutData.level = Level;
        ConvertUtils::UEStringToDDS(Name, OutData.name );
        ConvertUtils::UEStringToDDS(Msg, OutData.msg );
        ConvertUtils::UEStringToDDS(File, OutData.file );
        ConvertUtils::UEStringToDDS(Function, OutData.function );
        OutData.line = Line;
    };
    
    /**
     * @endcond
     */
};
/** @} */



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSLogCallback, const FROSLog, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API ULog_TopicProxy : public UTopicProxy
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintAssignable)
    FROSLogCallback OnDataChanged;

    virtual void Initialize() override {
        Data = rcl_interfaces_msg_Log__alloc();
    };

    virtual void Terminate() override {
        rcl_interfaces_msg_Log_free(Data, DDS_FREE_ALL);
    };

    UFUNCTION(BlueprintCallable)
    void GetData(FROSLog& Output)
    {
        Output.DDSToUE(*Data);
    };

    UFUNCTION(BlueprintCallable)
    void SetData(FROSLog Input)
    {
        Input.UEToDDS(*Data);
    };

    virtual void ExecuteMessageCallback() override
    {
        FROSLog NewData;
        NewData.DDSToUE(*Data);
        OnDataChanged.Broadcast(NewData);
    };

    virtual void* Get() override
    {
        return Data;
    };

    virtual const dds_topic_descriptor_t* GetTypeDesc() override
    {
        return &rcl_interfaces_msg_Log_desc;
    };

private:
    rcl_interfaces_msg_Log* Data;
};