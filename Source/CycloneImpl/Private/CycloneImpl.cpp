// Copyright Epic Games, Inc. All Rights Reserved.

#include "CycloneImpl.h"

#define LOCTEXT_NAMESPACE "FCycloneImplModule"

void FCycloneImplModule::StartupModule()
{

};

void FCycloneImplModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCycloneImplModule, CycloneImpl)