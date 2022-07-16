#pragma once

#include "defines.h"
#include "Fruit.h"

#include <fstream>

class ConfigManager
{

public:
	ConfigManager();
	~ConfigManager();

	void load();
	void loadFruits();

	int2 m_splashSize;
	int2 m_fruitsInWave;
	int2 m_timeBetweenWaves;
	int2 m_timeBetweenFruits;
	int2 m_speedX;
	int2 m_speedY;
	int m_splashTime;
	int m_bombsInWave;
	int m_width = 1920;
	int m_height = 1080;
	vector<Fruit> m_allFruits;
};
