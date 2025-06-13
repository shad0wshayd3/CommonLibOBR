#pragma once

#include "UE/F/FVector.h"

namespace UE
{
	class FVPawnKnockdownRequest
	{
	public:
		// members
		float   force;        // 000
		FVector knockVector;  // 008
		bool    isExplosion;  // 020
	};
	static_assert(sizeof(FVPawnKnockdownRequest) == 0x28);
}
