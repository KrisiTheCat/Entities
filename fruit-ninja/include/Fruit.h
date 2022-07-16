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
	void load(int initAfter, int x, int y, int speedX, int speedY, int rotateSpeed);

	void setRectHitBox();
	SDL_Rect getRectHitBox();
	void setTriangleHitBox(int2 a, int2 b, int2 c);
	TriangleHitBox getTriangleHitBox();
	void setCircleHitBox(int2 center, int r);
	CircleHitBox getCircleHitBox();
	void setOvalHitBox(int2 center, int r1, int r2);
	OvalHitBox getOvalHitBox();

	void update();
	void draw();
	void drawSplash();
	void cut();

	int m_id = 0;
	int m_hitBoxType;
	
	SDL_Rect m_rectHitBox;
	TriangleHitBox m_triangleHitBox;
	CircleHitBox m_circleHitBox;
	OvalHitBox m_ovalHitBox;

	bool m_isBomb;
	bool m_outOfScreen = false;

private:
	Drawable m_drawable;
	DrawableWithOpacity m_splash;
	Rotatable m_rotatable;
	vector<FruitSlice> m_slices;

	bool m_isCut;
	int m_initAfter;
	int m_splashTime;
	int m_speedX;
	int m_speedY;
};