#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BSTList.h"
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

		struct TileTemplate;
		struct TileTemplateItem;
		struct Value;

		enum class enumAction : std::int32_t
		{
			hNullAction = 0x0,
			hGroupStart = 0xA,
			hGroupEnd = 0xF,
			hActionStart = 0x14,
			hActionEnd = 0x19,
			hTraitStart = 0x1E,
			hTraitEnd = 0x23,
			hTileStart = 0x28,
			hTileEnd = 0x2D,
			hSimpleTrait = 0x32,
			hSimpleAction = 0x37,
			hTraitLink = 0x3C,
			hTop = 0x65,
			hCopy = 0x7D1,
			hFirstAction = 0x7D1,
			hAdd = 0x7D2,
			hSub = 0x7D3,
			hMult = 0x7D4,
			hDiv = 0x7D5,
			hRand = 0x7D6,
			hUser = 0x7D7,
			hGt = 0x7D8,
			hGte = 0x7D9,
			hEq = 0x7DA,
			hLte = 0x7DB,
			hLt = 0x7DC,
			hMin = 0x7DD,
			hMax = 0x7DE,
			hAnd = 0x7DF,
			hOr = 0x7E0,
			hNeq = 0x7E1,
			hMod = 0x7E2,
			hTrunc = 0x7E3,
			hAbs = 0x7E4,
			hOnlyIf = 0x7E5,
			hOnlyIfNot = 0x7E6,
			hLn = 0x7E7,
			hLog = 0x7E8,
			hCeil = 0x7E9,
			hNot = 0x7EA,
			hRef = 0x7EB,
			hLastAction = 0x7EB,
		};

		struct Action
		{
		private:
			union union_t
			{
				float      value;
				Value*     owner;
				enumAction groupType;
			};

		public:
			Action*    prevAction;    // 00
			Action*    nextAction;    // 08
			union_t    value;         // 10
			enumAction action;        // 18
			Action*    prevReaction;  // 20
			Action*    nextReaction;  // 28
		};
		static_assert(sizeof(Action) == 0x30);

		struct BuildStorage
		{
			// members
			TileTemplate*               _template;        // 00
			BSSimpleList<TileTemplate*> subTemplates;     // 08
			TileTemplate*               currentTemplate;  // 18
			bool                        deleteTemplates;  // 20
		};
		static_assert(sizeof(BuildStorage) == 0x28);

		struct FadeControl
		{
			// members
			Tile*        parent;  // 00
			std::int32_t trait;   // 08
			float        start;   // 0C
			float        end;     // 10
			float        len;     // 14
			FadeControl* next;    // 18
		};
		static_assert(sizeof(FadeControl) == 0x20);

		struct StringListElement
		{
			// members
			std::int32_t index;        // 00
			std::int32_t accessCount;  // 04
			BSString     string;       // 08
		};
		static_assert(sizeof(StringListElement) == 0x18);

		struct TileTemplate
		{
			// members
			BSString                   name;    // 00
			BuildStorage*              parent;  // 10
			NiTList<TileTemplateItem*> list;    // 18
		};
		static_assert(sizeof(TileTemplate) == 0x38);

		struct TileTemplateItem
		{
		private:
			union union_t
			{
				std::int32_t  ta;
				Tile*         tile;
				TileTemplate* _template;
			};

		public:
			// members
			std::int32_t cmd;   // 00
			float        val;   // 04
			BSString     str;   // 08
			union_t      u;     // 18
			std::int32_t line;  // 20
		};
		static_assert(sizeof(TileTemplateItem) == 0x28);

		struct Value
		{
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
