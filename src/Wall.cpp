#include "Wall.h"

Wall::Wall(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:StaticParticipant(location, wantedSize, ParticipantType::Wall)
{}



void Wall::handleCollision(Participant& obj, GameInformation& gameInfo)
{}


void Wall::handleCollision(Player& player, GameInformation& gameInfo)
{
	if (player.getTopLeft() == m_topLeft)
		player.setDirection(MovementConsts::NO_DIRECTION);
}


void Wall::handleCollision(SmartGuard& guard, GameInformation& gameInfo)
{
	if (guard.getTopLeft() == m_topLeft)
		guard.setDirection(MovementConsts::NO_DIRECTION);
}


void Wall::handleCollision(DumbGuard& guard, GameInformation& gameInfo)
{
	if (guard.getTopLeft() == m_topLeft)
		guard.setDirection(MovementConsts::NO_DIRECTION);
}

void Wall::handleCollision(Bomb& bomb, GameInformation& gameInfo)
{
	bomb.validationUpdate(m_topLeft);
}