// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZulaOnUECharacter.h"
#include "FpsCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ZULAONUE_API AFpsCharacter : public AZulaOnUECharacter
{
	GENERATED_BODY()
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	virtual int32 GetZulaNPCId() override;
};
