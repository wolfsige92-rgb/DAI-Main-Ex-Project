#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DAIExample_AutoSaveBinder.generated.h"

class USaveSubsystem;
class USaveGame;

UCLASS()
class DAIEXAMPLEPROJECT_API UDAIExample_AutoSaveBinder : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    virtual void Initialize(FSubsystemCollectionBase &Collection) override;
    virtual void Deinitialize() override;

private:
    UFUNCTION()
    void HandleAutoSaveRequested();

    TWeakObjectPtr<USaveSubsystem> CachedSave;
};
