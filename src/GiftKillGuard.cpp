#include "GiftKillGuard.h"


GiftKillGuard::GiftKillGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Gift(location, wantedSize, ParticipantType::GiftKillGuard)
{}


void GiftKillGuard::handleCollision(Player& player, GameInformation& gameInfo)
{
	if (gameInfo.getPlayerLocation() == m_topLeft)
	{
		gameInfo.setKillGuard(true);
		setDead();
	}
}
