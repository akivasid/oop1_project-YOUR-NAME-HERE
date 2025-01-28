#pragma once
#include "Images.h"
#include "ParticipantType.h"
#include "MovementConsts.h"
#include "GameInformation.h"
#include "GameWindow.h"

class SmartGuard;
class DumbGuard;
class Player;
class Rock;
class Wall;


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

	
	virtual void handleCollision(GameWindow& gameWindow, GameInformation& gameInfo, Participant& obj,
								sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) = 0;
	virtual void handleCollision(GameWindow& gameWindow, GameInformation& gameInfo, SmartGuard& guard,
								sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) = 0;
	

protected:
	//members
	sf::Vector2f m_topLeft;
	sf::Sprite m_picture;
	bool m_objectState;
	ParticipantType m_type;

	//public functions
	void pictureArrangement(const sf::Vector2f& wantedSize);
};