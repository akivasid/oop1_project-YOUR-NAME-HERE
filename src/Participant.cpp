#include "Participant.h"


//================================== constructor =====================================

Participant::Participant(const sf::Vector2f& location, const ParticipantType& type)
	:m_location(location), m_type(type)
{
	pictureArrangement();
}

//================================== public functions =====================================



//================================== private functions =====================================

void Participant::pictureArrangement()
{
	switch (m_type)
	{
	case ParticipantType::Player:
		m_picture = Images::getSpritePlayer();
		break;
	case ParticipantType::Guard:
		m_picture = Images::getSpriteGuard();
		break;
	case ParticipantType::Door:
		m_picture = Images::getSpriteDoor();
		break;
	case ParticipantType::Rock:
		m_picture = Images::getSpriteRock();
		break;
	case ParticipantType::Wall:
		m_picture = Images::getSpriteWall();
		break;
	case ParticipantType::GiftKillGuard:
		break;
	case ParticipantType::GiftAddTime:
		break;
	case ParticipantType::GiftFreezeGuards:
		break;
	case ParticipantType::GiftAddLife:
		break;
	default:
		break;
	}

}