#pragma once
#include "Participant.h"


class DynamicParticipant : public Participant
{
public:
	//constructor
	DynamicParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

	virtual ~DynamicParticipant() = default;

	//public functions
	bool gotToTopLeft() const;
	void move(const float& seconds);
	virtual sf::Vector2f getWantedDirection() const = 0;
	void updateMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection);
	
	 


protected:
	//members
	sf::Vector2f m_curLocation;
	sf::Vector2f m_direction;
	sf::Clock m_clock;
	
	//private functions
	sf::Vector2f getNewLocation(const float& seconds) const;
	
};