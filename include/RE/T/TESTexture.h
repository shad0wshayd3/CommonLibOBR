#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESTexture :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESTexture;
		inline static constexpr auto VTABLE = VTABLE::TESTexture;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// add
		virtual ~TESTexture();                                      // 04
		virtual const char* GetAsNormalFile(BSString& a_fileName);  // 05
		virtual char*       GetDefaultPath();                       // 06

		// members
		BSString textureName;  // 08
	};
	static_assert(sizeof(TESTexture) == 0x18);
}
