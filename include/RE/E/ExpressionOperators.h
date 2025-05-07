#pragma once

namespace RE
{
	enum class EXPRESSION_OPERATORS : std::int32_t
	{
		kLeftParen,
		kRightParen,
		kAnd,
		kOr,
		kLessEqual,
		kLess,
		kGreaterEqual,
		kGreater,
		kEqual,
		kNotEqual,
		kSubtract,
		kAdd,
		kMultiply,
		kDivide,
		kModulus,
		kUnaryMinus,
	};
}
