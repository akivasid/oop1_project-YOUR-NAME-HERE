#include "Participant.h"


//================================== constructor =====================================

Participant::Participant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type)
	:m_topLeft(location), m_type(type), m_objectState(true)
{
	pictureArrangement(wantedSize);
	m_picture.setPosition(m_topLeft);
}

//================================== public functions =====================================

const ParticipantType Participant::getType() const
{
	return m_type;
}


sf::Vector2f Participant::getTopLeft() const
{
	return m_topLeft;
}

//================================== private functions =====================================

void Participant::pictureArrangement(const sf::Vector2f& wantedSize)
{
	switch (m_type)
	{
	case ParticipantType::Player:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;
	case ParticipantType::Guard:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;
	case ParticipantType::Door:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;
	case ParticipantType::Rock:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;
	case ParticipantType::Wall:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;
	case ParticipantType::Bomb:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;
	case ParticipantType::GiftKillGuard:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;
	case ParticipantType::GiftAddTime:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;
	case ParticipantType::GiftFreezeGuards:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;
	case ParticipantType::GiftAddLife:
		m_picture = Images::getSprite(m_type, wantedSize);
		break;
	default:
		break;
	}
}

void Participant::draw(GameWindow& gameWindow)
{
	gameWindow.draw(m_picture);
}

bool Participant::getDeadOrAlive() const
{
	return m_objectState;
}

void Participant::setDead()
{
	m_objectState = false;
}