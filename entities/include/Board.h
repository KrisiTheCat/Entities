#pragma once

#include <map>
#include <fstream>

#include "Presenter.h"
#include "Reamor.h"
#include "Behavior.h"
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
	void createBullet();


private:

	vector<Reamor> m_reamors;
	vector<Entity> m_entities;
	vector<Behavior> m_behaviors;
	SDL_Texture* m_background;

	void updateReamors();
	void updateEntities();
	void updateBehaviors();

	void drawReamors();
	void drawEntities();
};