#pragma once

namespace UE
{
	enum class ENetDormancy : std::int32_t
	{
		Never,
		Awake,
		DormantAll,
		DormantPartial,
		Initial,

		MAX,
	};
}
