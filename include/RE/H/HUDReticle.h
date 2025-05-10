#pragma once

#include "RE/M/Menu.h"

namespace RE
{
	class HUDReticle :
		public Menu
	{
	public:
		inline static constexpr auto RTTI = RTTI::HUDReticle;
		inline static constexpr auto VTABLE = VTABLE::HUDReticle;

		virtual ~HUDReticle() override;  // 07

		// override (Menu)
		virtual void         AttachTileByID(std::int32_t a_ID, Tile* a_tile) override;  // 08
		virtual std::int32_t GetClass() override;                                       // 14
	};
	static_assert(sizeof(HUDReticle) == 0x50);
}
