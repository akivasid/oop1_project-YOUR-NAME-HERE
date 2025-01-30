#pragma once
#include "DynamicParticipant.h"

/*
class DumbGuard;
class SmartGuard*/;


class Player : public DynamicParticipant
{
public:
	//constructor
	Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	

	void updateMovement(GameWindow& gameWindow, GameInformation& gameInfo, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection) override;


	void handleCollision(GameInformation& gameInfo, Participant& obj, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameInformation& gameInfo, SmartGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameInformation& gameInfo, Player& player, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameInformation& gameInfo, DumbGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	
	  
private:
	sf::Vector2f getWantedDirection() const;
	
	
};