#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init()
{
	m_board.load(3);
}

void Game::destroy()
{
	m_board.destroy();
}

void Game::run()
{
	m_board.update();
	m_board.draw();
}