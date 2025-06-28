#pragma once

namespace RE
{
	enum class ExtraDataType : std::uint8_t
	{
		Havok = 0x02,
		Cell3D = 0x03,
		WaterHeight = 0x04,
		CellWaterType = 0x05,
		// 06
		// 07
		RegionList = 0x08,
		SeenData = 0x09,
		EditorID = 0x0A,
		CellMusicType = 0x0B,
		CellClimate = 0x0C,
		ProcessMiddleLow = 0x0D,
		EditorCommonDialogData = 0x0E,
		CellCanopyShadowMask = 0x0F,
		DetachTime = 0x10,
		PersistentCell = 0x11,
		Script = 0x12,
		Action = 0x13,
		StartingPosition = 0x14,
		Anim = 0x15,
		// 16
		UsedMarkers = 0x17,
		DistantData = 0x18,
		RagDollData = 0x19,
		ContainerChanges = 0x1A,
		Worn = 0x1B,
		WornLeft = 0x1C,
		// 1D
		StartLocation = 0x1E,
		Package = 0x1F,
		TrespassPackage = 0x20,
		RunOncePacks = 0x21,
		ReferencePointer = 0x22,
		Follower = 0x23,
		LevCreaModifier = 0x24,
		Ghost = 0x25,
		OriginalReference = 0x26,
		Ownership = 0x27,
		Global = 0x28,
		Rank = 0x29,
		Count = 0x2A,
		Health = 0x2B,
		Uses = 0x2C,
		TimeLeft = 0x2D,
		Charge = 0x2E,
		Soul = 0x2F,
		Light = 0x30,
		Lock = 0x31,
		Teleport = 0x32,
		MapMarker = 0x33,
		// 34
		LeveledCreature = 0x35,
		LeveledItem = 0x36,
		Scale = 0x37,
		Seed = 0x38,
		NonActorMagicCaster = 0x39,
		NonActorMagicTarget = 0x3A,
		// 3B
		// 3C
		CrimeGold = 0x3D,
		OblivionEntry = 0x3E,
		EnableStateParent = 0x3F,
		EnableStateChildren = 0x40,
		ItemDropper = 0x41,
		DroppedItemList = 0x42,
		RandomTeleportMarker = 0x43,
		MerchantContainer = 0x44,
		// 45
		PersuasionPercent = 0x46,
		CannotWear = 0x47,
		Poison = 0x48,
		// 49
		LastFinishedSequence = 0x4A,
		SavedMovementData = 0x4B,
		NorthRotation = 0x4C,
		XTarget = 0x4D,
		FriendHitList = 0x4E,
		HeadingTarget = 0x4F,
		BoundArmor = 0x50,
		RefractionProperty = 0x51,
		InvestmentGold = 0x52,
		StartingWorldOrCell = 0x53,
		// 54
		QuickKey = 0x55,
		// 56
		EditorRefMoveData = 0x57,
		TravelHorse = 0x58,
		InfoGeneralTopic = 0x59,
		HasNoRumors = 0x5A,
		ExtraSound = 0x5B,
		HaggleAmount = 0x5C,
		AltarBPVariant = 0x5D,           // ExtraAltarBPVariant
		AltarActorGUID = 0x5E,           // ExtraAltarActorGUID
		AltarCellName = 0x5F,            // VExtraAltarCellName
		AltarData = 0x60,                // ExtraAltarData
		AltarThreatLevel = 0x61,         // VExtraAltarThreatLevel
		AltarBigWorldLeveledRgn = 0x62,  // VExtraAltarBigWorldLeveledRegion

		Max = 0x80,
	};
}
