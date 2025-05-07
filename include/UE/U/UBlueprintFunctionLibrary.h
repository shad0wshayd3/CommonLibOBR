#pragma once

#include "UE/U/UObject.h"

namespace UE
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
