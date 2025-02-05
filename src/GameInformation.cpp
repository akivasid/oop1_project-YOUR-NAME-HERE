#include "GameInformation.h"

//======================================= constructor =========================================

GameInformation::GameInformation()
	:m_level(0),m_gameClock(), m_countDown(), m_life(GameInfoConsts::LIFE), m_possiblePoints(0),
	m_score(0),m_winStatus(false), m_killGuard(false), m_freezeGuards(false), m_freezeTime(sf::seconds(5)), m_freezeClock()
{}
	

//======================================= public functions =========================================

void GameInformation::initializer(int guards)
{
	m_level++;
	m_winStatus = false;
	m_life = GameInfoConsts::LIFE;
	m_score += m_possiblePoints;
	m_possiblePoints = GameInfoConsts::END_LEVEL + GameInfoConsts::LEVEL_GUARD * guards;
	m_gameClock.restart();
	m_countDown = GameInfoConsts::LEVEL_TIME;
	m_freezeGuards = false;
	m_killGuard = false;
	m_infoView.updateOutput(m_level, m_life, m_score, m_countDown.asSeconds());
}


void GameInformation::updateOutput()
{
	updateCountDown();
	m_infoView.updateOutput(m_level, m_life, m_score, m_countDown.asSeconds());
}


void GameInformation::drawInfo(GameWindow& window)
{
	updateOutput();
	m_infoView.draw(window);
}


void GameInformation::updateCountDown()
{
	m_countDown -= m_gameClock.restart();
}


bool GameInformation::timeEnded() const
{
	if (m_countDown.asSeconds() <= 0)
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


void GameInformation::lostLife()
{
	m_life = m_life -1;
}

void GameInformation::addLife()
{
	m_life = m_life + 1;
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

void GameInformation::setScoreKillGuard()
{
	m_score += GameInfoConsts::KILL_GUARD;
}