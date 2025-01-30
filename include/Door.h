#pragma once
#include "StaticParticipant.h"

class Door : public StaticParticipant
{
public:
	//constructor
	Door(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	void handleCollision(GameInformation& gameInfo, Participant& obj, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameInformation& gameInfo, SmartGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameInformation& gameInfo, Player& player, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameInformation& gameInfo, DumbGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;

private:

};