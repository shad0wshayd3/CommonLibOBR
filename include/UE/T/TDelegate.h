#pragma once

#include "UE/F/FDefaultDelegateUserPolicy.h"

namespace UE
{
	template <class T, class P = FDefaultDelegateUserPolicy>
	class TDelegate
	{
		static_assert(sizeof(P) == 0);
	};

	template <class R, class... Args, class P>
	class TDelegate<R(Args...), P> :
		public P::FDelegateExtras
	{
	public:

	};
}
