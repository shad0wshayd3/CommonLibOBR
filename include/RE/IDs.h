#pragma once

namespace RE::ID
{
	namespace FORM_ENUM_STRING
	{
		inline constexpr REL::Offset FormEnumString{ 0x8FDD6A0 };
	}

	namespace GameSettingCollection
	{
		inline constexpr REL::Offset Singleton{ 0x8FE1E10 };
	}

	namespace MenuConsole
	{
		inline constexpr REL::Offset Instance{ 0x665C360 };
		inline constexpr REL::Offset PrintLine{ 0x665C580 };
	}

	namespace Setting
	{
		inline constexpr REL::Offset SetString{ 0x6710B70 };
	}

	namespace TESForm
	{
		inline constexpr REL::Offset AllForms{ 0x8FDDD30 };
		inline constexpr REL::Offset AllFormsByEditorID{ 0x8FDDD70 };
	}

	inline constexpr REL::Offset malloc{ 0x472FD40 };
	inline constexpr REL::Offset free{ 0x0E30580 };

	inline constexpr REL::Offset RTDynamicCast{ 0x6C23656 };
}
