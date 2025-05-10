#pragma once

namespace RE
{
	class WaterShaderData
	{
	public:
		float         windVelocity;          //00
		float         windDirection;         //04
		float         waveAmplitude;         //08
		float         waveFrequency;         //0C
		float         sunPower;              //10
		float         reflectionAmount;      //14
		float         fresnelAmount;         //18
		float         scrollSpeedX;          //1C
		float         scrollSpeedY;          //20
		float         fogDistNear;           //24
		float         fogDistFar;            //28
		std::uint32_t shallowWaterColor;     //2C
		std::uint32_t deepWaterColor;        //30
		std::uint32_t reflectionWaterColor;  //34
		std::uint8_t  blend;                 //38
		float         rainForce;             //3C
		float         rainVelocity;          //40
		float         rainFalloff;           //44
		float         rainDampener;          //48
		float         rainSize;              //4C
		float         displacementForce;     //50
		float         displacementVelocity;  //54
		float         displacementFalloff;   //58
		float         displacementDampener;  //5C
		float         displacementSize;      //60
	};
	static_assert(sizeof(WaterShaderData) == 0x64);
}
