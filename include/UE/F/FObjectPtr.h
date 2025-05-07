#pragma once

namespace UE
{
	class UObject;

	class FObjectPtr
	{
	public:
		// members
		union
		{
			UObject* handle;
			UObject* debugPtr;
		};
	};
	static_assert(sizeof(FObjectPtr) == 0x08);
}
