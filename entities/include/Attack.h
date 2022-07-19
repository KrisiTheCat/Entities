#pragma once
#include "set"

#include "defines.h"
#include "Entity.h"

class Attack
{
public:
	Attack();
	~Attack();

	void init(Entity* entity);
	void update();
	void startAttacking(Unit* target);

private:
	int m_frameId = 0;
	int m_framesToShoot = 100;
	Entity* m_entity;
	vector<Unit*> m_attackTargets;
};