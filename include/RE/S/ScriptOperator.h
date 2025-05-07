#pragma once

#include "RE/E/ExpressionOperators.h"

namespace RE
{
	struct SCRIPT_OPERATOR
	{
	public:
		EXPRESSION_OPERATORS code;          // 00
		std::uint8_t         precedence;    // 04
		std::uint8_t         _operator[3];  // 05
	};
	static_assert(sizeof(SCRIPT_OPERATOR) == 0x08);
}
