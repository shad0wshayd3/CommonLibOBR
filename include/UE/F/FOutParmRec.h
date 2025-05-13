#pragma once

namespace UE
{
	class FProperty;

	class FOutParmRec
	{
	public:
		// members
		FProperty*    property;
		std::uint8_t* propAddr;
		FOutParmRec*  nextOutParm;
	};
	static_assert(sizeof(FOutParmRec) == 0x18);
}
