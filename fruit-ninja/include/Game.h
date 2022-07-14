#pragma once

#include <fstream>

#include "State.h"
#include "ConfigManager.h"

class Game : public State
{
public:

	Game();
	~Game();
		
	void init();
	void destroy();
	void run();
};