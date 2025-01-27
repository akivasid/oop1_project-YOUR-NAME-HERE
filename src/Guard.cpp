#include "Guard.h"


//====================================== constructor =================================
Guard::Guard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Guard)
{}

//===================================== public functions =============================

//
//sf::Vector2f Guard::getWantedDirection() const
//{
//	int directionRando = std::rand() % 4;
//	switch (directionRando)
//	{
//	case  0:
//		return MovementConsts::DIRECTION_RIGHT;
//		break;
//	case 1:
//		return MovementConsts::DIRECTION_LEFT;
//		break;
//	case 2:
//		return MovementConsts::DIRECTION_UP;
//		break;
//	case 3:
//		return MovementConsts::DIRECTION_DOWN;
//		break;
//	}
//	return MovementConsts::NO_DIRECTION;	
//}


void Guard::handleCollision(GameInformation& m_gameInfo, sf::Vector2f& newTopLeft,
	sf::Vector2f& newDirection, Participant& obj)
{
	/*if (obj.getTopLeft() != newTopLeft)
		updateMovement(newTopLeft, newDirection);*/
	obj.handleCollision(m_gameInfo, newTopLeft, newDirection, *this);
}
