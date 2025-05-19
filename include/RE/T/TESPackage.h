#pragma once

#include "RE/P/PACKAGE_DATA.h"
#include "RE/P/PACKAGE_PROCEDURE_TYPE.h"
#include "RE/P/PackageSchedule.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class PackageLocation;
	class PackageTarget;

	class TESPackage :
		public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESPackage;
		inline static constexpr auto VTABLE = VTABLE::TESPackage;
		inline static constexpr auto FORMTYPE = FormType::Package;

		// members
		PACKAGE_PROCEDURE_TYPE procedureType;   // 30
		PACKAGE_DATA           packData;        // 34
		PackageLocation*       packLocation;    // 40
		PackageTarget*         packTarget;      // 48
		PackageSchedule        packSchedule;    // 50
		TESCondition           packConditions;  // 58
	};
	static_assert(sizeof(TESPackage) == 0x68);
}
