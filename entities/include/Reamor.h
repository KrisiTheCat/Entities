#pragma once

#include "Unit.h"
#include "Presenter.h"
#include "defines.h"

class Reamor : public Unit
{
public:
	Reamor();
	~Reamor();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

private:

};