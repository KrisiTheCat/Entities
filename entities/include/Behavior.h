#pragma once

#include <set>

#include "Entity.h"
#include "Attack.h"
#include "ChaseState.h"
#include "Presenter.h"
#include "defines.h"

class Behavior
{
public:
	Behavior();
	~Behavior();

	void init(BEHAVIOR_TYPE type, Entity* entity, Unit* reamor);
	void update();
	void startChasing(int id);

private:
	int m_id;
	Entity* m_entity;
	MOVING_STATE m_movingState;
	ATTACKING_STATE m_attackingState;
	ChaseState m_chaseState;
	Attack m_attackState;
	int2 m_moveDest;
	bool m_isMoving = false;
};