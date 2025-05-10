#pragma once

namespace RE
{
	class TESMemContextForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESMemContextForm;
	};
	static_assert(std::is_empty_v<TESMemContextForm>);
}
