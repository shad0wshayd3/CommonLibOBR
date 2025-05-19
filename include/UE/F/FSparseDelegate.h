#pragma once

namespace UE
{
	class FSparseDelegate
	{
	public:
		FSparseDelegate() = default;

		// members
		bool isBound{ false };  // 00
	};
	static_assert(sizeof(FSparseDelegate) == 0x01);
}
