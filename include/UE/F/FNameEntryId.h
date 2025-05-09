#pragma once

namespace UE
{
	class FNameEntryId
	{
	public:
		FNameEntryId() = default;

		std::uint32_t ToUnstableInt() const
		{
			return value;
		}

		static FNameEntryId FromUnstableInt(const std::uint32_t a_value)
		{
			FNameEntryId id;
			id.value = a_value;
			return id;
		}

		// members
		std::uint32_t value{ 0 };  // 00
	};
	static_assert(sizeof(FNameEntryId) == 0x04);
}
