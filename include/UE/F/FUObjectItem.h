#pragma once

#include "UE/E/EInternalObjectFlags.h"

namespace UE
{
	class UObjectBase;

	class FUObjectItem
	{
	public:
		EInternalObjectFlags GetFlags() const
		{
			return EInternalObjectFlags(GetFlagsInternal());
		}

		std::int32_t GetFlagsInternal() const
		{
			return flags;
		}

		bool HasAnyFlags(EInternalObjectFlags a_flags) const
		{
			return !!(GetFlagsInternal() & std::int32_t(a_flags));
		}

		// members
		UObjectBase* object;            // 00
		std::int32_t flags;             // 08
		std::int32_t clusterRootIndex;  // 0C
		std::int32_t serialNumber;      // 10
	};
	static_assert(sizeof(FUObjectItem) == 0x18);
}
