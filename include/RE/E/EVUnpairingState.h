#pragma once

namespace RE
{
	enum class EVUnpairingState : std::int32_t
	{
		kNotUnpaired,
		kUnpairedAtDestruction,
		kUnpairedAtModelDeattachment,
		kUnpairedDueToCache,
	};
}
