#pragma once

namespace RE
{
	class TESObjectCell;

	class TESChildCell
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESChildCell;

		// add
		virtual TESObjectCELL* GetSaveParentCell();  // 00
	};
	static_assert(sizeof(TESChildCell) == 0x08);
}
