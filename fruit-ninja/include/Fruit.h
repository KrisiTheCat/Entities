#pragma once
#include <map>

#include "defines.h"
#include "Presenter.h"
#include "FruitSlice.h"

/*
\brief Grid structure splitting a place into gridded squares
*/

class Fruit
{

public:
	Fruit();
	~Fruit();

	void initBomb(int width, int height, SDL_Texture* texture, SDL_Texture* splashTexture, int2 splashSize, int splashTime);
	void init(int width, int height, int cutWidth, int cutHeight, int slicesNumber, SDL_Texture* texture, SDL_Texture* textureCut, SDL_Texture* splashTexture, int2 splashSize, int splashTime);
	void load(int initAfter, int x, int y, int speedX, int speedY);

	void setHitBox();
	SDL_Rect getHitBox();

	void update();
	void draw();
	void drawSplash();
	void cut();

	int m_id = 0;

	bool m_isCut;
	bool m_isBomb;
	bool m_outOfScreen = false;

private:
	Drawable m_drawable;
	DrawableWithOpacity m_splash;
	Rotatable m_rotatable;
	vector<FruitSlice> m_slices;

	SDL_Rect m_hitBox;

	int m_initAfter;
	int m_splashTime;
	int m_speedX;
	int m_speedY;
};