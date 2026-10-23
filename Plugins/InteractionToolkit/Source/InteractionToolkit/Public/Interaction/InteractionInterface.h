#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractionInterface : public UInterface
{
    GENERATED_BODY()
};

class INTERACTIONTOOLKIT_API IInteractionInterface
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
    void Interact(AActor* Interactor);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
    FText GetInteractionText() const;

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
    bool CanInteract(AActor* Interactor) const;
};