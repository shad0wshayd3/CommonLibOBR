#pragma once

#include "UE/E/EVDefaultSurfaceType.h"
#include "UE/E/EVPhysicsLoadingBehaviour.h"
#include "UE/E/EVPhysicsSimulationBehaviour.h"
#include "UE/F/FVBuoyancySettings.h"

namespace UE
{
	class FVPhysicsControlSettings
	{
	public:
		// members
		bool                         isGrabbable;                           // 000
		bool                         isTelekinesisTargetable;               // 001
		bool                         isAnchored;                            // 002
		EVPhysicsSimulationBehaviour physicsSimulationBehaviour;            // 003
		EVPhysicsLoadingBehaviour    physicsLoadingBehaviour;               // 004
		bool                         doesRepositionOnLoad;                  // 005
		bool                         doesReattachOnLoad;                    // 006
		bool                         doesRestoreAttachmentAfterSimulation;  // 007
		bool                         doesUseCCD;                            // 008
		FVBuoyancySettings           buoyancySettings;                      // 00C
		bool                         doesPlayCollisionSound;                // 018
		EVDefaultSurfaceType         defaultSelfSurfaceType;                // 019
		bool                         canSnapToEnvironment;                  // 01A
	};
	static_assert(sizeof(FVPhysicsControlSettings) == 0x1C);
}
