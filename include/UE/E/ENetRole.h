#pragma once

namespace UE
{
	enum class ENetRole : std::int32_t
	{
		None,
		SimulatedProxy,
		AutonomousProxy,
		Authority,
	};
}
