#include "Player.h"


//====================================== constructor =================================
Player::Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Player, MovementConsts::PLAYER_SPEED)
{}

//===================================== public functions =================================

void Player::updateMovement(GameWindow& gameWindow, GameInformation& gameInfo)
{
	changeDirection();
	sf::Vector2f newTopLeft = gameWindow.getNextTopLeft(m_topLeft, m_direction);
	if (gameWindow.inArea(newTopLeft))
		m_topLeft = newTopLeft;
	else
		m_direction = MovementConsts::NO_DIRECTION;
}


void Player::handleCollision(Participant& obj, GameInformation& gameInfo)
{
	obj.handleCollision(*this, gameInfo);
	gameInfo.setPlayerLocation(m_topLeft);
}


void Player::handleCollision(SmartGuard& guard, GameInformation& gameInfo)
{
	if (guard.getTopLeft() == m_topLeft)
		gameInfo.lostLife();
}


void Player::handleCollision(Player& player, GameInformation& gameInfo)
{}


void Player::handleCollision(DumbGuard& guard, GameInformation& gameInfo)
{
	if (guard.getTopLeft() == m_topLeft)
		gameInfo.lostLife();
}


void Player::handleCollision(Bomb& bomb, GameInformation& gameInfo)
{
	if (bomb.bombExploded() && bomb.inExplosionArea(m_topLeft))
		gameInfo.lostLife();
}

void Player::resetLocation(GameInformation& gameInfo)
{
	m_topLeft = m_firstLocation;
	m_curLocation = m_topLeft;
	m_direction = MovementConsts::NO_DIRECTION;
	gameInfo.setPlayerLocation(m_topLeft);
	m_picture.setPosition(m_topLeft);
}

//======================================= private functions =========================================

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
