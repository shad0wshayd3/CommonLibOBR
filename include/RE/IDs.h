#pragma once

namespace RE::ID
{
	namespace Actor
	{
		inline constexpr REL::Offset GetItemCountInContainer{ 0 };  // 0x65DA780
	}

	namespace FORM_ENUM_STRING
	{
		inline constexpr REL::Offset FormEnumString{ 0x8F9FCE0 };
	}

	namespace GameSettingCollection
	{
		inline constexpr REL::Offset Singleton{ 0 };  // 0x8FE1E10
	}

	namespace InterfaceManager
	{
		inline constexpr REL::Offset GetInstance{ 0x65D7AB0 };
	}

	namespace MapMenu
	{
		inline constexpr REL::Offset CenterMapAt{ 0x655B990 };
		inline constexpr REL::Offset SwitchTabs{ 0x6560E30 };
		inline constexpr REL::Offset SwitchTabsNotifyingAltar{ 0x6560FD0 };
		inline constexpr REL::Offset Update{ 0x6561220 };
	}

	namespace MenuConsole
	{
		inline constexpr REL::Offset Instance{ 0x6630730 };
		inline constexpr REL::Offset PrintLine{ 0x6630950 };
	}

	namespace PlayerCharacter
	{
		inline constexpr REL::Offset Singleton{ 0x9413B08 };
	}

	namespace Script
	{
		inline constexpr REL::Offset ParseParameters{ 0x662DCA0 };
	}

	namespace SCRIPT_FUNCTION
	{
		inline constexpr REL::Offset ConsoleFunctions{ 0x8FB6600 };
		inline constexpr REL::Offset ScriptFunctions{ 0x8FAF210 };
	}

	namespace Setting
	{
		inline constexpr REL::Offset SetString{ 0 };  // 0x6710B70
	}

	namespace TESDataHandler
	{
		inline constexpr REL::Offset Singleton{ 0x9474418 };
	}

	namespace TESForm
	{
		inline constexpr REL::Offset AllForms{ 0x8FA0370 };
		inline constexpr REL::Offset AllFormsByEditorID{ 0x8FA03B0 };
	}

	namespace TESFullName
	{
		inline constexpr REL::Offset GetFullName{ 0x657C4B0 };
	}

	namespace TESObjectREFR
	{
		inline constexpr REL::Offset GetInterior{ 0x657C740 };
		inline constexpr REL::Offset GetWorldSpace{ 0x657E270 };
	}

	namespace Tile
	{
		inline constexpr REL::Offset GetMenuByClass{ 0x66EF410 };
		inline constexpr REL::Offset GetMenu{ 0x66EF3C0 };
	}

	inline constexpr REL::Offset RTDynamicCast{ 0x6BF7A96 };
}

namespace UE::ID
{
	namespace FFrame
	{
		inline constexpr REL::Offset KismetExecutionMessage{ 0 };  // 0x10FD030
	}

	namespace FLogScopedCategoryAndVerbosityOverride
	{
		inline constexpr REL::Offset GetTLSCurrent{ 0 };  // 0x0EA74B0
	}

	namespace FMemory
	{
		inline constexpr REL::Offset Free{ 0x0E24570 };
		inline constexpr REL::Offset Malloc{ 0x0E30FB0 };
		inline constexpr REL::Offset Realloc{ 0 };       // 0x0E3EE30
		inline constexpr REL::Offset QuantizeSize{ 0 };  // 0x0E3E800
	}

	namespace FName
	{
		inline constexpr REL::Offset Ctor1{ 0x0F397B0 };
		inline constexpr REL::Offset Ctor2{ 0x0F39920 };
		inline constexpr REL::Offset AppendString{ 0x0F3F5C0 };
		inline constexpr REL::Offset ToString{ 0x0F54EC0 };
	}

	namespace FNamePool
	{
		inline constexpr REL::Offset GetSingleton{ 0x9061500 };
	}

	namespace FParse
	{
		inline constexpr REL::Offset Command{ 0 };  // 0x0F0F5E0
	}

	namespace FSelfRegisteringExec
	{
		inline constexpr REL::Offset Ctor{ 0 };  // 0x0EEA960
		inline constexpr REL::Offset Dtor{ 0 };  // 0x0EEAF70
	}

	namespace FString
	{
		inline constexpr REL::Offset AppendChar{ 0x0DDB660 };
		inline constexpr REL::Offset AppendChars1{ 0x0DDB6E0 };
		inline constexpr REL::Offset AppendChars2{ 0x0DDB6F0 };
		inline constexpr REL::Offset Ctor1{ 0x0DD8E70 };
		inline constexpr REL::Offset Ctor2{ 0x0DD9000 };
		inline constexpr REL::Offset Reset{ 0x0DE4060 };
	}

	namespace FText
	{
		inline constexpr REL::Offset Ctor1{ 0 };     // 0x0E561F0
		inline constexpr REL::Offset GetEmpty{ 0 };  // 0x0E6E7C0
		inline constexpr REL::Offset Rebuild{ 0 };   // 0x0E7F220
	}

	namespace FUObjectArray
	{
		inline constexpr REL::Offset GetSingleton{ 0x91077E0 };
	}

	namespace UAltarCheatManager
	{
		inline constexpr REL::Offset GetSelectedActor{ 0x2CDB4E0 };
		inline constexpr REL::Offset SetSelectedActor{ 0x4771160 };
	}

	namespace UClass
	{
		inline constexpr REL::Offset FindFunctionByName{ 0 };  // 0x1005AA0
	}

	namespace UEngine
	{
		inline constexpr REL::Offset GetSingleton{ 0x92734C0 };
		inline constexpr REL::Offset GetCurrentPlayWorld{ 0x37E3EB0 };
	}

	namespace UGameplayStatics
	{
		inline constexpr REL::Offset GetPlayerController{ 0x31AA560 };
	}

	namespace UObjectBaseUtility
	{
		inline constexpr REL::Offset GetFullName1{ 0 };  // 0x111F730
		inline constexpr REL::Offset GetFullName2{ 0 };  // 0x111F8D0
	}

	namespace UWorld
	{
		inline constexpr REL::Offset GetSingleton{ 0x9275EF8 };
	}

	namespace VOblivionUEPairingGate
	{
		inline constexpr REL::Offset GetSingleton{ 0x4594D60 };
	}

	inline constexpr REL::Offset AsyncTask{ 0x0DB8830 };
	inline constexpr REL::Offset GetExecRegistry{ 0 };                 // 0x0EF7E60
	inline constexpr REL::Offset GetExecRegistryLock{ 0 };             // 0x0EF7ED0
	inline constexpr REL::Offset GetTransientPackage{ 0 };             // 0x109A510
	inline constexpr REL::Offset IsInGameThread{ 0 };                  // 0x0E3C380
	inline constexpr REL::Offset LowLevelFatalErrorHandler{ 0 };       // 0x0ED7980
	inline constexpr REL::Offset StaticConstructObject_Internal{ 0 };  // 0x1129D30
	inline constexpr REL::Offset StaticFindObjectFast{ 0 };            // 0x112C350
	inline constexpr REL::Offset StaticFindObjectFastSafe{ 0 };        // 0x112CC40
	inline constexpr REL::Offset StaticFindObject{ 0 };                // 0x112C0F0
	inline constexpr REL::Offset StaticFindObjectSafe{ 0 };            // 0x112CCE0
}
