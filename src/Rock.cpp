#include "Rock.h"


Rock::Rock(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:StaticParticipant(location, wantedSize, ParticipantType::Rock)
{}



void Rock::handleCollision(GameInformation& m_gameInfo, sf::Vector2f& newTopLeft,
	sf::Vector2f& newDirection, Participant& obj)
{
	if (newTopLeft == m_topLeft)
	{
		newTopLeft = obj.getTopLeft();
		newDirection = MovementConsts::NO_DIRECTION;
	}
}