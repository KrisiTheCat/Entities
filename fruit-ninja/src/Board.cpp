#include "Board.h"
#include "World.h"
#include "InputManager.h"
#include "World.h"

extern World world;

Board::Board()
{
}

Board::~Board()
{
}


void Board::load(int bombRarity)
{
	fstream stream;

	string tmp, background, trail, fruitImg;

	stream.open(CONFIG_FOLDER + GAME_FOLDER + "board.txt");

	stream >> tmp >> background;
	stream >> tmp >> m_trail.rect.w >> m_trail.rect.h;
	stream >> tmp >> trail;
	stream >> tmp >> m_fruitScore.rect.x >> m_fruitScore.rect.y >> m_fruitScore.rect.w >> m_fruitScore.rect.h;
	stream >> tmp >> fruitImg;

	stream.close();
	
	m_background = loadTexture(GAME_FOLDER + background);

	m_trail.texture = loadTexture(GAME_FOLDER + trail);
	
	m_fruitScore.texture = loadTexture(GAME_FOLDER + fruitImg);
	
	loadHearts();
	
	m_score = 0;
	
	m_bombRarity = bombRarity;
	m_timeBeforeNextWave = 0;
}

void Board::loadHearts()
{
	fstream stream;

	string tmp, heartImg, brokenHeartImg;

	int _offset;

	Drawable _heart;

	stream.open(CONFIG_FOLDER + GAME_FOLDER + "hearts.txt");

	stream >> tmp >> _heart.rect.x >> _heart.rect.y >> _heart.rect.w >> _heart.rect.h;
	stream >> tmp >> heartImg >> brokenHeartImg;
	stream >> tmp >> _offset;
	stream >> tmp >> m_lives;

	stream.close();

	_heart.texture = loadTexture(GAME_FOLDER + heartImg);

	m_deadTexture = loadTexture(GAME_FOLDER + brokenHeartImg);

	m_hearts.push_back(_heart);
	
	for (int i = 1; i < m_lives; i++)
	{
		_heart.rect.x -= _offset;
		
		m_hearts.push_back(_heart);
	}
}

void Board::update()
{
	if (m_frameId == 0)
	{
		if (m_timeBeforeNextWave == 0) 
			initWave();
		
		m_timeBeforeNextWave--;
		
		updateFruits();
	}
	
	m_frameId++;
	m_frameId %= m_speed;
}

void Board::draw()
{
	drawObject(m_background);

	drawObject(m_fruitScore);

	drawFruitsSplashes();

	drawFruits();

	drawHearts();

	auto score = getText(to_string(m_score), FONT::ASSASIN, COLOR::LIGHT, 72);
	m_scoreUI.texture = score.second;
		
	m_scoreUI.rect = {170, 40, score.first.x, score.first.y};

	drawObject(m_scoreUI);
}

void Board::drawFruits()
{
	for (int i = 0; i < m_fruits.size(); i++)
	{
		m_fruits.at(i).draw();
	}
	
	if (InputManager::m_drag && m_trails.size() < 15)
	{
		m_trail.rect.x = InputManager::m_mouseCoor.x - 15;
		m_trail.rect.y = InputManager::m_mouseCoor.y - 15;

		m_trails.push_back(m_trail);

		for (int i = 0; i < m_trails.size(); i++)
		{
			drawObject(m_trails[i]);
		}
	}
	else
	{
		m_trails.clear();
	}
}

void Board::drawHearts()
{
	for (int i = 0; i < m_hearts.size(); i++)
	{
		drawObject(m_hearts[i]);
	}
}

