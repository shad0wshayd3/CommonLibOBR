#pragma once

#include "UE/E/EInternalObjectFlags.h"
#include "UE/E/EObjectFlags.h"
#include "UE/F/FName.h"
#include "UE/T/TFunction.h"

namespace UE
{
	class FObjectInstancingGraph;
	class UClass;
	class UObject;
	class UPackage;

	inline UPackage* GetTransientPackage();

	class FStaticConstructObjectParameters
	{
	public:
		FStaticConstructObjectParameters(const UClass* a_class) :
			cls(a_class)
		{}

		// members
		const UClass*           cls;
		UObject*                outer{ (UObject*)GetTransientPackage() };
		FName                   name;
		EObjectFlags            setFlags{ EObjectFlags::NoFlags };
		EInternalObjectFlags    internalSetFlags{ EInternalObjectFlags::None };
		bool                    copyTransientsFromClassDefaults{ false };
		bool                    assumeTemplateIsArchetype{ false };
		UObject*                objectTemplate{ nullptr };
		FObjectInstancingGraph* instanceGraph{ nullptr };
		UPackage*               externalPackage{ nullptr };
		TFunction<void()>       propertyInitCallback;
		void*                   subobjectOverrides{ nullptr };
	};
	static_assert(sizeof(FStaticConstructObjectParameters) == 0x90);
}
