#pragma once

namespace UE::SharedPointerInternals
{
	template <std::size_t N>
	class TReferenceControllerBase;

	template <std::size_t N>
	class FSharedReferencer
	{
	public:
		// members
		TReferenceControllerBase<N>* referenceController;  // 00
	};
	static_assert(sizeof(FSharedReferencer<1>) == 0x08);
}
