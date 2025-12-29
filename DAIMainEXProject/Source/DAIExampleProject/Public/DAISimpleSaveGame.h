#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DAISimpleSaveGame.generated.h"

UCLASS(BlueprintType)
class DAIEXAMPLEPROJECT_API UDAISimpleSaveGame : public USaveGame
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Example")
    int32 PlayerLevel = 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Example")
    float Health = 100.f;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Example")
    FString LastCheckpoint;
};
