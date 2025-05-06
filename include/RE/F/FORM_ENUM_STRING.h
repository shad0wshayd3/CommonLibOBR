#pragma once

namespace RE
{
	enum class FormType;

	struct FORM_ENUM_STRING
	{
	public:
		[[nodiscard]] static std::span<FORM_ENUM_STRING, 70> GetFormEnumString()
		{
			static REL::Relocation<FORM_ENUM_STRING(*)[70]> formEnumString{ ID::FORM_ENUM_STRING::FormEnumString };
			return { *formEnumString };
		}

		// members
		FormType      formType;    // 00
		const char*   formString;  // 08
		std::uint32_t formCode;    // 10
	};
	static_assert(sizeof(FORM_ENUM_STRING) == 0x18);
}
