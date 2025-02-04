#include "Rock.h"


Rock::Rock(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:StaticParticipant(location, wantedSize, ParticipantType::Rock)
{}



void Rock::handleCollision(Participant& obj, GameInformation& gameInfo)
{}


void Rock::handleCollision(Player& player, GameInformation& gameInfo)
{
	if (player.getTopLeft() == m_topLeft)
		player.setDirection(MovementConsts::NO_DIRECTION);
}


void Rock::handleCollision(SmartGuard& guard, GameInformation& gameInfo)
{
	if (guard.getTopLeft() == m_topLeft)
		guard.setDirection(MovementConsts::NO_DIRECTION);
}


void Rock::handleCollision(DumbGuard& guard, GameInformation& gameInfo)
{
	if (guard.getTopLeft() == m_topLeft)
		guard.setDirection(MovementConsts::NO_DIRECTION);
}

void Rock::handleCollision(Bomb& bomb, GameInformation& gameInfo)
{}