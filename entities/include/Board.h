#pragma once

#include <map>
#include <fstream>

#include "Presenter.h"
#include "Reamor.h"
#include "Behavior.h"
#include "Bullet.h"
#include "Entity.h"
#include "defines.h"

class Board
{
public:
	Board();
	~Board();
	
	void init();

	void update();

	void draw();
	
	void destroy();

	int2 getUnitPos(int id);


private:

	vector<Reamor> m_reamors;
	vector<Entity> m_entities;
	vector<Behavior> m_behaviors;
	vector<Bullet> m_bullets;
	SDL_Texture* m_background;

	void updateReamors();
	void updateEntities();
	void updateBullets();
	void updateBehaviors();

	void drawReamors();
	void drawEntities();
	void drawBullets();
};