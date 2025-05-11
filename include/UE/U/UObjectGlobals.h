#pragma once

#include "UE/E/EInternalObjectFlags.h"
#include "UE/E/EObjectFlags.h"
#include "UE/F/FName.h"

namespace UE
{
	class UClass;
	class UObject;

	inline UObject* StaticFindObject(UClass* a_class, UObject* a_outer, const wchar_t* a_name, bool a_exactClass = false)
	{
		using func_t = UObject* (*)(UClass*, UObject*, const wchar_t*, bool);
		static REL::Relocation<func_t> func{ ID::StaticFindObject };
		return func(a_class, a_outer, a_name, a_exactClass);
	}

	template <class T>
	inline T* StaticFindObject(UClass* a_class, UObject* a_outer, const wchar_t* a_name, bool a_exactClass = false)
	{
		return static_cast<T*>(StaticFindObject(a_class, a_outer, a_name, a_exactClass));
	}

	inline UObject* StaticFindObjectFast(UClass* a_class, UObject* a_outer, FName a_name, bool a_exactClass = false, EObjectFlags a_exclusiveFlags = EObjectFlags::NoFlags, EInternalObjectFlags a_exclusiveInternalFlags = EInternalObjectFlags::None)
	{
		using func_t = UObject* (*)(UClass*, UObject*, FName, bool, EObjectFlags, EInternalObjectFlags);
		static REL::Relocation<func_t> func{ ID::StaticFindObjectFast };
		return func(a_class, a_outer, a_name, a_exactClass, a_exclusiveFlags, a_exclusiveInternalFlags);
	}

	template <class T>
	inline T* StaticFindObjectFast(UClass* a_class, UObject* a_outer, FName a_name, bool a_exactClass = false, EObjectFlags a_exclusiveFlags = EObjectFlags::NoFlags, EInternalObjectFlags a_exclusiveInternalFlags = EInternalObjectFlags::None)
	{
		return static_cast<T*>(StaticFindObjectFast(a_class, a_outer, a_name, a_exactClass, a_exclusiveFlags, a_exclusiveInternalFlags));
	}

	inline UObject* StaticFindObjectFastSafe(UClass* a_class, UObject* a_outer, FName a_name, bool a_exactClass = false, EObjectFlags a_exclusiveFlags = EObjectFlags::NoFlags, EInternalObjectFlags a_exclusiveInternalFlags = EInternalObjectFlags::None)
	{
		using func_t = UObject* (*)(UClass*, UObject*, FName, bool, EObjectFlags, EInternalObjectFlags);
		static REL::Relocation<func_t> func{ ID::StaticFindObjectFastSafe };
		return func(a_class, a_outer, a_name, a_exactClass, a_exclusiveFlags, a_exclusiveInternalFlags);
	}

	template <class T>
	inline T* StaticFindObjectFastSafe(UClass* a_class, UObject* a_outer, FName a_name, bool a_exactClass = false, EObjectFlags a_exclusiveFlags = EObjectFlags::NoFlags, EInternalObjectFlags a_exclusiveInternalFlags = EInternalObjectFlags::None)
	{
		return static_cast<T*>(StaticFindObjectFastSafe(a_class, a_outer, a_name, a_exactClass, a_exclusiveFlags, a_exclusiveInternalFlags));
	}

	inline UObject* StaticFindObjectSafe(UClass* a_class, UObject* a_outer, const wchar_t* a_name, bool a_exactClass = false)
	{
		using func_t = UObject* (*)(UClass*, UObject*, const wchar_t*, bool);
		static REL::Relocation<func_t> func{ ID::StaticFindObjectSafe };
		return func(a_class, a_outer, a_name, a_exactClass);
	}

	template <class T>
	inline T* StaticFindObjectSafe(UClass* a_class, UObject* a_outer, const wchar_t* a_name, bool a_exactClass = false)
	{
		return static_cast<T*>(StaticFindObjectSafe(a_class, a_outer, a_name, a_exactClass));
	}

	template <class T>
	inline T* FindObject(UObject* a_outer, const wchar_t* a_name, bool a_exactClass = false)
	{
		return StaticFindObject<T>(FindClass<T>(), a_outer, a_name, a_exactClass);
	}

	template <class T>
	inline T* FindObject(const wchar_t* a_name, bool a_exactClass = false)
	{
		return StaticFindObject<T>(FindClass<T>(), nullptr, a_name, a_exactClass);
	}

	template <class T>
	inline T* FindObjectFast(UObject* a_outer, FName a_name, bool a_exactClass = false, EObjectFlags a_exclusiveFlags = EObjectFlags::NoFlags)
	{
		return StaticFindObjectFast<T>(FindClass<T>(), a_outer, a_name, a_exactClass, a_exclusiveFlags);
	}

	template <class T>
	inline T* FindObjectFastSafe(UObject* a_outer, FName a_name, bool a_exactClass = false, EObjectFlags a_exclusiveFlags = EObjectFlags::NoFlags, EInternalObjectFlags a_exclusiveInternalFlags = EInternalObjectFlags::None)
	{
		return StaticFindObjectFastSafe<T>(FindClassSafe<T>(), a_outer, a_name, a_exactClass, a_exclusiveFlags, a_exclusiveInternalFlags);
	}

	template <class T>
	inline T* FindObjectSafe(UObject* a_outer, const wchar_t* a_name, bool a_exactClass = false)
	{
		return StaticFindObjectSafe<T>(FindClassSafe<T>(), a_outer, a_name, a_exactClass);
	}

	template <class T>
	inline T* FindObjectSafe(const wchar_t* a_name, bool a_exactClass = false)
	{
		return StaticFindObjectSafe<T>(FindClassSafe<T>(), nullptr, a_name, a_exactClass);
	}

	template <class T>
	UClass* FindClass()
	{
		static UClass* ptr{ nullptr };
		if (!ptr)
			ptr = StaticFindObject<UClass>(nullptr, nullptr, T::UE_CLASS);

		return ptr;
	}

	template <class T>
	UClass* FindClassSafe()
	{
		static UClass* ptr{ nullptr };
		if (!ptr)
			ptr = StaticFindObjectSafe<UClass>(nullptr, nullptr, T::UE_CLASS);

		return ptr;
	}
}
