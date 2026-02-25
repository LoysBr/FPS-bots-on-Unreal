// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZulaOnUEGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZulaOnUEGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_ZulaOnUE();
ZULAONUE_API UClass* Z_Construct_UClass_AZulaOnUEGameMode();
ZULAONUE_API UClass* Z_Construct_UClass_AZulaOnUEGameMode_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AZulaOnUEGameMode ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AZulaOnUEGameMode;
UClass* AZulaOnUEGameMode::GetPrivateStaticClass()
{
	using TClass = AZulaOnUEGameMode;
	if (!Z_Registration_Info_UClass_AZulaOnUEGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZulaOnUEGameMode"),
			Z_Registration_Info_UClass_AZulaOnUEGameMode.InnerSingleton,
			StaticRegisterNativesAZulaOnUEGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AZulaOnUEGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_AZulaOnUEGameMode_NoRegister()
{
	return AZulaOnUEGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AZulaOnUEGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a first person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ZulaOnUEGameMode.h" },
		{ "ModuleRelativePath", "ZulaOnUEGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a first person game" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AZulaOnUEGameMode constinit property declarations ************************
// ********** End Class AZulaOnUEGameMode constinit property declarations **************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZulaOnUEGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AZulaOnUEGameMode_Statics
UObject* (*const Z_Construct_UClass_AZulaOnUEGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ZulaOnUE,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZulaOnUEGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZulaOnUEGameMode_Statics::ClassParams = {
	&AZulaOnUEGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZulaOnUEGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AZulaOnUEGameMode_Statics::Class_MetaDataParams)
};
void AZulaOnUEGameMode::StaticRegisterNativesAZulaOnUEGameMode()
{
}
UClass* Z_Construct_UClass_AZulaOnUEGameMode()
{
	if (!Z_Registration_Info_UClass_AZulaOnUEGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZulaOnUEGameMode.OuterSingleton, Z_Construct_UClass_AZulaOnUEGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZulaOnUEGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AZulaOnUEGameMode);
AZulaOnUEGameMode::~AZulaOnUEGameMode() {}
// ********** End Class AZulaOnUEGameMode **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h__Script_ZulaOnUE_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZulaOnUEGameMode, AZulaOnUEGameMode::StaticClass, TEXT("AZulaOnUEGameMode"), &Z_Registration_Info_UClass_AZulaOnUEGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZulaOnUEGameMode), 3247911737U) },
	};
}; // Z_CompiledInDeferFile_FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h__Script_ZulaOnUE_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h__Script_ZulaOnUE_1628424874{
	TEXT("/Script/ZulaOnUE"),
	Z_CompiledInDeferFile_FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h__Script_ZulaOnUE_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUEGameMode_h__Script_ZulaOnUE_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
