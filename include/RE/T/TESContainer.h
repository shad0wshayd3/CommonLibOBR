#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/B/BSTList.h"

namespace RE
{
	class ContainerObject;

	class TESContainer :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESContainer;
		inline static constexpr auto VTABLE = VTABLE::TESContainer;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void ClearDataComponent() override;                        // 01
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// members
		std::uint8_t                   contFlag;    // 08
		BSSimpleList<ContainerObject*> objectList;  // 10
	};
	static_assert(sizeof(TESContainer) == 0x20);
}
