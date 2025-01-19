#pragma once
#include "GameInfoConsts.h"
#include "FontHolder.h"

class GameInformation
{
public:
	//constructor
	GameInformation(const int guardAmount);

	//public functions
	void updateOutput();
	const sf::RectangleShape& getInfoRec() const;
	const sf::Text& getInfoOutput() const;


private:
	//members
	unsigned m_level;
	unsigned m_life;
	unsigned m_score;
	unsigned m_possiblePoinst;

	sf::RectangleShape m_rectangle;
	sf::Text m_text;

};

