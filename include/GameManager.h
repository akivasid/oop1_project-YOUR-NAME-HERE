#pragma once
#include <memory>
#include <fstream>
#include <string>
#include "ParticipantsCharId.h"
#include "GameWindow.h"
#include "GameWindowConsts.h"
#include "GameInformation.h"
#include "Player.h"
#include "DumbGuard.h"
#include "SmartGuard.h"
#include "Wall.h"
#include "Rock.h"
#include "Door.h"
#include "Bomb.h"
#include "GiftAddTime.h"
#include "GiftKillGuard.h"
#include "GiftFreezeGuards.h"
#include "GiftAddLife.h"



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
	sf::Clock m_clock;
	std::vector <std::unique_ptr<DynamicParticipant>> m_dynamic;
	std::vector <std::unique_ptr <StaticParticipant> > m_static;
	std::vector <std::unique_ptr <Bomb>> m_bombs;
	
	//private functions
	void setLevel(const std::string& nameLevel);
	void readFile(int& row, int& col, const std::string& nameLevel);
	void updateObjects(const std::string& nameLevel, int& guards);
	void createGifts(const int row, const int col);
	void createBomb(const sf::Event& event);
	void handleBombs();
	void handleBombCollisions(int i);
	bool handleBombOnDynamic(const int index, const int prevLife);
	void handleBombOnStatic(const int index, const int prevLife);
	void handleEvents();
	void handleMovement();
	void manageDynamicCollisions(const sf::Vector2f& prevTopLeft, const int index);
	bool manageDynamicOnStatic(const int index, const int prevLife, const sf::Vector2f& prevTopLeft);
	void manageDynamicOnDynamic(const int index, const int prevLife, const sf::Vector2f& prevTopLeft);
	void manageLostLife();
	void clearDeadObjects();
	void updateWindow();
	void clearObjects();
};