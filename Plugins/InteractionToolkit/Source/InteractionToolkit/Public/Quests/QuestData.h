#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Quests/QuestTypes.h"
#include "QuestData.generated.h"

UCLASS(BlueprintType)
class INTERACTIONTOOLKIT_API UQuestData : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FText QuestName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    FText QuestDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    TArray<FQuestObjective> Objectives;
};