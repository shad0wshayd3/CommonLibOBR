#pragma once

#include "UE/F/FName.h"
#include "UE/T/TSharedPtr.h"

namespace UE
{
	class FKeyDetails;

	class FKey
	{
	public:
		FKey() = default;

		FKey(const FName a_name) :
			m_name(a_name)
		{}

	private:
		FName                           m_name;     // 000
		mutable TSharedPtr<FKeyDetails> m_details;  // 008
	};
	static_assert(sizeof(FKey) == 0x18);
}
