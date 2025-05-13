#pragma once

#include "UE/T/TAlignedBytes.h"

namespace UE::Core::Private::Function
{
	class FFunctionStorage
	{
	public:
		FFunctionStorage() = default;

		// members
		void*                 heapAllocation{ nullptr };
		TAlignedBytes<32, 16> inlineAllocation;
	};
	static_assert(sizeof(FFunctionStorage) == 0x030);

	template <bool U>
	class TFunctionStorage :
		public FFunctionStorage
	{
	public:
		TFunctionStorage() = default;
	};

	template <class S, typename F>
	class TFunctionRefBase;

	template <class S, class R, class... Args>
	class TFunctionRefBase<S, R(Args...)>
	{
	public:
		TFunctionRefBase() = default;

		// members
		R (*callable)
		(void*, Args&...){ nullptr };
		S storage;
	};
}

namespace UE
{
	template <class T>
	class TFunction :
		public Core::Private::Function::TFunctionRefBase<Core::Private::Function::TFunctionStorage<false>, T>
	{
	public:
		TFunction() = default;
	};
}
