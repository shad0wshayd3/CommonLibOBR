#pragma once

#include "RE/M/ModifierList.h"
#include "RE/T/TESAIForm.h"
#include "RE/T/TESActorBaseData.h"
#include "RE/T/TESAnimation.h"
#include "RE/T/TESAttributes.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESHealthForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESScriptableForm.h"
#include "RE/T/TESSpellList.h"
namespace RE
{
	class TESActorBase :
		public TESBoundAnimObject,
		public TESActorBaseData,
		public TESContainer,
		public TESSpellList,
		public TESAIForm,
		public TESHealthForm,
		public TESAttributes,
		public TESAnimation,
		public TESFullName,
		public TESModel,
		public TESScriptableForm
	{
	public:
		// members
		ModifierList modifierList;  // 180
	};
	static_assert(sizeof(TESActorBase) == 0x1A8);
}
