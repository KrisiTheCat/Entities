#include "Board.h"
#include "World.h"

extern World world;

Board::Board()
{
}

Board::~Board()
{
}


void Board::init()
{
	m_background = loadTexture(GAME_FOLDER + "background.bmp");
	Reamor me;
	SDL_Texture* text = loadTexture(GAME_FOLDER + "me.bmp");
	me.init(text, 118, 102, 100);
	m_reamors.push_back(me);
}

void Board::update()
{
	if (keyUpIsDown()) m_reamors.at(0).moveUp();
	if (keyDownIsDown()) m_reamors.at(0).moveDown();
	if (keyLeftIsDown()) m_reamors.at(0).moveLeft();
	if (keyRightIsDown()) m_reamors.at(0).moveRight();
	updateEntities();
	updateReamors();
}

void Board::draw()
{
	drawObject(m_background);
	drawReamors();
	drawEntities();
}

void Board::destroy()
{
	
}

void Board::updateReamors()
{
	for (int i = 0; i < m_reamors.size(); i++)
	{
		m_reamors.at(i).update();
	}
}

void Board::updateEntities()
{
	for (int i = 0; i < m_reamors.size(); i++)
	{
		m_reamors.at(i).update();
	}
}

void Board::drawReamors()
{
	for (int i = 0; i < m_reamors.size(); i++)
	{
		m_reamors.at(i).draw();
	}
}

void Board::drawEntities()
{
	for (int i = 0; i < m_reamors.size(); i++)
	{
		m_reamors.at(i).draw();
	}
}
