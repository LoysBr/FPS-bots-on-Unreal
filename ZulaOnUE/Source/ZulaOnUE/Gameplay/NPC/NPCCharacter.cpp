#include "NPCCharacter.h"
#include "ShooterWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "ShooterGameMode.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "ZulaOnUEGameModeBase.h"
#include "ZulaOnUE.h"
#include "NPCController.h"
#include "Components/StateTreeAIComponent.h"

void ANPCCharacter::BeginPlay()
{
	Super::BeginPlay();

	OriginalCollisionProfile = GetMesh()->GetCollisionProfileName();

	//// spawn the weapon
	//FActorSpawnParameters SpawnParams;
	//SpawnParams.Owner = this;
	//SpawnParams.Instigator = this;
	//SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	///*CurrentWeapon = GetWorld()->SpawnActor<AShooterWeapon>(StartWeapon, GetActorTransform(), SpawnParams);*/
}

void ANPCCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// clear the death timer
	GetWorld()->GetTimerManager().ClearTimer(DeathTimer);
}
//
//float ANPCCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
//{
//	// ignore if already dead
//	if (bIsDead)
//	{
//		return 0.0f;
//	}
//
//	// Reduce HP
//	CurrentHP -= Damage;
//
//	// Have we depleted HP?
//	if (CurrentHP <= 0.0f)
//	{
//		Die();
//	}
//
//	return Damage;
//}
//
//void ANPCCharacter::AttachWeaponMeshes(AShooterWeapon* WeaponToAttach)
//{
//	const FAttachmentTransformRules AttachmentRule(EAttachmentRule::SnapToTarget, false);
//
//	// attach the weapon actor
//	WeaponToAttach->AttachToActor(this, AttachmentRule);
//
//	// attach the weapon meshes
//	WeaponToAttach->GetFirstPersonMesh()->AttachToComponent(GetFirstPersonMesh(), AttachmentRule, FirstPersonWeaponSocket);
//	WeaponToAttach->GetThirdPersonMesh()->AttachToComponent(GetMesh(), AttachmentRule, ThirdPersonWeaponSocket);
//}
//
//void ANPCCharacter::PlayFiringMontage(UAnimMontage* Montage)
//{
//	// unused
//}
//
//void ANPCCharacter::AddWeaponRecoil(float Recoil)
//{
//	// unused
//}
//
//void ANPCCharacter::UpdateWeaponHUD(int32 CurrentAmmo, int32 MagazineSize)
//{
//	// unused
//}
//
//FVector ANPCCharacter::GetWeaponTargetLocation()
//{
//	// start aiming from the camera location
//	const FVector AimSource = GetFirstPersonCameraComponent()->GetComponentLocation();
//
//	FVector AimDir, AimTarget = FVector::ZeroVector;
//
//	// do we have an aim target?
//	if (CurrentAimTarget)
//	{
//		// target the actor location
//		AimTarget = CurrentAimTarget->GetActorLocation();
//
//		// apply a vertical offset to target head/feet
//		AimTarget.Z += FMath::RandRange(MinAimOffsetZ, MaxAimOffsetZ);
//
//		// get the aim direction and apply randomness in a cone
//		AimDir = (AimTarget - AimSource).GetSafeNormal();
//		AimDir = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(AimDir, AimVarianceHalfAngle);
//
//		
//	} else {
//
//		// no aim target, so just use the camera facing
//		AimDir = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(GetFirstPersonCameraComponent()->GetForwardVector(), AimVarianceHalfAngle);
//
//	}
//
//	// calculate the unobstructed aim target location
//	AimTarget = AimSource + (AimDir * AimRange);
//
//	// run a visibility trace to see if there's obstructions
//	FHitResult OutHit;
//
//	FCollisionQueryParams QueryParams;
//	QueryParams.AddIgnoredActor(this);
//
//	GetWorld()->LineTraceSingleByChannel(OutHit, AimSource, AimTarget, ECC_Visibility, QueryParams);
//
//	// return either the impact point or the trace end
//	return OutHit.bBlockingHit ? OutHit.ImpactPoint : OutHit.TraceEnd;
//}
//
//void ANPCCharacter::AddWeaponClass(const TSubclassOf<AShooterWeapon>& InWeaponClass)
//{
//	// unused
//}
//
//void ANPCCharacter::OnWeaponActivated(AShooterWeapon* InWeapon)
//{
//	// unused
//}
//
//void ANPCCharacter::OnWeaponDeactivated(AShooterWeapon* InWeapon)
//{
//	// unused
//}
//
//void ANPCCharacter::OnSemiWeaponRefire()
//{
//	// are we still shooting?
//	if (bIsShooting)
//	{
//		// fire the weapon
//		//CurrentWeapon->StartFireAction();
//	}
//}
//
void ANPCCharacter::Die()
{
	//printScreen("ANPCCharacter::Die()");
	Super::Die();

	// enable ragdoll physics on the third person mesh
	GetMesh()->SetCollisionProfileName(RagdollCollisionProfile);
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetPhysicsBlendWeight(1.0f);

	/*AZulaOnUEGameModeBase* ZulaGameMode = Cast<AZulaOnUEGameModeBase>(UGameplayStatics::GetGameMode(this));
	if (ZulaGameMode)
	{
		GetWorld()->GetTimerManager().SetTimer(DeathTimer, this, &ANPCCharacter::DeferredDestruction, ZulaGameMode->GetRespawnTime(), false);
	}*/
}

//void ANPCCharacter::Respawn()
//{
//	printScreen("ANPCCharacter::Respawn()");
//	GetMesh()->SetSimulatePhysics(false);
//	GetMesh()->SetCollisionProfileName(OriginalCollisionProfile);
//
//	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
//
//	Tags.Remove(DeathTag);
//
//	//EnableInput(nullptr);
//
//	if (NPCController* AIController = Cast<NPCController>(Controller.Get()))
//	{
//		printScreen("StateTreeAI->RestartLogic()");
//		AIController->StateTreeAI->RestartLogic();
//	}
//
//	CurrentHP = MaxHP;
//}

//TO REMOVE
//void ANPCCharacter::DeferredDestruction()
//{
//	printScreen("call ANPCCharacter::DeferredDestruction()")
//	Destroy();
//}

void ANPCCharacter::StartShooting(AActor* ActorToShoot)
{
	if (CurrentWeapon)
	{
		// save the aim target
		CurrentAimTarget = ActorToShoot;

		// raise the flag
		bIsShooting = true;

		// signal the weapon
		CurrentWeapon->StartFireAction();
	}
}

void ANPCCharacter::StopShooting()
{
	// lower the flag
	bIsShooting = false;

	// signal the weapon
	CurrentWeapon->StopFireAction();
}

int32 ANPCCharacter::GetZulaNPCId()
{
	if (ANPCController* AIController = Cast<ANPCController>(Controller.Get()))
	{
		return AIController->GetZulaNPCId();
	}
	else
	{
		UE_LOG(LogZulaOnUE, Error, TEXT("ANPCCharacter::GetZulaNPCId() => no valid controller. Returning -1"));
		return -1;
	}
}
