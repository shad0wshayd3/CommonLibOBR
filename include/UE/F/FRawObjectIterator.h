#pragma once

#include "UE/F/FUObjectArray.h"

namespace UE
{
	class FRawObjectIterator :
		public FUObjectArray::TIterator
	{
	public:
		FRawObjectIterator(bool a_onlyGCedObjects = false) :
			FUObjectArray::TIterator(*FUObjectArray::GetSingleton(), a_onlyGCedObjects)
		{}

		FUObjectItem* operator*() const
		{
			return GetObject();
		}

		FUObjectItem* operator->() const
		{
			return GetObject();
		}
	};
}
