#pragma once
#include "AIComponent.h"

class cAIAggressiveComponent : public cAIComponent {
	typedef cAIComponent super;
protected:
	enum MState{ATTACKING, IDLE, CHASING, ESCAPING} m_EMState;
	cEntity * m_Target;
public:
	cAIAggressiveComponent(cMonster * a_Monster) : cAIComponent(a_Monster), m_Target(NULL){}

	virtual void Tick(float a_Dt, cChunk & a_Chunk) override;
	virtual void InStateChasing(float a_Dt);
	
	virtual void Attack(float a_Dt);

protected:
	virtual void CheckEventLostPlayer(void);
	virtual void CheckEventSeePlayer(void);
	virtual void EventLosePlayer(void);
	virtual void EventSeePlayer(cEntity *);
	
	bool IsMovingToTargetPosition();
	bool ReachedFinalDestination();
};