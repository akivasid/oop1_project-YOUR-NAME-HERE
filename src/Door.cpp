#include "Door.h"


Door::Door(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:StaticParticipant(location, wantedSize, ParticipantType::Door)
{}

//public functions
void Door::handleCollision(GameInformation& gameInfo, Participant& obj, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{}


void Door::handleCollision(GameInformation& gameInfo, SmartGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{}


void Door::handleCollision(GameInformation& gameInfo, Player& player, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	if (newTopLeft == m_topLeft)
		gameInfo.setPlayerWon();
}


void Door::handleCollision(GameInformation& gameInfo, DumbGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{}
