#pragma once

#include "UE/E/EClassCastFlags.h"
#include "UE/U/UStruct.h"

namespace UE
{
	class FObjectInitializer;
	class FVTableHelper;

	enum class EIncludeSuperFlag : std::int32_t
	{
		ExcludeSuper,
		IncludeSuper
	};

	class UClass :
		public UStruct
	{
	public:
		// override
		virtual ~UClass();

		// add
		virtual UClass*       GetAuthoritativeClass();                                                                                                                                 // 6C
		virtual void          PostInitInstance(UObject* a_object, FObjectInstancingGraph* a_instanceGraph);                                                                            // 6D
		virtual void          PostLoadInstance(UObject* a_object);                                                                                                                     // 6F
		virtual void          InitPropertiesFromCustomList(std::uint8_t* a_dataPtr, const std::uint8_t* a_defaultDataPtr);                                                             // 70
		virtual void          SetupObjectInitializer(FObjectInitializer& a_objectInitializer) const;                                                                                   // 71
		virtual bool          CanCreateAssetOfClass() const;                                                                                                                           // 72
		virtual std::uint8_t* GetPersistentUberGraphFrame(UObject* a_object, UFunction* a_funcToCheck) const;                                                                          // 73
		virtual void          CreatePersistentUberGraphFrame(UObject* a_object, bool a_createOnlyIfEmpty = false, bool a_skipSuperClass = false, UClass* a_oldClass = nullptr) const;  // 74
		virtual void          DestroyPersistentUberGraphFrame(UObject* a_object, bool a_skipSuperClass = false) const;                                                                 // 75
		virtual void          SerializeDefaultObject(UObject* a_object, FStructuredArchive::FSlot a_slot);                                                                             // 76
		virtual void          SerializeDefaultObject(UObject* a_object, FArchive& a_archive);                                                                                          // 77
		virtual void          PostLoadDefaultObject(UObject* a_object);                                                                                                                // 78
		virtual void          PurgeClass(bool a_recompilingOnLoad);                                                                                                                    // 79
		virtual bool          IsFunctionImplementedInScript(FName a_name) const;                                                                                                       // 7A
		virtual bool          HasProperty(FProperty* a_property) const;                                                                                                                // 7B
		virtual UObject*      FindArchetype(const UClass* a_class, const FName a_name) const;                                                                                          // 7C
		virtual UObject*      GetArchetypeForCDO() const;                                                                                                                              // 7D
		virtual void          GetDefaultObjectPreloadDependencies(TArray<UObject*>& a_deps);                                                                                           // 7E
		virtual UObject*      CreateDefaultObject();                                                                                                                                   // 7F

		UFunction* FindFunctionByName(FName a_name, EIncludeSuperFlag a_includeSuper = EIncludeSuperFlag::IncludeSuper) const
		{
			using func_t = UFunction* (UClass::*)(FName, EIncludeSuperFlag) const;
			static REL::Relocation<func_t> func{ ID::UClass::FindFunctionByName };
			return func(this, a_name, a_includeSuper);
		}

		bool HasAnyCastFlag(EClassCastFlags a_flag) const
		{
			return !!(classCastFlags & a_flag);
		}

		bool HasAllCastFlags(EClassCastFlags a_flag) const
		{
			return (classCastFlags & a_flag) == a_flag;
		}

		// memebers
		std::byte       unk[0x28];
		EClassCastFlags classCastFlags;
	};
}
