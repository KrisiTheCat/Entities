#pragma once

#include "Unit.h"
#include "Presenter.h"
#include "defines.h"

class Entity : public Unit
{
public:
	Entity();
	~Entity();

	void update();
	void move(int2 a);

private:
	int2 m_moveDest;
	bool m_isMoving;
};