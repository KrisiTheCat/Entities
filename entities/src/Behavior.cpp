#include "Behavior.h"

Behavior::Behavior()
{
}

Behavior::~Behavior()
{
}

void Behavior::init(BEHAVIOR_TYPE type, Entity* entity, Unit* reamor)
{
	m_entity = entity;
	switch (type)
	{
	case BEHAVIOR_TYPE::HOSTILE:

		m_movingState = new MovingContext(new Chase);
		m_movingState->init(m_entity);
		m_entity->m_chaseTargets.insert(make_pair(0, reamor));

		m_attackingState = new AttackingContext(new Attack);
		m_attackingState->init(m_entity);
		m_entity->m_attackTargets.push_back(reamor);

		break;
	}
}

void Behavior::update()
{
	m_movingState->update();
	m_attackingState->update();
}

void Behavior::startChasing(int id)
{
	m_id = id;
}
