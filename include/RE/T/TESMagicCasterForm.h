#pragma once

namespace RE
{
	class TESMagicCasterForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESMagicCasterForm;
	};
	static_assert(std::is_empty_v<TESMagicCasterForm>);
}
