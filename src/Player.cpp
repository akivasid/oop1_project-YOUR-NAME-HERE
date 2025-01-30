#include "Player.h"


//====================================== constructor =================================
Player::Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Player)
{}

//===================================== public functions =================================

void Player::updateMovement(GameWindow& gameWindow, GameInformation& gameInfo, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	newDirection = getWantedDirection();
	newTopLeft = gameWindow.getNextTopLeft(m_topLeft, newDirection);
	if (!gameWindow.inArea(newTopLeft))
	{
		newDirection = MovementConsts::NO_DIRECTION;
		newTopLeft = m_topLeft;
	}
}


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

void Player::handleCollision(GameInformation& gameInfo, Participant& obj, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	
	obj.handleCollision(gameInfo, *this, newDirection, newTopLeft);
	gameInfo.setPlayerLocation(newTopLeft);
}


void Player::finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection)
{
	m_topLeft = newTopLeft;
	m_direction = newDirection;
}

void Player::handleCollision(GameInformation& gameInfo, SmartGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) 
{
	if (newTopLeft == m_topLeft)
		gameInfo.setLife();
}


void Player::handleCollision(GameInformation& gameInfo, Player& player,	sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{}


void Player::handleCollision(GameInformation& gameInfo, DumbGuard& guard, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft)
{
	if (newTopLeft == m_topLeft)
		gameInfo.setLife();
}