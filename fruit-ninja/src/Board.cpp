#include "Board.h"
#include "InputManager.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::load()
{
	fstream stream;

	string tmp, background, trail;

	stream.open(CONFIG_FOLDER + GAME_FOLDER + "board.txt");

	stream >> tmp >> background;
	stream >> tmp >> m_trail.rect.w >> m_trail.rect.h;
	stream >> tmp >> trail;
	
	stream.close();
	
	m_background = loadTexture(GAME_FOLDER + background);

	m_trail.texture = loadTexture(GAME_FOLDER + trail);
	
	Fruit fruit;
	fruit.load(100, 10, 100, 100, 1);
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
	
	if (InputManager::m_drag)
	{
		m_trail.rect.x = InputManager::m_mouseCoor.x - 15;
		m_trail.rect.y = InputManager::m_mouseCoor.y - 15;
		
		drawObject(m_trail);
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
