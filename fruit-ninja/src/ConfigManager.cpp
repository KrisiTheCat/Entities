#include "ConfigManager.h"

ConfigManager::ConfigManager()
{

}

ConfigManager::~ConfigManager()
{

}

void ConfigManager::load()
{
	loadFruits();
}

void ConfigManager::loadFruits()
{
	fstream stream;
	string tmp;

	stream.open(CONFIG_FOLDER + GAME_FOLDER + "wave.txt");

	stream >> tmp >> m_fruitsInWave.x >> m_fruitsInWave.y;
	stream >> tmp >> m_bombsInWave;
	stream >> tmp >> m_timeBetweenWaves.x >> m_timeBetweenWaves.y;
	stream >> tmp >> m_timeBetweenFruits.x >> m_timeBetweenFruits.y;
	stream >> tmp >> m_speedX.x >> m_speedX.y;
	stream >> tmp >> m_speedY.x >> m_speedY.y;
	stream >> tmp >> m_splashTime;

	stream.close();

	stream.open(CONFIG_FOLDER + FRUITS_FOLDER + "allFruits.txt");

	stream >> tmp;
	stream >> tmp;
	m_splashSize.x = stoi(tmp);
	stream >> tmp;
	m_splashSize.y = stoi(tmp);

	while (!stream.eof())
	{
		Fruit fruit;
		string name, splash;
		int width, height, slices, widthCut, heightCut;
		stream >> name >> width >> height;
		SDL_Texture* text = loadTexture(GAME_FOLDER + FRUITS_FOLDER + name + ".bmp");
		if (name == "bomb")
		{
			int2 splSize;
			int splTime;
			stream >> splSize.x >> splSize.y >> splTime;
			SDL_Texture* textSpl = loadTexture(GAME_FOLDER + SPLASHES_FOLDER + name + "Splash.bmp");
			fruit.initBomb(width, height, text, textSpl, splSize, splTime);
			fruit.setRectHitBox();
		}
		else
		{
			stream >> widthCut >> heightCut >> slices >> splash;
			SDL_Texture* textCut = loadTexture(GAME_FOLDER + FRUITS_FOLDER + name + "_cut.bmp");
			SDL_Texture* textSpl = loadTexture(GAME_FOLDER + SPLASHES_FOLDER + splash + "Splash.bmp");
			fruit.init(width, height, widthCut, heightCut, slices, text, textCut, textSpl, m_splashSize, m_splashTime);
			int hitboxType;
			stream >> hitboxType;
			int2 p, a, b, c;
			int r, r1, r2;
			switch (hitboxType)
			{
			case 1:
				fruit.setRectHitBox();
				break;
			case 2:
				cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
				fruit.setTriangleHitBox(a, b, c);
				break;
			case 3:
				cin >> c.x >> c.y >> r;
				fruit.setCircleHitBox(c, r);
				break;
			case 4:
				cin >> c.x >> c.y >> r1 >> r2;
				fruit.setOvalHitBox(c, r1, r2);
				break;
			}
		}
		m_allFruits.push_back(fruit);
	}

	stream.close();
}

