#pragma once

#include "UE/E/ESearchCase.h"
#include "UE/T/TArray.h"

namespace UE
{
	class FString;

	inline wchar_t* GetData(FString& a_str);
	inline const wchar_t* GetData(const FString& a_str);
	inline std::int32_t GetNum(const FString& a_str);

	class FString
	{
	public:
		FString() = default;
		FString(FString&&) = default;
		FString(const FString&) = default;
		FString& operator=(FString&&) = default;
		FString& operator=(const FString&) = default;

		FString(const char* a_str)
		{
			using func_t = void (FString::*)(const char*);
			static REL::Relocation<func_t> func{ ID::FString::Ctor1 };
			func(this, a_str);
		}

		FString(const wchar_t* a_str)
		{
			using func_t = void (FString::*)(const wchar_t*);
			static REL::Relocation<func_t> func{ ID::FString::Ctor2 };
			func(this, a_str);
		}

	public:
		FString& Append(const char* a_str, std::int32_t a_length)
		{
			AppendChars(a_str, a_length);
			return *this;
		}

		FString& Append(const wchar_t* a_str, std::int32_t a_length)
		{
			AppendChars(a_str, a_length);
			return *this;
		}

		template <class T>
		FString& Append(T* a_str)
		{
			const auto length = std::char_traits<std::remove_const_t<T>>::length(a_str);
			AppendChars(a_str, static_cast<std::int32_t>(length));

			return *this;
		}

		FString& Append(FString&& a_str)
		{
			AppendChars(GetData(a_str), GetNum(a_str));
			return *this;
		}

		FString& AppendChar(wchar_t a_char)
		{
			using func_t = FString& (FString::*)(wchar_t);
			static REL::Relocation<func_t> func{ ID::FString::AppendChar };
			return func(this, a_char);
		}

		void AppendChars(const char* a_str, std::int32_t a_length)
		{
			using func_t = void (FString::*)(const char*, std::int32_t);
			static REL::Relocation<func_t> func{ ID::FString::AppendChars1 };
			return func(this, a_str, a_length);
		}

		void AppendChars(const wchar_t* a_str, std::int32_t a_length)
		{
			using func_t = void (FString::*)(const wchar_t*, std::int32_t);
			static REL::Relocation<func_t> func{ ID::FString::AppendChars2 };
			return func(this, a_str, a_length);
		}

		bool Equals(const FString& a_other, ESearchCase a_searchCase = ESearchCase::CaseSensitive) const
		{
			auto num = m_data.Num();
			auto numOther = a_other.m_data.Num();

			if (num != numOther)
				return num + numOther == 1;

			if (num > 1) {
				if (a_searchCase == ESearchCase::CaseSensitive)
					return std::wcscmp(m_data.GetData(), a_other.m_data.GetData()) == 0;
				else
					return _wcsicmp(m_data.GetData(), a_other.m_data.GetData()) == 0;
			}

			return true;
		}

		bool IsEmpty() const
		{
			return m_data.Num() <= 1;
		}

		std::int32_t Len() const
		{
			return m_data.Num() ? m_data.Num() - 1 : 0;
		}

		void Reset(std::int32_t a_newReservedSize = 0)
		{
			using func_t = void (FString::*)(std::int32_t);
			static REL::Relocation<func_t> func{ ID::FString::Reset };
			func(this, a_newReservedSize);
		}

	public:
		TArray<wchar_t>& GetCharArray()
		{
			return m_data;
		}

		const TArray<wchar_t>& GetCharArray() const
		{
			return m_data;
		}

		wchar_t* begin()
		{
			return m_data.begin();
		}

		const wchar_t* begin() const
		{
			return m_data.begin();
		}

		wchar_t* end()
		{
			auto result = m_data.end();
			return m_data.Num() ? --result : result;
		}

		const wchar_t* end() const
		{
			auto result = m_data.end();
			return m_data.Num() ? --result : result;
		}

	public:
		bool operator==(const FString& a_rhs) const
		{
			return Equals(a_rhs, ESearchCase::IgnoreCase);
		}

		bool operator!=(const FString& a_rhs) const
		{
			return !Equals(a_rhs, ESearchCase::IgnoreCase);
		}

		bool operator==(const wchar_t* a_rhs) const
		{
			return _wcsicmp(**this, a_rhs) == 0;
		}

		bool operator!=(const wchar_t* a_rhs) const
		{
			return _wcsicmp(**this, a_rhs) != 0;
		}

		friend bool operator==(const wchar_t* a_lhs, const FString& a_rhs)
		{
			return _wcsicmp(a_lhs, *a_rhs) == 0;
		}

		friend bool operator!=(const wchar_t* a_lhs, const FString& a_rhs)
		{
			return _wcsicmp(a_lhs, *a_rhs) != 0;
		}

		const wchar_t* operator*() const
		{
			return m_data.Num() ? m_data.GetData() : L"";
		}

		template <class T>
		FString& operator+=(T&& a_str)
		{
			return Append(std::forward<T>(a_str));
		}

	private:
		// members
		TArray<wchar_t> m_data;  // 00
	};
	static_assert(sizeof(FString) == 0x10);

	inline wchar_t* GetData(FString& a_str)
	{
		return a_str.GetCharArray().GetData();
	}

	inline const wchar_t* GetData(const FString& a_str)
	{
		return a_str.GetCharArray().GetData();
	}

	inline std::int32_t GetNum(const FString& a_str)
	{
		return a_str.Len();
	}
}

template <>
struct std::formatter<UE::FString, wchar_t> : formatter<const wchar_t*, wchar_t>
{
	template <class FormatContext>
	constexpr auto format(const UE::FString& a_str, FormatContext& a_ctx) const
	{
		return formatter<const wchar_t*, wchar_t>::format(*a_str, a_ctx);
	}
};

template <>
struct std::formatter<UE::FString, char> : formatter<std::string, char>
{
	template <class FormatContext>
	constexpr auto format(const UE::FString& a_str, FormatContext& a_ctx) const
	{
		const auto cvt = [&](char* a_dst, const std::size_t a_length) {
			return REX::W32::WideCharToMultiByte(
				REX::W32::CP_UTF8, 0, a_str.begin(), a_str.Len(), a_dst, static_cast<int>(a_length), nullptr, nullptr);
		};

		const auto len = cvt(nullptr, 0);
		if (len == 0) {
			return formatter<std::string, char>::format("", a_ctx);
		}

		std::string str(len, '\0');
		if (cvt(str.data(), str.length()) == 0) {
			return formatter<std::string, char>::format("", a_ctx);
		}

		return formatter<std::string, char>::format(str, a_ctx);
	}
};
