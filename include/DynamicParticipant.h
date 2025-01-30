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
	void resetLocation();
	sf::Vector2f getDirection() const;
	void setDirection(const sf::Vector2f& newDirection);
	void move(const float& seconds);
	virtual void finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection) = 0;
	virtual void updateMovement(GameWindow& gameWindow, GameInformation& gameInfo, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) = 0;
	


protected:
	//members
	sf::Vector2f m_curLocation;
	sf::Vector2f m_direction;
	const sf::Vector2f m_firstLocation;
	//sf::Clock m_clock;
	
	//private functions
	sf::Vector2f getNewLocation(const float& seconds) const;
	
};