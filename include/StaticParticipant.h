#pragma once
#include "Participant.h"


class StaticParticipant : public Participant
{
public:
	//constructor
	StaticParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

	virtual void handleCollision(GameInformation& m_gameInfo, sf::Vector2f& newTopLeft,
		sf::Vector2f& newDirection, Participant& obj) = 0;

protected:

};
