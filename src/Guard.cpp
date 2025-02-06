#include "Guard.h"


//====================================== constructor =================================
Guard::Guard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Guard, MovementConsts::GUARD_SPEED)
{}

//===================================== public functions =============================

void Guard::resetLocation(GameInformation& gameInfo)
{
	m_topLeft = m_firstLocation;
	m_curLocation = m_topLeft;
	m_direction = MovementConsts::NO_DIRECTION;
	m_picture.setPosition(m_topLeft);
}