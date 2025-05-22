#pragma once

#include "RE/M/Menu.h"

namespace RE
{
	class TESObjectREFR;
	class Tile;

	class HUDInfoMenu :
		public Menu
	{
	public:
		inline static constexpr auto RTTI = RTTI::HUDInfoMenu;
		inline static constexpr auto VTABLE = VTABLE::HUDInfoMenu;

		virtual ~HUDInfoMenu() override;  // 07

		// override (IVPairableItem)
		virtual void ProcessPairItem() override;    // 01
		virtual void ProcessUnpairItem() override;  // 02

		// override (Menu)
		virtual void         AttachTileByID(std::int32_t a_ID, Tile* a_tile) override;  // 08
		virtual void         DoIdle() override;                                         // 12
		virtual std::int32_t GetClass() override;                                       // 14
		virtual void         StartFadeOut() override;                                   // 16
		virtual void         StartFadeIn() override;                                    // 18

		// members
		Tile*          name;           // 50
		Tile*          value;          // 58
		Tile*          weight;         // 60
		Tile*          damage;         // 68
		Tile*          armor;          // 70
		Tile*          quality;        // 78
		Tile*          health;         // 80
		Tile*          uses;           // 88
		Tile*          dest;           // 90
		Tile*          lock;           // 98
		Tile*          actionHint;     // A0
		TESObjectREFR* lastObject;     // A8
		std::int32_t   updateCounter;  // B0
		bool           skipFadeIn;     // B4
	};
	static_assert(sizeof(HUDInfoMenu) == 0xB8);
}
