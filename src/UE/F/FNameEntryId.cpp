#include "UE/F/FNameEntryId.h"

#include "UE/F/FNamePool.h"

namespace UE
{
	FNameEntryId FNameEntryId::FromValidEName(EName a_name)
	{
		const auto pool = FNamePool::GetSingleton();
		return pool->Find(a_name);
	}
}
