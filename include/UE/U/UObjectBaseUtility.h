#pragma once

#include "UE/E/EObjectFullNameFlags.h"
#include "UE/T/TStringBuilder.h"
#include "UE/U/UObjectBase.h"

namespace UE
{
	class UObjectBaseUtility :
		public UObjectBase
	{
	public:
		// override
		virtual ~UObjectBaseUtility();  // 00

		// add
		virtual bool CanBeClusterRoot() = 0;              // 04
		virtual bool CanBeInCluster() = 0;                // 05
		virtual void CreateCluster() = 0;                 // 06
		virtual void OnClusterMarkedAsPendingKill() = 0;  // 07

		FString GetFullName(const UObject* a_stopOuter = nullptr, EObjectFullNameFlags a_flags = EObjectFullNameFlags::None) const
		{
			using func_t = FString (UObjectBaseUtility::*)(const UObject*, EObjectFullNameFlags) const;
			static REL::Relocation<func_t> func{ ID::UObjectBaseUtility::GetFullName1 };
			return func(this, a_stopOuter, a_flags);
		}

		void GetFullName(const UObject* a_stopOuter, FString& a_str, EObjectFullNameFlags a_flags = EObjectFullNameFlags::None) const
		{
			using func_t = void (UObjectBaseUtility::*)(const UObject*, FString&, EObjectFullNameFlags) const;
			static REL::Relocation<func_t> func{ ID::UObjectBaseUtility::GetFullName2 };
			func(this, a_stopOuter, a_str, a_flags);
		}

		FString GetName() const
		{
			return GetFName().ToString();
		}
	};
	static_assert(sizeof(UObjectBaseUtility) == 0x28);
}
