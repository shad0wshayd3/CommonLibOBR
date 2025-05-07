#pragma once

namespace RE
{
	class TESForm;

	struct ACTION_OBJECT
	{
	public:
		// members
		TESForm*      form;   // 00
		std::uint64_t flags;  // 08
	};
	static_assert(sizeof(ACTION_OBJECT) == 0x10);
}
