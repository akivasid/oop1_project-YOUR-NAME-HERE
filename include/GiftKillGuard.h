#pragma once
#include "Gift.h"


class GiftKillGuard : public Gift
{
public:
	//constructor
	GiftKillGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	void handleCollision(Participant& obj, GameInformation& gameInfo) override {};
	void handleCollision(Player& player, GameInformation& gameInfo) override;
	void handleCollision(SmartGuard& guard, GameInformation& gameInfo) override {};
	void handleCollision(DumbGuard& guard, GameInformation& gameInfo) override {};
	void handleCollision(Bomb& bomb, GameInformation& gameInfo) override {};

private:

};
