/*****************************************************************//**
 * Generated by Morse IDL to UE Translator.
 * @file   ROSImage.h
 * @brief  File containing data structures and the definition of the message generated from the IDL.
 *         Idl Type : ROSImage.idl
 *         
 * @author Nicolas B.
 * @date   December 2023
 * @copyright Copyright 2023 Nicolas Brugie. All rights reserved.
 *********************************************************************/

#pragma once 
#include "CoreMinimal.h" 
#include "Topic/TopicProxy.h"
#include "Utils/ConvertUtils.h"


#include "sensor_msgs/msg/Image.h"

#include "StdMsgs/Msg/ROSHeader.h"

#include "ROSImage.generated.h" 





USTRUCT(Blueprintable)
struct FROSImage
{
    GENERATED_BODY()
    
    FROSImage()
    {

    };
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FROSHeader Header;
    
    UPROPERTY(EditAnywhere)
    unsigned int Height;
    
    UPROPERTY(EditAnywhere)
    unsigned int Width;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Encoding;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    uint8 IsBigendian;
    
    UPROPERTY(EditAnywhere)
    unsigned int Step;
    
    TArray<uint8> Data;
    
    
    void DDSToUE (const sensor_msgs_msg_Image& InData);
    void UEToDDS (sensor_msgs_msg_Image& OutData);
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FROSImageCallback, const FROSImage, Data);

UCLASS(BlueprintType, Blueprintable)
class MORSEROSDATAMODEL_API UImage_TopicProxy : public UTopicProxy
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintAssignable)
    FROSImageCallback OnDataChanged;

    /** Begin implement TopicProxy Interface */
    virtual void Initialize() override;
    virtual void Terminate() override;
    virtual const dds_topic_descriptor_t* GetTypeDesc() override;
    virtual void* Get() override;
    virtual void ExecuteMessageCallback() override;
    /** End implement TopicProxy Interface */

    UFUNCTION(BlueprintCallable)
    void GetData(FROSImage& Output);

    UFUNCTION(BlueprintCallable)
    void SetData(FROSImage Input);

private:
    sensor_msgs_msg_Image* Data;
};