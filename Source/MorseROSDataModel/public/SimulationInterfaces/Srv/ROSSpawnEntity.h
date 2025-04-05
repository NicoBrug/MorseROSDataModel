/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSSpawnEntity.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSSpawnEntity.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Topic/MRSTopicProxy.h"
#include "Utils/ConvertUtils.h"

#include "simulation_interfaces/srv/SpawnEntity.h"
#include "GeometryMsgs/Msg/ROSPoseStamped.h"
#include "SimulationInterfaces/Msg/ROSResult.h"

#include "ROSSpawnEntity.generated.h" 

USTRUCT(Blueprintable)
struct FROSSpawnEntity_Request
{
    GENERATED_BODY()

    FROSSpawnEntity_Request()
    {

    };

    
    UPROPERTY(EditAnywhere)
    FString Name;
    
    UPROPERTY(EditAnywhere)
    bool AllowRenaming;
    
    UPROPERTY(EditAnywhere)
    FString Uri;
    
    UPROPERTY(EditAnywhere)
    FString ResourceString;
    
    UPROPERTY(EditAnywhere)
    FString EntityNamespace;
    
    UPROPERTY(EditAnywhere)
    FROSPoseStamped InitialPose;
    

    void DDSToUE(const simulation_interfaces_srv_SpawnEntity_Request& InData);
    void UEToDDS(simulation_interfaces_srv_SpawnEntity_Request& OutData);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSSpawnEntity_RequestCallback, const FROSSpawnEntity_Request, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API USpawnEntity_Request_TopicProxy : public UMRSTopicProxy
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FROSSpawnEntity_RequestCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSSpawnEntity_Request& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSSpawnEntity_Request Input);

private:
    simulation_interfaces_srv_SpawnEntity_Request* Data;
};

USTRUCT(Blueprintable)
struct FROSSpawnEntity_Response
{
    GENERATED_BODY()

    FROSSpawnEntity_Response()
    {

    };
    
    static constexpr uint8 NameNotUnique = 101;
    static constexpr uint8 NameInvalid = 102;
    static constexpr uint8 UnsupportedFormat = 103;
    static constexpr uint8 NoRessource = 104;
    static constexpr uint8 NamespaceInvalid = 105;
    static constexpr uint8 RessourceParseError = 106;
    static constexpr uint8 MissingAsset = 107;
    static constexpr uint8 UnsupportedAsset = 108;
    static constexpr uint8 InvalidPose = 109;
    
    UPROPERTY(EditAnywhere)
    FROSResult Result;
    
    UPROPERTY(EditAnywhere)
    FString EntityName;
    

    void DDSToUE(const simulation_interfaces_srv_SpawnEntity_Response& InData);
    void UEToDDS(simulation_interfaces_srv_SpawnEntity_Response& OutData);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSSpawnEntity_ResponseCallback, const FROSSpawnEntity_Response, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API USpawnEntity_Response_TopicProxy : public UMRSTopicProxy
{
    GENERATED_BODY()

public:
    
    UPROPERTY(BlueprintAssignable)
    FROSSpawnEntity_ResponseCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSSpawnEntity_Response& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSSpawnEntity_Response Input);

private:
    simulation_interfaces_srv_SpawnEntity_Response* Data;
};