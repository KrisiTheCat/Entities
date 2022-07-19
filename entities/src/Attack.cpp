#include "Attack.h"

Attack::Attack()
{
}

Attack::~Attack()
{
}

void Attack::init(Entity* entity)
{
	m_entity = entity;
}

void Attack::update()
{
	if (m_attackTargets.size() > 0)
	{
		if (m_frameId == 0)
		{
			m_entity->attack(m_attackTargets.at(0));
		}
		m_frameId++;
		m_frameId %= m_framesToShoot;
	}
}

void Attack::startAttacking(Unit* target)
{
	m_attackTargets.push_back(target);
}
