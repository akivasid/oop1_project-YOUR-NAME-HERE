#include "GameInformation.h"

//======================================= constructor =========================================

GameInformation::GameInformation()
	:m_level(0), m_rectangle(GameInfoConsts::INFO_SIZE), m_clock(), m_countDown(), m_life(GameInfoConsts::LIFE), m_possiblePoints(0),
	m_score(0),m_winStatus(false), m_lifeText(FontHolder::getText()), m_levelText(FontHolder::getText()), 
	m_timeText(FontHolder::getText()), m_scoreText(FontHolder::getText()), m_killGuard(false), m_freezeGuards(false),
	m_freezeTime(sf::seconds(5)), m_freezeClock()
{
	m_rectangle.setPosition(GameInfoConsts::INFO_LOCATION);
	m_rectangle.setFillColor(GameInfoConsts::INFO_COLOR);
	m_lifeText.setPosition(GameInfoConsts::LIFE_TEXT_LOCATION);
	m_timeText.setPosition(GameInfoConsts::TIME_TEXT_LOCATION);
	m_scoreText.setPosition(GameInfoConsts::SCORE_TEXT_LOCATION);
	m_levelText.setPosition(GameInfoConsts::LEVEL_TEXT_LOCATION);
}
	

//======================================= public functions =========================================

void GameInformation::initializer(int guards)
{
	m_level++;
	m_winStatus = false;
	m_life = GameInfoConsts::LIFE;
	m_possiblePoints = GameInfoConsts::END_LEVEL + GameInfoConsts::LEVEL_GUARD * guards;
	m_clock.restart();
	m_countDown = GameInfoConsts::LEVEL_TIME;
	updateOutput();
}


void GameInformation::updateOutput()
{
	updateCountDown();

	std::string levelStr = GameInfoConsts::LEVEL_OUTPUT + std::to_string(m_level);
	std::string lifeStr = GameInfoConsts::LIFE_OUTPUT + std::to_string(m_life);
	std::string scoreStr = GameInfoConsts::SCORE_OUTPUT + std::to_string(m_score);
	std::string timeStr = GameInfoConsts::TIME_OUTPUT + std::to_string(static_cast <int>(m_countDown.asSeconds()) / 60)
		+ ":" + (((static_cast <int>(m_countDown.asSeconds()) % 60) < 10) ? "0" : "")
		+ std::to_string(static_cast <int>(m_countDown.asSeconds()) % 60);
	
	m_levelText.setString(levelStr);
	m_lifeText.setString(lifeStr);
	m_scoreText.setString(scoreStr);
	m_timeText.setString(timeStr);	
}


void GameInformation::drawInfo(GameWindow& window)
{
	updateOutput();
	window.draw(m_rectangle);
	window.draw(m_lifeText);
	window.draw(m_timeText);
	window.draw(m_levelText);
	window.draw(m_scoreText);
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


void GameInformation::setPlayerLocation(const sf::Vector2f& newLocation)
{
	m_playerLocation = newLocation;
}


sf::Vector2f GameInformation::getPlayerLocation() const
{
	return m_playerLocation;
}


void GameInformation::setLife()
{
	m_life = m_life -1;
}


int GameInformation::getLife() const
{
	return m_life;
}


void GameInformation::setPlayerWon()
{
	m_winStatus = true;
}


bool GameInformation::getPlayerStatus() const
{
	return m_winStatus;
}

void GameInformation::addToTime(const sf::Time& addTime)
{
	m_countDown += addTime;
}

bool GameInformation::getKillGuard()
{
	return m_killGuard;
}

void GameInformation::setKillGuard(const bool kill)
{
	m_killGuard = kill;
}

void GameInformation::setFreezeGuards()
{
	m_freezeGuards = true;
	m_freezeClock.restart();
}


bool GameInformation::getFreezeGuards()
{
	if (m_freezeGuards && m_freezeClock.getElapsedTime() >= m_freezeTime)
		m_freezeGuards = false;
	return m_freezeGuards;		
}