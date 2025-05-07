#pragma once

namespace UE
{
	class FObjectSaveContextData;

	class FObjectPostSaveContext
	{
	public:
		// members
		FObjectSaveContextData* data;  // 00
	};
	static_assert(sizeof(FObjectPostSaveContext) == 0x08);
}
