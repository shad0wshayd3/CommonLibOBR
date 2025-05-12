#pragma once

#include "UE/E/EObjectFlags.h"
#include "UE/F/FName.h"
#include "UE/T/TEnumAsByte.h"
#include "UE/T/TIndirectArray.h"

namespace UE
{
	class FBlueprintComponentChangedPropertyInfo;
	class FCustomPropertyListNode;
	class UClass;

	class FBlueprintCookedComponentInstancingData
	{
	public:
		// members
		TArray<FBlueprintComponentChangedPropertyInfo> changedPropertyList;                 // 00
		FName                                          componentTemplateName;               // 10
		UClass*                                        componentTemplateClass;              // 18
		TEnumAsByte<EObjectFlags>                      componentTemplateFlags;              // 20
		bool                                           hasValidCookedData;                  // 21
		TIndirectArray<FCustomPropertyListNode>        cachedPropertyListForSerialization;  // 28
		TArray<std::uint8_t>                           cachedPropertyData;                  // 38
	};
	static_assert(sizeof(FBlueprintCookedComponentInstancingData) == 0x48);
}
