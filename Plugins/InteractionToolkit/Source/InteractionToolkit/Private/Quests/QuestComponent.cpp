#include "Quests/QuestComponent.h"
#include "Quests/QuestData.h"
#include "Quests/QuestHUD.h"
#include "Blueprint/UserWidget.h"

UQuestComponent::UQuestComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UQuestComponent::BeginPlay()
{
    Super::BeginPlay();

    if (QuestHUDClass)
    {
        if (UWorld* World = GetWorld())
        {
            QuestHUDWidget = CreateWidget<UQuestHUD>(World, QuestHUDClass);
            if (QuestHUDWidget)
            {
                QuestHUDWidget->AddToViewport();
            }
        }
    }
}

void UQuestComponent::UpdateQuestHUD()
{
    if (!QuestHUDWidget) return;

    UQuestData* Quest = nullptr;
    for (UQuestData* Q : ActiveQuests)
    {
        if (Q && !Q->bCompleted)
        {
            Quest = Q;
            break;
        }
    }

    if (!Quest)
    {
        QuestHUDWidget->SetVisibility(ESlateVisibility::Hidden);
        return;
    }

    QuestHUDWidget->SetVisibility(ESlateVisibility::Visible);

    if (Quest->Objectives.Num() == 0) return;

    const FQuestObjective& Objective = Quest->Objectives[0];
    int32* ProgressPtr = ObjectiveProgress.Find(Objective.ObjectiveID);
    int32 CurrentProgress = ProgressPtr ? *ProgressPtr : 0;

    QuestHUDWidget->UpdateQuestDisplay(Quest->QuestName, Quest->QuestDescription, CurrentProgress, Objective.RequiredProgress);
}

void UQuestComponent::StartQuest(UQuestData* Quest)
{
    if(!Quest) return;

    Quest->bCompleted = false;
    ActiveQuests.Add(Quest);

    for(const FQuestObjective& Objective : Quest->Objectives)
    {
        ObjectiveProgress.Add(Objective.ObjectiveID, 0);
    }

    UpdateQuestHUD();
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
        if (!Quest || Quest->bCompleted) continue;

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
        Quest->bCompleted = true;
        OnQuestCompleted.Broadcast(Quest);
    }

    UpdateQuestHUD();
}