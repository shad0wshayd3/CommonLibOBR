#pragma once

#include "UE/E/EObjectFlags.h"
#include "UE/F/FFieldVariant.h"
#include "UE/F/FName.h"
#include "UE/T/TArray.h"

namespace UE
{
	class FArchive;
	class FFieldClass;
	class FProperty;
	class FReferenceCollector;
	class UObject;

	class FField
	{
	public:
		// add
		virtual ~FField();  // 00

		// add
		virtual void    Serialize(FArchive& a_archive);                          // 01
		virtual void    PostLoad();                                              // 02
		virtual void    GetPreloadDependencies(TArray<UObject*>& a_outDeps);     // 03
		virtual void    BeginDestroy();                                          // 04
		virtual void    AddReferencedObjects(FReferenceCollector& a_collector);  // 05
		virtual void    AddCppProperty(FProperty* a_property);                   // 06
		virtual void    Bind();                                                  // 07
		virtual void    PostDuplicate(const FField& a_field);                    // 08
		virtual FField* GetInnerFieldByName(const FName& a_name);                // 09
		virtual void    GetInnerFields(TArray<FField*>& a_fields);               // 10

		// members
		FFieldClass*  classPrivate;  // 08
		FFieldVariant owner;         // 10
		FField*       next;          // 18
		FName         namePrivate;   // 20
		EObjectFlags  flagsPrivate;  // 28
	};
	static_assert(sizeof(FField) == 0x30);
}
