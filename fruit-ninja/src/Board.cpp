#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::load()
{
	m_background = loadTexture(GAME_FOLDER + "background.bmp");
	Fruit fruit;
	SDL_Texture* text = loadTexture(GAME_FOLDER + FRUIT_FOLDER + "passionFruit.bmp");
	fruit.init(100, 100, text);
	fruit.load(100, 1000);
	m_fruits.push_back(fruit);
}

void Board::update()
{
	if(m_frameId == 0) { updateFruits(); }
	m_frameId++;
	m_frameId %= m_speed;
	
}

void Board::drawFruits()
{
	for (int i = 0; i < m_fruits.size(); i++)
	{
		m_fruits.at(i).draw();
	}
}

void Board::updateFruits()
{
	for (int i = 0; i < m_fruits.size(); i++)
	{
		m_fruits.at(i).update();
	}
}

void Board::draw()
{
	drawObject(m_background);
	drawFruits();
}

void Board::destroy()
{
}
