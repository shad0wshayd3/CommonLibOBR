#pragma once

namespace UE
{
	class FObjectSaveContextData;

	class FObjectPreSaveContext
	{
	public:
		// members
		FObjectSaveContextData* data;  // 00
	};
	static_assert(sizeof(FObjectPreSaveContext) == 0x08);
}
