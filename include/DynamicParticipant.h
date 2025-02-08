#pragma once
#include "Participant.h"


class DynamicParticipant : public Participant
{
public:
	//constructor
	DynamicParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type, const float& speed);

	//desructor
	virtual ~DynamicParticipant() = default;

	//public functions
	void setTopLeft(const sf::Vector2f& newTopLeft);
	void setDirection(const sf::Vector2f& newDirection);
	bool gotToTopLeft() const;
	sf::Vector2f getDirection() const;
	void move(const float& seconds);
	virtual void resetLocation(GameInformation& gameInfo) = 0;
	virtual void updateMovement(GameWindow& gameWindow, GameInformation& gameInfo) = 0;

protected:
	//members
	sf::Vector2f m_curLocation;
	sf::Vector2f m_direction;
	const sf::Vector2f m_firstLocation;
	float m_speed;
	
	//private functions
	sf::Vector2f getNewLocation(const float& seconds) const;
};