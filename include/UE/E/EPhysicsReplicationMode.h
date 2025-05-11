#pragma once

namespace UE
{
	enum class EPhysicsReplicationMode : std::uint8_t
	{
		Default,
		PredictiveInterpolation,
		Resimulation,
	};
}
