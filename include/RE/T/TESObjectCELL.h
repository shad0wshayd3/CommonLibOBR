#pragma once

#include "RE/B/BSTList.h"
#include "RE/E/ExtraDataList.h"
#include "RE/I/IVPairableItem.h"
#include "RE/N/NiPointer.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESMemContextForm.h"

namespace RE
{
	class NiNode;
	class TESObjectLAND;
	class TESObjectREFR;
	class TESPathGrid;
	class TESWorldSpace;

	class TESObjectCELL :
		public TESForm,
		public TESFullName,
		public IVPairableItem,
		public TESMemContextForm
	{
	private:
		union union_t
		{
			TESWorldSpace* worldSpace;
			std::uint32_t  tempDataOffset;
		};

	public:
		inline static constexpr auto RTTI = RTTI::TESObjectCELL;
		inline static constexpr auto VTABLE = VTABLE::TESObjectCELL;
		inline static constexpr auto FORMTYPE = FormType::Cell;

		// override (TESForm)
		virtual ~TESObjectCELL() override;                                                                                        // 04
		virtual void          ClearData() override;                                                                               // 06
		virtual bool          Load(TESFile* a_file) override;                                                                     // 07
		virtual bool          Save(TESFile* a_file) override;                                                                     // 08
		virtual void          Save() override;                                                                                    // 09
		virtual bool          SaveEdit(TESFile* a_file) override;                                                                 // 0B
		virtual bool          SavesBefore(FORM* a_group) override;                                                                // 0C
		virtual bool          SavesBefore(TESForm* a_form) override;                                                              // 0D
		virtual TESForm*      CreateDuplicateForm(bool a_createEditorID, NiTPointerMap<TESForm*, TESForm*>* a_copyMap) override;  // 0E
		virtual std::uint16_t GetSaveSize(std::uint32_t a_changeFlags) override;                                                  // 13
		virtual void          SaveGame(std::uint32_t a_changeFlags) override;                                                     // 14
		virtual void          LoadGame(std::uint32_t a_flags, std::uint32_t a_currentFlags) override;                             // 15
		virtual void          InitLoadGame(std::uint32_t a_flags, std::uint32_t a_oldFlags) override;                             // 16
		virtual void          Revert(std::uint32_t a_flags) override;                                                             // 18
		virtual bool          FindInFileFast(TESFile* a_file) override;                                                           // 1A
		virtual void          InitItem() override;                                                                                // 1B
		virtual bool          GetQuestObject() override;                                                                          // 1E
		virtual void          SetAltered(bool a_set) override;                                                                    // 24
		virtual void          Copy(TESForm* a_srcForm) override;                                                                  // 2D
		virtual bool          Compare(TESForm* a_copyForm) override;                                                              // 2E
		virtual bool          BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly) override;                // 2F
		virtual void          CreateGroupData(FORM* a_form, FORM_GROUP* a_group) override;                                        // 30
		virtual bool          IsFormTypeChild(FormType a_type) override;                                                          // 32
		virtual const char*   GetFormEditorID() override;                                                                         // 35
		virtual bool          SetFormEditorID(const char* a_editorID) override;                                                   // 36

		// override (IVPairableItem)
		virtual bool ShouldBePaired() override;     // 00
		virtual void ProcessPairItem() override;    // 01
		virtual void ProcessUnpairItem() override;  // 02

		// members
		bool                         cellFullyPaired;               // 60
		BSSimpleList<TESObjectREFR*> prePlacedActorStillNotPaired;  // 68
		bool                         isUnpairedBecauseOfCache;      // 78
		std::uint8_t                 cellFlags;                     // 79
		std::uint8_t                 cellGameFlags;                 // 7A
		std::uint8_t                 cellState;                     // 7B
		ExtraDataList                extraData;                     // 80
		void*                        cellData;                      // A0
		TESObjectLAND*               cellLand;                      // A8
		TESPathGrid*                 cellGrid;                      // B0
		BSSimpleList<TESObjectREFR*> listReferences;                // B8
		union_t                      data;                          // C8
		NiPointer<NiNode>            cell3D;                        // D0
	};
	static_assert(sizeof(TESObjectCELL) == 0xD8);
}
