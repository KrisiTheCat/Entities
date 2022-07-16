#include "FruitSlice.h"

FruitSlice::FruitSlice()
{
}

FruitSlice::~FruitSlice()
{
}

void FruitSlice::init(int width, int height, SDL_Texture* texture)
{
	m_drawable.texture = texture;
	m_drawable.rect.h = height;
	m_drawable.rect.w = width;
}

void FruitSlice::load(int x, int y, int speedX, int speedY)
{
	m_drawable.rect.x = x;
	m_drawable.rect.y = y;

	m_speedX = speedX;
	m_speedY = speedY;

	m_rotatable.angle = 0;
	if(speedX < 0) m_rotatable.flip = SDL_FLIP_HORIZONTAL;
	else m_rotatable.flip = SDL_FLIP_NONE;
}

void FruitSlice::update()
{
	m_drawable.rect.x += m_speedX;
	if(m_drawable.rect.y<=1080) m_drawable.rect.y -= m_speedY;
	m_speedY--;
}

void FruitSlice::draw()
{
	drawObjectRotated(m_drawable, m_rotatable);
}

void FruitSlice::destroy()
{

}
