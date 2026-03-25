#include "NPCController.h"
#include "NPCCharacter.h"
#include "Components/StateTreeAIComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "AI/Navigation/PathFollowingAgentInterface.h"

ANPCController::ANPCController()
{
	// create the StateTree component
	StateTreeAI = CreateDefaultSubobject<UStateTreeAIComponent>(TEXT("StateTreeAI"));
	StateTreeAI->SetStartLogicAutomatically(false);

	// create the AI perception component. It will be configured in BP
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));

	// subscribe to the AI perception delegates
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ANPCController::OnPerceptionUpdated);
	AIPerception->OnTargetPerceptionForgotten.AddDynamic(this, &ANPCController::OnPerceptionForgotten);
}

void ANPCController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// ensure we're possessing an NPC
	if (ANPCCharacter* NPC = Cast<ANPCCharacter>(InPawn))
	{
		// add the team tag to the pawn
		NPC->Tags.Add(TeamTag);

		// subscribe to the pawn's OnDeath delegate
		NPC->OnCharacterDied.AddDynamic(this, &ANPCController::OnPawnDeath);

		// start AI logic
		StateTreeAI->StartLogic();
	}
}

void ANPCController::OnPawnDeath(int32 id)
{
	// stop movement
	GetPathFollowingComponent()->AbortMove(*this, FPathFollowingResultFlags::UserAbort);

	// stop StateTree logic
	StateTreeAI->StopLogic(FString(""));

	// unpossess the pawn
	UnPossess();

	// destroy this controller
	Destroy();
}

void ANPCController::SetCurrentTarget(AActor* Target)
{
	TargetEnemy = Target;
}

void ANPCController::ClearCurrentTarget()
{
	TargetEnemy = nullptr;
}

void ANPCController::SetZulaNPCId(int32 zulaPlayerId)
{
	this->ZulaNPCId = zulaPlayerId;
}

int32 ANPCController::GetZulaNPCId()
{
	return ZulaNPCId;
}

void ANPCController::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	// pass the data to the StateTree delegate hook
	OnShooterPerceptionUpdated.ExecuteIfBound(Actor, Stimulus);
}

void ANPCController::OnPerceptionForgotten(AActor* Actor)
{
	// pass the data to the StateTree delegate hook
	OnShooterPerceptionForgotten.ExecuteIfBound(Actor);
}
