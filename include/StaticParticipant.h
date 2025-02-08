#pragma once
#include "Participant.h"
#include "Player.h"
#include "SmartGuard.h"
#include "DumbGuard.h"


class StaticParticipant : public Participant
{
public:
	//constructor
	StaticParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

protected:

};
