#pragma once

namespace RE
{
	namespace VAnimationPairingComponentHandlers
	{
		class OblivionAnimSectionInfo
		{
		public:
			// members
			std::int16_t  groupAction;  // 00
			std::uint16_t groupID;      // 02
			std::int32_t  sequenceIdx;  // 04
		};
		static_assert(sizeof(OblivionAnimSectionInfo) == 0x08);

		class OblivionAnimState
		{
		public:
			// members
			std::int32_t            action;                   // 00
			std::uint16_t           moveMode;                 // 04
			OblivionAnimSectionInfo animBodySectionInfos[5];  // 08
		};
		static_assert(sizeof(OblivionAnimState) == 0x30);
	}
}
