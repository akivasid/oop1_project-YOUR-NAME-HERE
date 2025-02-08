#include "Door.h"


Door::Door(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:StaticParticipant(location, wantedSize, ParticipantType::Door)
{}

//=================================================== public functions =============================
void Door::handleCollision(Participant& obj, GameInformation& gameInfo)
{}


void Door::handleCollision(Player& player, GameInformation& gameInfo)
{
	if (player.getTopLeft() == m_topLeft)
		gameInfo.setPlayerWon();
}


void Door::handleCollision(SmartGuard& guard, GameInformation& gameInfo)
{
	if (guard.getTopLeft() == m_topLeft)
		guard.setDirection(MovementConsts::NO_DIRECTION);
}


void Door::handleCollision(DumbGuard& guard, GameInformation& gameInfo)
{
	if (guard.getTopLeft() == m_topLeft)
		guard.setDirection(MovementConsts::NO_DIRECTION);
}

void Door::handleCollision(Bomb& bomb, GameInformation& gameInfo)
{
	bomb.validationUpdate(m_topLeft);
}