#include "Interaction/InteractionComponent.h"
#include "Interaction/InteractionInterface.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Engine/OverlapResult.h"
#include "TimerManager.h"

UInteractionComponent::UInteractionComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UInteractionComponent::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(
        SearchTimer,
        this,
        &UInteractionComponent::FindInteractable,
        SearchInterval,
        true
    );
}

void UInteractionComponent::FindInteractable()
{
    AActor* Owner = GetOwner();
    if (!Owner) return;

    TArray<FOverlapResult> Overlaps;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(Owner);

    GetWorld()->OverlapMultiByChannel(
        Overlaps,
        Owner->GetActorLocation(),
        FQuat::Identity,
        ECC_Visibility,
        FCollisionShape::MakeSphere(InteractionDistance),
        Params
    );

    AActor* Closest = nullptr;
    float ClosestDist = FLT_MAX;

    for (const FOverlapResult& Overlap : Overlaps)
    {
        AActor* Actor = Overlap.GetActor();
        if (!Actor) continue;

        if (Actor->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()))
        {
            float Dist = FVector::Dist(Owner->GetActorLocation(), Actor->GetActorLocation());
            if (Dist < ClosestDist)
            {
                ClosestDist = Dist;
                Closest = Actor;
            }
        }
    }

    CurrentInteractable = Closest;
}

void UInteractionComponent::Interact()
{
    if(!CurrentInteractable) return;

    if(CurrentInteractable->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()))
    {
        IInteractionInterface::Execute_Interact(CurrentInteractable, GetOwner());
    }
}