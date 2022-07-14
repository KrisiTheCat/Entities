#pragma once

#include <map>

#include "defines.h"
#include "Presenter.h"
#include "Fruit.h"

/*
\brief Grid structure splitting a place into gridded squares
*/

class Board
{

public:
	Board();
	~Board();

	void load();

	void update();
	void draw();
	void drawFruits();
	void updateFruits();
	
	void destroy();

private:
	int m_speed = 5;
	int m_frameId = 0;
	SDL_Texture* m_background;
	vector<Fruit> m_fruits;
};