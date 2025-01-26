#pragma once
#include <memory>
#include "GameWindow.h"
#include "GameInformation.h"
#include "Player.h"
#include "Guard.h"
#include "Wall.h"
#include "Rock.h"



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
	std::vector <std::unique_ptr<DynamicParticipant>> m_dynamic;
	std::vector <std::unique_ptr <StaticParticipant> > m_static;
	
	//private functions
	void readFile(int& row, int& col, int& guards);
	void setLevel();
	void handleEvents();
	void handleMovement(sf::Clock& clock);
	void updateWindow();
};