#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::init(int id, SDL_Texture* text, int x, int y, int h, int w)
{
	m_unitId = id;
	m_drawable.rect.x = x;
	m_drawable.rect.y = y;
	m_drawable.rect.h = h;
	m_drawable.rect.w = w;
	m_drawable.texture = text;
}

void Bullet::update(int2 a)
{
	if (a.x < m_drawable.rect.x)
		m_drawable.rect.x -= min(m_drawable.rect.x - a.x, m_speed);
	if (a.x > m_drawable.rect.x)
		m_drawable.rect.x += min(a.x - m_drawable.rect.x, m_speed);
	if (a.y < m_drawable.rect.y)
		m_drawable.rect.y -= min(m_drawable.rect.y - a.y, m_speed);
	if (a.y > m_drawable.rect.y)
		m_drawable.rect.y += min(a.y - m_drawable.rect.y, m_speed);
}

int Bullet::unitId()
{
	return m_unitId;
}

void Bullet::draw()
{
	drawObject(m_drawable);
}
