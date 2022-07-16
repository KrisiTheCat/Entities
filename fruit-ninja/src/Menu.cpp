#include "Menu.h"
#include "World.h"

extern World world;

Menu::Menu()
{
}

Menu::~Menu()
{
	
}

void Menu::init()
{
	fstream stream;

	string tmp, img, exitBtnPath, easyImg, 
		easyImgGlow, mediumImg, mediumImgGlow, hardImg, hardImgGlow;

	stream.open(CONFIG_FOLDER + MENU_FOLDER + "menu.txt");

	stream >> tmp >> img;
	stream >> tmp >> exitBtnPath;
	stream >> tmp >> easyImg >> easyImgGlow;
	stream >> tmp >> mediumImg >> mediumImgGlow;
	stream >> tmp >> hardImg >> hardImgGlow;

	stream >> tmp >> m_easy.rect.x >> m_easy.rect.y >> m_easy.rect.w >> m_easy.rect.h;
	stream >> tmp >> m_medium.rect.x >> m_medium.rect.y >> m_medium.rect.w >> m_medium.rect.h;
	stream >> tmp >> m_hard.rect.x >> m_hard.rect.y >> m_hard.rect.w >> m_hard.rect.h;

	stream.close();

	m_menuTexture = loadTexture(MENU_FOLDER + img);

	m_easy.texture = loadTexture(MENU_FOLDER + easyImg);
	m_easy.glowTexture = loadTexture(MENU_FOLDER + easyImgGlow);

	m_medium.texture = loadTexture(MENU_FOLDER + mediumImg);
	m_medium.glowTexture = loadTexture(MENU_FOLDER + mediumImgGlow);

	m_hard.texture = loadTexture(MENU_FOLDER + hardImg);
	m_hard.glowTexture = loadTexture(MENU_FOLDER + hardImgGlow);

	m_exitBtn.init(exitBtnPath, MENU_FOLDER);
}

void Menu::run()
{	
	drawObject(m_menuTexture);

	m_exitBtn.update();
	m_exitBtn.draw();

	if (isMouseInRect(m_exitBtn.getRect()) && mouseIsPressed())
	{
		world.m_stateManager.changeGameState(GAME_STATE::NONE);
	}

	if (isMouseInRect(m_easy.rect))
	{
		SDL_RenderCopy(world.m_presenter.m_main_renderer, m_easy.glowTexture, NULL, &m_easy.rect);

		if (mouseIsPressed())
		{
			//easy

			world.m_stateManager.changeGameState(GAME_STATE::GAME);
		}
	}
	else
	{
		SDL_RenderCopy(world.m_presenter.m_main_renderer, m_easy.texture, NULL, &m_easy.rect);
	}

	if (isMouseInRect(m_medium.rect))
	{
		SDL_RenderCopy(world.m_presenter.m_main_renderer, m_medium.glowTexture, NULL, &m_medium.rect);

		if (mouseIsPressed())
		{
			//medium

			world.m_stateManager.changeGameState(GAME_STATE::GAME);
		}
	}
	else
	{
		SDL_RenderCopy(world.m_presenter.m_main_renderer, m_medium.texture, NULL, &m_medium.rect);
	}

	if (isMouseInRect(m_hard.rect))
	{
		SDL_RenderCopy(world.m_presenter.m_main_renderer, m_hard.glowTexture, NULL, &m_hard.rect);

		if (mouseIsPressed())
		{
			//hard

			world.m_stateManager.changeGameState(GAME_STATE::GAME);
		}
	}
	else
	{
		SDL_RenderCopy(world.m_presenter.m_main_renderer, m_hard.texture, NULL, &m_hard.rect);
	}
}

void Menu::destroy()
{
	SDL_DestroyTexture(m_menuTexture);

	m_exitBtn.destroy(); 

	//Destroy all textures !!!
}