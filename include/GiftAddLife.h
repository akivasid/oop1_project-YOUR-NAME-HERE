#pragma once
#include "Gift.h"


class GiftAddLife : public Gift
{
public:
	//constructor
	GiftAddLife(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	void handleCollision(Participant& obj, GameInformation& gameInfo) override {};
	void handleCollision(Player& player, GameInformation& gameInfo) override;
	void handleCollision(SmartGuard& guard, GameInformation& gameInfo) override {};
	void handleCollision(DumbGuard& guard, GameInformation& gameInfo) override {};
	void handleCollision(Bomb& bomb, GameInformation& gameInfo) override {};


private:
	//members
	int m_addLifeAmount;
};

