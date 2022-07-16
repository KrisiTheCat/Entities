#pragma once
#include <map>

#include "defines.h"
#include "Presenter.h"

/*
\brief Grid structure splitting a place into gridded squares
*/

class FruitSlice
{

public:
	FruitSlice();
	~FruitSlice();

	void init(int width, int height, SDL_Texture* texture);
	void load(int x, int y, int speedX, int speedY);

	void update();
	void draw();
	
	void destroy();

private:
	Drawable m_drawable;
	Rotatable m_rotatable;
	int state;
	// 0 - slices fly
	// 1 - slices fall
	int m_speedX;
	int m_speedY;
};