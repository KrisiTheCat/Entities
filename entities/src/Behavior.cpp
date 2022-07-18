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
		m_movingState = MOVING_STATE::CHASE;
		m_chaseState.init(entity);
		m_chaseState.startChasing(1, reamor);
		break;
	}
}

void Behavior::update()
{
	switch (m_movingState)
	{
	case MOVING_STATE::CHASE:
		m_chaseState.update();
		break;
	}
}

void Behavior::startChasing(int id)
{
	m_id = id;
}
