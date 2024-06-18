// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VRM4UCapture/Public/VRM4U_VMCSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRM4U_VMCSubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UEngineSubsystem();
	UPackage* Z_Construct_UPackage__Script_VRM4UCapture();
	VRM4UCAPTURE_API UClass* Z_Construct_UClass_UVRM4U_VMCSubsystem();
	VRM4UCAPTURE_API UClass* Z_Construct_UClass_UVRM4U_VMCSubsystem_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVRM4U_VMCSubsystem::execDestroyVMCServer)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_ServerAddress);
		P_GET_PROPERTY(FIntProperty,Z_Param_port);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DestroyVMCServer(Z_Param_ServerAddress,Z_Param_port);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVRM4U_VMCSubsystem::execCreateVMCServer)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_ServerAddress);
		P_GET_PROPERTY(FIntProperty,Z_Param_port);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CreateVMCServer(Z_Param_ServerAddress,Z_Param_port);
		P_NATIVE_END;
	}
	void UVRM4U_VMCSubsystem::StaticRegisterNativesUVRM4U_VMCSubsystem()
	{
		UClass* Class = UVRM4U_VMCSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateVMCServer", &UVRM4U_VMCSubsystem::execCreateVMCServer },
			{ "DestroyVMCServer", &UVRM4U_VMCSubsystem::execDestroyVMCServer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics
	{
		struct VRM4U_VMCSubsystem_eventCreateVMCServer_Parms
		{
			FString ServerAddress;
			int32 port;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ServerAddress_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ServerAddress;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_port;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_ServerAddress_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_ServerAddress = { "ServerAddress", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(VRM4U_VMCSubsystem_eventCreateVMCServer_Parms, ServerAddress), METADATA_PARAMS(Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_ServerAddress_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_ServerAddress_MetaData)) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_port = { "port", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(VRM4U_VMCSubsystem_eventCreateVMCServer_Parms, port), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VRM4U_VMCSubsystem_eventCreateVMCServer_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(VRM4U_VMCSubsystem_eventCreateVMCServer_Parms), &Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_ServerAddress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_port,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::Function_MetaDataParams[] = {
		{ "Category", "VRM4U" },
		{ "ModuleRelativePath", "Public/VRM4U_VMCSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRM4U_VMCSubsystem, nullptr, "CreateVMCServer", nullptr, nullptr, sizeof(Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::VRM4U_VMCSubsystem_eventCreateVMCServer_Parms), Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics
	{
		struct VRM4U_VMCSubsystem_eventDestroyVMCServer_Parms
		{
			FString ServerAddress;
			int32 port;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ServerAddress_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ServerAddress;
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_port;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::NewProp_ServerAddress_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::NewProp_ServerAddress = { "ServerAddress", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(VRM4U_VMCSubsystem_eventDestroyVMCServer_Parms, ServerAddress), METADATA_PARAMS(Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::NewProp_ServerAddress_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::NewProp_ServerAddress_MetaData)) };
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::NewProp_port = { "port", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(VRM4U_VMCSubsystem_eventDestroyVMCServer_Parms, port), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::NewProp_ServerAddress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::NewProp_port,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::Function_MetaDataParams[] = {
		{ "Category", "VRM4U" },
		{ "ModuleRelativePath", "Public/VRM4U_VMCSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRM4U_VMCSubsystem, nullptr, "DestroyVMCServer", nullptr, nullptr, sizeof(Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::VRM4U_VMCSubsystem_eventDestroyVMCServer_Parms), Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVRM4U_VMCSubsystem);
	UClass* Z_Construct_UClass_UVRM4U_VMCSubsystem_NoRegister()
	{
		return UVRM4U_VMCSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UVRM4U_VMCSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVRM4U_VMCSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEngineSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VRM4UCapture,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UVRM4U_VMCSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVRM4U_VMCSubsystem_CreateVMCServer, "CreateVMCServer" }, // 3915269440
		{ &Z_Construct_UFunction_UVRM4U_VMCSubsystem_DestroyVMCServer, "DestroyVMCServer" }, // 1530636342
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVRM4U_VMCSubsystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "VRM4U_VMCSubsystem.h" },
		{ "ModuleRelativePath", "Public/VRM4U_VMCSubsystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVRM4U_VMCSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVRM4U_VMCSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVRM4U_VMCSubsystem_Statics::ClassParams = {
		&UVRM4U_VMCSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UVRM4U_VMCSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UVRM4U_VMCSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVRM4U_VMCSubsystem()
	{
		if (!Z_Registration_Info_UClass_UVRM4U_VMCSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVRM4U_VMCSubsystem.OuterSingleton, Z_Construct_UClass_UVRM4U_VMCSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVRM4U_VMCSubsystem.OuterSingleton;
	}
	template<> VRM4UCAPTURE_API UClass* StaticClass<UVRM4U_VMCSubsystem>()
	{
		return UVRM4U_VMCSubsystem::StaticClass();
	}
	UVRM4U_VMCSubsystem::UVRM4U_VMCSubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVRM4U_VMCSubsystem);
	UVRM4U_VMCSubsystem::~UVRM4U_VMCSubsystem() {}
	struct Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VRM4U_VMCSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VRM4U_VMCSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVRM4U_VMCSubsystem, UVRM4U_VMCSubsystem::StaticClass, TEXT("UVRM4U_VMCSubsystem"), &Z_Registration_Info_UClass_UVRM4U_VMCSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVRM4U_VMCSubsystem), 1773227458U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VRM4U_VMCSubsystem_h_2331991610(TEXT("/Script/VRM4UCapture"),
		Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VRM4U_VMCSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VRM4U_VMCSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
