#pragma once

#include "UE/F/FDelegateHandle.h"

namespace UE
{
	class UObject;

	class IDelegateInstance
	{
	public:
		// add
		virtual ~IDelegateInstance() = default;  // 00

		// add
		virtual UObject*        GetUObject() const = 0;                             // 01
		virtual const void*     GetObjectForTimerManager() const = 0;               // 02
		virtual std::uint64_t   GetBoundProgramCounterForTimerManager() const = 0;  // 03
		virtual bool            HasSameObject(const void* InUserObject) const = 0;  // 04
		virtual bool            IsCompactable() const;                              // 05
		virtual bool            IsSafeToExecute() const = 0;                        // 06
		virtual FDelegateHandle GetHandle() const = 0;                              // 07
	};
	static_assert(sizeof(IDelegateInstance) == 0x8);
}
