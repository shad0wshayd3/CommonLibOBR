#include "RE/F/FormTypes.h"

#include "RE/F/FORM_ENUM_STRING.h"

namespace RE
{
	std::string_view FormTypeToString(FormType a_formType) noexcept
	{
		switch (a_formType) {
		case FormType::PluginInfo:
			return "TES4";
		case FormType::FormGroup:
			return "GRUP";
		case FormType::GameSetting:
			return "GMST";
		case FormType::Global:
			return "GLOB";
		case FormType::Class:
			return "CLAS";
		case FormType::Faction:
			return "FACT";
		case FormType::Hair:
			return "HAIR";
		case FormType::Eyes:
			return "EYES";
		case FormType::Race:
			return "RACE";
		case FormType::Sound:
			return "SOUN";
		case FormType::Skill:
			return "SKIL";
		case FormType::MagicEffect:
			return "MGEF";
		case FormType::Script:
			return "SCPT";
		case FormType::LandTexture:
			return "LTEX";
		case FormType::Enchantment:
			return "ENCH";
		case FormType::Spell:
			return "SPEL";
		case FormType::BirthSign:
			return "BSGN";
		case FormType::Activator:
			return "ACTI";
		case FormType::Apparatus:
			return "APPA";
		case FormType::Armor:
			return "ARMO";
		case FormType::Book:
			return "BOOK";
		case FormType::Clothing:
			return "CLOT";
		case FormType::Container:
			return "CONT";
		case FormType::Door:
			return "DOOR";
		case FormType::Ingredient:
			return "INGR";
		case FormType::Light:
			return "LIGH";
		case FormType::Misc:
			return "MISC";
		case FormType::Static:
			return "STAT";
		case FormType::Grass:
			return "GRAS";
		case FormType::Tree:
			return "TREE";
		case FormType::Flora:
			return "FLOR";
		case FormType::Furniture:
			return "FURN";
		case FormType::Weapon:
			return "WEAP";
		case FormType::Ammo:
			return "AMMO";
		case FormType::NPC:
			return "NPC_";
		case FormType::Creature:
			return "CREA";
		case FormType::LeveledCreature:
			return "LVLC";
		case FormType::SoulGem:
			return "SLGM";
		case FormType::KeyMaster:
			return "KEYM";
		case FormType::AlchemyItem:
			return "ALCH";
		case FormType::SubSpace:
			return "SBSP";
		case FormType::SigilStone:
			return "SGST";
		case FormType::LeveledItem:
			return "LVLI";
		case FormType::SNDG:
			return "SNDG";
		case FormType::Weather:
			return "WTHR";
		case FormType::Climate:
			return "CLMT";
		case FormType::Region:
			return "REGN";
		case FormType::Cell:
			return "CELL";
		case FormType::Reference:
			return "REFR";
		case FormType::ActorCharacter:
			return "ACHR";
		case FormType::ActorCreature:
			return "ACRE";
		case FormType::PathGrid:
			return "PGRD";
		case FormType::WorldSpace:
			return "WRLD";
		case FormType::Land:
			return "LAND";
		case FormType::TLOD:
			return "TLOD";
		case FormType::Road:
			return "ROAD";
		case FormType::Dialogue:
			return "DIAL";
		case FormType::Info:
			return "INFO";
		case FormType::Quest:
			return "QUST";
		case FormType::Idle:
			return "IDLE";
		case FormType::Package:
			return "PACK";
		case FormType::CombatStyle:
			return "CSTY";
		case FormType::LoadScreen:
			return "LSCR";
		case FormType::LeveledSpell:
			return "LVSP";
		case FormType::AnimatedObject:
			return "ANIO";
		case FormType::Water:
			return "WATR";
		case FormType::EffectShader:
			return "EFSH";
		case FormType::TOFT:
			return "TOFT";
		case FormType::LVRG:
			return "LVRG";
		default:
			return "NONE";
		}
	}

	FormType StringToFormType(std::string_view a_formType)
	{
		for (auto& iter : FORM_ENUM_STRING::GetFormEnumString()) {
			if (_stricmp(iter.formString, a_formType.data()) == 0) {
				return iter.formType;
			}
		}

		return FormType::None;
	}
}
