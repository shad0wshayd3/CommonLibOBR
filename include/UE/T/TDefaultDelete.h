#pragma once

namespace UE
{
	template <class T>
	class TDefaultDelete
	{
	public:
		TDefaultDelete() = default;

		void operator()(T* a_ptr) const
		{
			delete a_ptr;
		}
	};

	template <class T>
	class TDefaultDelete<T[]>
	{
	public:
		TDefaultDelete() = default;

		void operator()(T* a_ptr) const
		{
			delete[] a_ptr;
		}
	};
}
