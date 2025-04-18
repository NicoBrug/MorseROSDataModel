/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSGetEntities.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSGetEntities.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "SimulationInterfaces/Msg/ROSEntityFilters.h"
#include "SimulationInterfaces/Msg/ROSResult.h"
#include "Topic/MRSTopicProxy.h"
#include "Utils/ConvertUtils.h"


#include "simulation_interfaces/srv/GetEntities.h"

#include "ROSGetEntities.generated.h" 



USTRUCT(Blueprintable)
struct FROSGetEntities_Request
{
    GENERATED_BODY()

    FROSGetEntities_Request()
    {

    };

    
    UPROPERTY(EditAnywhere)
    FROSEntityFilters Filters;
    

    void DDSToUE(const simulation_interfaces_srv_GetEntities_Request& InData);
    void UEToDDS(simulation_interfaces_srv_GetEntities_Request& OutData);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSGetEntities_RequestCallback, const FROSGetEntities_Request, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API UGetEntities_Request_TopicProxy : public UMRSTopicProxy
{
    GENERATED_BODY()

public:
    
    UPROPERTY(BlueprintAssignable)
    FROSGetEntities_RequestCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSGetEntities_Request& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSGetEntities_Request Input);

private:
    simulation_interfaces_srv_GetEntities_Request* Data;
};

USTRUCT(Blueprintable)
struct FROSGetEntities_Response
{
    GENERATED_BODY()

    FROSGetEntities_Response()
    {

    };

    
    UPROPERTY(EditAnywhere)
    FROSResult Result;
    
    UPROPERTY(EditAnywhere)
    TArray<FString> Entities;
    

    void DDSToUE(const simulation_interfaces_srv_GetEntities_Response& InData);
    void UEToDDS(simulation_interfaces_srv_GetEntities_Response& OutData);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSGetEntities_ResponseCallback, const FROSGetEntities_Response, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API UGetEntities_Response_TopicProxy : public UMRSTopicProxy
{
    GENERATED_BODY()

    
public:
    
    UPROPERTY(BlueprintAssignable)
    FROSGetEntities_ResponseCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSGetEntities_Response& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSGetEntities_Response Input);

private:
    simulation_interfaces_srv_GetEntities_Response* Data;
};