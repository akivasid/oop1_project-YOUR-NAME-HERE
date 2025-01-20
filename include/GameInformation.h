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


private:
	//members
	unsigned m_level;
	unsigned m_life;
	unsigned m_score;
	unsigned m_possiblePoinst;

	sf::RectangleShape m_rectangle;
	sf::Text m_text;
	sf::Clock m_clock;
	sf::Time m_countDown;
};

