#pragma once
#include "Images.h"
#include "ParticipantType.h"



class Participant
{
public:
	//constructor
	Participant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

	//public
	sf::Sprite getParticipantSprite();



protected:
	//members
	sf::Vector2f m_location;
	sf::Sprite m_picture;
	ParticipantType m_type;

	//public functions
	void pictureArrangement(const sf::Vector2f& wantedSize);
};