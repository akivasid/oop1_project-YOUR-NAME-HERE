#include "DynamicParticipant.h"


// ===================================================== constructor =====================================================
DynamicParticipant::DynamicParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type, const float& speed)
	:Participant(location, wantedSize, type), m_direction(0.f, 0.f), m_curLocation(location), m_firstLocation(m_curLocation), m_speed(speed)
{}


// ===================================================== public functions =====================================================

void DynamicParticipant::setTopLeft(const sf::Vector2f& newTopLeft)
{
	m_topLeft = newTopLeft;
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
	if ((m_direction == MovementConsts::DIRECTION_DOWN && (getNewLocation(seconds).y - m_topLeft.y) >= 0)
		|| (m_direction == MovementConsts::DIRECTION_UP && (getNewLocation(seconds).y - m_topLeft.y) <= 0)
		|| (m_direction == MovementConsts::DIRECTION_RIGHT && (getNewLocation(seconds).x - m_topLeft.x) >= 0)
		|| (m_direction == MovementConsts::DIRECTION_LEFT && (getNewLocation(seconds).x - m_topLeft.x) <= 0))
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
