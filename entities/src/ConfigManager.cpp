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

fstream stream;
void ConfigManager::loadFruits()
{
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

	Fruit bomb;

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
			bomb.initBomb(width, height, text, textSpl, splSize, splTime);
			bomb.setHitBox();
		}
		else
		{
			stream >> widthCut >> heightCut >> slices >> splash;
			SDL_Texture* textCut = loadTexture(GAME_FOLDER + FRUITS_FOLDER + name + "_cut.bmp");
			SDL_Texture* textSpl = loadTexture(GAME_FOLDER + SPLASHES_FOLDER + splash + "Splash.bmp");
			fruit.init(width, height, widthCut, heightCut, slices, text, textCut, textSpl, m_splashSize, m_splashTime);
			fruit.setHitBox();
			m_allFruits.push_back(fruit);
		}
	}
	m_allFruits.push_back(bomb);

	stream.close();
}

int ConfigManager::inputIntFromFile()
{
	string tmp;
	stream >> tmp;
	return stoi(tmp);
}

