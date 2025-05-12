#pragma once

#include "UE/T/TVector.h"

namespace UE
{
	class AActor;
	class FNavAgentProperties;
	class IPathFollowingAgentInterface;
	class UObject;

	class INavAgentInterface
	{
	public:
		virtual ~INavAgentInterface();  // 00

		virtual UObject*                      _GetUObject();                                                                                                                                        // 01
		virtual const FNavAgentProperties&    GetNavAgentPropertiesRef() const;                                                                                                                     // 02
		virtual FVector                       GetNavAgentLocation() const;                                                                                                                          // 03
		virtual FVector                       GetMoveGoalOffset(const AActor* a_actor) const;                                                                                                       // 04
		virtual void                          GetMoveGoalReachTest(const AActor* a_actor, const FVector& a_moveOffset, FVector& a_goalOffset, float& a_goalRadius, float& a_goalHalfHeight) const;  // 05
		virtual bool                          ShouldPostponePathUpdates() const;                                                                                                                    // 06
		virtual bool                          IsFollowingAPath() const;                                                                                                                             // 07
		virtual IPathFollowingAgentInterface* GetPathFollowingAgent() const;                                                                                                                        // 08
	};
}
