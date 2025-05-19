#pragma once

namespace RE
{
	class BSExtraData;

	class BaseExtraList
	{
	public:
		inline static constexpr auto RTTI = RTTI::BaseExtraList;
		inline static constexpr auto VTABLE = VTABLE::BaseExtraList;

		// add
		virtual ~BaseExtraList();  // 00

		// members
		BSExtraData* head;       // 08
		std::uint8_t flags[16];  // 10
	};
	static_assert(sizeof(BaseExtraList) == 0x20);
}
