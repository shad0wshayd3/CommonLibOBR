#pragma once

#include "UE/F/FNetworkNotify.h"
#include "UE/U/UObject.h"

namespace UE
{
	class UWorld :
		public UObject,
		public FNetworkNotify
	{
	public:
		// override
		virtual ~UWorld();  // 00

		// members
		std::byte unk30[0x8D0];  // 30
	};
	static_assert(sizeof(UWorld) == 0x900);
}
