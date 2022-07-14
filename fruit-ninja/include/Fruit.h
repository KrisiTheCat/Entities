#pragma once

#include "Presenter.h"

#include <map>

/*
\brief Grid structure splitting a place into gridded squares
*/

class Fruit
{

public:
	Fruit();
	~Fruit();

	void load(int x, int y, int width, int height, int mass);
	void setCircularHitBox(int r, int2 center);

	void update();
	void draw();
	
	void destroy();

private:
	Drawable m_drawable;
	CircleHitBox m_hitbox;
	int m_speedX;
	int m_speedY;
	int m_mass; 
};