void Board::updateFruits()
{
	for (int i = 0; i < m_fruits.size(); i++)
	{
		m_fruits.at(i).update();

		if (m_fruits.at(i).m_outOfScreen)
		{
			if(!m_fruits.at(i).m_isCut && !m_fruits.at(i).m_isBomb) removeHeart();
			m_fruits.erase(m_fruits.begin() + i);
			continue;
		}
		
		if (InputManager::m_drag)
		{
			if (m_fruits.at(i).m_isBomb && isMouseInRect(m_fruits[i].getRectHitBox()))
			{
				removeHeart();
				removeHeart();
			}

			switch (m_fruits[i].m_hitBoxType)
			{
			case 1: // rect
				if (isMouseInRect(m_fruits[i].getRectHitBox()))
				{
					m_fruits.at(i).cut();
					
					if (!m_fruits[i].m_isBomb)
					{
						m_score++;
					}
				}
				break;
			case 2: // triangle 
				if (MouseIsInTriangle(InputManager::m_mouseCoor, m_fruits[i].getTriangleHitBox().a,
					m_fruits[i].getTriangleHitBox().b, m_fruits[i].getTriangleHitBox().c))
				{
					m_fruits.at(i).cut();
					m_score++;
				}
				break;
			case 3: // circle
				if (MouseIsInCircle(InputManager::m_mouseCoor, m_fruits[i].getCircleHitBox().center,
					m_fruits[i].getCircleHitBox().radius))
				{
					m_fruits.at(i).cut();
					m_score++;
				}
				break;
			case 4: // ellipse
				if (MouseIsInEllipse(InputManager::m_mouseCoor, m_fruits[i].getOvalHitBox().center,
					m_fruits[i].getOvalHitBox().radius))
				{
					m_fruits.at(i).cut();
					m_score++;
				}
				break;
			default:
				break;
			}
		}
	}
}

void Board::removeHeart()
{
	m_lives--;

	m_hearts[m_lives].texture = m_deadTexture;
	cout << "life: " << m_lives << endl;

	if (m_lives == 0)
	{
		world.m_stateManager.changeGameState(GAME_STATE::WIN_SCREEN);
	}
}

void Board::initWave()
{
	int fruitsCount = world.m_config.m_fruitsInWave.x + (rand() % world.m_config.m_fruitsInWave.y);
	int bombsSoFar = 0;
	
	for (int i = 0; i < fruitsCount; i++)
	{
		int fruitId = rand() % (world.m_config.m_allFruits.size() - 1 + m_bombRarity);
		
		if (fruitId >= world.m_config.m_allFruits.size()) 
			fruitId = world.m_config.m_allFruits.size() - 1;
		
		if (world.m_config.m_allFruits.at(fruitId).m_isBomb)
		{
			if (bombsSoFar < world.m_config.m_bombsInWave) 
				bombsSoFar++;
			else 
			{
				while (world.m_config.m_allFruits.at(fruitId).m_isBomb) 
				{
					fruitId = rand() % world.m_config.m_allFruits.size();
					
					if (fruitId > world.m_config.m_allFruits.size()) 
						fruitId = 0;
				}
			}
		}
		
		Fruit fruit = world.m_config.m_allFruits.at(fruitId);
		
		int speedX = world.m_config.m_speedX.x + (rand() % world.m_config.m_speedX.y);
		int speedY = world.m_config.m_speedY.x + (rand() % world.m_config.m_speedY.y);
		
		int x = (rand() % world.m_config.m_width);
		
		if (speedX < 0 && x < speedY * 2 * (-1) * speedX + 100) 
			x = world.m_config.m_width - x;
		
		if (speedX > 0 && x > world.m_config.m_width - speedY * 2 * speedX - 100) 
			x = world.m_config.m_width - x;
		int initAfter = world.m_config.m_fruitsInWave.x + (rand() % world.m_config.m_fruitsInWave.y);
		
		fruit.load(initAfter, x, world.m_config.m_height, speedX, speedY, 20);
		
		m_fruits.push_back(fruit);
	}
	m_timeBeforeNextWave = world.m_config.m_timeBetweenWaves.x + (rand() % world.m_config.m_timeBetweenWaves.y);
}

void Board::drawFruitsSplashes()
{
	for (int i = 0; i < m_fruits.size(); i++)
	{
		m_fruits.at(i).drawSplash();
	}
}

void Board::destroy()
{
	
}
