#pragma once

#include "UE/F/FNameEntryId.h"
#include "UE/F/FNamePool.h"
#include "UE/F/FString.h"

namespace UE
{
	class FNameEntry;

	enum class EFindName
	{
		Find,
		Add
	};

	class FName
	{
	public:
		FName(const char* a_name, EFindName a_type = EFindName::Add)
		{
			using func_t = void (FName::*)(const char*, EFindName);
			static REL::Relocation<func_t> func{ ID::FName::Ctor1 };
			func(this, a_name, a_type);
		}

		bool IsNone() const
		{
			return ToUnstableInt() == 0;
		}

		FString ToString() const
		{
			FString str;
			ToString(str);
			return str;
		}

		void ToString(FString& a_str) const
		{
			using func_t = void (FName::*)(FString&) const;
			static REL::Relocation<func_t> func{ ID::FName::ToString };
			func(this, a_str);
		}

		std::uint64_t ToUnstableInt() const
		{
			std::uint64_t result = 0;
			FMemory::Memcpy(&result, this, sizeof(std::uint64_t));
			return result;
		}

		bool operator==(FName a_rhs) const
		{
			return ToUnstableInt() == a_rhs.ToUnstableInt();
		}

		bool operator!=(FName a_rhs) const
		{
			return !(*this == a_rhs);
		}

		// members
		FNameEntryId  comparisonIndex;  // 00
		std::uint32_t number;           // 04
	};
	static_assert(sizeof(FName) == 0x08);
}

template <>
struct std::formatter<UE::FName, wchar_t> : formatter<UE::FString, wchar_t>
{
	template <class FormatContext>
	constexpr auto format(const UE::FName& a_name, FormatContext& a_ctx) const
	{
		return formatter<UE::FString, wchar_t>::format(a_name.ToString(), a_ctx);
	}
};

template <>
struct std::formatter<UE::FName, char> : formatter<UE::FString, char>
{
	template <class FormatContext>
	constexpr auto format(const UE::FName& a_name, FormatContext& a_ctx) const
	{
		return formatter<UE::FString, char>::format(a_name.ToString(), a_ctx);
	}
};
