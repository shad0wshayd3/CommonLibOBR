#pragma once

namespace UE
{
	template <std::int32_t N>
	struct TBitsToSizeType
	{
		static_assert(N, "Unsupported allocator index size");
	};

	template <>
	struct TBitsToSizeType<8>
	{
		using Type = std::int8_t;
	};

	template <>
	struct TBitsToSizeType<16>
	{
		using Type = std::int16_t;
	};

	template <>
	struct TBitsToSizeType<32>
	{
		using Type = std::int32_t;
	};

	template <>
	struct TBitsToSizeType<64>
	{
		using Type = std::int64_t;
	};
}
