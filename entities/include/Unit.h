#pragma once

#include "Presenter.h"
#include "defines.h"

class Unit
{
public:
	Unit();
	~Unit();

	void init(int id, SDL_Texture* texture, int width, int height, int health, int x, int y, int speed);

	void load(int x, int y);

	void update();

	void draw();
	
	void destroy();

	int2 getPos();
	int getSpeed();
	int m_id;

protected:
	int m_health;
	int m_speed;
	Drawable m_drawable;
};