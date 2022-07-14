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
	vector<Fruit> m_allFruits;
};
