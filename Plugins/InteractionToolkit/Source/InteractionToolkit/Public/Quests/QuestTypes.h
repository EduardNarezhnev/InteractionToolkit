#pragma once

#include "CoreMinimal.h"
#include "QuestTypes.generated.h"

USTRUCT(BlueprintType)
struct INTERACTIONTOOLKIT_API FQuestObjective
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FName ObjectiveID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    int32 RequiredProgress = 1;
};