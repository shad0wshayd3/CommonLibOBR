#pragma once

#include "RE/T/TArray.h"

namespace RE::UE
{
	class FString
	{
	public:
		// members
		TArray<wchar_t> data;  // 00
	};
	static_assert(sizeof(FString) == 0x10);
}
