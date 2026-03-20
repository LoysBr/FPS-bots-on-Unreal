#include "ZulaOnUEGameModeBase.h"
#include "Variant_Shooter/ShooterGameMode.h"
#include "ShooterUI.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "ZulaOnUE.h"

AZulaOnUEGameModeBase::AZulaOnUEGameModeBase()
{
}

void AZulaOnUEGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// create the UI
	ShooterUI = CreateWidget<UShooterUI>(UGameplayStatics::GetPlayerController(GetWorld(), 0), ShooterUIClass);
	ShooterUI->AddToViewport(0);

	NumberOfNPCsSpawned = 0;

	bool isOnlineMatch = false;
	if (isOnlineMatch)
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::BeginPlay : ONLINE MATCH"));
	}
	else
	{
		NumberOfRealPlayers = 1;
		NextZulaNPCId = 0;
		OnMatchStart();
	}
}

void AZulaOnUEGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	ClearNPCs();
}

void AZulaOnUEGameModeBase::OnMatchStart()
{
	if (FillAllFreeSlotsWithNPCs)
	{
		DesiredNumberOfNPCs = DesiredNumberOfPlayers - NumberOfRealPlayers;
	}
	else
	{
		DesiredNumberOfNPCs = CustomNumberOfNPCs;
	}
	
	for (int i = 0; i < DesiredNumberOfNPCs; i++)
	{
		AddNewNPC();
	}
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

/// <summary>
/// Use a new slot in NPCControllers[], Spawn a NPC, Subscribe to NPC events
/// </summary>
void AZulaOnUEGameModeBase::AddNewNPC()
{
	UE_LOG(LogTemp, Display, TEXT("call AZulaOnUEGameModeBase::AddNewNPC()"));
	if (NumberOfNPCsSpawned + NumberOfRealPlayers >= DesiredNumberOfPlayers)
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::AddNewNPC : too many players already, returning"));
		return;
	}

	int32 id = NextZulaNPCId;
	if (id >= DesiredNumberOfNPCs)
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::AddNewNPC : GetNewZulaNPCId returned %hd > DesiredNumberOfPlayers, returning"), id);
		return;
	} 
	else if (id < 0)
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::AddNewNPC : GetNewZulaNPCId returned %hd < 0, returning"), id);
		return;
	}

	AShooterNPC* newNPC = SpawnNewNPC();
	RegisterNPC(newNPC, id);
}

void AZulaOnUEGameModeBase::RegisterNPC(AShooterNPC* NPC, int32 NPCId)
{
	UE_LOG(LogTemp, Display, TEXT("call AZulaOnUEGameModeBase::RegisterNPC()"));
	if (!NPC)
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::AddNewNPC : error when Spawning NPC, returning"));
		return;
	}
	else
	{
		if (AShooterAIController* AIController = Cast<AShooterAIController>(NPC->Controller.Get()))
		{
			AIController->SetZulaNPCId(NPCId);

			NPCControllers[NPCId] = AIController;
			NumberOfNPCsSpawned++;
			NextZulaNPCId++;
			UE_LOG(LogTemp, Display, TEXT("NextZulaNPCId = % i"), NextZulaNPCId);

			NPC->OnCharacterDied.AddDynamic(this, &AZulaOnUEGameModeBase::OnNPCDied);
		}
		else
		{
			UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::AddNewNPC : Spawned AShooterNPC's controller class is not AShooterAIController"));
		}
	}
}

void AZulaOnUEGameModeBase::RespawnNPC(int32 NPCId)
{
	printScreen("AZulaOnUEGameModeBase::RespawnNPC");
	if (NPCId < 0 || NPCId >= NumberOfNPCsSpawned)
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::RespawnNPC( %i ) : invalid NPCId. -- (NumberOfNPCsSpawned: %i"), NPCId, NumberOfNPCsSpawned);
		return;
	}

	NPCControllers[NPCId] = NULL; //free the former Controller 

	//normally the Character class has called Destroy, and for some reason the AIController is also destroyed... ?
	//we can spawn a new NPC and use this ID
	AShooterNPC* newNPC = SpawnNewNPC();
	RegisterNPC(newNPC, NPCId);
}

/// <summary>
/// Spawn Actor
/// </summary>
/// <returns>The created Actor, or NULL</returns>
AShooterNPC* AZulaOnUEGameModeBase::SpawnNewNPC()
{
	UE_LOG(LogTemp, Display, TEXT("call AZulaOnUEGameModeBase::SpawnNewNPC()"));

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
	UE_LOG(LogTemp, Display, TEXT("call AZulaOnUEGameModeBase::GetRandomStartPointData()"));

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

/// <summary>
/// Find the first NULL element in NPCControllers and return its index
/// </summary>
/// <returns>index of a free NPCControllers element</returns>
int32 AZulaOnUEGameModeBase::GetNewZulaNPCId()
{
	UE_LOG(LogZulaOnUE, Error, TEXT("TO BE IMPLEMENTED"));

	/*int32 ret = 0;

	for (TObjectPtr<AShooterAIController> NPCController : NPCControllers)
	{
		if (NPCController == NULL)
		{
			return ret;
		}

		ret++;
	}*/

	UE_LOG(LogZulaOnUE, Error, TEXT("AZulaOnUEGameModeBase::GetNewZulaNPCId could not find a null element in NPCControllers, means there are too many NPC already!"));
	return 0;
}

void AZulaOnUEGameModeBase::OnNPCDied(int32 NPCId)
{
	printScreen("call AZulaOnUEGameModeBase::OnNPCDied()")

	// schedule the next NPC spawn
	FTimerHandle RespawnTimer;
	FTimerDelegate timerDelegate;
	timerDelegate.BindUFunction(this, FName("RespawnNPC"), NPCId);
	GetWorld()->GetTimerManager().SetTimer(RespawnTimer, timerDelegate, RespawnTime, false);
}

float AZulaOnUEGameModeBase::GetRespawnTime()
{
	return RespawnTime;
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

	NumberOfNPCsSpawned = 0;
	NextZulaNPCId = 0;
}