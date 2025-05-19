#pragma once

#include "RE/S/SCRIPT_OUTPUT.h"
#include "RE/S/SCRIPT_PARAMETER.h"

namespace RE
{
	class Script;
	class ScriptCompileData;
	class ScriptLocals;
	class TESObjectREFR;

	struct SCRIPT_LINE;

	struct SCRIPT_FUNCTION
	{
	public:
		struct Op
		{
			enum : std::uint32_t
			{
				kConsoleBase = 0x100,
				kScriptBase = 0x1000
			};
		};

		using Execute_t = bool(const SCRIPT_PARAMETER* a_parameters, const char* a_compiledParams, TESObjectREFR* a_refObject, TESObjectREFR* a_container, Script* a_script, ScriptLocals* a_scriptLocals, double& a_result, std::uint32_t& a_offset);
		using Compile_t = bool(std::uint16_t a_paramCount, const SCRIPT_PARAMETER* a_parameters, SCRIPT_LINE* a_scriptLine, ScriptCompileData* a_compileData);
		using Condition_t = bool(TESObjectREFR* a_refObject, void* a_param01, void* a_param02, double& a_result);

		static auto GetConsoleFunctions()
		{
			static REL::Relocation<SCRIPT_FUNCTION(*)[135]> functions{ ID::SCRIPT_FUNCTION::ConsoleFunctions };
			return std::span{ *functions };
		}

		static SCRIPT_FUNCTION* LocateConsoleCommand(std::string_view a_functionName)
		{
			for (auto& command : GetConsoleFunctions()) {
				if (command.functionName && std::strlen(command.functionName) == a_functionName.size()) {
					if (_strnicmp(command.functionName, a_functionName.data(), a_functionName.size()) == 0) {
						return std::addressof(command);
					}
				}
			}
			return nullptr;
		}

		static auto GetScriptFunctions()
		{
			static REL::Relocation<SCRIPT_FUNCTION(*)[371]> functions{ ID::SCRIPT_FUNCTION::ScriptFunctions };
			return std::span{ *functions };
		}

		static SCRIPT_FUNCTION* LocateScriptCommand(std::string_view a_functionName)
		{
			for (auto& command : GetScriptFunctions()) {
				if (command.functionName && std::strlen(command.functionName) == a_functionName.size()) {
					if (_strnicmp(command.functionName, a_functionName.data(), a_functionName.size()) == 0) {
						return std::addressof(command);
					}
				}
			}
			return nullptr;
		}

		template <std::uint16_t N>
		inline void SetParameters(SCRIPT_PARAMETER (&a_parameters)[N])
		{
			paramCount = N;
			parameters = a_parameters;
		}

		void SetParameters()
		{
			paramCount = 0;
			parameters = nullptr;
		}

		// members
		const char*       functionName;         // 00
		const char*       shortName;            // 08
		SCRIPT_OUTPUT     output;               // 10
		const char*       helpString;           // 18
		bool              referenceFunction;    // 20
		std::uint16_t     paramCount;           // 22
		SCRIPT_PARAMETER* parameters;           // 28
		Execute_t*        executeFunction;      // 30
		Compile_t*        compileFunction;      // 38
		Condition_t*      conditionFunction;    // 40
		bool              editorFilter;         // 48
		bool              invalidatesCellList;  // 49
	};
	static_assert(sizeof(SCRIPT_FUNCTION) == 0x50);
}
