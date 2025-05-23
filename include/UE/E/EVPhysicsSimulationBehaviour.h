#pragma once

namespace UE
{
	enum class EVPhysicsSimulationBehaviour : std::uint8_t
	{
		Always = 0,
		Never = 1,
		AtDeathOrFall = 2,
		StartOnActivate = 3,
		StopOnActivate = 4,
		WhenUnequipped = 5,
	};
}
