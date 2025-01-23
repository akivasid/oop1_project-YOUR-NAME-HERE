#pragma once
#include "Participant.h"


class DynamicParticipant : public Participant
{
public:
	DynamicParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

	virtual ~DynamicParticipant() = default;

	 virtual const sf::Vector2f getWantedDirection() = 0;
	 virtual const sf::Vector2f getDirection() const = 0;
	 virtual void resetDirection() = 0;
	 virtual void move(const sf::Vector2f& newLoc) = 0;
	 virtual const sf::Vector2f getNewLocation(const sf::Vector2f& direction, const float& seconds) const = 0;


protected:
	sf::Vector2f m_direction;
};