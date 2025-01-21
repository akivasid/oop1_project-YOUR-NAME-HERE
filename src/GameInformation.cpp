#include "GameInformation.h"

//======================================= constructor =========================================

GameInformation::GameInformation()
	:m_level(0), m_rectangle(GameInfoConsts::INFO_SIZE), m_text(FontHolder::getText()), m_score(0),
	m_clock(), m_countDown(), m_life(0), m_possiblePoinst(0)
{
	m_rectangle.setPosition(GameInfoConsts::INFO_LOCATION);
	m_rectangle.setFillColor(GameInfoConsts::INFO_COLOR);
	m_text.setPosition(GameInfoConsts::TEXT_LOCATION);
}
	

//======================================= public functions =========================================

void GameInformation::initializer(int guards)
{
	m_level++;
	m_life = GameInfoConsts::LIFE;
	m_possiblePoinst = GameInfoConsts::END_LEVEL + GameInfoConsts::LEVEL_GUARD * guards;
	m_clock.restart();
	m_countDown = GameInfoConsts::LEVEL_TIME;
	updateOutput();
}


void GameInformation::updateOutput()
{
	updateCountDown();

	std::string str = GameInfoConsts::LEVEL_OUTPUT + std::to_string(m_level) + '\n'
		+ GameInfoConsts::LIFE_OUTPUT + std::to_string(m_life) + '\n' 
		+ GameInfoConsts::SCORE_OUTPUT + std::to_string(m_score) + '\n'
		+ GameInfoConsts::TIME_OUTPUT + std::to_string(static_cast <int>(m_countDown.asSeconds()) / 60)
		+ ":" + (((static_cast <int>(m_countDown.asSeconds()) % 60) < 10) ? "0" :"")
		+ std::to_string(static_cast <int>(m_countDown.asSeconds()) % 60) ;

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

void GameInformation::updateCountDown()
{
	m_countDown -= m_clock.restart();
}

bool GameInformation::timeEnded() const
{
	if (m_countDown.asMicroseconds() <= 0)
		return true;
	return false;
}