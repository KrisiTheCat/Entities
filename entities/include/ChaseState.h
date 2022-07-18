#pragma once
#include <set>
#include "defines.h"
#include "Entity.h"

class ChaseState
{
public:
	ChaseState();
	~ChaseState();

	void init(Entity* m_entity);
	void update();
	void startChasing(int type, Unit* target);

private:
	int m_id;
	Entity* m_entity;
	set<pair<int, Unit*>> m_chaseTarget;
};