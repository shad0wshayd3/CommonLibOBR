#pragma once

#include "RE/C/CHUNK_ID.h"
#include "RE/E/EffectItemList.h"
#include "RE/M/MagicSystem.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class EffectItem;
	class TESFile;

	class MagicItem :
		public TESFullName,
		public EffectItemList
	{
	public:
		inline static constexpr auto RTTI = RTTI::MagicItem;
		inline static constexpr auto VTABLE = VTABLE::MagicItem;

		enum class CannotCastReason : std::int32_t
		{
			kOk,
			kMagicka,
			kSilenced,
			kSkillCheck,
			kPowerUsed,
			kMultipleBoundEffects,
			kRangedUnderwater,
			kClairvoyanceWithoutQuest,
		};

		// add
		virtual bool                   IsAutoCalc();                                             // 04
		virtual void                   SetAutoCalc(bool a_value);                                // 05
		virtual MagicSystem::SpellType GetSpellType();                                           // 06
		virtual bool                   IgnoreResistance();                                       // 07
		virtual bool                   GetNoAbsorbOrReflect();                                   // 08
		virtual CHUNK_ID               GetChunkID();                                             // 09
		virtual void*                  GetData();                                                // 0A
		virtual unsigned __int64       GetDataSize();                                            // 0B
		virtual bool                   CompareMagicItemData(MagicItem* a_compare);               // 0C
		virtual void                   CopyMagicItemData(MagicItem* a_copy);                     // 0D
		virtual void                   SaveMagicItemComponents();                                // 0E
		virtual void                   LoadMagicItemChunk(TESFile* a_file, CHUNK_ID a_chunkID);  // 0F

		// members
		std::list<EffectItem*>* visibleEffectsInAltar;              // 38
		EffectItem*             mainTargetEffectInAltar;            // 40
		EffectItem*             mainSelfEffectInAltar;              // 48
		EffectItem*             secondEffectInAltar;                // 50
		bool                    hasChosenVisibleEffects;            // 58
		bool                    hasAlreadyPlayedHitEffectsInAltar;  // 59
	};
	static_assert(sizeof(MagicItem) == 0x60);
}
