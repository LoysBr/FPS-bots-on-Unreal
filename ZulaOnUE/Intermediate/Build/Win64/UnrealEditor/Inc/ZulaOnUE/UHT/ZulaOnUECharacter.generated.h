// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ZulaOnUECharacter.h"

#ifdef ZULAONUE_ZulaOnUECharacter_generated_h
#error "ZulaOnUECharacter.generated.h already included, missing '#pragma once' in ZulaOnUECharacter.h"
#endif
#define ZULAONUE_ZulaOnUECharacter_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AZulaOnUECharacter *******************************************************
#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDoJumpEnd); \
	DECLARE_FUNCTION(execDoJumpStart); \
	DECLARE_FUNCTION(execDoMove); \
	DECLARE_FUNCTION(execDoAim);


struct Z_Construct_UClass_AZulaOnUECharacter_Statics;
ZULAONUE_API UClass* Z_Construct_UClass_AZulaOnUECharacter_NoRegister();

#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZulaOnUECharacter(); \
	friend struct ::Z_Construct_UClass_AZulaOnUECharacter_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ZULAONUE_API UClass* ::Z_Construct_UClass_AZulaOnUECharacter_NoRegister(); \
public: \
	DECLARE_CLASS2(AZulaOnUECharacter, ACharacter, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZulaOnUE"), Z_Construct_UClass_AZulaOnUECharacter_NoRegister) \
	DECLARE_SERIALIZER(AZulaOnUECharacter)


#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECharacter_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AZulaOnUECharacter(AZulaOnUECharacter&&) = delete; \
	AZulaOnUECharacter(const AZulaOnUECharacter&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZulaOnUECharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZulaOnUECharacter); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AZulaOnUECharacter) \
	NO_API virtual ~AZulaOnUECharacter();


#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECharacter_h_21_PROLOG
#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AZulaOnUECharacter;

// ********** End Class AZulaOnUECharacter *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECharacter_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
