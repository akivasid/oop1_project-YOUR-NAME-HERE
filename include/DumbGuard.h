#pragma once
#include "Guard.h"
#include "GameInformation.h"
//#include "Player.h"
//#include "SmartGuard.h"


class DumbGuard : public Guard
{
public:
	//constructor
	DumbGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	void updateMovement(GameWindow& gameWindow, GameInformation& gameInfo, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameInformation& gameInfo, Participant& obj, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameInformation& gameInfo, SmartGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameInformation& gameInfo, Player& player,	sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameInformation& gameInfo, DumbGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	
	void finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection) override;
	
private:
	sf::Vector2f getWantedDirection() const;
};