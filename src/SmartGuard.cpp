#include "SmartGuard.h"

SmartGuard::SmartGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Guard(location, wantedSize), m_target(location), m_downIsOpen(1), m_rightIsOpen(1), m_leftIsOpen(1), m_upIsOpen(1)
{}


sf::Vector2f SmartGuard::getWantedDirection() const
{
	if(m_target.x > m_topLeft.x)
	{
		if (m_rightIsOpen)
			return MovementConsts::DIRECTION_RIGHT;
		if (m_upIsOpen)
			return MovementConsts::DIRECTION_UP;
		if (m_downIsOpen)
			return MovementConsts::DIRECTION_DOWN;
		if (m_leftIsOpen)
			return MovementConsts::DIRECTION_LEFT;
	}

	else if (m_target.x < m_topLeft.x)
	{
		if (m_leftIsOpen)
			return MovementConsts::DIRECTION_LEFT;
		if (m_upIsOpen)
			return MovementConsts::DIRECTION_UP;
		if (m_downIsOpen)
			return MovementConsts::DIRECTION_DOWN;
		if (m_rightIsOpen)
			return MovementConsts::DIRECTION_RIGHT;
		
	}

	else if (m_target.y < m_topLeft.y)
	{
		if (m_upIsOpen)
			return MovementConsts::DIRECTION_UP;
		if (m_rightIsOpen)
			return MovementConsts::DIRECTION_RIGHT;
		if (m_leftIsOpen)
			return MovementConsts::DIRECTION_LEFT;
		if (m_downIsOpen)
			return MovementConsts::DIRECTION_DOWN;
	}

	if (m_target.y > m_topLeft.y)
	{
		if (m_downIsOpen)
			return MovementConsts::DIRECTION_DOWN;
		if (m_rightIsOpen)
			return MovementConsts::DIRECTION_RIGHT;
		if (m_upIsOpen)
			return MovementConsts::DIRECTION_UP;
		if (m_leftIsOpen)
			return MovementConsts::DIRECTION_LEFT;
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


void SmartGuard::blockDirection(const sf::Vector2f& blockedDirection)
{
	if (blockedDirection == MovementConsts::DIRECTION_DOWN)
		m_downIsOpen = false;
	if (blockedDirection == MovementConsts::DIRECTION_LEFT)
		m_leftIsOpen = false;
	if (blockedDirection == MovementConsts::DIRECTION_RIGHT)
		m_rightIsOpen = false;
	if (blockedDirection == MovementConsts::DIRECTION_UP)
		m_upIsOpen = false;
}

void SmartGuard::openDirection(const sf::Vector2f& openDirection)
{

}


void SmartGuard::handleCollision(GameWindow& gameWindow, GameInformation& gameInfo, Participant& obj,
	sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	//temps will solve the problem of remembering the last one
	obj.handleCollision(gameWindow, gameInfo, *this, newDirection, newTopLeft);
}

void SmartGuard::handleCollision(GameWindow& gameWindow, GameInformation& gameInfo, SmartGuard& guard,
	sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) 
{}

void SmartGuard::finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection)
{
	m_topLeft = newTopLeft;
	m_direction = newDirection;
	openAll();
}

void SmartGuard::openAll()
{
	m_leftIsOpen = true;
	m_rightIsOpen = true;
	m_upIsOpen = true;
	m_downIsOpen = true;
}
