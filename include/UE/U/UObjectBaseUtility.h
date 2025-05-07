#pragma once

#include "UE/U/UObjectBase.h"

namespace UE
{
	class UObjectBaseUtility :
		public UObjectBase
	{
	public:
		// override
		virtual ~UObjectBaseUtility();  // 00

		// add
		virtual bool CanBeClusterRoot() = 0;              // 04
		virtual bool CanBeInCluster() = 0;                // 05
		virtual void CreateCluster() = 0;                 // 06
		virtual void OnClusterMarkedAsPendingKill() = 0;  // 07
	};
	static_assert(sizeof(UObjectBaseUtility) == 0x28);
}
