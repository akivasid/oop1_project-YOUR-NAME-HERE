#include "GameManager.h"


//============================================ constructor ==================================
GameManager::GameManager()
	:m_gameInfo(), m_gameWindow()
{}

//============================================ public functions ==================================

void GameManager::runGame()
{
	int row = 0;
	int col = 0;
	int guards = 0;
	readFile(row, col, guards);
	m_gameInfo.initializer(guards);
	m_gameWindow.initializer(row, col);


	while (true)
	{
		m_gameWindow.clear();
		m_gameInfo.updateOutput();
		m_gameWindow.draw(m_gameInfo.getInfoRec());
		m_gameWindow.draw(m_gameInfo.getInfoOutput());
		m_gameWindow.display();
	}



}


//============================================ private functions ==================================

void GameManager::readFile(int& row, int& col, int& guards)
{
	//read file/playlist
	row = 10;
	col = 10;
}