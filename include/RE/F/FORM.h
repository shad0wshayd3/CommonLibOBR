#pragma once

namespace RE
{
	struct FORM
	{
	public:
		// members
		std::uint32_t form;            // 00
		std::uint32_t length;          // 04
		std::uint32_t flags;           // 08
		TESFormID     formID;          // 0C
		std::uint32_t versionControl;  // 10
	};
	static_assert(sizeof(FORM) == 0x14);

	struct FORM_GROUP
	{
	public:
		// members
		FORM          groupData;    // 00
		std::uint32_t groupOffset;  // 14
	};
	static_assert(sizeof(FORM_GROUP) == 0x18);
}
