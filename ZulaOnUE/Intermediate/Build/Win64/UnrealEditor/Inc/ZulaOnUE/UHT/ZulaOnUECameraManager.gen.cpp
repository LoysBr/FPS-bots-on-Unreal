// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZulaOnUECameraManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeZulaOnUECameraManager() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager();
UPackage* Z_Construct_UPackage__Script_ZulaOnUE();
ZULAONUE_API UClass* Z_Construct_UClass_AZulaOnUECameraManager();
ZULAONUE_API UClass* Z_Construct_UClass_AZulaOnUECameraManager_NoRegister();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AZulaOnUECameraManager ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_AZulaOnUECameraManager;
UClass* AZulaOnUECameraManager::GetPrivateStaticClass()
{
	using TClass = AZulaOnUECameraManager;
	if (!Z_Registration_Info_UClass_AZulaOnUECameraManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ZulaOnUECameraManager"),
			Z_Registration_Info_UClass_AZulaOnUECameraManager.InnerSingleton,
			StaticRegisterNativesAZulaOnUECameraManager,
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
	return Z_Registration_Info_UClass_AZulaOnUECameraManager.InnerSingleton;
}
UClass* Z_Construct_UClass_AZulaOnUECameraManager_NoRegister()
{
	return AZulaOnUECameraManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AZulaOnUECameraManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Basic First Person camera manager.\n *  Limits min/max look pitch.\n */" },
#endif
		{ "IncludePath", "ZulaOnUECameraManager.h" },
		{ "ModuleRelativePath", "ZulaOnUECameraManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Basic First Person camera manager.\nLimits min/max look pitch." },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class AZulaOnUECameraManager constinit property declarations *******************
// ********** End Class AZulaOnUECameraManager constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZulaOnUECameraManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_AZulaOnUECameraManager_Statics
UObject* (*const Z_Construct_UClass_AZulaOnUECameraManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerCameraManager,
	(UObject* (*)())Z_Construct_UPackage__Script_ZulaOnUE,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AZulaOnUECameraManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AZulaOnUECameraManager_Statics::ClassParams = {
	&AZulaOnUECameraManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AZulaOnUECameraManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AZulaOnUECameraManager_Statics::Class_MetaDataParams)
};
void AZulaOnUECameraManager::StaticRegisterNativesAZulaOnUECameraManager()
{
}
UClass* Z_Construct_UClass_AZulaOnUECameraManager()
{
	if (!Z_Registration_Info_UClass_AZulaOnUECameraManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZulaOnUECameraManager.OuterSingleton, Z_Construct_UClass_AZulaOnUECameraManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AZulaOnUECameraManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AZulaOnUECameraManager);
AZulaOnUECameraManager::~AZulaOnUECameraManager() {}
// ********** End Class AZulaOnUECameraManager *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECameraManager_h__Script_ZulaOnUE_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AZulaOnUECameraManager, AZulaOnUECameraManager::StaticClass, TEXT("AZulaOnUECameraManager"), &Z_Registration_Info_UClass_AZulaOnUECameraManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZulaOnUECameraManager), 2365991128U) },
	};
}; // Z_CompiledInDeferFile_FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECameraManager_h__Script_ZulaOnUE_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECameraManager_h__Script_ZulaOnUE_857531451{
	TEXT("/Script/ZulaOnUE"),
	Z_CompiledInDeferFile_FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECameraManager_h__Script_ZulaOnUE_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ZulaOnUE_Source_ZulaOnUE_ZulaOnUECameraManager_h__Script_ZulaOnUE_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
