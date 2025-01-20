#pragma once
#include "Images.h"
#include "ParticipantType.h"



class Participant
{
	Participant(const sf::Vector2f& location, const ParticipantType& type);





protected:
	//members
	sf::Vector2f m_location;
	sf::Sprite m_picture;
	ParticipantType m_type;

	//public functions
	void pictureArrangement();
};