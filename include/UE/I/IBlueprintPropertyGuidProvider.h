#pragma once

#include "UE/F/FGuid.h"
#include "UE/F/FName.h"

namespace UE
{
	class IBlueprintPropertyGuidProvider
	{
	public:
		virtual ~IBlueprintPropertyGuidProvider() = default;  // 00

		virtual FName FindBlueprintPropertyNameFromGuid(const FGuid& a_guid) const = 0;  // 01
		virtual FGuid FindBlueprintPropertyGuidFromName(const FName a_name) const = 0;   // 02
	};
}
