#pragma once

namespace UE::VPairingData
{
	enum class EDataUnits : std::int32_t
	{
		Original = 0,
		Host = 1,
	};

	class IPairingData
	{
	public:
		// add
		virtual ~IPairingData();  // 00

		// members
		EDataUnits currentDataUnits;  // 08
	};
	static_assert(sizeof(IPairingData) == 0x10);
}
