#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

class UInteractionPrompt;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONTOOLKIT_API UInteractionComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInteractionComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    float InteractionDistance = 200.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    float SearchInterval = 0.1f;

    UPROPERTY(BlueprintReadOnly, Category = "Interaction")
    AActor* CurrentInteractable = nullptr;

    UFUNCTION(BlueprintCallable, Category = "Interaction")
    void FindInteractable();
    
    UFUNCTION(BlueprintCallable, Category = "Interaction")
    void Interact();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
    TSubclassOf<UUserWidget> PromptClass;

protected:
    virtual void BeginPlay() override;

private:
    FTimerHandle SearchTimer;

    UPROPERTY()
    UInteractionPrompt* PromptWidget = nullptr;

    void UpdatePrompt();
};