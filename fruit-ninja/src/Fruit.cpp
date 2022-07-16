#include "Fruit.h"

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}

void Fruit::init(int width, int height, SDL_Texture* texture)
{
	m_drawable.texture = texture;
	m_drawable.rect.h = height;
	m_drawable.rect.w = width;
}

void Fruit::load(int x, int y)
{
	m_drawable.rect.x = x;
	m_drawable.rect.y = y;

	m_speedX = 1;
	m_speedY = 40;
}

void Fruit::setRectHitBox(int2 topLeft, int width, int height)
{
	//m_hitBoxType = HITBOX::RECT;
	//m_rectHitBox.topLeft = topLeft;
	//m_rectHitBox.width = width;
	//m_rectHitBox.height = height;
}

void Fruit::setTriangleHitBox(int2 a, int2 b, int2 c)
{
	//m_hitBoxType = HITBOX::TRIANGLE;
	//m_triangleHitBox.a = a;
	//m_triangleHitBox.b = b;
	//m_triangleHitBox.c = c;
}

void Fruit::setCircleHitBox(int2 center, int r)
{
	//m_hitBoxType = HITBOX::CIRCLE;
	//m_circleHitBox.center = center;
	//m_circleHitBox.radius = r;
}

void Fruit::setOvalHitBox(int2 center, int r1, int r2)
{
	//m_hitBoxType = HITBOX::OVAL;
	//m_ovalHitBox.radius1 = r1;
	//m_ovalHitBox.radius2 = r2;
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
