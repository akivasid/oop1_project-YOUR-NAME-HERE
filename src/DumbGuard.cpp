#include "DumbGuard.h"


DumbGuard::DumbGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Guard(location, wantedSize)
{}


sf::Vector2f DumbGuard::getWantedDirection() const
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
	return MovementConsts::NO_DIRECTION;
}

void DumbGuard::updateMovement(GameWindow& gameWindow, GameInformation& gameInfo, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	newDirection = getWantedDirection();
	newTopLeft = gameWindow.getNextTopLeft(m_topLeft, newDirection);
	if (!gameWindow.inArea(newTopLeft))
	{
		newDirection = MovementConsts::NO_DIRECTION;
		newTopLeft = m_topLeft;
	}
}



void DumbGuard::handleCollision(GameWindow& gameWindow, GameInformation& gameInfo, Participant& obj,
	sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	obj.handleCollision(gameWindow, gameInfo, *this, newDirection, newTopLeft);
}

void DumbGuard::handleCollision(GameWindow& gameWindow, GameInformation& gameInfo, SmartGuard& guard,
	sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) 
{}


void DumbGuard::finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection)
{
	m_topLeft = newTopLeft;
	m_direction = newDirection;
}
