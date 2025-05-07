#pragma once

namespace RE
{
	class TESObject;
	class TESObjectCELL;

	class TESObjectList
	{
	public:
		// members
		std::uint32_t  count;  // 00
		TESObject*     head;   // 08
		TESObject*     tail;   // 10
		TESObjectCELL* owner;  // 18
	};
	static_assert(sizeof(TESObjectList) == 0x20);
}
