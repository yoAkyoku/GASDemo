// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VrmMocopiReceiver.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FStructMocopiData;
#ifdef VRM4UCAPTURE_VrmMocopiReceiver_generated_h
#error "VrmMocopiReceiver.generated.h already included, missing '#pragma once' in VrmMocopiReceiver.h"
#endif
#define VRM4UCAPTURE_VrmMocopiReceiver_generated_h

#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_35_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FStructMocopiData_Statics; \
	VRM4UCAPTURE_API static class UScriptStruct* StaticStruct();


template<> VRM4UCAPTURE_API UScriptStruct* StaticStruct<struct FStructMocopiData>();

#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_136_DELEGATE \
static void FVrmMocopiReceiverDelegate_DelegateWrapper(const FMulticastScriptDelegate& VrmMocopiReceiverDelegate, FStructMocopiData data);


#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_SPARSE_DATA
#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCurrentTime); \
	DECLARE_FUNCTION(execGetLatestFrameData); \
	DECLARE_FUNCTION(execGetNextFrameData); \
	DECLARE_FUNCTION(execSetBufferNum); \
	DECLARE_FUNCTION(execSetAddress); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execListen);


#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCurrentTime); \
	DECLARE_FUNCTION(execGetLatestFrameData); \
	DECLARE_FUNCTION(execGetNextFrameData); \
	DECLARE_FUNCTION(execSetBufferNum); \
	DECLARE_FUNCTION(execSetAddress); \
	DECLARE_FUNCTION(execStop); \
	DECLARE_FUNCTION(execListen);


#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_ACCESSORS
#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVrmMocopiReceiver(); \
	friend struct Z_Construct_UClass_UVrmMocopiReceiver_Statics; \
public: \
	DECLARE_CLASS(UVrmMocopiReceiver, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VRM4UCapture"), NO_API) \
	DECLARE_SERIALIZER(UVrmMocopiReceiver)


#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_INCLASS \
private: \
	static void StaticRegisterNativesUVrmMocopiReceiver(); \
	friend struct Z_Construct_UClass_UVrmMocopiReceiver_Statics; \
public: \
	DECLARE_CLASS(UVrmMocopiReceiver, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VRM4UCapture"), NO_API) \
	DECLARE_SERIALIZER(UVrmMocopiReceiver)


#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVrmMocopiReceiver(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVrmMocopiReceiver) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVrmMocopiReceiver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVrmMocopiReceiver); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVrmMocopiReceiver(UVrmMocopiReceiver&&); \
	NO_API UVrmMocopiReceiver(const UVrmMocopiReceiver&); \
public: \
	NO_API virtual ~UVrmMocopiReceiver();


#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVrmMocopiReceiver(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVrmMocopiReceiver(UVrmMocopiReceiver&&); \
	NO_API UVrmMocopiReceiver(const UVrmMocopiReceiver&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVrmMocopiReceiver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVrmMocopiReceiver); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVrmMocopiReceiver) \
	NO_API virtual ~UVrmMocopiReceiver();


#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_97_PROLOG
#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_SPARSE_DATA \
	FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_RPC_WRAPPERS \
	FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_ACCESSORS \
	FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_INCLASS \
	FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_SPARSE_DATA \
	FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_ACCESSORS \
	FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h_100_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class VrmMocopiReceiver."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VRM4UCAPTURE_API UClass* StaticClass<class UVrmMocopiReceiver>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_GASDemo_Plugins_VRM4U_Source_VRM4UCapture_Public_VrmMocopiReceiver_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
