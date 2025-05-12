#pragma once

#include "UE/T/TObjectPtr.h"
#include "UE/U/UClass.h"

namespace UE
{
	template <class T>
	class TSubclassOf
	{
	public:
		UClass* Get() const
		{
			if (!m_class || !m_class->IsChildOf<T>())
				return nullptr;

			return m_class;
		}

		UClass* operator*() const
		{
			return Get();
		}

		UClass* operator->() const
		{
			return Get();
		}

		operator UClass*() const
		{
			return Get();
		}

	private:
		// members
		TObjectPtr<UClass> m_class;  // 00
	};
	static_assert(sizeof(TSubclassOf<void*>) == 0x08);
}
