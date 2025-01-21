#pragma once
#include "GameWindow.h"
#include "GameInformation.h"
#include "Player.h"


class GameManager
{
public:
	//constructor
	GameManager();

	//public functions
	void runGame();



private:
	GameInformation m_gameInfo;
	GameWindow m_gameWindow;
	//participent

	//private functions
	void readFile(int& row, int& col, int& guards);
};