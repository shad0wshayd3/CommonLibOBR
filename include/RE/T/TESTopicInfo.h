#pragma once

#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TOPIC_INFO_DATA.h"

namespace RE
{
	class TESConversationData;

	class TESTopicInfo :
		public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESTopicInfo;
		inline static constexpr auto VTABLE = VTABLE::TESTopicInfo;
		inline static constexpr auto FORMTYPE = FormType::Info;

		// members
		TESCondition            conditions;        // 30
		std::uint16_t           index;             // 40
		bool                    saidOnce;          // 42
		TOPIC_INFO_DATA         data;              // 43
		BSSimpleList<TESTopic*> addTopics;         // 48
		TESConversationData*    conversationData;  // 58
		std::uint32_t           fileOffset;        // 60
	};
	static_assert(sizeof(TESTopicInfo) == 0x68);
}
