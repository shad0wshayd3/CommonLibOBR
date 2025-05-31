#pragma once

namespace UE
{
	enum class ECollisionResponse : std::int32_t
	{
		Ignore = 0,
		Overlap = 1,
		Block = 2,
	};
}
