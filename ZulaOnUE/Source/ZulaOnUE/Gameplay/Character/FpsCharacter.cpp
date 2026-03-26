// Fill out your copyright notice in the Description page of Project Settings.

#include "FpsCharacter.h"
#include "EnhancedInputComponent.h"

void AFpsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UE_LOG(LogTemp, Display, TEXT("AFpsCharacter::SetupPlayerInputComponent()"));

	// base class handles move, aim and jump inputs
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Firing
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, this, &AFpsCharacter::DoStartFireAction);
		EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Completed, this, &AFpsCharacter::DoStopFireAction);

		// Switch weapon
		EnhancedInputComponent->BindAction(SwitchWeaponAction, ETriggerEvent::Triggered, this, &AFpsCharacter::DoSwitchWeaponAction);
	}

}

int32 AFpsCharacter::GetZulaNPCId()
{
	return 0;
}