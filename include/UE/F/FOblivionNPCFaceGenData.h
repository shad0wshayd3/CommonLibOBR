#pragma once

#include "UE/T/TArray.h"

namespace UE
{
	class FOblivionNPCFaceGenData
	{
	public:
		// members
		TArray<float> symmetricalGeometryData;   // 00
		TArray<float> asymmetricalGeometryData;  // 10
		TArray<float> textureData;               // 20
	};
	static_assert(sizeof(FOblivionNPCFaceGenData) == 0x30);
}
