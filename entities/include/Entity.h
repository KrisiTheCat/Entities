#pragma once

#include <set>
#include "Unit.h"
#include "Presenter.h"
#include "defines.h"

class Entity : public Unit
{
public:
	Entity();
	~Entity();

	void updateEntity();
	void move(int2 a);
	void startChasing(int type, Unit* target);

	set<pair<int, Unit*>> m_chaseTargets;
	vector<Unit*> m_attackTargets;
private:
	int2 m_moveDest;
	bool m_isMoving;
};