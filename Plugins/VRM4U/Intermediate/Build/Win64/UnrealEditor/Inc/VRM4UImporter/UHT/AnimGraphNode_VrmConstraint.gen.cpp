// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VRM4UImporter/Private/AnimGraphNode_VrmConstraint.h"
#include "VRM4U/Public/AnimNode_VrmConstraint.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimGraphNode_VrmConstraint() {}
// Cross Module References
	ANIMGRAPH_API UClass* Z_Construct_UClass_UAnimGraphNode_SkeletalControlBase();
	UPackage* Z_Construct_UPackage__Script_VRM4UImporter();
	VRM4U_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_VrmConstraint();
	VRM4UIMPORTER_API UClass* Z_Construct_UClass_UAnimGraphNode_VrmConstraint();
	VRM4UIMPORTER_API UClass* Z_Construct_UClass_UAnimGraphNode_VrmConstraint_NoRegister();
// End Cross Module References
	void UAnimGraphNode_VrmConstraint::StaticRegisterNativesUAnimGraphNode_VrmConstraint()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAnimGraphNode_VrmConstraint);
	UClass* Z_Construct_UClass_UAnimGraphNode_VrmConstraint_NoRegister()
	{
		return UAnimGraphNode_VrmConstraint::StaticClass();
	}
	struct Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Node_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Node;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPreviewLive_MetaData[];
#endif
		static void NewProp_bPreviewLive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreviewLive;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPreviewForeground_MetaData[];
#endif
		static void NewProp_bPreviewForeground_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPreviewForeground;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimGraphNode_SkeletalControlBase,
		(UObject* (*)())Z_Construct_UPackage__Script_VRM4UImporter,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AnimGraphNode_VrmConstraint.h" },
		{ "Keywords", "VRM4U" },
		{ "ModuleRelativePath", "Private/AnimGraphNode_VrmConstraint.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_Node_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Private/AnimGraphNode_VrmConstraint.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UAnimGraphNode_VrmConstraint, Node), Z_Construct_UScriptStruct_FAnimNode_VrmConstraint, METADATA_PARAMS(Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_Node_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_Node_MetaData)) }; // 2573929882
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewLive_MetaData[] = {
		{ "Category", "Preview" },
		{ "ModuleRelativePath", "Private/AnimGraphNode_VrmConstraint.h" },
	};
#endif
	void Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewLive_SetBit(void* Obj)
	{
		((UAnimGraphNode_VrmConstraint*)Obj)->bPreviewLive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewLive = { "bPreviewLive", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UAnimGraphNode_VrmConstraint), &Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewLive_SetBit, METADATA_PARAMS(Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewLive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewLive_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewForeground_MetaData[] = {
		{ "Category", "Preview" },
		{ "ModuleRelativePath", "Private/AnimGraphNode_VrmConstraint.h" },
	};
#endif
	void Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewForeground_SetBit(void* Obj)
	{
		((UAnimGraphNode_VrmConstraint*)Obj)->bPreviewForeground = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewForeground = { "bPreviewForeground", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UAnimGraphNode_VrmConstraint), &Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewForeground_SetBit, METADATA_PARAMS(Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewForeground_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewForeground_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_Node,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewLive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::NewProp_bPreviewForeground,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimGraphNode_VrmConstraint>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::ClassParams = {
		&UAnimGraphNode_VrmConstraint::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAnimGraphNode_VrmConstraint()
	{
		if (!Z_Registration_Info_UClass_UAnimGraphNode_VrmConstraint.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnimGraphNode_VrmConstraint.OuterSingleton, Z_Construct_UClass_UAnimGraphNode_VrmConstraint_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UAnimGraphNode_VrmConstraint.OuterSingleton;
	}
	template<> VRM4UIMPORTER_API UClass* StaticClass<UAnimGraphNode_VrmConstraint>()
	{
		return UAnimGraphNode_VrmConstraint::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimGraphNode_VrmConstraint);
	UAnimGraphNode_VrmConstraint::~UAnimGraphNode_VrmConstraint() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UImporter_Private_AnimGraphNode_VrmConstraint_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UImporter_Private_AnimGraphNode_VrmConstraint_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UAnimGraphNode_VrmConstraint, UAnimGraphNode_VrmConstraint::StaticClass, TEXT("UAnimGraphNode_VrmConstraint"), &Z_Registration_Info_UClass_UAnimGraphNode_VrmConstraint, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnimGraphNode_VrmConstraint), 558052843U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UImporter_Private_AnimGraphNode_VrmConstraint_h_2577506570(TEXT("/Script/VRM4UImporter"),
		Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UImporter_Private_AnimGraphNode_VrmConstraint_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UImporter_Private_AnimGraphNode_VrmConstraint_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
