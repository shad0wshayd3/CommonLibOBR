#pragma once

#include "RE/U/UObject.h"

namespace RE::UE
{
	class UBlueprintFunctionLibrary :
		public UObject
	{
	public:
		// override
		virtual ~UBlueprintFunctionLibrary();  // 00
	};
	static_assert(sizeof(UBlueprintFunctionLibrary) == 0x28);
}
