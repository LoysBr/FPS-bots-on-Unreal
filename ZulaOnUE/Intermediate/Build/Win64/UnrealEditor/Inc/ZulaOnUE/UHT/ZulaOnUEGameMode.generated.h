// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ZulaOnUEGameMode.h"

#ifdef ZULAONUE_ZulaOnUEGameMode_generated_h
#error "ZulaOnUEGameMode.generated.h already included, missing '#pragma once' in ZulaOnUEGameMode.h"
#endif
#define ZULAONUE_ZulaOnUEGameMode_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AZulaOnUEGameMode ********************************************************
struct Z_Construct_UClass_AZulaOnUEGameMode_Statics;
ZULAONUE_API UClass* Z_Construct_UClass_AZulaOnUEGameMode_NoRegister();

#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZulaOnUEGameMode(); \
	friend struct ::Z_Construct_UClass_AZulaOnUEGameMode_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ZULAONUE_API UClass* ::Z_Construct_UClass_AZulaOnUEGameMode_NoRegister(); \
public: \
	DECLARE_CLASS2(AZulaOnUEGameMode, AGameModeBase, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZulaOnUE"), Z_Construct_UClass_AZulaOnUEGameMode_NoRegister) \
	DECLARE_SERIALIZER(AZulaOnUEGameMode)


#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AZulaOnUEGameMode(AZulaOnUEGameMode&&) = delete; \
	AZulaOnUEGameMode(const AZulaOnUEGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZulaOnUEGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZulaOnUEGameMode); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AZulaOnUEGameMode) \
	NO_API virtual ~AZulaOnUEGameMode();


#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h_12_PROLOG
#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h_15_INCLASS_NO_PURE_DECLS \
	FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AZulaOnUEGameMode;

// ********** End Class AZulaOnUEGameMode **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
