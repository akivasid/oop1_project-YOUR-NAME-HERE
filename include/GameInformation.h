#pragma once
#include "GameInfoConsts.h"
#include "FontHolder.h"
#include "GameWindow.h"
#include <iostream>

class GameInformation
{
public:
	//constructor
	GameInformation();

	//public functions
	void initializer(int guards);
	void updateOutput();
	const sf::RectangleShape& getInfoRec() const;
	void drawInfo(GameWindow& window);
	bool timeEnded() const;
	void updateCountDown();
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


private:
	//members
	sf::Vector2f m_playerLocation;
	unsigned m_level;
	sf::Text m_levelText;
	int m_life;
	sf::Text m_lifeText;
	unsigned m_score;
	sf::Text m_scoreText;
	unsigned m_possiblePoints;
	sf::Clock m_clock;
	sf::Time m_countDown;
	sf::Text m_timeText;
	bool m_winStatus;
	sf::RectangleShape m_rectangle;
	bool m_killGuard;
	bool m_freezeGuards;
	sf::Time m_freezeTime;
	sf::Clock m_freezeClock;
};

