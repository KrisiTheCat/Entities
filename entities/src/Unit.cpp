#include "Unit.h"

Unit::Unit()
{

}

Unit::~Unit()
{
}

void Unit::init(SDL_Texture* texture, int width, int height, int health)
{
	m_drawable.texture = texture;
	m_drawable.rect.w = width;
	m_drawable.rect.h = height;
	m_health = health;
}

void Unit::load(int x, int y)
{
	m_drawable.rect.x = x;
	m_drawable.rect.y = y;
}

void Unit::update()
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

void Unit::draw()
{
	drawObject(m_drawable);
}

void Unit::destroy()
{
}

void Unit::move(int x, int y)
{
	m_moveDest.x = x;
	m_moveDest.y = y;
}
