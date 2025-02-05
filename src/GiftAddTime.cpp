#include "GiftAddTime.h"


GiftAddTime::GiftAddTime(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Gift(location, wantedSize, ParticipantType::GiftAddTime), m_addTimeAmount(sf::seconds(60))
{}


void GiftAddTime::handleCollision(Player& player, GameInformation& gameInfo)
{
	if (gameInfo.getPlayerLocation() == m_topLeft)
	{
		gameInfo.addToTime(m_addTimeAmount);
		setDead();
	}
}
