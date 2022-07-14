#include "Fruit.h"

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}

void Fruit::load(int x, int y, int width, int height, int mass)
{
	m_drawable.texture = loadTexture(GAME_FOLDER + "passionFruit.bmp");
	m_drawable.rect.x = x;
	m_drawable.rect.y = y;
	m_drawable.rect.h = height;
	m_drawable.rect.w = width;

	m_speedX = 1;
	m_speedY = 40;
}

void Fruit::setCircularHitBox(int r, int2 center)
{
	m_hitbox.center = center;
	m_hitbox.radius = r;
}

void Fruit::update()
{
	//m_drawable.rect.x += m_speedX;
	if(m_drawable.rect.y<=1920) m_drawable.rect.y -= m_speedY;

	m_speedY--;
}

void Fruit::draw()
{
	drawObject(m_drawable);
}

void Fruit::destroy()
{
}
