#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionPrompt.generated.h"

class UTextBlock;

UCLASS()
class INTERACTIONTOOLKIT_API UInteractionPrompt : public UUserWidget
{
    GENERATED_BODY()
public:
    void SetPromptText(const FText& Text);

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UTextBlock> PromptText;
};