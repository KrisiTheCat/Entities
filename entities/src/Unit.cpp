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
	
	updateBullets();
}

void Unit::draw()
{
	drawObject(m_drawable);
	drawBullets();
}

void Unit::attack(Unit* target)
{
	Bullet bullet;
	SDL_Texture* text = loadTexture(GAME_FOLDER + "bullet.bmp");
	bullet.init(0, text, m_drawable.rect.x, m_drawable.rect.y, 50, 50);
	m_bullets.push_back(make_pair(target, bullet));
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

void Unit::drawBullets()
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets.at(i).second.draw();
	}
}

void Unit::updateBullets()
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets.at(i).second.update(m_bullets.at(i).first->getPos());
	}
}
