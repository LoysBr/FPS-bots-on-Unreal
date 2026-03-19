// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterNPC.h"
#include "ShooterAIController.h"
#include "ZulaOnUEGameModeBase.generated.h"

class UShooterUI;

UCLASS(abstract)
class AZulaOnUEGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AZulaOnUEGameModeBase();

protected:
	/** Type of UI widget to spawn */
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UShooterUI> ShooterUIClass;

	/** Pointer to the UI widget */
	TObjectPtr<UShooterUI> ShooterUI;

	/** Map of scores by team ID */
	TMap<uint8, int32> TeamScores;

	UPROPERTY(EditAnywhere, Category = "Tweak", meta = (ClampMin = 1, ClampMax = 10, Units = "s"))
	float RespawnTime = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NPC")
	TSubclassOf<AShooterNPC> NPCClass;

	TStaticArray<TObjectPtr<AShooterAIController>, 10> NPCControllers;

	int32 MaxNumberOfPlayers; //init with NPCControllers size

	int32 NumberOfNPCsInGame = 0;

	int32 NumberOfRealPlayers = 1; //for offline mode - use this when player online with several clients

	int32 NextZulaPlayerId = 0;

	//METHODS
protected:
	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Gameplay cleanup */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void ClearNPCs();

	void AddNewNPC();

	UFUNCTION()
	void RespawnNPC(int32 NPCId);

	AShooterNPC* SpawnNewNPC();

	void RegisterNPC(AShooterNPC* NPC, int32 NPCId);

	UFUNCTION()
	void OnNPCDied(int32 NPCId);

	void GetRandomStartPointData(FVector& Location, FRotator& Rotation);

	int32 GetNewZulaNPCId();

public:
	/** Increases the score for the given team */
	void IncrementTeamScore(uint8 TeamByte);

	float GetRespawnTime();
};



