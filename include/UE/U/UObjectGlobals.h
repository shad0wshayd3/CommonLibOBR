#pragma once

#include "UE/E/EClassCastFlags.h"
#include "UE/E/EInternalObjectFlags.h"
#include "UE/E/EObjectFlags.h"
#include "UE/F/FName.h"

namespace UE
{
	class UClass;
	class UObject;

	inline UObject* StaticFindObjectFast(UClass* a_class, UObject* a_outer, FName a_name, bool a_exactClass = false, EObjectFlags a_exclusiveFlags = EObjectFlags::NoFlags, EInternalObjectFlags a_exclusiveInternalFlags = EInternalObjectFlags::None)
	{
		using func_t = UObject* (*)(UClass*, UObject*, FName, bool, EObjectFlags, EInternalObjectFlags);
		static REL::Relocation<func_t> func{ ID::StaticFindObjectFast };
		return func(a_class, a_outer, a_name, a_exactClass, a_exclusiveFlags, a_exclusiveInternalFlags);
	}

	inline UObject* StaticFindObject(UClass* a_class, UObject* a_objectPackage, const wchar_t* a_name, bool a_exactClass)
	{
		using func_t = UObject* (*)(UClass*, UObject*, const wchar_t*, bool);
		static REL::Relocation<func_t> func{ ID::StaticFindObject };
		return func(a_class, a_objectPackage, a_name, a_exactClass);
	}


	UObject* FindObjectFast(FName a_name, EClassCastFlags a_type);
	UObject* FindObject(FName a_name, EClassCastFlags a_type);

	template <class T>
	inline T* FindObjectFast(FName a_name, EClassCastFlags a_type)
	{
		return (T*)FindObjectFast(a_name, a_type);
	}

	template <class T>
	inline T* FindObject(FName a_name, EClassCastFlags a_type)
	{
		return (T*)FindObject(a_name, a_type);
	}

	template <class T>
	inline T* FindObjectFast(UObject* a_outer, FName a_name, bool a_exactClass = false, EObjectFlags a_exclusiveFlags = EObjectFlags::NoFlags)
	{
		return (T*)StaticFindObjectFast(T::StaticClass(), a_outer, a_name, a_exactClass, a_exclusiveFlags);
	}

	template <class T>
	inline T* FindObject(UObject* a_outer, const wchar_t* a_name, bool a_exactClass = false)
	{
		return (T*)StaticFindObject(T::StaticClass(), a_outer, a_name, a_exactClass);
	}
}
