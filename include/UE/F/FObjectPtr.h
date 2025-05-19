#pragma once

namespace UE
{
	class UObject;

	class FObjectPtr
	{
	public:
		UObject* Get() const
		{
			return handle;
		}

		explicit operator bool() const
		{
			return handle;
		}

		// members
		union
		{
			UObject* handle;
			UObject* debugPtr;
		};
	};
	static_assert(sizeof(FObjectPtr) == 0x08);
}
