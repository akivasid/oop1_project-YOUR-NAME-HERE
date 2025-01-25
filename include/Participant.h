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
	sf::Vector2f getTopLeft() const;

	virtual bool gotToTopLeft() const = 0;
	virtual const sf::Vector2f getWantedDirection() const = 0;
	virtual void updateMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection) = 0;
	virtual void move(const float& seconds) = 0;
	



protected:
	//members
	sf::Vector2f m_topLeft;
	sf::Sprite m_picture;
	ParticipantType m_type;

	//public functions
	void pictureArrangement(const sf::Vector2f& wantedSize);
};