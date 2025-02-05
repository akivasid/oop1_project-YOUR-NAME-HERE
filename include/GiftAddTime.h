#pragma once
#include "Gift.h"


class GiftAddTime : public Gift
{
public:
	//constructor
	GiftAddTime(const sf::Vector2f& location, const sf::Vector2f& wantedSize); 


	void handleCollision(Participant& obj, GameInformation& gameInfo) override {};
	void handleCollision(Player& player, GameInformation& gameInfo) override;
	void handleCollision(SmartGuard& guard, GameInformation& gameInfo) override {};
	void handleCollision(DumbGuard& guard, GameInformation& gameInfo) override {};
	void handleCollision(Bomb& bomb, GameInformation& gameInfo) override {};


private:
	//members
	sf::Time m_addTimeAmount;
};

