#pragma once

namespace UE
{
	template <class T>
	class TRefCountPtr
	{
	public:
		TRefCountPtr(T* a_ptr, bool a_addRef = true) :
			ptr(a_ptr)
		{
			if (ptr && a_addRef)
				ptr->AddRef();
		}

		TRefCountPtr(const TRefCountPtr& a_other) :
			ptr(a_other.ptr)
		{
			if (ptr)
				ptr->AddRef();
		}

		TRefCountPtr(TRefCountPtr&& a_other) :
			ptr(a_other.ptr)
		{
			a_other.ptr = nullptr;
		}

		~TRefCountPtr()
		{
			if (ptr)
				ptr->Release();
		}

		T* operator->() const
		{
			return ptr;
		}

		// members
		T* ptr{ nullptr };  // 00
	};
	static_assert(sizeof(TRefCountPtr<void>) == 0x08);
}
