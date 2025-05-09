#pragma once

namespace UE
{
	class FWeakObjectPtr
	{
		friend class FFieldPath;

	public:
		FWeakObjectPtr() = default;

		// members
		std::int32_t objectIndex{ 0 };
		std::int32_t objectSerialNumber{ 0 };
	};
	static_assert(sizeof(FWeakObjectPtr) == 0x08);
}
