#pragma once
#include "GameInfoConsts.h"
#include "FontHolder.h"
#include "GameWindow.h"
#include "InformationView.h"
#include <iostream>

class GameInformation
{
public:
	//constructor
	GameInformation();

	//public functions
	void initializer(int guards);
	void updateOutput();
	void updateCountDown();
	void drawInfo(GameWindow& window);
	void setPlayerLocation(const sf::Vector2f& newLocation);
	sf::Vector2f getPlayerLocation() const;
	void lostLife();
	void addLife();
	int getLife() const;
	void setPlayerWon();
	bool getPlayerStatus() const;
	void addToTime(const sf::Time& addTime);
	bool getKillGuard();
	void setKillGuard(const bool kill);
	void setFreezeGuards();
	bool getFreezeGuards();
	bool timeEnded() const;
	void setScoreKillGuard();
	
	
private:
	//members
	unsigned m_level;
	int m_life;
	unsigned m_score;
	unsigned m_possiblePoints;
	sf::Clock m_gameClock;
	sf::Time m_countDown;
	sf::Vector2f m_playerLocation;
	bool m_winStatus;
	bool m_killGuard;
	bool m_freezeGuards;
	sf::Time m_freezeTime;
	sf::Clock m_freezeClock;
	InformationView m_infoView;
};
