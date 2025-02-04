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
class Bomb;


class Participant
{
public:
	//constructor
	Participant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type);

	virtual ~Participant() = default;

	//public
	sf::Vector2f getTopLeft() const;
	const ParticipantType getType() const;
	void draw(GameWindow& gameWindow);
	bool getDeadOrAlive() const;
	void setDead();

	
	virtual void handleCollision(Participant& obj , GameInformation& gameInfo) = 0;
	virtual void handleCollision(SmartGuard& guard, GameInformation& gameInfo) = 0;
	virtual void handleCollision(DumbGuard& guard , GameInformation& gameInfo) = 0;
	virtual void handleCollision(Player& player   , GameInformation& gameInfo) = 0;
	virtual void handleCollision(Bomb& bomb  , GameInformation& gameInfo) = 0;
	

protected:
	//members
	sf::Vector2f m_topLeft;
	sf::Sprite m_picture;
	bool m_objectState;
	ParticipantType m_type;

	//public functions
	void pictureArrangement(const sf::Vector2f& wantedSize);
	
};