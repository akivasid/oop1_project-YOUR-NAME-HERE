#pragma once
#include "GameInfoConsts.h"
#include "FontHolder.h"

class GameInformation
{
public:
	//constructor
	GameInformation();

	//public functions
	void initializer(int guards);
	void updateOutput();
	const sf::RectangleShape& getInfoRec() const;
	const sf::Text& getInfoOutput() const;
	bool timeEnded() const;
	void updateCountDown();
	void setPlayerLocation(const sf::Vector2f& newLocation);
	sf::Vector2f getPlayerLocation() const;


private:
	//members
	unsigned m_level;
	unsigned m_life;
	unsigned m_score;
	unsigned m_possiblePoints;

	sf::RectangleShape m_rectangle;
	sf::Text m_text;
	sf::Clock m_clock;
	sf::Time m_countDown;
	sf::Vector2f m_playerLocation;
};

