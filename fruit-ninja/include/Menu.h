#pragma once

#include <fstream>

#include "defines.h"
#include "State.h"
#include "Button.h"

class Menu : public State
{
public:
	Menu();
	~Menu();

	void init();
	void run();
	void destroy();
	
private: 
	SDL_Texture* m_menuTexture;

	DrawableForMenu m_easy;
	DrawableForMenu m_medium;
	DrawableForMenu m_hard;

	Button m_exitBtn;
};