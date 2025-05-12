#pragma once

#include "UE/F/FSoftObjectPath.h"
#include "UE/T/TPersistentObjectPtr.h"

namespace UE
{
	class FSoftObjectPtr :
		public TPersistentObjectPtr<FSoftObjectPath>
	{
	public:

	};
	static_assert(sizeof(FSoftObjectPtr) == 0x28);
}
