#pragma once
#include <map>

#include "defines.h"
#include "Presenter.h"

/*
\brief Grid structure splitting a place into gridded squares
*/

class Fruit
{

public:
	Fruit();
	~Fruit();

	void init(int width, int height, SDL_Texture* texture);
	void load(int x, int y);

	void setRectHitBox(int2 topLeft, int width, int height);
	void setTriangleHitBox(int2 a, int2 b, int2 c);
	void setCircleHitBox(int2 center, int r);
	void setOvalHitBox(int2 center, int r1, int r2);

	void update();
	void draw();
	
	void destroy();

	int m_hitBoxType;
	
	SDL_Rect m_rectHitBox;
	TriangleHitBox m_triangleHitBox;
	CircleHitBox m_circleHitBox;
	OvalHitBox m_ovalHitBox;
	
	Drawable m_drawable;

private:
	int m_speedX;
	int m_speedY;
};