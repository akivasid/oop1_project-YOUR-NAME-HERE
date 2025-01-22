#include "Player.h"


//====================================== constructor =================================
Player::Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Player)
{}

//===================================== public functions =============================

void Player::move(const sf::Vector2f& newLoc)
{
	if (newLoc == m_location)
		return;
	m_picture.setPosition(newLoc);
	m_location = newLoc;
}

const sf::Vector2f Player::getDirection() const
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return sf::Vector2f(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return sf::Vector2f(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return sf::Vector2f(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return sf::Vector2f(0.f, 1.f);
	return sf::Vector2f(0.f, 0.f);
}

const sf::Vector2f Player::getNewLocation(const sf::Vector2f& direction, const float& seconds) const
{
	return sf::Vector2f(m_location.x + direction.x * seconds * MovementConsts::PIXEL_PER_SECOND, 
						m_location.y + direction.y * seconds * MovementConsts::PIXEL_PER_SECOND);
}