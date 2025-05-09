#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	template <class CharT>
	class BSStringT
	{
	private:
		static constexpr auto MAX{ static_cast<std::uint16_t>(-1) };

	public:
		using value_type = CharT;
		using traits_type = std::char_traits<value_type>;
		using size_type = std::uint16_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;

		BSStringT()
		{
			clear();
		}

		BSStringT(const BSStringT& a_rhs)
		{
			set_cstr(a_rhs.c_str());
		}

		BSStringT(BSStringT&& a_rhs) :
			_data(a_rhs._data),
			_size(a_rhs._size),
			_capacity(a_rhs._capacity)
		{
			a_rhs._data = nullptr;
			a_rhs._size = 0;
			a_rhs._capacity = 0;
		}

		BSStringT(const value_type* a_rhs)
		{
			set_cstr(a_rhs);
		}

		BSStringT(const std::string_view& a_rhs)
		{
			set_cstr(a_rhs.data(), a_rhs.size());
		}

		~BSStringT()
		{
			deallocate(_data);
			_data = nullptr;
		}

		BSStringT& operator=(const BSStringT& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				set_cstr(a_rhs.c_str());
			}
			return *this;
		}

		BSStringT& operator=(BSStringT&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				_data = a_rhs._data;
				a_rhs._data = nullptr;

				_size = a_rhs._size;
				a_rhs._size = 0;

				_capacity = a_rhs._capacity;
				a_rhs._capacity = 0;
			}
			return *this;
		}

		BSStringT& operator=(const_pointer a_rhs)
		{
			set_cstr(a_rhs);
			return *this;
		}

		BSStringT& operator=(const std::basic_string_view<value_type>& a_rhs)
		{
			set_cstr(a_rhs.data(), a_rhs.size());
			return *this;
		}

		[[nodiscard]] constexpr reference operator[](size_type a_pos) noexcept
		{
			assert(a_pos <= size());
			return data()[a_pos];
		}

		[[nodiscard]] constexpr const_reference operator[](size_type a_pos) const noexcept
		{
			assert(a_pos <= size());
			return data()[a_pos];
		}

		[[nodiscard]] constexpr reference       front() noexcept { return operator[](0); }
		[[nodiscard]] constexpr const_reference front() const noexcept { return operator[](0); }

		[[nodiscard]] constexpr reference       back() noexcept { return operator[](size() - 1); }
		[[nodiscard]] constexpr const_reference back() const noexcept { return operator[](size() - 1); }

		[[nodiscard]] constexpr pointer       data() noexcept { return _data ? _data : EMPTY; }
		[[nodiscard]] constexpr const_pointer data() const noexcept { return _data ? _data : EMPTY; }

		[[nodiscard]] constexpr const_pointer c_str() const noexcept { return data(); }

		[[nodiscard]] operator std::basic_string_view<value_type>() const noexcept { return { data(), size() }; }

		[[nodiscard]] constexpr bool empty() const noexcept { return size() == 0; }

		[[nodiscard]] constexpr size_type size() const noexcept { return _size != MAX ? _size : static_cast<size_type>(traits_type::length(data())); }

		[[nodiscard]] constexpr size_type length() const noexcept { return size(); }

		void clear() { set_cstr(EMPTY); }

		[[nodiscard]] inline friend bool operator==(const BSStringT& a_lhs, const value_type* a_rhs) { return (a_lhs._data == a_rhs || stricmp(a_lhs._data, a_rhs) == 0); }
		[[nodiscard]] inline friend bool operator!=(const BSStringT& a_lhs, const value_type* a_rhs) { return !(a_lhs == a_rhs); }
		[[nodiscard]] inline friend bool operator==(const value_type* a_lhs, const BSStringT& a_rhs) { return a_rhs == a_lhs; }
		[[nodiscard]] inline friend bool operator!=(const value_type* a_lhs, const BSStringT& a_rhs) { return !(a_lhs == a_rhs); }
		[[nodiscard]] inline friend bool operator==(const BSStringT& a_lhs, const BSStringT& a_rhs) { return a_lhs == a_rhs.c_str(); }
		[[nodiscard]] inline friend bool operator!=(const BSStringT& a_lhs, const BSStringT& a_rhs) { return !(a_lhs == a_rhs); }
		[[nodiscard]] inline friend bool operator==(const BSStringT& a_lhs, const std::string_view& a_rhs) { return a_lhs._data == a_rhs.data() || strnicmp(a_lhs._data, a_rhs.data(), a_rhs.size()); }
		[[nodiscard]] inline friend bool operator!=(const BSStringT& a_lhs, const std::string_view& a_rhs) { return !(a_lhs == a_rhs); }
		[[nodiscard]] inline friend bool operator==(const std::string_view& a_lhs, const BSStringT& a_rhs) { return a_rhs == a_lhs; }
		[[nodiscard]] inline friend bool operator!=(const std::string_view& a_lhs, const BSStringT& a_rhs) { return !(a_lhs == a_rhs); }

		TES_HEAP_REDEFINE_NEW();

	private:
		[[nodiscard]] static int stricmp(const char* a_lhs, const char* a_rhs) { return _stricmp(a_lhs, a_rhs); }

		[[nodiscard]] static int stricmp(const wchar_t* a_lhs, const wchar_t* a_rhs) { return _wcsicmp(a_lhs, a_rhs); }

		[[nodiscard]] static int strnicmp(const char* a_lhs, const char* a_rhs, std::size_t len) { return _strnicmp(a_lhs, a_rhs, len); }

		[[nodiscard]] static int strnicmp(const wchar_t* a_lhs, const wchar_t* a_rhs, std::size_t len) { return _wcsnicmp(a_lhs, a_rhs, len); }

		[[nodiscard]] pointer allocate(size_type a_num)
		{
			if (a_num > MAX) {
				return 0;
			}

			auto size = a_num * sizeof(value_type);
			auto mem = malloc<value_type>(size);
			std::memset(mem, 0, size);
			return mem;
		}

		void deallocate(pointer a_ptr) { free(a_ptr); }

		bool set_cstr(const_pointer a_str, size_type a_len = 0)
		{
			auto len = static_cast<size_type>(a_len);
			if (_data == a_str) {
				return true;
			}

			if (len == 0) {
				len = static_cast<size_type>(traits_type::length(a_str));
			}

			const size_type newSize = len > MAX ? MAX : len;
			++len;
			const size_type newCap = len > MAX ? MAX : len;

			if (len <= _capacity) {
				traits_type::copy(_data, a_str, len);
				_size = newSize;
				return true;
			}

			const auto newData = allocate(len);
			if (!newData) {
				return false;
			}

			traits_type::copy(newData, a_str, len);
			if (_data) {
				deallocate(_data);
			}

			_data = newData;
			_size = newSize;
			_capacity = newCap;
			return true;
		}

		static constexpr value_type EMPTY[]{ 0 };

		// members
		pointer       _data{ nullptr };  // 00
		size_type     _size{ 0 };        // 08
		size_type     _capacity{ 0 };    // 0A
		std::uint32_t _pad0C{ 0 };       // 0C
	};

	using BSString = BSStringT<char>;
	static_assert(sizeof(BSString) == 0x10);

	using BSStringC = BSStringT<char>;
	static_assert(sizeof(BSStringC) == 0x10);

	using BSStringW = BSStringT<wchar_t>;
	static_assert(sizeof(BSStringW) == 0x10);
}
