#pragma once

#include "UE/E/EEulerRotationOrder.h"
#include "UE/V/VPairingData_IPairingData.h"

namespace UE::VPairingData
{
	class VTransform :
		public IPairingData
	{
	public:
		enum class ERotationType : std::int32_t
		{
			Euler = 0,
			Quaternion = 1,
		};

		union Rotation
		{
			float euler[3];
			float quaternion[4];
		};
		static_assert(sizeof(Rotation) == 0x10);

		union Scale
		{
			float value;
			float xyz[3];
		};
		static_assert(sizeof(Scale) == 0xC);

		// override
		virtual ~VTransform();  // 00

		// members
		ERotationType currentRotationType;                  // 10
		bool          isTurnedAround;                       // 14
		alignas(4) EEulerRotationOrder originalEulerOrder;  // 18
		float    position[3];                               // 1C
		Rotation rotation;                                  // 28
		Scale    scale;                                     // 38
	};
	static_assert(sizeof(VTransform) == 0x48);
}
