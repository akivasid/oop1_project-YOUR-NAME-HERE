#include "Guard.h"


//====================================== constructor =================================
Guard::Guard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Guard)
{}

//===================================== public functions =============================

const sf::Vector2f Guard::getWantedDirection()
{
	m_direction = sf::Vector2f(1.f, 0.f);
	return m_direction;
}


void Guard::move(const sf::Vector2f& newLoc)
{
	if (newLoc == m_location)
		return;
	m_picture.setPosition(newLoc);
	m_location = newLoc;
}


const sf::Vector2f Guard::getNewLocation(const sf::Vector2f& direction, const float& seconds) const
{
	return sf::Vector2f(m_location.x + direction.x * seconds * MovementConsts::PIXEL_PER_SECOND,
		m_location.y + direction.y * seconds * MovementConsts::PIXEL_PER_SECOND);
}

const sf::Vector2f Guard::getDirection() const
{
	return m_direction;
}

void Guard::resetDirection()
{
	m_direction = sf::Vector2f(0.f, 0.f);
}