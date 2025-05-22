#pragma once

#include "UE/F/FName.h"

namespace UE::FieldNotification
{
	class FFieldId
	{
	public:
		// members
		FName        fieldName;  // 00
		std::int32_t bitNumber;  // 08
	};
	static_assert(sizeof(FFieldId) == 0x0C);
}
