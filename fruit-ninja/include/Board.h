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
	
	int m_score;

	void load();

	void update();
	void draw();
	
	void destroy();

private:
	int m_speed = 5;
	int m_frameId = 0;
	int m_lives;

	SDL_Texture* m_background;
	
	vector<Fruit> m_fruits;

	Drawable m_trail;

	Drawable m_scoreUI;
	
	Drawable m_fruitScore;

	vector<Drawable> m_hearts;

	SDL_Texture* m_deadTexture;

	void loadHearts();

	void updateFruits();
	void drawFruits();

	void drawHearts();
};