#include "Quests/QuestComponent.h"
#include "Quests/QuestData.h"

UQuestComponent::UQuestComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UQuestComponent::StartQuest(UQuestData* Quest)
{
    if(!Quest) return;

    ActiveQuests.Add(Quest);

    for(const FQuestObjective& Objective : Quest->Objectives)
    {
        ObjectiveProgress.Add(Objective.ObjectiveID, 0);
    }
}

void UQuestComponent::UpdateProgress(FName ObjectiveID, int32 Progress)
{
    int32* CurrentPtr = ObjectiveProgress.Find(ObjectiveID);
    if (!CurrentPtr) return;

    *CurrentPtr = FMath::Max(0, *CurrentPtr + Progress);

    OnObjectiveProgress.Broadcast(ObjectiveID, *CurrentPtr);

    TArray<UQuestData*> CompletedQuests;

    for (UQuestData* Quest : ActiveQuests)
    {
        if (!Quest) continue;

        bool bAllComplete = true;
        for (const FQuestObjective& Objective : Quest->Objectives)
        {
            int32* ProgressPtr = ObjectiveProgress.Find(Objective.ObjectiveID);
            if (!ProgressPtr || *ProgressPtr < Objective.RequiredProgress)
            {
                bAllComplete = false;
                break;
            }
        }

        if (bAllComplete)
        {
            CompletedQuests.Add(Quest);
        }
    }

    for (UQuestData* Quest : CompletedQuests)
    {
        ActiveQuests.Remove(Quest);
        OnQuestCompleted.Broadcast(Quest);
    }
}