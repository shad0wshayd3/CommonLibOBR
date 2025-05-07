#pragma once

#include "UE/T/TIntegerSequence.h"

namespace UE
{
	namespace CoPrivate::Tuple
	{
		template <class T, std::size_t N, std::size_t O>
		class TTupleBaseElement
		{
		public:
			// members
			T value;  // 00
		};
		static_assert(sizeof(TTupleBaseElement<void*, 0, 2>) == 0x08);

		template <class V, class T, class U>
		class TTupleBase :
			public TTupleBaseElement<T, 0, 2>,
			public TTupleBaseElement<U, 1, 2>
		{
		public:
		};
		static_assert(sizeof(TTupleBase<void*, void*, void*>) == 0x10);
	}

	template <class T, class U>
	class TTuple :
		public CoPrivate::Tuple::TTupleBase<TIntegerSequence<std::uint32_t, 0, 1>, T, U>
	{
	public:
	};
	static_assert(sizeof(TTuple<void*, void*>) == 0x10);
}
