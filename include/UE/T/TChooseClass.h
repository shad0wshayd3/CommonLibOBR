#pragma once

namespace UE
{
	template <bool Predicate, class True, class False>
	class TChooseClass;

	template <class True, class FalseClass>
	class TChooseClass<true, True, FalseClass>
	{
	public:
		using Result = True;
	};

	template <class True, class False>
	class TChooseClass<false, True, False>
	{
	public:
		using Result = False;
	};
}
