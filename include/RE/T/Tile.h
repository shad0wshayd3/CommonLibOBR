#pragma once

#include "RE/B/BSStringT.h"
#include "RE/M/MENU_CLASS.h"
#include "RE/N/NiTList.h"

namespace RE
{
	class Menu;
	class NiNode;

	class Tile
	{
	public:
		inline static constexpr auto RTTI = RTTI::Tile;
		inline static constexpr auto VTABLE = VTABLE::Tile;

		struct Action;  // sizeof(Action) == 0x30

		struct FadeControl
		{
		public:
			// members
			Tile*        parent;  // 00
			std::int32_t trait;   // 08
			float        start;   // 0C
			float        end;     // 10
			float        len;     // 14
			FadeControl* next;    // 18
		};
		static_assert(sizeof(FadeControl) == 0x20);

		struct Value
		{
		public:
			// members
			Tile*         parent;     // 00
			float         value;      // 08
			BSString      string;     // 10
			Action*       actions;    // 20
			Action*       reactions;  // 28
			std::uint16_t index;      // 30
			bool          isNumber;   // 32
		};
		static_assert(sizeof(Value) == 0x38);

		virtual ~Tile();  // 00

		virtual void         Init(Tile* a_parent, const char* a_name, Tile* a_replacedTile);        // 01
		virtual NiNode*      MakeNode();                                                            // 02
		virtual std::int32_t GetType();                                                             // 03
		virtual const char*  GetTypeName();                                                         // 04
		virtual Tile*        PostParse(std::int32_t a_trait, float a_value, const char* a_string);  // 05
		virtual void         ForceTextureRelease();                                                 // 06

		static Tile* GetMenuByClass(MENU_CLASS a_menuClass);

		Menu* GetMenu();

		// members
		bool            released;          // 08
		bool            menuDeleting;      // 09
		bool            manualUpdateTris;  // 0A
		bool            scissorHidden;     // 0B
		BSString        name;              // 10
		Tile*           parent;            // 20
		NiTList<Value*> traits;            // 28
		NiNode*         model;             // 48
		FadeControl*    fadeControls;      // 50
		std::int32_t    flags;             // 58
		NiTList<Tile*>  children;          // 60
	};
	static_assert(sizeof(Tile) == 0x80);

}
