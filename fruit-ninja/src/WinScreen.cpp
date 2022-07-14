#include "WinScreen.h"
#include "World.h"

extern World world;

WinScreen::WinScreen()
{

}

WinScreen::~WinScreen()
{
	
}

void WinScreen::init()
{
	fstream stream;

	string tmp, background, playBtnPath, exitBtnPath;

	stream.open(CONFIG_FOLDER + WIN_SCREEN_FOLDER + "winScreen.txt");

	stream >> tmp >> background;
	stream >> tmp >> playBtnPath;
	stream >> tmp >> exitBtnPath;
	
	stream.close();

	m_background = loadTexture(WIN_SCREEN_FOLDER + background);

	m_playBtn.init(playBtnPath, MENU_FOLDER);
	m_exitBtn.init(exitBtnPath, MENU_FOLDER);
}

void WinScreen::run()
{	
	drawObject(m_background);

	m_playBtn.update();
	m_playBtn.draw();

	m_exitBtn.update();
	m_exitBtn.draw();
	
	if (mouseIsPressed())
	{
		if (isMouseInRect(m_playBtn.getRect()))
		{
			world.m_stateManager.changeGameState(GAME_STATE::MENU);

			return;
		}

		if (isMouseInRect(m_exitBtn.getRect()))
		{
			world.m_stateManager.changeGameState(GAME_STATE::NONE);

			return;
		}
	}
}

void WinScreen::destroy()
{
	m_playBtn.destroy();
	m_exitBtn.destroy();
}
