// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VRM4UCapture/Public/AnimNode_VrmVMC.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_VrmVMC() {}
// Cross Module References
	ANIMGRAPHRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_SkeletalControlBase();
	UPackage* Z_Construct_UPackage__Script_VRM4UCapture();
	VRM4U_API UClass* Z_Construct_UClass_UVrmMetaObject_NoRegister();
	VRM4UCAPTURE_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_VrmVMC();
// End Cross Module References

static_assert(std::is_polymorphic<FAnimNode_VrmVMC>() == std::is_polymorphic<FAnimNode_SkeletalControlBase>(), "USTRUCT FAnimNode_VrmVMC cannot be polymorphic unless super FAnimNode_SkeletalControlBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_VrmVMC;
class UScriptStruct* FAnimNode_VrmVMC::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_VrmVMC.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_VrmVMC.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_VrmVMC, (UObject*)Z_Construct_UPackage__Script_VRM4UCapture(), TEXT("AnimNode_VrmVMC"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_VrmVMC.OuterSingleton;
}
template<> VRM4UCAPTURE_API UScriptStruct* StaticStruct<FAnimNode_VrmVMC>()
{
	return FAnimNode_VrmVMC::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnableAutoSearchMetaData_MetaData[];
#endif
		static void NewProp_EnableAutoSearchMetaData_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_EnableAutoSearchMetaData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VrmMetaObject_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_VrmMetaObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseRemoteCenterPos_MetaData[];
#endif
		static void NewProp_bUseRemoteCenterPos_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseRemoteCenterPos;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ModelRelativeScale_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ModelRelativeScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIgnoreLocalRotation_MetaData[];
#endif
		static void NewProp_bIgnoreLocalRotation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnoreLocalRotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ServerAddress_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ServerAddress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Port_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_Port;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n*\x09Simple controller that replaces or adds to the translation/rotation of a single bone.\n*/" },
		{ "ModuleRelativePath", "Public/AnimNode_VrmVMC.h" },
		{ "ToolTip", "Simple controller that replaces or adds to the translation/rotation of a single bone." },
	};
#endif
	void* Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_VrmVMC>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_EnableAutoSearchMetaData_MetaData[] = {
		{ "Category", "Skeleton" },
		{ "ModuleRelativePath", "Public/AnimNode_VrmVMC.h" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_EnableAutoSearchMetaData_SetBit(void* Obj)
	{
		((FAnimNode_VrmVMC*)Obj)->EnableAutoSearchMetaData = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_EnableAutoSearchMetaData = { "EnableAutoSearchMetaData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_VrmVMC), &Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_EnableAutoSearchMetaData_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_EnableAutoSearchMetaData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_EnableAutoSearchMetaData_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_VrmMetaObject_MetaData[] = {
		{ "Category", "Skeleton" },
		{ "ModuleRelativePath", "Public/AnimNode_VrmVMC.h" },
		{ "NativeConst", "" },
		{ "PinHiddenByDefault", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_VrmMetaObject = { "VrmMetaObject", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_VrmVMC, VrmMetaObject), Z_Construct_UClass_UVrmMetaObject_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_VrmMetaObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_VrmMetaObject_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bUseRemoteCenterPos_MetaData[] = {
		{ "Category", "Skeleton" },
		{ "Comment", "//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Skeleton, meta = (PinShownByDefault))\n//TMap<FString, FTransform> BoneTrans;\n" },
		{ "ModuleRelativePath", "Public/AnimNode_VrmVMC.h" },
		{ "PinShownByDefault", "" },
		{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Skeleton, meta = (PinShownByDefault))\nTMap<FString, FTransform> BoneTrans;" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bUseRemoteCenterPos_SetBit(void* Obj)
	{
		((FAnimNode_VrmVMC*)Obj)->bUseRemoteCenterPos = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bUseRemoteCenterPos = { "bUseRemoteCenterPos", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_VrmVMC), &Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bUseRemoteCenterPos_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bUseRemoteCenterPos_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bUseRemoteCenterPos_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_ModelRelativeScale_MetaData[] = {
		{ "Category", "Skeleton" },
		{ "ModuleRelativePath", "Public/AnimNode_VrmVMC.h" },
		{ "PinShownByDefault", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_ModelRelativeScale = { "ModelRelativeScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_VrmVMC, ModelRelativeScale), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_ModelRelativeScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_ModelRelativeScale_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bIgnoreLocalRotation_MetaData[] = {
		{ "Category", "Skeleton" },
		{ "ModuleRelativePath", "Public/AnimNode_VrmVMC.h" },
		{ "PinShownByDefault", "" },
	};
#endif
	void Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bIgnoreLocalRotation_SetBit(void* Obj)
	{
		((FAnimNode_VrmVMC*)Obj)->bIgnoreLocalRotation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bIgnoreLocalRotation = { "bIgnoreLocalRotation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FAnimNode_VrmVMC), &Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bIgnoreLocalRotation_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bIgnoreLocalRotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bIgnoreLocalRotation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_ServerAddress_MetaData[] = {
		{ "Category", "Skeleton" },
		{ "ModuleRelativePath", "Public/AnimNode_VrmVMC.h" },
		{ "PinShownByDefault", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_ServerAddress = { "ServerAddress", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_VrmVMC, ServerAddress), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_ServerAddress_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_ServerAddress_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_Port_MetaData[] = {
		{ "Category", "Skeleton" },
		{ "ModuleRelativePath", "Public/AnimNode_VrmVMC.h" },
		{ "PinShownByDefault", "" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_Port = { "Port", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FAnimNode_VrmVMC, Port), METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_Port_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_Port_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_EnableAutoSearchMetaData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_VrmMetaObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bUseRemoteCenterPos,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_ModelRelativeScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_bIgnoreLocalRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_ServerAddress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewProp_Port,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VRM4UCapture,
		Z_Construct_UScriptStruct_FAnimNode_SkeletalControlBase,
		&NewStructOps,
		"AnimNode_VrmVMC",
		sizeof(FAnimNode_VrmVMC),
		alignof(FAnimNode_VrmVMC),
		Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_VrmVMC()
	{
		if (!Z_Registration_Info_UScriptStruct_AnimNode_VrmVMC.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_VrmVMC.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AnimNode_VrmVMC.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_AnimNode_VrmVMC_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_AnimNode_VrmVMC_h_Statics::ScriptStructInfo[] = {
		{ FAnimNode_VrmVMC::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_VrmVMC_Statics::NewStructOps, TEXT("AnimNode_VrmVMC"), &Z_Registration_Info_UScriptStruct_AnimNode_VrmVMC, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_VrmVMC), 1072207576U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_AnimNode_VrmVMC_h_2567653900(TEXT("/Script/VRM4UCapture"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_AnimNode_VrmVMC_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_AnimNode_VrmVMC_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
