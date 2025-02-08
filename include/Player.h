#pragma once
#include "DynamicParticipant.h"
#include "DumbGuard.h"
#include "SmartGuard.h"
#include "Bomb.h"


class Player : public DynamicParticipant
{
public:
	//constructor
	Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	void updateMovement(GameWindow& gameWindow, GameInformation& gameInfo) override;
	void handleCollision(Participant& obj, GameInformation& gameInfo) override;
	void handleCollision(SmartGuard& guard, GameInformation& gameInfo) override;
	void handleCollision(DumbGuard& guard, GameInformation& gameInfo) override;
	void handleCollision(Player& player, GameInformation& gameInfo) override;
	void handleCollision(Bomb& bomb, GameInformation& gameInfo) override;
	void resetLocation(GameInformation& gameInfo) override;

	  
private:
	//private functions
	void changeDirection();	
};