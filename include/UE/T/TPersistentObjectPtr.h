#pragma once

#include "UE/F/FWeakObjectPtr.h"
#include "UE/U/UObject.h"

namespace UE
{
	template <class T>
	class TPersistentObjectPtr
	{
	public:
		// members
		mutable FWeakObjectPtr weakPtr;   // 00
		T                      objectID;  // 08
	};
}
