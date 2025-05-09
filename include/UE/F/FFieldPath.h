#pragma once

#include "UE/T/TArray.h"
#include "UE/T/TWeakObjectPtr.h"

namespace UE
{
	class FField;
	class FName;
	class UStruct;

	class FFieldPath
	{
	public:
		// members
		mutable FField*                 resolvedField{ nullptr };
		mutable TWeakObjectPtr<UStruct> resolvedOwner;
		TArray<FName>                   path;
	};
	static_assert(sizeof(FFieldPath) == 0x20);
}
