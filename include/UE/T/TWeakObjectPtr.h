#pragma once

#include "UE/F/FWeakObjectPtr.h"

namespace UE
{
	class UObject;

	template <class T = UObject, class TB = FWeakObjectPtr>
	class TWeakObjectPtr :
		private TB
	{
		friend class FFieldPath;

	public:
		TWeakObjectPtr() = default;
	};
	static_assert(sizeof(TWeakObjectPtr<UObject>) == 0x08);
}
