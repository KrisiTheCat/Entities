#pragma once

#include <set>

#include "Entity.h"
#include "MovingState.h"
#include "AttackingState.h"
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

	MovingContext* m_movingState;
	AttackingContext* m_attackingState;

	int2 m_moveDest;
	bool m_isMoving = false;
};