#include "Interaction/InteractionPrompt.h"
#include "Components/TextBlock.h"

void UInteractionPrompt::SetPromptText(const FText& Text)
{
    if(PromptText)
    {
        PromptText->SetText(Text);
    }
}