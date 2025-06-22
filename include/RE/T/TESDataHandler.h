#pragma once

#include "RE/B/BSTList.h"
#include "RE/N/NiTArray.h"
#include "RE/T/TESSkill.h"

namespace RE
{
	class BirthSign;
	class EnchantmentItem;
	class InventoryChanges;
	class Script;
	class SpellItem;
	class TESClass;
	class TESClimate;
	class TESCombatStyle;
	class TESEffectShader;
	class TESEyes;
	class TESFaction;
	class TESFile;
	class TESForm;
	class TESGlobal;
	class TESHair;
	class TESLandTexture;
	class TESLoadScreen;
	class TESObjectANIO;
	class TESObjectCELL;
	class TESObjectList;
	class TESPackage;
	class TESQuest;
	class TESRace;
	class TESRegionDataManager;
	class TESRegionList;
	class TESSound;
	class TESTopic;
	class TESWaterForm;
	class TESWeather;
	class TESWorldSpace;

	class TESDataHandler
	{
	public:
		static TESDataHandler* GetSingleton()
		{
			static REL::Relocation<TESDataHandler**> singleton{ ID::TESDataHandler::Singleton };
			return *singleton;
		}

		// members
		TESObjectList*                 objectList;            // 0000
		BSSimpleList<TESPackage*>      listPackages;          // 0008
		BSSimpleList<TESWorldSpace*>   listWorldSpaces;       // 0018
		BSSimpleList<TESClimate*>      listClimates;          // 0028
		BSSimpleList<TESWeather*>      listWeather;           // 0038
		BSSimpleList<EnchantmentItem*> listEnchantmentItems;  // 0048
		BSSimpleList<SpellItem*>       listSpellItems;        // 0058
		BSSimpleList<TESHair*>         listHair;              // 0068
		BSSimpleList<TESEyes*>         listEyes;              // 0078
		BSSimpleList<TESRace*>         listRaces;             // 0088
		BSSimpleList<TESLandTexture*>  listLandTexts;         // 0098
		BSSimpleList<TESClass*>        listClasses;           // 00A8
		BSSimpleList<TESFaction*>      listFactions;          // 00B8
		BSSimpleList<Script*>          listScripts;           // 00C8
		BSSimpleList<TESSound*>        listSounds;            // 00D8
		BSSimpleList<TESGlobal*>       listGlobals;           // 00E8
		BSSimpleList<TESTopic*>        listTopics;            // 00F8
		BSSimpleList<TESQuest*>        listQuests;            // 0108
		BSSimpleList<BirthSign*>       listBirthSigns;        // 0118
		BSSimpleList<TESCombatStyle*>  listCombatStyles;      // 0128
		BSSimpleList<TESLoadScreen*>   listLoadScreens;       // 0138
		BSSimpleList<TESWaterForm*>    listWater;             // 0148
		BSSimpleList<TESEffectShader*> listEffectShaders;     // 0158
		BSSimpleList<TESObjectANIO*>   animObjects;           // 0168
		TESRegionList*                 regionList;            // 0178
		NiTLargeArray<TESObjectCELL*>  arrayInteriorCells;    // 0180
		TESSkill                       skill[21];             // 01A0
		BSSimpleList<TESForm*>         listBadForms;          // 1010
		std::uint32_t                  nextID;                // 1020
		TESFile*                       activeFile;            // 1028
		BSSimpleList<TESFile*>         listFiles;             // 1030
		std::uint32_t                  numCompile;            // 1040
		TESFile*                       fileIndex[255];        // 1048
		bool                           masterSave;            // 1840
		bool                           saveLoadGame;          // 1841
		bool                           autoSaving;            // 1842
		bool                           exportingPlugin;       // 1843
		bool                           clearingData;          // 1844
		bool                           hasDesiredFiles;       // 1845
		bool                           checkingModels;        // 1846
		bool                           loadingFiles;          // 1847
		TESRegionDataManager*          regionDataManager;     // 1848
		InventoryChanges*              barterContainer;       // 1850
		bool                           enableLeveledRegion;   // 1858

		template<typename FN>
		void ForEachObject(FN fn)
		{
			for (auto& object : *objectList)
				fn(object);
		}
	};
	static_assert(sizeof(TESDataHandler) == 0x1860);
}
