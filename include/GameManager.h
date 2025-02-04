#pragma once
#include <memory>
#include <fstream>
#include <string>
#include "ParticipantsCharId.h"
#include "GameWindow.h"
#include "GameInformation.h"
#include "Player.h"
#include "DumbGuard.h"
#include "SmartGuard.h"
#include "Wall.h"
#include "Rock.h"
#include "Door.h"
#include "Bomb.h"



class GameManager
{
public:
	//constructor
	GameManager();

	//public functions
	void runGame();



private:
	//members
	GameInformation m_gameInfo;
	GameWindow m_gameWindow;
	std::vector <std::unique_ptr<DynamicParticipant>> m_dynamic;
	std::vector <std::unique_ptr <StaticParticipant> > m_static;
	std::vector <std::unique_ptr <Bomb>> m_bombs;
	
	//private functions
	void setLevel(const std::string& nameLevel);
	void readFile(int& row, int& col, const std::string& nameLevel);
	void updateObjects(const std::string& nameLevel, int& guards);
	void handleBombs();
	void handleBombCollisions(int i);
	void handleEvents();
	void handleMovement(sf::Clock& clock);
	void createBombs();
	void manageDynamicCollisions(const sf::Vector2f& prevTopLeft, const int i);
	void manageFirstLocations();
	void clearDeadObjects();
	void updateWindow();
	void clearObjects();
};