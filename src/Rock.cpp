#include "Rock.h"


Rock::Rock(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:StaticParticipant(location, wantedSize, ParticipantType::Rock)
{}



void Rock::handleCollision(GameInformation& gameInfo, Participant& obj,	sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	if (newTopLeft == m_topLeft)
	{
		newTopLeft = obj.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}

void Rock::handleCollision(GameInformation& gameInfo, SmartGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	if (newTopLeft == m_topLeft)
	{
		newTopLeft = guard.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}

void Rock::handleCollision(GameInformation& gameInfo, Player& player, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	if (newTopLeft == m_topLeft)
	{
		newTopLeft = player.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}

void Rock::handleCollision(GameInformation& gameInfo, DumbGuard& guard,	sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	if (newTopLeft == m_topLeft)
	{
		newTopLeft = guard.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}