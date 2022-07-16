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

private:
	int m_lives;

	int m_speed = 1;
	int m_frameId = 0;

	int m_timeBeforeNextWave = 0;
	SDL_Texture* m_background;
	
	vector<Fruit> m_fruits;

	Drawable m_trail;

	vector<Drawable> m_trails;

	Drawable m_scoreUI;
	
	Drawable m_fruitScore;

	vector<Drawable> m_hearts;

	SDL_Texture* m_deadTexture;

	void loadHearts();
	void removeHeart();

	void updateFruits();

	void drawFruits();
	void drawFruitsSplashes();
	void drawHearts();
};