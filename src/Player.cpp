#include "Player.h"


//====================================== constructor =================================
Player::Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Player)
{}

//===================================== public functions =================================

void Player::updateMovement(GameWindow& gameWindow, GameInformation& gameInfo)
{
	if (bombDropped(gameInfo))
		return;
		
	changeDirection();
	sf::Vector2f newTopLeft = gameWindow.getNextTopLeft(m_topLeft, m_direction);
	if (gameWindow.inArea(newTopLeft))
		m_topLeft = newTopLeft;
	else
		m_direction = MovementConsts::NO_DIRECTION;
}


void Player::changeDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_direction = MovementConsts::DIRECTION_RIGHT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_direction = MovementConsts::DIRECTION_LEFT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_direction = MovementConsts::DIRECTION_UP;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_direction = MovementConsts::DIRECTION_DOWN;
}

void Player::handleCollision(Participant& obj, GameInformation& gameInfo)
{
	obj.handleCollision(*this, gameInfo);
	gameInfo.setPlayerLocation(m_topLeft);
}


void Player::handleCollision(SmartGuard& guard, GameInformation& gameInfo)
{
	if (guard.getTopLeft() == m_topLeft)
		gameInfo.setLife();
}


void Player::handleCollision(Player& player, GameInformation& gameInfo)
{}


void Player::handleCollision(DumbGuard& guard, GameInformation& gameInfo)
{
	if (guard.getTopLeft() == m_topLeft)
		gameInfo.setLife();
}


bool Player::bombDropped(GameInformation& gameInfo)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		gameInfo.setDropBomb(true);
		return true;
	}
	return false;
}

void Player::handleCollision(Bomb& bomb, GameInformation& gameInfo)
{
	if (bomb.bombExploded() && bomb.inExplosionArea(m_topLeft))
		gameInfo.setLife();
}