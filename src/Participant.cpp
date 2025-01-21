#include "Participant.h"


//================================== constructor =====================================

Participant::Participant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type)
	:m_location(location), m_type(type)
{
	pictureArrangement(wantedSize);
	m_picture.setPosition(m_location);
}

//================================== public functions =====================================

sf::Sprite Participant::getParticipantSprite()
{
	return m_picture;
}


//================================== private functions =====================================

void Participant::pictureArrangement(const sf::Vector2f& wantedSize)
{
	switch (m_type)
	{
	case ParticipantType::Player:
		m_picture = Images::getSprite(ParticipantType::Player, wantedSize);
		break;
	case ParticipantType::Guard:
		m_picture = Images::getSprite(ParticipantType::Guard, wantedSize);
		break;
	case ParticipantType::Door:
		m_picture = Images::getSprite(ParticipantType::Door, wantedSize);
		break;
	case ParticipantType::Rock:
		m_picture = Images::getSprite(ParticipantType::Rock, wantedSize);
		break;
	case ParticipantType::Wall:
		m_picture = Images::getSprite(ParticipantType::Wall, wantedSize);
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