#pragma once

#include "RE/T/TESTexture.h"

namespace RE
{
	class TESIcon :
		public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESIcon;
		inline static constexpr auto VTABLE = VTABLE::TESIcon;

		// override (TESTexture)
		virtual ~TESIcon() override;              // 04
		virtual char* GetDefaultPath() override;  // 06
	};
	static_assert(sizeof(TESIcon) == 0x18);
}
