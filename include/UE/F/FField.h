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
		virtual ~FField();

		// add
		virtual void    Serialize(FArchive& a_archive);
		virtual void    PostLoad();
		virtual void    GetPreloadDependencies(TArray<UObject*>& a_outDeps);
		virtual void    BeginDestroy();
		virtual void    AddReferencedObjects(FReferenceCollector& a_collector);
		virtual void    AddCppProperty(FProperty* a_property);
		virtual void    Bind();
		virtual void    PostDuplicate(const FField& a_field);
		virtual FField* GetInnerFieldByName(const FName& a_name);
		virtual void    GetInnerFields(TArray<FField*>& a_fields);

		// members
		FFieldClass*  classPrivate;
		FFieldVariant owner;
		FField*       next;
		FName         namePrivate;
		EObjectFlags  flagsPrivate;
	};
	static_assert(sizeof(FField) == 0x30);
}
