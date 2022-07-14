#pragma once

#include <map>
#include <fstream>

#include "Presenter.h"
#include "Fruit.h"
#include "defines.h"

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

	Drawable m_trail;
};