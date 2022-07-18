#pragma once

#include <map>
#include <fstream>

#include "Presenter.h"
#include "Reamor.h"
//#include "Enemy.h"
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


private:

	vector<Reamor> m_reamors;
	SDL_Texture* m_background;

	void updateReamors();
	void updateEntities();

	void drawReamors();
	void drawEntities();
};