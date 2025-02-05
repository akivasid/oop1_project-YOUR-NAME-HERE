#include "GiftAddLife.h"


GiftAddLife::GiftAddLife(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Gift(location, wantedSize, ParticipantType::GiftAddLife), m_addLifeAmount(1)
{}


void GiftAddLife::handleCollision(Player& player, GameInformation& gameInfo)
{
	if (gameInfo.getPlayerLocation() == m_topLeft)
	{
		gameInfo.addLife();
		setDead();
	}
}
