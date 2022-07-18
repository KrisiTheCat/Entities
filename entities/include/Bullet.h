#pragma once

#include "Presenter.h"
#include "defines.h"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void init(int id, SDL_Texture* text, int x, int y, int h, int w);

	void update(int2 a);

	void draw();
	int unitId();

private:
	int m_speed = 5;
	int m_unitId;
	Drawable m_drawable;
};