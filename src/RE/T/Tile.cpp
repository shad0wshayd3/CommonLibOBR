#include "RE/T/Tile.h"

namespace RE
{
	Tile* Tile::GetMenuByClass(MENU_CLASS a_menuClass)
	{
		using func_t = decltype(&Tile::GetMenuByClass);
		static REL::Relocation<func_t> func{ ID::Tile::GetMenuByClass };
		return func(a_menuClass);
	}

	Menu* Tile::GetMenu()
	{
		using func_t = decltype(&Tile::GetMenu);
		static REL::Relocation<func_t> func{ ID::Tile::GetMenu };
		return func(this);
	}
}
