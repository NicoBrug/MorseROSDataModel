#pragma once

#include "CoreMinimal.h"

#include "geometry_msgs/msg/Vector3.h"
#include "geometry_msgs/msg/Quaternion.h"

class ConvertUtils
{
public:
    /**
     * @brief Converts an FString to char*.
     * @details This operation converts an FString to a char*.
     * @param inString The FString to convert.
     * @param outString The resulting char*.
     */
    static void UEStringToDDS(const FString inString, char*& outString) {
        const unsigned int msgStringCapacity = inString.Len() + 1;
        if (outString != nullptr)
        {
            free(outString);
        };
        outString = (char*)malloc(msgStringCapacity);
        memcpy(outString, TCHAR_TO_ANSI(*inString), msgStringCapacity);
    };

    /**
     * @brief Converts a char* to FString.
     * @details This operation converts a char* to FString.
     * @param inString The char* to convert.
     * @param outString The resulting FString.
     */
    static void DDSStringToUE(const char* inString, FString& outString) {
        outString = FString(inString);
    };
  
    static void UEVectorToDDS(FVector inVector, geometry_msgs_msg_Vector3& outVector)
    {
        outVector.x = inVector.X;
        outVector.y = inVector.Y;
        outVector.z = inVector.Z;
    }


    static void DDSVectorToUE(const geometry_msgs_msg_Vector3& inVector, FVector& outVector)
    {
        outVector.X = inVector.x;
        outVector.Y = inVector.y;
        outVector.Z = inVector.z;
    }

    static void UEQuaternionToDDS(FQuat inQuat, geometry_msgs_msg_Quaternion& outQuat)
    {
        outQuat.x = inQuat.X;
        outQuat.y = inQuat.Y;
        outQuat.z = inQuat.Z;
        outQuat.w = inQuat.W;
    }


    static void DDSQuaternionToUE(const geometry_msgs_msg_Quaternion& inQuat, FQuat& outQuat)
    {
        outQuat.X = inQuat.x;
        outQuat.Y = inQuat.y;
        outQuat.Z = inQuat.z;
        outQuat.W = inQuat.w;
    }


    template<typename TSequence, typename T>
    static void SequenceToTArray(const TSequence* InSequence, TArray<T>& OutArray, const int size)
    {
        OutArray.SetNum(size);
        for (auto i = 0; i < size; ++i)
        {
            if constexpr (TIsArithmetic<T>::Value)
            {
                OutArray[i] = InSequence[i];
            }
            else
            {
                OutArray[i].DDSToUE(InSequence[i]);
            }
        }
    }


    template<typename TSequence, typename T>
    static void TArrayToSequence(TArray<T>& InArray, TSequence* OutSequence, const int size) //need const ?? const TArray<T>& InArray
    {
        for (auto i = 0; i < size; ++i)
        {
            if constexpr (TIsArithmetic<T>::Value)
            {
                OutSequence[i] = InArray[i];
            }
            else
            {
                InArray[i].UEToDDS(OutSequence[i]);
            }
        }
    }


    template<typename TSequence, typename T>
    static void StrSequenceToTArray(const TSequence* InSequence, TArray<T>& OutArray, const int size) //need const ?? const TArray<T>& InArray
    {
        OutArray.Reserve(size);
        for (int i = 0; i < size; ++i) {
            DDSStringToUE(InSequence[i], OutArray[i]);
        }
    }

    template<typename TSequence, typename T>
    static void StrTArrayToSequence(TArray<T>& InArray, TSequence* OutSequence, const int size) //need const ?? const TArray<T>& InArray
    {
        for (int i = 0; i < size; ++i) {
            UEStringToDDS(InArray[i], OutSequence[i]);
        }
    }
};