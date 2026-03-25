#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NPCCharacter.h"
#include "NPCController.h"
#include "ZulaOnUEGameModeBase.generated.h"

class UShooterUI;

UCLASS(abstract)
class AZulaOnUEGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AZulaOnUEGameModeBase();

protected:
	UPROPERTY(EditAnywhere, Category = "Tweak", meta = (ClampMin = 1, ClampMax = 10))
	int32 DesiredNumberOfPlayers = 4;

	UPROPERTY(EditAnywhere, Category = "Tweak", meta = (ToolTip = "Create NPC until reaching 'DesiredNumberOfPlayers' if there is not enough real players"))
	bool FillAllFreeSlotsWithNPCs = true;

	UPROPERTY(EditAnywhere, Category = "Tweak", meta = (EditCondition = "FillAllFreeSlotsWithNPCs==false", ClampMin = 0, ClampMax = 9))
	int32 CustomNumberOfNPCs = 1;

	UPROPERTY(EditAnywhere, Category = "Tweak", meta = (ClampMin = 1, ClampMax = 10, Units = "s"))
	float RespawnTime = 5.0f;	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NPC")
	TSubclassOf<ANPCCharacter> NPCClass;

	/** Type of UI widget to spawn */
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UShooterUI> ShooterUIClass;

	/** Pointer to the UI widget */
	TObjectPtr<UShooterUI> ShooterUI;

	/** Map of scores by team ID */
	TMap<uint8, int32> TeamScores;

	TStaticArray<TObjectPtr<ANPCController>, 10> NPCControllers;

	int32 DesiredNumberOfNPCs = 1;
	int32 NumberOfNPCsSpawned = 0;
	int32 NumberOfRealPlayers = 1; //for offline mode - use this when player online with several clients
	int32 NextZulaNPCId = 0;

	//METHODS
protected:
	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Gameplay cleanup */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	//In Online match I excpect to have a pre-match phase when Clients connect, then the Match can start
	void OnMatchStart();

	void ClearNPCs();

	void AddNewNPC();

	UFUNCTION()
	void RespawnNPC(int32 NPCId);

	ANPCCharacter* SpawnNewNPC();

	void RegisterNPC(ANPCCharacter* NPC, int32 NPCId);

	UFUNCTION()
	void OnNPCDied(int32 NPCId);

	void GetRandomStartPointData(FVector& Location, FRotator& Rotation);

	int32 GetNewZulaNPCId();

public:
	/** Increases the score for the given team */
	void IncrementTeamScore(uint8 TeamByte);

	float GetRespawnTime();
};



