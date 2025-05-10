#pragma once

#include "RE/T/TileRect.h"

namespace RE
{
	class Menu;

	class TileMenu :
		public TileRect
	{
	public:
		virtual ~TileMenu() override;  // 00

		// override (Tile)
		virtual void         Init(Tile* a_parent, const char* a_name, Tile* a_replacedTile) override;        // 01
		virtual NiNode*      MakeNode() override;                                                            // 02
		virtual std::int32_t GetType() override;                                                             // 03
		virtual const char*  GetTypeName() override;                                                         // 04
		virtual TileMenu*    PostParse(std::int32_t a_trait, float a_value, const char* a_string) override;  // 05
		virtual void         ForceTextureRelease() override;                                                 // 06

		// members
		Menu* menu;  // 88
	};
	static_assert(sizeof(TileMenu) == 0x90);
}
