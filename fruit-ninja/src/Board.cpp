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
	fruit.load(100, 1000, 100, 100, 1);
	m_fruits.push_back(fruit);
}

void Board::update()
{
	updateFruits();
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
