#include "ChaseState.h"

ChaseState::ChaseState()
{
}

ChaseState::~ChaseState()
{
}

void ChaseState::init(Entity* entity)
{
	m_entity = entity;
}

void ChaseState::update()
{
	if (m_chaseTarget.size() > 0)
	{
		int2 a = m_chaseTarget.begin()->second->getPos();
		m_entity->move(a);
	}
}

void ChaseState::startChasing(int type, Unit* target)
{
	m_chaseTarget.insert(make_pair(type, target));
}
