#pragma once

#include "RE/I/Interface.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class Actor;
	class Menu;
	class NiAlphaProperty;
	class NiDirectionalLight;
	class NiNode;
	class SceneGraph;
	class ShadowSceneNode;
	class TESObjectREFR;
	class Tile;
	class TileImage;
	class ViewCaster;

	class InterfaceManager
	{
	public:
		using Result_t = void (*)();

		class Timer
		{
		public:
			// members
			void*  index;    // 00
			float  elapsed;  // 08
			float  end;      // 0C
			Timer* prev;     // 10
			Timer* next;     // 18
		};
		static_assert(sizeof(Timer) == 0x20);

		static InterfaceManager* GetInstance(bool a_create, bool a_initialLoad)
		{
			using func_t = decltype(&InterfaceManager::GetInstance);
			static REL::Relocation<func_t> func{ ID::InterfaceManager::GetInstance };
			return func(a_create, a_initialLoad);
		}

		// members
		NiPointer<SceneGraph>         sceneGraph;                // 000
		NiPointer<SceneGraph>         _3DSceneGraph;             // 008
		std::uint8_t                  menuMode;                  // 010
		std::uint8_t                  lastMenuMode;              // 011
		std::uint32_t                 lastEnterStackTop;         // 014
		bool                          lockMenuModeForFade;       // 018
		std::uint8_t                  statsPageNumber;           // 019
		std::uint8_t                  inventoryPageNumber;       // 01A
		std::uint8_t                  magicPageNumber;           // 01B
		std::uint8_t                  mapPageNumber;             // 01C
		std::int32_t                  pickDistance;              // 020
		std::int32_t                  telekinesisDistance;       // 024
		NiDirectionalLight*           playerLight;               // 028
		TileImage*                    cursor;                    // 030
		NiPoint3                      cursorPos;                 // 038
		NiPoint3                      realCursorPos;             // 044
		float                         mouseWheel;                // 050
		float                         mouseHeldTime;             // 054
		std::int32_t                  cursorOffsetX;             // 058
		std::int32_t                  cursorOffsetY;             // 05C
		std::int32_t                  targetID;                  // 060
		Tile*                         target;                    // 068
		bool                          debugTextVisible;          // 070
		NiNode*                       interfaceRoot;             // 078
		NiNode*                       cursorRoot;                // 080
		ShadowSceneNode*              playerRoot;                // 088
		NiNode*                       player3D;                  // 090
		ShadowSceneNode*              shadowNode;                // 098
		Tile*                         menusRoot;                 // 0A0
		Tile*                         stringRoot;                // 0A8
		NiNode*                       debugTextRoot;             // 0B0
		float                         oneToOneDistance;          // 0B8
		NiPointer<NiAlphaProperty>    alphaProp;                 // 0C0
		bool                          needToUpdate;              // 0C8
		std::uint16_t                 charHit;                   // 0CA
		Tile*                         targetReticle;             // 0D0
		Tile*                         safeZone;                  // 0D8
		Tile*                         mouseOverTarget;           // 0E0
		std::uint32_t                 lastXDefault;              // 0E8
		std::int32_t                  dragDroppingState;         // 0EC
		bool                          firstChanceLoad;           // 0F0
		Tile*                         overTileTarget;            // 0F8
		Menu*                         overTileMenu;              // 100
		Tile*                         dragOverTileTarget;        // 108
		Menu*                         dragOverTileMenu;          // 110
		bool                          fullHelp;                  // 118
		Menu*                         topMenu;                   // 120
		std::uint8_t                  lastMessageButtonClicked;  // 128
		Result_t*                     result;                    // 130
		bool                          textureRelease;            // 138
		bool                          mouseInMotion;             // 139
		TESObjectREFR*                pickRef;                   // 140
		TESObjectREFR*                reticleRef;                // 148
		TESObjectREFR*                crosshairRef;              // 150
		TESObjectREFR*                activateRef;               // 158
		TESObjectREFR*                telekinesisRef;            // 160
		NiPoint3                      activatePickLocation;      // 168
		bool                          fuzzyActivatePick;         // 174
		std::int32_t                  enterStack[10];            // 178
		ViewCaster*                   viewCaster;                // 1A0
		Actor*                        jailSpeaker;               // 1A8
		Actor*                        payFineSpeaker;            // 1B0
		bool                          shiftDown;                 // 1B8
		std::int32_t                  modifierKeys;              // 1BC
		std::int32_t                  repeatingKey;              // 1C0
		std::uint32_t                 keyDownTime;               // 1C4
		std::uint32_t                 keyRepeatStartTime;        // 1C8
		Interface::enumGamepadButtons lastGamepadEvent;          // 1CC
		std::uint32_t                 gamepadRepeatStartTime;    // 1D0
		Timer*                        pTimers;                   // 1D8
	};
	static_assert(sizeof(InterfaceManager) == 0x1E0);
}
