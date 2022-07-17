#include "Fruit.h"

Fruit::Fruit()
{
}

Fruit::~Fruit()
{
}

void Fruit::initBomb(int width, int height, SDL_Texture* texture, SDL_Texture* splashTexture, int2 splashSize, int splashTime)
{
	m_drawable.texture = texture;
	m_drawable.rect.h = height;
	m_drawable.rect.w = width;

	m_splash.rect.w = splashSize.x;
	m_splash.rect.h = splashSize.y;
	m_splash.texture = splashTexture;

	m_isCut = false;
	m_isBomb = true;
	m_splashTime = splashTime;
}

void Fruit::init(int width, int height, int cutWidth, int cutHeight, int slicesNumber, SDL_Texture* texture, SDL_Texture* textureCut, SDL_Texture* splashTexture, int2 splashSize, int splashTime)
{
	m_drawable.texture = texture;
	m_drawable.rect.h = height;
	m_drawable.rect.w = width;

	m_splash.rect.w = splashSize.x;
	m_splash.rect.h = splashSize.y;
	m_splash.texture = splashTexture;

	FruitSlice slice;
	slice.init(cutWidth, cutHeight, textureCut);
	for (int i = 0; i < slicesNumber; i++)
	{
		m_slices.push_back(slice);
	}

	m_isCut = false;
	m_isBomb = false;
	m_splashTime = splashTime;
}

void Fruit::load(int initAfter, int x, int y, int speedX, int speedY)
{
	m_drawable.rect.x = x;
	m_drawable.rect.y = y;

	m_rotatable.angle = 0;
	m_rotatable.flip = SDL_FLIP_NONE;

	m_speedX = speedX;
	m_speedY = speedY;
	m_rotatable.angle = 360;

	m_initAfter = initAfter;
}


void Fruit::setHitBox()
{
	m_hitBox = m_drawable.rect;
}

SDL_Rect Fruit::getHitBox()
{
	SDL_Rect hitbox = m_hitBox;
	hitbox.x += m_drawable.rect.x;
	hitbox.y += m_drawable.rect.y;
	return hitbox;
}

void Fruit::update()
{
	if (!m_isCut)
	{
		if (m_initAfter <= 0)
		{
			m_rotatable.angle -= m_speedY / 3;
			m_drawable.rect.x += m_speedX;
			if (m_drawable.rect.y <= 1080)
			{
				m_drawable.rect.y -= m_speedY;
			}
			else {
				m_outOfScreen = true;
				return;
			}
			m_speedY--;
		}
		else m_initAfter--;
	}
	else
	{
		for (int i = 0; i < m_slices.size(); i++)
		{
			m_slices.at(i).update();
		}
		m_splashTime--;
		if (m_splashTime <= 0) m_outOfScreen = true;
		if (m_splashTime <= 255) m_splash.opacity = m_splashTime;
	}
}

void Fruit::draw()
{
	if (!m_isCut)
	{
		drawObjectRotated(m_drawable, m_rotatable);
	}
	else
	{
		for (int i = 0; i < m_slices.size(); i++)
		{
			m_slices.at(i).draw();
		}
	}
}

void Fruit::drawSplash()
{
	if (m_isCut) drawObject(m_splash);
}

void Fruit::cut()
{
	m_isCut = true;
	m_splash.rect.x = m_drawable.rect.x - (m_splash.rect.w - m_drawable.rect.w) / 2;
	m_splash.rect.y = m_drawable.rect.y - (m_splash.rect.h - m_drawable.rect.h) / 2;
	m_splash.opacity = 255;
	bool left = true;
	for (int i = 0; i < m_slices.size(); i++)
	{
		int spX = 0;
		if (i == 0)
		{
			spX = -7 + (rand() % 15);
			if (spX < 0) left = false;
		}
		else {
			if (left) spX = -7 + (rand() % 8);
			else spX = (rand() % 8);
			left = !left;
		}
		int spY = -10 + (rand() % 31);
		m_slices.at(i).load(m_drawable.rect.x, m_drawable.rect.y,
			spX, spY);
	}
	m_hitBox.w = 0;
	m_hitBox.h = 0;
}
