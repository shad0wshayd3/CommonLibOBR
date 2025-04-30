#pragma once

namespace RE
{
	inline void* malloc(std::size_t a_size)
	{
		using func_t = decltype(&malloc);
		static REL::Relocation<func_t> func{ ID::malloc };
		return func(a_size);
	}

	template <class T>
	inline T* malloc(std::size_t a_size)
	{
		return static_cast<T*>(malloc(a_size));
	}

	template <class T>
	inline T* malloc()
	{
		return malloc<T>(sizeof(T));
	}

	inline void* calloc(std::size_t a_num, std::size_t a_size)
	{
		const auto ret = malloc(a_num * a_size);
		if (ret) {
			std::memset(ret, 0, a_num * a_size);
		}
		return ret;
	}

	template <class T>
	inline T* calloc(std::size_t a_num, std::size_t a_size)
	{
		return static_cast<T*>(calloc(a_num, a_size));
	}

	template <class T>
	inline T* calloc(std::size_t a_num)
	{
		return calloc<T>(a_num, sizeof(T));
	}

	inline void free(void* a_ptr)
	{
		if (a_ptr) {
			using func_t = decltype(&free);
			static REL::Relocation<func_t> func{ ID::free };
			func(a_ptr);
		}
	}
}

#define TES_HEAP_REDEFINE_NEW()                                                                                         \
	[[nodiscard]] inline void* operator new(std::size_t a_count)                                                        \
	{                                                                                                                   \
		const auto mem = RE::malloc(a_count);                                                                           \
		if (mem) {                                                                                                      \
			return mem;                                                                                                 \
		} else {                                                                                                        \
			stl::report_and_fail("out of memory"sv);                                                                    \
		}                                                                                                               \
	}                                                                                                                   \
                                                                                                                        \
	[[nodiscard]] inline void* operator new[](std::size_t a_count)                                                      \
	{                                                                                                                   \
		const auto mem = RE::malloc(a_count);                                                                           \
		if (mem) {                                                                                                      \
			return mem;                                                                                                 \
		} else {                                                                                                        \
			stl::report_and_fail("out of memory"sv);                                                                    \
		}                                                                                                               \
	}                                                                                                                   \
                                                                                                                        \
	[[nodiscard]] constexpr void* operator new(std::size_t, void* a_ptr) noexcept { return a_ptr; }                     \
	[[nodiscard]] constexpr void* operator new[](std::size_t, void* a_ptr) noexcept { return a_ptr; }                   \
	[[nodiscard]] constexpr void* operator new(std::size_t, std::align_val_t, void* a_ptr) noexcept { return a_ptr; }   \
	[[nodiscard]] constexpr void* operator new[](std::size_t, std::align_val_t, void* a_ptr) noexcept { return a_ptr; } \
                                                                                                                        \
	inline void operator delete(void* a_ptr) { RE::free(a_ptr); }                                                       \
	inline void operator delete[](void* a_ptr) { RE::free(a_ptr); }                                                     \
	inline void operator delete(void* a_ptr, std::size_t) { RE::free(a_ptr); }                                          \
	inline void operator delete[](void* a_ptr, std::size_t) { RE::free(a_ptr); }
