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

void Fruit::load(int initAfter, int x, int y, int speedX, int speedY, int rotateSpeed)
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


void Fruit::setRectHitBox()
{
	m_hitBoxType = 1;
	m_rectHitBox = m_drawable.rect;
}

SDL_Rect Fruit::getRectHitBox()
{
	SDL_Rect hitbox = m_rectHitBox;
	hitbox.x += m_drawable.rect.x;
	hitbox.y += m_drawable.rect.y;
	return hitbox;
}

void Fruit::setTriangleHitBox(int2 a, int2 b, int2 c)
{
	m_hitBoxType = 2;
	m_triangleHitBox.a = a;
	m_triangleHitBox.b = b;
	m_triangleHitBox.c = c;
}

TriangleHitBox Fruit::getTriangleHitBox()
{
	TriangleHitBox hitbox = m_triangleHitBox;
	hitbox.a.x += m_drawable.rect.x;
	hitbox.a.y += m_drawable.rect.y;
	hitbox.b.x += m_drawable.rect.x;
	hitbox.b.y += m_drawable.rect.y;
	hitbox.c.x += m_drawable.rect.x;
	hitbox.c.y += m_drawable.rect.y;
	return hitbox;
}

void Fruit::setCircleHitBox(int2 center, int r)
{
	m_hitBoxType = 3;
	m_circleHitBox.center = center;
	m_circleHitBox.radius = r;
}

CircleHitBox Fruit::getCircleHitBox()
{
	CircleHitBox hitbox = m_circleHitBox;
	hitbox.center.x += m_drawable.rect.x;
	hitbox.center.y += m_drawable.rect.y;
	return hitbox;
}

void Fruit::setOvalHitBox(int2 center, int r1, int r2)
{
	m_hitBoxType = 4;
	m_ovalHitBox.radius.x = r1;
	m_ovalHitBox.radius.y = r2;
}

OvalHitBox Fruit::getOvalHitBox()
{
	OvalHitBox hitbox = m_ovalHitBox;
	hitbox.center.x += m_drawable.rect.x;
	hitbox.center.y += m_drawable.rect.y;
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
			if (m_speedY == 0) cut();
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
		if (m_splashTime <= 200) m_splash.opacity = m_splashTime;
	}
}

void Fruit::draw()
{
	if (!m_isCut) drawObjectRotated(m_drawable, m_rotatable);
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
	m_splash.opacity = 200;
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
	switch (m_hitBoxType)
	{
	case 1:
		m_rectHitBox.w = 0;
		m_rectHitBox.h = 0;
		break;
	case 2:
		m_triangleHitBox.reset();
		break;
	case 3:
		m_circleHitBox.reset();
		break;
	case 4:
		m_ovalHitBox.reset();
		break;
	default:
		break;
	}
}
