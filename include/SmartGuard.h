#pragma once
#include "Guard.h"
#include "GameInformation.h"
#include "DumbGuard.h"
#include "Bomb.h"

class Player;

class SmartGuard : public Guard
{
public:
	//constructor
	SmartGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	void updateMovement(GameWindow& gameWindow, GameInformation& gameInfo) override;
	void handleCollision(Participant& obj, GameInformation& gameInfo) override;
	void handleCollision(SmartGuard& guard, GameInformation& gameInfo) override;
	void handleCollision(DumbGuard& guard, GameInformation& gameInfo) override;
	void handleCollision(Player& player, GameInformation& gameInfo) override;
	void handleCollision(Bomb& bomb, GameInformation& gameInfo) override;
	
private:
	//members
	sf::Vector2f m_target;
	bool m_stuckInPlace;
	
	//private functions
	void changeDirection();
};