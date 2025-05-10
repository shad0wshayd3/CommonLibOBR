#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESTextureList.h"

namespace RE
{
	class TESModel :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESModel;
		inline static constexpr auto VTABLE = VTABLE::TESModel;

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;                   // 00
		virtual void ClearDataComponent() override;                        // 01
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;     // 02
		virtual bool CompareComponent(BaseFormComponent* a_rhs) override;  // 03

		// add
		virtual ~TESModel();                                // 04
		virtual const char* GetModel();                     // 05
		virtual void        SetModel(const char* a_model);  // 06

		// members
		BSString       model;        // 08
		float          boundSize;    // 18
		TESTextureList textureList;  // 20
	};
	static_assert(sizeof(TESModel) == 0x30);
}
