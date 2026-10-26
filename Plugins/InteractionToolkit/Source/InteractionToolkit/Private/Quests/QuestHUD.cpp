#include "Quests/QuestHUD.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UQuestHUD::UpdateQuestDisplay(const FText& QuestName, int32 CurrentProgress, int32 RequiredProgress)
{
    if(QuestNameText)
    {
        QuestNameText->SetText(QuestName);
    }

    if(QuestProgressBar && RequiredProgress > 0)
    {
        float Percent = static_cast<float>(CurrentProgress) / static_cast<float>(RequiredProgress);
        QuestProgressBar->SetPercent(FMath::Clamp(Percent, 0.f, 1.f));
    }

    if(ProgressText)
    {
        FString Text = FString::Printf(TEXT("%d / %d"), CurrentProgress, RequiredProgress);
        ProgressText->SetText(FText::FromString(Text));
    }
}