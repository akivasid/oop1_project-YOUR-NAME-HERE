#pragma once
#include "Images.h"
#include "ParticipantType.h"
#include "MovementConsts.h"
#include "GameInformation.h"



class Participant
{
public:
	//constructor
	Participant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

	virtual ~Participant() = default;

	//public
	sf::Sprite getParticipantSprite() const;
	sf::Vector2f getTopLeft() const;
	const ParticipantType getType() const;

	virtual void handleCollision(GameInformation& m_gameInfo, sf::Vector2f& newTopLeft,
									sf::Vector2f& newDirection, Participant& obj) = 0;
	

protected:
	//members
	sf::Vector2f m_topLeft;
	sf::Sprite m_picture;
	ParticipantType m_type;

	//public functions
	void pictureArrangement(const sf::Vector2f& wantedSize);
};