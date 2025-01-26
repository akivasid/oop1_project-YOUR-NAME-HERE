#include "Player.h"


//====================================== constructor =================================
Player::Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Player)
{}

//===================================== public functions =================================




sf::Vector2f Player::getWantedDirection() const
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return MovementConsts::DIRECTION_RIGHT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return MovementConsts::DIRECTION_LEFT;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return MovementConsts::DIRECTION_UP;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return MovementConsts::DIRECTION_DOWN;
	return MovementConsts::NO_DIRECTION;
}

void Player::handleCollision(GameInformation& m_gameInfo, sf::Vector2f& newTopLeft,
							sf::Vector2f& newDirection, Participant& obj)
{
	
	obj.handleCollision(m_gameInfo, newTopLeft, newDirection, *this);
	
	//std::cout << obj.getTopLeft().x << ',' << obj.getTopLeft().y << '\n' << newTopLeft.x << ',' << newTopLeft.y << '\n';
	
	

	//std::cout << obj.getTopLeft().x << ',' << obj.getTopLeft().y << '\n' << newTopLeft.x << ',' << newTopLeft.y << '\n';
	//obj.handleCollision(m_gameInfo, newTopLeft, newDirection, *this);
}

