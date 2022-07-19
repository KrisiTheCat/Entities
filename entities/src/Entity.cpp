#include "Entity.h"

Entity::Entity()
{
	m_isMoving = false;
}

Entity::~Entity()
{
}
void Entity::updateEntity()
{
	if (m_isMoving)
	{
		if (m_moveDest.x < m_drawable.rect.x)
			m_drawable.rect.x -= min(m_drawable.rect.x - m_moveDest.x, m_speed);
		if (m_moveDest.x > m_drawable.rect.x)
			m_drawable.rect.x += min(m_moveDest.x - m_drawable.rect.x, m_speed);
		if (m_moveDest.y < m_drawable.rect.y)
			m_drawable.rect.y -= min(m_drawable.rect.y - m_moveDest.y, m_speed);
		if (m_moveDest.y > m_drawable.rect.y)
			m_drawable.rect.y += min(m_moveDest.y - m_drawable.rect.y, m_speed);
	}
}

void Entity::move(int2 a)
{
	m_isMoving = true;
	m_moveDest.x = a.x;
	m_moveDest.y = a.y;
}
