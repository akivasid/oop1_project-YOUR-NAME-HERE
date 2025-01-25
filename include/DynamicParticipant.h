#pragma once
#include "Participant.h"


class DynamicParticipant : public Participant
{
public:
	//constructor
	DynamicParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

	virtual ~DynamicParticipant() = default;

	//public functions
	virtual bool gotToTopLeft() const = 0;
	virtual const sf::Vector2f getWantedDirection() const = 0;
	virtual void updateMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection) = 0;
	virtual void move(const float& seconds) = 0;
	 


protected:
	sf::Vector2f m_curLocation;
	sf::Vector2f m_direction;
};