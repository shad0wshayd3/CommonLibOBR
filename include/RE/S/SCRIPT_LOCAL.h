#pragma once

namespace RE
{
	struct SCRIPT_LOCAL
	{
	public:
		// members
		std::uint32_t id;         // 00
		double        value;      // 08
		bool          isInteger;  // 10
	};
	static_assert(sizeof(SCRIPT_LOCAL) == 0x18);
}
