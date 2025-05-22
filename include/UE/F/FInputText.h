#pragma once

#include "UE/F/FText.h"

namespace UE
{
	class FInputText
	{
	public:
		// members
		FText controllerText;  // 00
		FText keyboardText;    // 18
	};
	static_assert(sizeof(FInputText) == 0x30);
}
