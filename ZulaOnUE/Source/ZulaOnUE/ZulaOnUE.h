// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/** Main log category used across the project */
DECLARE_LOG_CATEGORY_EXTERN(LogZulaOnUE, Log, All);

#define printScreen(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 999, FColor::Black, text); \
UE_LOG(LogTemp, Display, TEXT(text))