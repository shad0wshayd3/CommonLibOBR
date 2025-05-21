#pragma once

namespace UE
{
	class VPairingEntry;
}

namespace RE
{
	class IVPairableItem
	{
	public:
		inline static constexpr auto RTTI = RTTI::IVPairableItem;
		inline static constexpr auto VTABLE = VTABLE::IVPairableItem;

		// add
		virtual bool ShouldBePaired();     // 00
		virtual void ProcessPairItem();    // 01
		virtual void ProcessUnpairItem();  // 02
		virtual void OnPrePairItem();      // 03
		virtual void OnPostPairItem();     // 04
		virtual void OnPreUnpairItem();    // 05
		virtual void OnPostUnpairItem();   // 06

		// members
		bool               isActuallyPaired;  // 08
		UE::VPairingEntry* pairingEntry;      // 10
	};
	static_assert(sizeof(IVPairableItem) == 0x18);
}
