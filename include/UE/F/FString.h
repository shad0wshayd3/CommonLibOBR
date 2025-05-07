#pragma once

#include "UE/T/TArray.h"

namespace UE
{
	class FString
	{
	public:
		// members
		TArray<wchar_t> data;  // 00
	};
	static_assert(sizeof(FString) == 0x10);
}
