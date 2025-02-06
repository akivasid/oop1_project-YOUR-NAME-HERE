#include "GeneralManager.h"


//============================================ constructor ==================================

GeneralManager::GeneralManager()
	:m_welcomeWindow()
{}


//============================================ public functions ==================================

void GeneralManager::runProgram()
{ 
	m_welcomeWindow.draw();
	if (m_welcomeWindow.handleEvent())
	{
		m_welcomeWindow.close();
		GameManager game;
		game.runGame();
	}
}