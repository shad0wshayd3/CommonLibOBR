#pragma once

namespace RE
{
	template <typename T>
	class FR2MatrixVTC
	{
	public:
		// members
		std::uint32_t  rows;  // 00
		std::uint32_t  cols;  // 04
		std::vector<T> data;  // 08
	};
	static_assert(sizeof(FR2MatrixVTC<float>) == 0x20);
}
