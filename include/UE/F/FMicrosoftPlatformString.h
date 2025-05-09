#pragma once

#include "UE/F/FGenericPlatformString.h"

namespace UE
{
	struct FMicrosoftPlatformString :
		public FGenericPlatformString
	{
		static std::int32_t Strlen(const wchar_t* a_str)
		{
			return wcslen(a_str);
		}

		static std::int32_t Strnlen(const wchar_t* a_str, std::size_t a_size)
		{
			return wcsnlen(a_str, a_size);
		}
	};
}
