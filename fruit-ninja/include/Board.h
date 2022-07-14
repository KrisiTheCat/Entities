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
	
	void destroy();

private:
	int m_speed = 5;
	int m_frameId = 0;
	SDL_Texture* m_background;
	
	vector<Fruit> m_fruits;

	Drawable m_trail;

	Drawable m_fruitScore;

	//SCORE 

	vector<Drawable> m_hearts;

	SDL_Texture* m_deadTexture;

	void loadHearts();

	void updateFruits();
	void drawFruits();

	void drawHearts();
};