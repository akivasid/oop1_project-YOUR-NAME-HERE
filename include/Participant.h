#pragma once
#include "Images.h"
#include "ParticipantType.h"
#include "MovementConsts.h"



class Participant
{
public:
	//constructor
	Participant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

	virtual ~Participant() = default;

	//public
	sf::Sprite getParticipantSprite() const;
	sf::Vector2f getLocation() const;
	virtual const sf::Vector2f getDirection() const = 0;
	virtual void move(const sf::Vector2f& newLoc) = 0;
	virtual const sf::Vector2f getNewLocation(const sf::Vector2f& direction, const float& seconds) const = 0;



protected:
	//members
	sf::Vector2f m_location;
	sf::Sprite m_picture;
	ParticipantType m_type;

	//public functions
	void pictureArrangement(const sf::Vector2f& wantedSize);
};