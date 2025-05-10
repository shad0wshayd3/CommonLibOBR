#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class TESObjectSTAT :
		public TESBoundObject,
		public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESObjectSTAT;
		inline static constexpr auto VTABLE = VTABLE::TESObjectSTAT;
		inline static constexpr auto FORMTYPE = FormType::Static;

		// override (TESForm)
		virtual ~TESObjectSTAT() override;                   // 04
		virtual bool Load(TESFile* a_file) override;         // 07
		virtual void Save() override;                        // 09
		virtual void Copy(TESForm* a_srcForm) override;      // 2D
		virtual bool Compare(TESForm* a_copyForm) override;  // 2E
	};
	static_assert(sizeof(TESObjectSTAT) == 0x78);
}
