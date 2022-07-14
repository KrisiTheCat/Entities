#pragma once

#include "Presenter.h"
#include "Fruit.h"

#include <map>


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
	SDL_Texture* m_background;
	vector<Fruit> m_fruits;
};