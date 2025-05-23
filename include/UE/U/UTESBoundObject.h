#pragma once

#include "UE/F/FVPhysicsControlSettings.h"
#include "UE/U/UTESObject.h"

namespace UE
{
	class AVImpactSystemVFXBlueprint;
	class AVPropItem;
	class UTESModel;
	class UVEnchantSaveData;

	class UTESBoundObject :
		public UTESObject
	{
	public:
		UE_DEFINE_UOBJECT(UTESBoundObject, UTESObject, "Altar", "TESBoundObject");

		// override
		virtual ~UTESBoundObject();  // 00

		// members
		TSoftClassPtr<AVImpactSystemVFXBlueprint> impactSystemVFXBlueprintClass;        // 0D8
		float                                     impactSystemDuration;                 // 100
		float                                     mass;                                 // 104
		TSoftObjectPtr<UPhysicsAsset>             physicsAsset;                         // 108
		bool                                      isUsingCustomPhysicsControlSettings;  // 130
		FVPhysicsControlSettings                  physicsControlSettingsOverride;       // 134
		UTESModel*                                inheritedModel;                       // 150
		TSoftClassPtr<AVPropItem>                 propBlueprintClassOverride;           // 158
		UVEnchantSaveData*                        enchantSaveData;                      // 180
		bool                                      isEnchantedObject;                    // 188
	};
	static_assert(sizeof(UTESBoundObject) == 0x190);
}
