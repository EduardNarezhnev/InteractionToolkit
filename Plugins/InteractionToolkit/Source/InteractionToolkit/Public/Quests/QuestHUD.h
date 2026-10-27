#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestHUD.generated.h"

class UTextBlock;
class UProgressBar;

UCLASS()
class INTERACTIONTOOLKIT_API UQuestHUD : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Quest")
    void UpdateQuestDisplay(const FText& QuestName, const FText& QuestDescription, int32 CurrentProgress, int32 RequiredProgress);

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> QuestNameText;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> QuestDescriptionText;    

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UProgressBar> QuestProgressBar;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> ProgressText;
};