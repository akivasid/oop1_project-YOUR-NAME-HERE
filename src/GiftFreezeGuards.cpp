#include "GiftFreezeGuards.h"

// ======================================= constructor ==========================

GiftFreezeGuards::GiftFreezeGuards(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Gift(location, wantedSize, ParticipantType::GiftFreezeGuards)
{}


void GiftFreezeGuards::handleCollision(Player& player, GameInformation& gameInfo)
{
	if (gameInfo.getPlayerLocation() == m_topLeft)
	{
		gameInfo.setFreezeGuards();
		setDead();
	}
}
