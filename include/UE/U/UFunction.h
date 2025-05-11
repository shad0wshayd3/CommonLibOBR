#pragma once

#include "UE/E/EFunctionFlags.h"
#include "UE/U/UInterface.h"
#include "UE/U/UStruct.h"

namespace UE
{
	using FNativeFuncPtr = void (*)(UObject*, FFrame&, const void*);

	class UFunction :
		public UStruct
	{
	public:
		UE_DEFINE_OBJECT("/Script/CoreUObject", "Function");

		// override
		virtual ~UFunction();

		// members
		EFunctionFlags functionFlags;
		std::uint8_t   numParms;
		std::uint16_t  parmsSize;
		std::uint16_t  returnValueOffset;
		std::uint16_t  rpcId;
		std::uint16_t  rpcResponseId;
		FProperty*     firstPropertyToInit;
		UFunction*     eventGraphFunction;
		std::int32_t   eventGraphCallOffset;
		FNativeFuncPtr func;
	};
	static_assert(sizeof(UFunction) == 0xE0);
}
