#pragma once

namespace UE
{
	enum class EMovementMode : std::int32_t
	{
		None,
		Walking,
		NavWalking,
		Falling,
		Swimming,
		Flying,
		Custom,
	};
}
