// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZulaOnUE_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	ZULAONUE_API UFunction* Z_Construct_UDelegateFunction_ZulaOnUE_BulletCountUpdatedDelegate__DelegateSignature();
	ZULAONUE_API UFunction* Z_Construct_UDelegateFunction_ZulaOnUE_DamagedDelegate__DelegateSignature();
	ZULAONUE_API UFunction* Z_Construct_UDelegateFunction_ZulaOnUE_PawnDeathDelegate__DelegateSignature();
	ZULAONUE_API UFunction* Z_Construct_UDelegateFunction_ZulaOnUE_SprintStateChangedDelegate__DelegateSignature();
	ZULAONUE_API UFunction* Z_Construct_UDelegateFunction_ZulaOnUE_UpdateSprintMeterDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ZulaOnUE;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ZulaOnUE()
	{
		if (!Z_Registration_Info_UPackage__Script_ZulaOnUE.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_ZulaOnUE_BulletCountUpdatedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_ZulaOnUE_DamagedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_ZulaOnUE_PawnDeathDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_ZulaOnUE_SprintStateChangedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_ZulaOnUE_UpdateSprintMeterDelegate__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/ZulaOnUE",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x996F0374,
			0xA3559542,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ZulaOnUE.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_ZulaOnUE.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ZulaOnUE(Z_Construct_UPackage__Script_ZulaOnUE, TEXT("/Script/ZulaOnUE"), Z_Registration_Info_UPackage__Script_ZulaOnUE, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x996F0374, 0xA3559542));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
