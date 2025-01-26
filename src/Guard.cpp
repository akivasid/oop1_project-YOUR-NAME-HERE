#include "Guard.h"


//====================================== constructor =================================
Guard::Guard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Guard)
{}

//===================================== public functions =============================


sf::Vector2f Guard::getWantedDirection() const
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


void Guard::handleCollision(GameInformation& m_gameInfo, sf::Vector2f& newTopLeft,
	sf::Vector2f& newDirection, Participant& obj)
{
	/*if (obj.getTopLeft() != newTopLeft)
		updateMovement(newTopLeft, newDirection);*/
	obj.handleCollision(m_gameInfo, newTopLeft, newDirection, *this);
}
