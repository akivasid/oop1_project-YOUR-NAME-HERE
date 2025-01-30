#include "SmartGuard.h"

SmartGuard::SmartGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Guard(location, wantedSize), m_target(location)
{}


sf::Vector2f SmartGuard::getWantedDirection() const
{
	if (m_topLeft != m_prevLocation) {
		if (m_target.x > m_topLeft.x)
			return MovementConsts::DIRECTION_RIGHT;
		if (m_target.x < m_topLeft.x)
			return MovementConsts::DIRECTION_LEFT;
		if (m_target.y < m_topLeft.y)
			return MovementConsts::DIRECTION_UP;
		if (m_target.y > m_topLeft.y)
			return MovementConsts::DIRECTION_DOWN;
	}

	else 
	{
		int directionRandom = std::rand() % 4;
		switch (directionRandom)
		{
		case  0:
			return MovementConsts::DIRECTION_RIGHT;
			break;
		case 1:
			return MovementConsts::DIRECTION_LEFT;
			break;
		case 2:
			return MovementConsts::DIRECTION_UP;
			break;
		case 3:
			return MovementConsts::DIRECTION_DOWN;
			break;
		}
	}
	return MovementConsts::NO_DIRECTION;
}

void SmartGuard::updateMovement(GameWindow& gameWindow, GameInformation& gameInfo, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	m_target = gameInfo.getPlayerLocation();
	newDirection = getWantedDirection();
	newTopLeft = gameWindow.getNextTopLeft(m_topLeft, newDirection);
	if (!gameWindow.inArea(newTopLeft))
	{
		newDirection = MovementConsts::NO_DIRECTION;
		newTopLeft = m_topLeft;
	}
}

void SmartGuard::handleCollision(GameInformation& gameInfo, Participant& obj, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	obj.handleCollision(gameInfo, *this, newDirection, newTopLeft);
}

void SmartGuard::handleCollision(GameInformation& gameInfo, Player& player,	sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	if (newTopLeft == m_topLeft)
		gameInfo.setLife();	
}

void SmartGuard::handleCollision(GameInformation& gameInfo, DumbGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{}


void SmartGuard::handleCollision(GameInformation& gameInfo, SmartGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{}


void SmartGuard::finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection)
{
	m_prevLocation = m_topLeft;
	m_topLeft = newTopLeft;
	m_direction = newDirection;
}