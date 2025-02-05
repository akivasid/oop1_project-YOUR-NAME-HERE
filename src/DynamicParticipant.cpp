#include "DynamicParticipant.h"

DynamicParticipant::DynamicParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type, const float& speed)
	:Participant(location, wantedSize, type), m_direction(0.f, 0.f), m_curLocation(location), m_firstLocation(m_curLocation), m_speed(speed)
{}

void DynamicParticipant::setTopLeft(const sf::Vector2f& newTopLeft)
{
	m_topLeft = newTopLeft;
}


void DynamicParticipant::resetLocation()
{
	m_topLeft = m_firstLocation;
	m_curLocation = m_topLeft;
	m_direction = MovementConsts::NO_DIRECTION;
	m_picture.setPosition(m_topLeft);
}

sf::Vector2f DynamicParticipant::getDirection() const
{
	return m_direction;
}


void DynamicParticipant::setDirection(const sf::Vector2f& newDirection)
{
	m_direction = newDirection;
}


bool DynamicParticipant::gotToTopLeft() const
{
	return m_curLocation == m_topLeft;
}




void DynamicParticipant::move(const float& seconds)
{
	if ((m_curLocation.x - m_topLeft.x < 2 && m_curLocation.x - m_topLeft.x > -2) &&
		(m_curLocation.y - m_topLeft.y < 2 && m_curLocation.y - m_topLeft.y > -2))
	{
		m_curLocation = m_topLeft;
		m_direction = MovementConsts::NO_DIRECTION;
		m_picture.setPosition(m_topLeft);
		return;
	}

	m_curLocation = getNewLocation(seconds);
	m_picture.setPosition(m_curLocation);
}


sf::Vector2f DynamicParticipant::getNewLocation(const float& seconds) const
{
	return sf::Vector2f(m_curLocation.x + m_direction.x * seconds * m_speed,
		m_curLocation.y + m_direction.y * seconds * m_speed);
}
