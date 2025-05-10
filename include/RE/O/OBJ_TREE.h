#pragma once

namespace RE
{
	class OBJ_TREE
	{
	public:
		// members
		float        curveScalar;         // 00
		float        minimumLeafAngle;    // 04
		float        maximumLeafAngle;    // 08
		float        branchDimming;       // 0C
		float        leafDimming;         // 10
		std::int32_t canopyShadowRadius;  // 14
		float        rockSpeed;           // 18
		float        rustleSpeed;         // 1C
	};
	static_assert(sizeof(OBJ_TREE) == 0x20);
}
