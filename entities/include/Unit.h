#pragma once

#include "Presenter.h"
#include "defines.h"

class Unit
{
public:
	Unit();
	~Unit();

	void init(SDL_Texture* texture, int width, int height, int health);

	void load(int x, int y);

	void update();

	void draw();
	
	void destroy();

	void move(int x, int y);

protected:
	int m_health;
	int2 m_moveDest;
	bool m_isMoving = false;
	int m_speed = 5;
	Drawable m_drawable;
};