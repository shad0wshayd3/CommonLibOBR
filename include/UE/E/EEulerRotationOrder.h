#pragma once

namespace UE
{
	enum class EEulerRotationOrder : std::uint8_t
	{
		XYZ = 0u,
		XZY = 1u,
		YXZ = 2u,
		YZX = 3u,
		ZXY = 4u,
		ZYX = 5u,
	};
}
