#pragma once

#include "RE/B/BSStringT.h"
#include "RE/N/NiTList.h"

namespace RE
{
	class ScriptCompiler;

	class MenuConsole
	{
	public:
		static MenuConsole* Instance(bool a_create)
		{
			using func_t = decltype(&MenuConsole::Instance);
			static REL::Relocation<func_t> func{ ID::MenuConsole::Instance };
			return func(a_create);
		}

		void PrintLine(const char* a_string, va_list a_args)
		{
			using func_t = void (MenuConsole::*)(const char*, va_list);
			static REL::Relocation<func_t> func{ ID::MenuConsole::PrintLine };
			return func(this, a_string, a_args);
		}

		void PrintLine(const char* a_string, ...)
		{
			va_list args;
			va_start(args, a_string);
			PrintLine(a_string, args);
			va_end(args);
		}

		// members
		ScriptCompiler*   consoleCompiler;
		NiTList<BSString> strings;
		NiTList<BSString> inputs;
		std::int32_t      inputsPos;
		std::int32_t      numStrings;
		std::int32_t      lastString;
		bool              lastMenuMode;
		std::uint8_t      visible;
		bool              isActive;
	};
	static_assert(sizeof(MenuConsole) == 0x58);
}
