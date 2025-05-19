#pragma once

#include "RE/T/Tile.h"

namespace RE
{
	class TileRect :
		public Tile
	{
	public:
		virtual ~TileRect() override;  // 00

		// override (Tile)
		virtual void         Init(Tile* a_parent, const char* a_name, Tile* a_replacedTile) override;  // 01
		virtual NiNode*      MakeNode() override;                                                      // 02
		virtual std::int32_t GetType() override;                                                       // 03
		virtual const char*  GetTypeName() override;                                                   // 04

		// members
		bool isScissor;  // 80
	};
	static_assert(sizeof(TileRect) == 0x88);
}
