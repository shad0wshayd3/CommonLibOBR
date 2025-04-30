#pragma once

namespace RE::ID
{
	namespace GameSettingCollection
	{
		inline constexpr REL::Offset Singleton{ 0x8FE1E10 };
	}

	namespace Setting
	{
		inline constexpr REL::Offset SetString{ 0x6710B70 };
	}

	inline constexpr REL::Offset malloc{ 0x472FD40 };
	inline constexpr REL::Offset free{ 0x0E30580 };

	inline constexpr REL::Offset RTDynamicCast{ 0x6C23656 };
}
