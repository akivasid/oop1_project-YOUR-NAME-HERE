#include "Guard.h"


//====================================== constructor =================================
Guard::Guard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Guard)
{}

//===================================== public functions =============================


bool Guard::gotToTopLeft() const
{
	return m_curLocation == m_topLeft;
}


const sf::Vector2f Guard::getWantedDirection() const
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return MovementConsts::DIRECTION_RIGHT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return MovementConsts::DIRECTION_LEFT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return MovementConsts::DIRECTION_UP;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return MovementConsts::DIRECTION_DOWN;
	return MovementConsts::NO_DIRECTION;
}


void Guard::updateMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection)
{
	m_topLeft = newTopLeft;
	m_direction = newDirection;
}



void Guard::move(const float& seconds)
{
	if ((m_curLocation.x - m_topLeft.x < 3 && m_curLocation.x - m_topLeft.x > -3) &&
		(m_curLocation.y - m_topLeft.y < 3 && m_curLocation.y - m_topLeft.y > -3))
	{
		m_curLocation = m_topLeft;
		m_direction = MovementConsts::NO_DIRECTION;
		m_picture.setPosition(m_topLeft);
		return;
	}

	m_curLocation = getNewLocation(seconds);
	m_picture.setPosition(m_curLocation);
}


sf::Vector2f Guard::getNewLocation(const float& seconds) const
{
	return sf::Vector2f(m_curLocation.x + m_direction.x * seconds * MovementConsts::PIXEL_PER_SECOND,
		m_curLocation.y + m_direction.y * seconds * MovementConsts::PIXEL_PER_SECOND);
}