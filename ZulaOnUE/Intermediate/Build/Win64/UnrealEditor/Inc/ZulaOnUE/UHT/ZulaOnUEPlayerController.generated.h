// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ZulaOnUEPlayerController.h"

#ifdef ZULAONUE_ZulaOnUEPlayerController_generated_h
#error "ZulaOnUEPlayerController.generated.h already included, missing '#pragma once' in ZulaOnUEPlayerController.h"
#endif
#define ZULAONUE_ZulaOnUEPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AZulaOnUEPlayerController ************************************************
struct Z_Construct_UClass_AZulaOnUEPlayerController_Statics;
ZULAONUE_API UClass* Z_Construct_UClass_AZulaOnUEPlayerController_NoRegister();

#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEPlayerController_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZulaOnUEPlayerController(); \
	friend struct ::Z_Construct_UClass_AZulaOnUEPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend ZULAONUE_API UClass* ::Z_Construct_UClass_AZulaOnUEPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AZulaOnUEPlayerController, APlayerController, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZulaOnUE"), Z_Construct_UClass_AZulaOnUEPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AZulaOnUEPlayerController)


#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEPlayerController_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AZulaOnUEPlayerController(AZulaOnUEPlayerController&&) = delete; \
	AZulaOnUEPlayerController(const AZulaOnUEPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZulaOnUEPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZulaOnUEPlayerController); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(AZulaOnUEPlayerController) \
	NO_API virtual ~AZulaOnUEPlayerController();


#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEPlayerController_h_17_PROLOG
#define FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEPlayerController_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEPlayerController_h_20_INCLASS_NO_PURE_DECLS \
	FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEPlayerController_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AZulaOnUEPlayerController;

// ********** End Class AZulaOnUEPlayerController **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
