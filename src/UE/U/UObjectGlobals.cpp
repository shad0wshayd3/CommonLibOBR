#include "UE/U/UObjectGlobals.h"

#include "UE/F/FRawObjectIterator.h"
#include "UE/U/UClass.h"

namespace UE
{
	UObject* FindObjectFast(FName a_name, EClassCastFlags a_type)
	{
		for (FRawObjectIterator it; it; ++it) {
			if (const auto object = it->object)
				if (object->classPrivate->HasAnyCastFlag(a_type) && object->GetFName() == a_name)
					return (UObject*)object;
		}

		return nullptr;
	}

	UObject* FindObject(FName a_name, EClassCastFlags a_type)
	{
		for (FRawObjectIterator it; it; ++it) {
			if (const auto object = (UObject*)it->object)
				if (object->classPrivate->HasAnyCastFlag(a_type) && object->GetFullName() == a_name.ToString())
					return (UObject*)object;
		}

		return nullptr;
	}
}
