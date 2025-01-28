#pragma once
#include "StaticParticipant.h"
#include "SmartGuard.h"


class Wall : public StaticParticipant
{
public:
	Wall(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	void handleCollision(GameWindow& gameWindow, GameInformation& gameInfo, Participant& obj,
		sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameWindow& gameWindow, GameInformation& gameInfo, SmartGuard& obj,
		sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;

private:


};