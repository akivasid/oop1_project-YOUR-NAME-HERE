#include "SmartGuard.h"

SmartGuard::SmartGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Guard(location, wantedSize), m_target(location), m_stuckInPlace(false)
{}


void SmartGuard::changeDirection()
{
	if (!m_stuckInPlace) 
	{
		if (m_target.x > m_topLeft.x)
			m_direction = MovementConsts::DIRECTION_RIGHT;
		else if (m_target.x < m_topLeft.x)
			m_direction = MovementConsts::DIRECTION_LEFT;
		else if (m_target.y < m_topLeft.y)
			m_direction = MovementConsts::DIRECTION_UP;
		else if (m_target.y > m_topLeft.y)
			m_direction = MovementConsts::DIRECTION_DOWN;
		else
			m_direction = MovementConsts::NO_DIRECTION;
	}

	else 
	{
		int directionRandom = std::rand() % 4;
		switch (directionRandom)
		{
		case  0:
			m_direction = MovementConsts::DIRECTION_RIGHT;
			return;
		case 1:
			m_direction = MovementConsts::DIRECTION_LEFT;
			return;
		case 2:
			m_direction = MovementConsts::DIRECTION_UP;
			return;
		case 3:
			m_direction = MovementConsts::DIRECTION_DOWN;
			return;
		}
	}
}

void SmartGuard::updateMovement(GameWindow& gameWindow, GameInformation& gameInfo)
{

	m_target = gameInfo.getPlayerLocation();
	changeDirection();
	sf::Vector2f newTopLeft = gameWindow.getNextTopLeft(m_topLeft, m_direction);
	if (gameWindow.inArea(newTopLeft))
		m_topLeft = newTopLeft;

	else
	{
		m_stuckInPlace = true;
		m_direction = MovementConsts::NO_DIRECTION;
	}
}

void SmartGuard::handleCollision(Participant& obj, GameInformation& gameInfo)
{
	if (gameInfo.getKillGuard())
	{
		setDead();
		m_direction = MovementConsts::NO_DIRECTION;
		gameInfo.setKillGuard(false);
		return;
	}

	if (gameInfo.getFreezeGuards())
	{
		m_direction = MovementConsts::NO_DIRECTION;
		return;
	}

	obj.handleCollision(*this, gameInfo);

	if (m_direction == MovementConsts::NO_DIRECTION)
		m_stuckInPlace = true;
	else
		m_stuckInPlace = false;
}

void SmartGuard::handleCollision(Player& player, GameInformation& gameInfo)
{
	if (gameInfo.getPlayerLocation() == m_topLeft)
		gameInfo.lostLife();	
}


void SmartGuard::handleCollision(DumbGuard& guard, GameInformation& gameInfo)
{}


void SmartGuard::handleCollision(SmartGuard& guard, GameInformation& gameInfo)
{}


void SmartGuard::handleCollision(Bomb& bomb, GameInformation& gameInfo)
{
	if (bomb.bombExploded() && bomb.inExplosionArea(m_topLeft))
		setDead();
}