#include "UE/U/UObjectGlobals.h"

#include "UE/F/FRawObjectIterator.h"
#include "UE/U/UClass.h"

namespace UE
{
	UObject* FindObjectFast(FString a_name, EClassCastFlags a_type)
	{
		for (FRawObjectIterator it; it; ++it) {
			if (const auto object = it->object)
				if (object->classPrivate->HasAnyCastFlag(a_type) && object->GetFName().ToString() == a_name)
					return (UObject*)object;
		}

		return nullptr;
	}

	UObject* FindObject(FString a_name, EClassCastFlags a_type)
	{
		for (FRawObjectIterator it; it; ++it) {
			if (const auto object = (UObject*)it->object)
				if (object->classPrivate->HasAnyCastFlag(a_type) && object->GetFullName() == a_name)
					return (UObject*)object;
		}

		return nullptr;
	}
}
