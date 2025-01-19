#include "GameInformation.h"

//======================================= constructor =========================================

GameInformation::GameInformation(const int guardAmount)
	:m_level(1), m_life(GameInfoConsts::LIFE), m_possiblePoinst(GameInfoConsts::END_LEVEL + GameInfoConsts::LEVEL_GUARD * guardAmount),
	m_rectangle(GameInfoConsts::INFO_SIZE), m_text(FontHolder::getText()), m_score(0)
{
	m_rectangle.setPosition(GameInfoConsts::INFO_LOCATION);
	m_rectangle.setFillColor(GameInfoConsts::INFO_COLOR);
	m_text.setPosition(GameInfoConsts::TEXT_LOCATION);
	updateOutput();
}
	

void GameInformation::updateOutput()
{
	std::string str = GameInfoConsts::LEVEL_OUTPUT + std::to_string(m_level) + '\n'
		+ GameInfoConsts::LIFE_OUTPUT + std::to_string(m_life) + '\n' 
		+ GameInfoConsts::SCORE_OUTPUT + std::to_string(m_score) + '\n';
	m_text.setString(str);
}


const sf::Text& GameInformation::getInfoOutput() const
{
	return m_text;
}


const sf::RectangleShape& GameInformation::getInfoRec() const
{
	return m_rectangle;
}