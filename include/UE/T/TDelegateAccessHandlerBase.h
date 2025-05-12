#pragma once

#include "UE/F/FScopeLock.h"

namespace UE
{
	struct FNotThreadSafeNotCheckedDelegateMode;
	struct FThreadSafeDelegateMode;
	struct FNotThreadSafeDelegateMode;

	template <class ThreadSafetyMode>
	class TDelegateAccessHandlerBase;

	template <>
	class TDelegateAccessHandlerBase<FNotThreadSafeNotCheckedDelegateMode>
	{
	protected:
		struct FReadAccessScope
		{};

		struct FWriteAccessScope
		{};

		[[nodiscard]] FReadAccessScope GetReadAccessScope() const
		{
			return {};
		}

		[[nodiscard]] FWriteAccessScope GetWriteAccessScope()
		{
			return {};
		}
	};

	template <>
	class TDelegateAccessHandlerBase<FThreadSafeDelegateMode>
	{
	protected:
		struct FReadAccessScope
		{
			FScopeLock lock;
		};

		struct FWriteAccessScope
		{
			FScopeLock lock;
		};

		[[nodiscard]] FReadAccessScope GetReadAccessScope() const
		{
			return { &mutex };
		}

		[[nodiscard]] FWriteAccessScope GetWriteAccessScope()
		{
			return { &mutex };
		}

	private:
		mutable FCriticalSection mutex;
	};

	template <>
	class TDelegateAccessHandlerBase<FNotThreadSafeDelegateMode> :
		public TDelegateAccessHandlerBase<FNotThreadSafeNotCheckedDelegateMode>
	{};
}
