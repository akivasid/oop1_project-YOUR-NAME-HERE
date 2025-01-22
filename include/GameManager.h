#pragma once
#include <memory>
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
	std::vector <std::unique_ptr<Participant>> m_dynamic;
	//std::vector <std::unique_ptr <Participant> > m_static;
	
	//private functions
	void readFile(int& row, int& col, int& guards);
	void setLevel();
	void handleEvents();
	void handleMovement(sf::Clock& clock);
	void takeToTopLeft(const sf::Vector2f& direction, int index);
	void updateWindow();

};