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

	void load(int bombRarity);

	void update();

	void initWave();

	void draw();
	
	void destroy();

	int m_bombRarity;
	
	int m_lives;

	vector<Drawable> m_hearts;
	vector<Fruit> m_fruits;

private:

	int m_speed = 2;
	int m_frameId = 0;

	int m_timeBeforeNextWave = 0;
	SDL_Texture* m_background;

	Drawable m_trail;

	vector<Drawable> m_trails;

	Drawable m_scoreUI;
	
	Drawable m_fruitScore;

	SDL_Texture* m_deadTexture;

	void loadHearts();
	void removeHeart();

	void updateFruits();

	void drawFruits();
	void drawFruitsSplashes();
	void drawHearts();
};