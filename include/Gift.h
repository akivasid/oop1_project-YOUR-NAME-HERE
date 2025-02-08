#pragma once
#include "StaticParticipant.h"


class Gift : public StaticParticipant
{
public:
	//constructor
	Gift(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

private:
};