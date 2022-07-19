#include "Board.h"
#include "World.h"

extern World world;

Board::Board()
{
}

Board::~Board()
{
}

int2 Board::getUnitPos(int id)
{
	for (int i = 0; i < m_reamors.size(); i++)
	{
		if (m_reamors.at(i).m_id == id)
		{
			return m_reamors.at(i).getPos();
		}
	}
}

void Board::init()
{
	m_background = loadTexture(GAME_FOLDER + "background.bmp");

	Reamor me;
	SDL_Texture* text = loadTexture(GAME_FOLDER + "me.bmp");
	me.init(0, text, 118, 102, 100, 900, 900, 10);
	m_reamors.push_back(me);

	Entity ent;
	text = loadTexture(GAME_FOLDER + "enemyHostile1.bmp");
	ent.init(1, text, 94, 127, 100, 100, 100, 3);
	m_entities.push_back(ent);

	Behavior beh;
	beh.init(BEHAVIOR_TYPE::HOSTILE, &m_entities.at(0), &m_reamors.at(0));
	m_behaviors.push_back(beh);

}

void Board::update()
{
	if (keyUpIsDown()) m_reamors.at(0).moveUp();
	if (keyDownIsDown()) m_reamors.at(0).moveDown();
	if (keyLeftIsDown()) m_reamors.at(0).moveLeft();
	if (keyRightIsDown()) m_reamors.at(0).moveRight();
	updateEntities();
	updateReamors();
	updateBehaviors();
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
	for (int i = 0; i < m_entities.size(); i++)
	{
		m_entities.at(i).updateEntity();
		m_entities.at(i).update();
	}
}

void Board::updateBehaviors()
{
	for (int i = 0; i < m_behaviors.size(); i++)
	{
		m_behaviors.at(i).update();
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
	for (int i = 0; i < m_entities.size(); i++)
	{
		m_entities.at(i).draw();
	}
}
