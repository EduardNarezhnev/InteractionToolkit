#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Quests/QuestTypes.h"
#include "QuestComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestCompleted, UQuestData*, Quest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnObjectiveProgress, FName, ObjectiveID, int32, Progress);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONTOOLKIT_API UQuestComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UQuestComponent();

    UPROPERTY(BlueprintReadOnly, Category = "Quest")
    TArray<UQuestData*> ActiveQuests;

    UFUNCTION(BlueprintCallable, Category = "Quest")
    void StartQuest(UQuestData* Quest);

    UFUNCTION(BlueprintCallable, Category = "Quest")
    void UpdateProgress(FName ObjectiveID, int32 Progress);

    UPROPERTY(BlueprintAssignable, Category = "Quest")
    FOnQuestCompleted OnQuestCompleted;

    UPROPERTY(BlueprintAssignable, Category = "Quest")
    FOnObjectiveProgress OnObjectiveProgress;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
    TSubclassOf<UUserWidget> QuestHUDClass;

protected:
    virtual void BeginPlay() override;

private:
    TMap<FName, int32> ObjectiveProgress;

    UPROPERTY()
    class UQuestHUD* QuestHUDWidget = nullptr;

    void UpdateQuestHUD();
};