#include "DAIExample_AutoSaveBinder.h"
#include "SaveSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "DAISimpleSaveGame.h"

void UDAIExample_AutoSaveBinder::Initialize(FSubsystemCollectionBase &Collection)
{
    Super::Initialize(Collection);
    if (UGameInstance *GI = GetGameInstance())
    {
        USaveSubsystem *Save = GI->GetSubsystem<USaveSubsystem>();
        if (Save)
        {
            CachedSave = Save;
            Save->OnAutoSaveRequested.AddUniqueDynamic(this, &UDAIExample_AutoSaveBinder::HandleAutoSaveRequested);
        }
    }
}

void UDAIExample_AutoSaveBinder::Deinitialize()
{
    if (CachedSave.IsValid())
    {
        CachedSave->OnAutoSaveRequested.RemoveAll(this);
    }
    CachedSave.Reset();
    Super::Deinitialize();
}

void UDAIExample_AutoSaveBinder::HandleAutoSaveRequested()
{
    if (!CachedSave.IsValid())
        return;

    // Use the example project save game class so state can be persisted
    UDAISimpleSaveGame *SaveObj = NewObject<UDAISimpleSaveGame>();
    if (!SaveObj)
        return;

    // Prefix "Auto" and keep up to 5 rotating autosave slots
    CachedSave->AutoSave(SaveObj, TEXT("Auto"), /*UserIndex*/ 0, /*MaxSlots*/ 5);
}
