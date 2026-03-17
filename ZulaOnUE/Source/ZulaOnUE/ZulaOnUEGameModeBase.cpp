#include "ZulaOnUEGameModeBase.h"
#include "Variant_Shooter/ShooterGameMode.h"
#include "ShooterUI.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "ZulaOnUE.h"

AZulaOnUEGameModeBase::AZulaOnUEGameModeBase()
{
	MaxNumberOfPlayers = NPCControllers.Num();
}

void AZulaOnUEGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// create the UI
	ShooterUI = CreateWidget<UShooterUI>(UGameplayStatics::GetPlayerController(GetWorld(), 0), ShooterUIClass);
	ShooterUI->AddToViewport(0);

	AddNewNPC();
}

void AZulaOnUEGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	ClearNPCs();
}

void AZulaOnUEGameModeBase::IncrementTeamScore(uint8 TeamByte)
{
	// retrieve the team score if any
	int32 Score = 0;
	if (int32* FoundScore = TeamScores.Find(TeamByte))
	{
		Score = *FoundScore;
	}

	// increment the score for the given team
	++Score;
	TeamScores.Add(TeamByte, Score);

	// update the UI
	ShooterUI->BP_UpdateScore(TeamByte, Score);
}

void AZulaOnUEGameModeBase::AddNewNPC()
{
	if (NumberOfNPCsInGame + NumberOfRealPlayers >= MaxNumberOfPlayers)
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::AddNewNPC : too many players already, returning"));
		return;
	}

	short id = GetNewZulaNPCId();
	if (id >= MaxNumberOfPlayers)
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::AddNewNPC : GetNewZulaNPCId returned a value > MaxNumberOfPlayers, returning"));
		return;
	}

	AShooterNPC* newNPC = SpawnNewNPC();

	if (!newNPC)
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::AddNewNPC : error when Spawning NPC, returning"));
		return;
	}
	else
	{
		if (AShooterAIController* AIController = Cast<AShooterAIController>(newNPC->Controller.Get()))
		{
			AIController->SetZulaNPCId(id);

			NPCControllers[id] = AIController;
			NumberOfNPCsInGame++;
		}
		else
		{
			UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::AddNewNPC : Spawned AShooterNPC's controller class is not AShooterAIController"));
		}
	}
}

AShooterNPC* AZulaOnUEGameModeBase::SpawnNewNPC()
{
	printScreen("AZulaOnUEGameModeBase::SpawnNewNPC");

	if (!IsValid(NPCClass))
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::SpawnNewNPC : NPCClass is not Valid"));
		return NULL;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	FVector SpawnLocation;
	FRotator SpawnRotation;
	GetRandomStartPointData(SpawnLocation, SpawnRotation);

	AShooterNPC* SpawnedNPC = GetWorld()->SpawnActor<AShooterNPC>(NPCClass, SpawnLocation, SpawnRotation, SpawnParams);

	if (IsValid(SpawnedNPC))
	{
		return SpawnedNPC;
	}
	else
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::SpawnNewNPC : Error while spawning actor AShooterNPC"));
		return NULL;
	}
}

void AZulaOnUEGameModeBase::GetRandomStartPointData(FVector &Location, FRotator &Rotation)
{	
	printScreen("call AZulaOnUEGameModeBase::GetRandomStartPointData()")

	AActor* StartSpot = ChoosePlayerStart(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (StartSpot == nullptr)
	{
		UE_LOG(LogGameMode, Log, TEXT("AZulaOnUEGameModeBase::GetRandomStartPointData: NO PLAYERSTART FOUND, Spawning on (0, 0, 0)"));

		// This is a bit odd, but there was a complex chunk of code that in the end always resulted in this, so we may as well just 
		// short cut it down to this.  Basically we are saying spawn at 0,0,0 if we didn't find a proper player start
		StartSpot = GetWorld()->GetWorldSettings();
	}

	Rotation.Yaw = StartSpot->GetActorRotation().Yaw;
	Location = StartSpot->GetActorLocation();
}

void AZulaOnUEGameModeBase::OnNPCDied()
{
	// schedule the next NPC spawn
	FTimerHandle RespawnTimer;
	//GetWorld()->GetTimerManager().SetTimer(RespawnTimer, this, &AZulaOnUEGameModeBase::SpawnNewNPC, RespawnTime);
}

float AZulaOnUEGameModeBase::GetRespawnTime()
{
	return RespawnTime;
}

/// <summary>
/// Find the first NULL element in NPCControllers and return its index
/// </summary>
/// <returns>index of a free NPCControllers element</returns>
short AZulaOnUEGameModeBase::GetNewZulaNPCId()
{
	short ret = 0;

	for (TObjectPtr<AShooterAIController> NPCController : NPCControllers)
	{
		if (NPCController == NULL)
		{
			return ret;
		}

		ret++;
	}

	UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::GetNewZulaNPCId could not find a null element in NPCControllers, means there are too many NPC already!"));
	return ret;
}

void AZulaOnUEGameModeBase::ClearNPCs()
{
	UE_LOG(LogTemp, Display, TEXT("AZulaOnUEGameModeBase::ClearNPCs"));
	for (TObjectPtr<AShooterAIController> NPCController : NPCControllers)
	{
		if (NPCController == NULL)
		{
			continue;
		}

		if (ACharacter* charac = NPCController->GetCharacter())
		{
			charac->Destroy();
		}

		NPCController->Destroy();
	}
}