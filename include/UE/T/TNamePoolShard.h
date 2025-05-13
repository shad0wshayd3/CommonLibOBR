#pragma once

#include "UE/E/ENameCase.h"
#include "UE/F/FNamePoolShardBase.h"

namespace UE
{
	template <ENameCase E>
	class TNamePoolShard :
		public FNamePoolShardBase
	{
	public:

	};
	static_assert(sizeof(TNamePoolShard<ENameCase::IgnoreCase>) == 0x40);
}
