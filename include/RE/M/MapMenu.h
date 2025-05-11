#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BSTList.h"
#include "RE/M/Menu.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class TESObjectREFR;
	class TESQuest;
	class TESQuestTarget;
	class TESWorldSpace;
	class Tile;

	class MapMenu :
		public Menu
	{
	public:
		inline static constexpr auto RTTI = RTTI::MapMenu;
		inline static constexpr auto VTABLE = VTABLE::MapMenu;

		virtual ~MapMenu() override;  // 07

		// override (IVPairableItem)
		virtual void ProcessPairItem() override;    // 01
		virtual void ProcessUnpairItem() override;  // 02

		// override (Menu)
		virtual void         AttachTileByID(std::int32_t a_ID, Tile* a_tile) override;    // 08
		virtual void         DoDownClick(std::int32_t a_ID, Tile* a_target) override;     // 09
		virtual void         DoClick(std::int32_t a_ID, Tile* a_target) override;         // 0A
		virtual void         DoEnter(std::int32_t a_ID, Tile* a_target) override;         // 0B
		virtual void         DoLeave(std::int32_t a_ID, Tile* a_target) override;         // 0C
		virtual void         DoStillDown(std::int32_t a_ID, Tile* a_target) override;     // 0F
		virtual void         DoWheelMove(std::int32_t a_ID, Tile* a_target) override;     // 11
		virtual void         DoIdle() override;                                           // 12
		virtual std::int32_t GetClass() override;                                         // 14
		virtual bool         DoGamepad(GAMEPAD_BUTTON a_button, float a_value) override;  // 15
		virtual void         StartFadeOut() override;                                     // 16
		virtual void         StartFadeIn() override;                                      // 18

		// members
		Tile*                          background;                 // 050
		Tile*                          localTab;                   // 058
		Tile*                          worldTab;                   // 060
		Tile*                          activeTab;                  // 068
		Tile*                          logTab;                     // 070
		Tile*                          completeTab;                // 078
		Tile*                          scrollBar;                  // 080
		Tile*                          scrollMarker;               // 088
		Tile*                          itemList;                   // 090
		Tile*                          focus;                      // 098
		Tile*                          mapIt;                      // 0A0
		Tile*                          back;                       // 0A8
		Tile*                          worldMap;                   // 0B0
		Tile*                          worldFocus;                 // 0B8
		Tile*                          localLayout;                // 0C0
		Tile*                          localMap;                   // 0C8
		Tile*                          localIcons;                 // 0D0
		Tile*                          worldMapCursor;             // 0D8
		Tile*                          localMapCursor;             // 0E0
		Tile*                          worldMapWindow;             // 0E8
		Tile*                          lastFocus;                  // 0F0
		bool                           completed;                  // 0F8
		TESQuest*                      activeQuest;                // 100
		char                           delayFocusHide;             // 108
		float                          mouseDownX;                 // 10C
		float                          mouseDownY;                 // 110
		std::uint32_t                  localMapWidth;              // 114
		std::uint32_t                  localMapHeight;             // 118
		std::uint32_t                  worldMapWidth;              // 11C
		std::uint32_t                  worldMapHeight;             // 120
		std::int32_t                   worldMapXMin;               // 124
		std::int32_t                   worldMapXMax;               // 128
		std::int32_t                   worldMapYMin;               // 12C
		std::int32_t                   worldMapYMax;               // 130
		BSString                       travelTargetName;           // 138
		NiPoint3                       travelTargetPos;            // 148
		BSSimpleList<TESObjectREFR*>*  mapMarkerList;              // 158
		BSSimpleList<TESObjectREFR*>*  teleportDoorList;           // 160
		BSSimpleList<TESQuestTarget*>* questList;                  // 168
		TESWorldSpace*                 worldSpace;                 // 170
		float                          markerX;                    // 178
		float                          markerY;                    // 17C
		bool                           isLocalMarker;              // 180
		Tile*                          worldMapMarker;             // 188
		float                          worldMapStartX;             // 190
		float                          worldMapStartY;             // 194
		float                          localMapStartX;             // 198
		float                          localMapStartY;             // 19C
		Tile*                          lastWorldFocus;             // 1A0
		Tile*                          worldMapPlayerArrow;        // 1A8
		Tile*                          localMapPlayerArrow;        // 1B0
		bool                           isVisible;                  // 1B8
		bool                           isInsideFastTravelProcess;  // 1B9
	};
	static_assert(sizeof(MapMenu) == 0x1C0);

}
