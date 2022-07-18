#include "Unit.h"

Unit::Unit()
{

}

Unit::~Unit()
{
}

void Unit::init(int id, SDL_Texture* texture, int width, int height, int health, int x, int y, int speed)
{
	m_drawable.texture = texture;
	m_drawable.rect.x = x;
	m_drawable.rect.y = y;
	m_drawable.rect.w = width;
	m_drawable.rect.h = height;
	m_health = health;
	m_id = id;
	m_speed = speed;
}

void Unit::load(int x, int y)
{
	m_drawable.rect.x = x;
	m_drawable.rect.y = y;
}

void Unit::update()
{
	
}

void Unit::draw()
{
	drawObject(m_drawable);
}

void Unit::destroy()
{
}

int2 Unit::getPos()
{
	int2 a;
	a.x = m_drawable.rect.x;
	a.y = m_drawable.rect.y;
	return a;
}

int Unit::getSpeed()
{
	return m_speed;
}
