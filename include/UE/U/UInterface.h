#pragma once

#include "UE/U/UObject.h"

namespace UE
{
	class UInterface :
		public UObject
	{
	public:
		UE_DEFINE_OBJECT("/Script/CoreUObject", "Interface");
	};
}
