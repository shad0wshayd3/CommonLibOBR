#pragma once

namespace RE
{
	class TESForm;
	class TESGlobal;
	class TESClass;
	class TESFaction;
	class TESHair;
	class TESEyes;
	class TESRace;
	class TESSound;
	class TESSkill;
	class EffectSetting;
	class Script;
	class TESLandTexture;
	class EnchantmentItem;
	class SpellItem;
	class BirthSign;
	class TESObjectACTI;
	class TESObjectAPPA;
	class TESObjectARMO;
	class TESObjectBOOK;
	class TESObjectCLOT;
	class TESObjectCONT;
	class TESObjectDOOR;
	class IngredientItem;
	class TESObjectLIGH;
	class TESObjectMISC;
	class TESObjectSTAT;
	class TESGrass;
	class TESObjectTREE;
	class TESFlora;
	class TESFurniture;
	class TESObjectWEAP;
	class TESAmmo;
	class TESNPC;
	class TESCreature;
	class TESLevCreature;
	class TESSoulGem;
	class TESKey;
	class AlchemyItem;
	class TESSubSpace;
	class TESSigilStone;
	class TESLevItem;
	class TESWeather;
	class TESClimate;
	class TESRegion;
	class TESObjectCELL;
	class TESObjectREFR;
	class Actor;
	class Character;
	class Creature;
	class PlayerCharacter;
	class TESPathGrid;
	class TESWorldSpace;
	class TESObjectLAND;
	class TESRoad;
	class TESTopic;
	class TESQuest;
	class TESIdleForm;
	class TESPackage;
	class TESCombatStyle;
	class TESLoadScreen;
	class TESLevSpell;
	class TESObjectANIO;
	class TESWaterForm;
	class TESEffectShader;

	enum class FormType
	{
		None = 0,         //  00 NONE TESForm
		PluginInfo,       //  01 TES4
		FormGroup,        //  02 GRUP
		GameSetting,      //  03 GMST
		Global,           //  04 GLOB TESGlobal
		Class,            //  05 CLAS TESClass
		Faction,          //  06 FACT TESFaction
		Hair,             //  07 HAIR TESHair
		Eyes,             //  08 EYES TESEyes
		Race,             //  09 RACE TESRace
		Sound,            //  0A SOUN TESSound
		Skill,            //  0B SKIL TESSkill
		MagicEffect,      //  0C MGEF EffectSetting
		Script,           //  0D SCPT Script
		LandTexture,      //  0E LTEX TESLandTexture
		Enchantment,      //  0F ENCH EnchantmentItem
		Spell,            //  10 SPEL SpellItem
		BirthSign,        //  11 BSGN BirthSign
		Activator,        //  12 ACTI TESObjectACTI
		Apparatus,        //  13 APPA TESObjectAPPA
		Armor,            //  14 ARMO TESObjectARMO
		Book,             //  15 BOOK TESObjectBOOK
		Clothing,         //  16 CLOT TESObjectCLOT
		Container,        //  17 CONT TESObjectCONT
		Door,             //  18 DOOR TESObjectDOOR
		Ingredient,       //  19 INGR IngredientItem
		Light,            //  1A LIGH TESObjectLIGH
		Misc,             //  1B MISC TESObjectMISC
		Static,           //  1C STAT TESObjectSTAT
		Grass,            //  1D GRAS TESGrass
		Tree,             //  1E TREE TESObjectTREE
		Flora,            //  1F FLOR TESFlora
		Furniture,        //  20 FURN TESFurniture
		Weapon,           //  21 WEAP TESObjectWEAP
		Ammo,             //  22 AMMO TESAmmo
		NPC,              //  23 NPC_ TESNPC
		Creature,         //  24 CREA TESCreature
		LeveledCreature,  //  25 LVLC TESLevCreature
		SoulGem,          //  26 SLGM TESSoulGem
		KeyMaster,        //  27 KEYM TESKey
		AlchemyItem,      //  28 ALCH AlchemyItem
		SubSpace,         //  29 SBSP TESSubSpace
		SigilStone,       //  2A SGST TESSigilStone
		LeveledItem,      //  2B LVLI TESLevItem
		SNDG,             //  2C SNDG
		Weather,          //  2D WTHR TESWeather
		Climate,          //  2E CLMT TESClimate
		Region,           //  2F REGN TESRegion
		Cell,             //  30 CELL TESObjectCELL
		Reference,        //  31 REFR TESObjectREFR
		ActorCharacter,   //  32 ACHR Actor / Character / PlayerCharacter
		ActorCreature,    //  33 ACRE Creature
		PathGrid,         //  34 PGRD TESPathGrid
		WorldSpace,       //  35 WRLD TESWorldSpace
		Land,             //  36 LAND TESObjectLAND
		TLOD,             //  37 TLOD
		Road,             //  38 ROAD TESRoad
		Dialogue,         //  39 DIAL TESTopic
		Info,             //  3A INFO TESTopicInfo
		Quest,            //  3B QUST TESQuest
		Idle,             //  3C IDLE TESIdleForm
		Package,          //  3D PACK TESPackage
		CombatStyle,      //  3E CSTY TESCombatStyle
		LoadScreen,       //  3F LSCR TESLoadScreen
		LeveledSpell,     //  40 LVSP TESLevSpell
		AnimatedObject,   //  41 ANIO TESObjectANIO
		Water,            //  42 WATR TESWaterForm
		EffectShader,     //  43 EFSH TESEffectShader
		TOFT,             //  44 TOFT
		LVRG,             //  45 LVRG

		Max
	};

	[[nodiscard]] std::string_view FormTypeToString(FormType a_formType) noexcept;
	[[nodiscard]] FormType         StringToFormType(std::string_view a_formType);
}

namespace std
{
	[[nodiscard]] inline std::string to_string(RE::FormType a_formType)
	{
		return RE::FormTypeToString(a_formType).data();
	}
}

#ifdef FMT_VERSION
namespace fmt
{
	template <>
	struct formatter<RE::FormType>
	{
		template <class ParseContext>
		constexpr auto parse(ParseContext& a_ctx)
		{
			return a_ctx.begin();
		}

		template <class FormatContext>
		auto format(const RE::FormType& a_formType, FormatContext& a_ctx) const
		{
			return fmt::format_to(a_ctx.out(), "{}", RE::FormTypeToString(a_formType));
		}
	};
}
#endif

#ifdef __cpp_lib_format
namespace std
{
	template <class CharT>
	struct formatter<RE::FormType, CharT> : std::formatter<std::string_view, CharT>
	{
		template <class FormatContext>
		auto format(RE::FormType a_formType, FormatContext& a_ctx)
		{
			return formatter<std::string_view, CharT>::format(RE::FormTypeToString(a_formType), a_ctx);
		}
	};
}
#endif
