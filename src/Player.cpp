#include "Player.h"


//====================================== constructor =================================
Player::Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Player)
{}

//===================================== public functions =================================

const sf::Vector2f Player::getWantedDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_direction = sf::Vector2f(1.f, 0.f);
		return m_direction;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_direction = sf::Vector2f(-1.f, 0.f);
		return m_direction;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_direction = sf::Vector2f(0.f, -1.f);
		return m_direction;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_direction = sf::Vector2f(0.f, 1.f);
		return m_direction;
	}
	return sf::Vector2f(0.f, 0.f);
}



void Player::move(const sf::Vector2f& newLoc)
{
	if (newLoc == m_location)
		return;
	m_picture.setPosition(newLoc);
	m_location = newLoc;
}

const sf::Vector2f Player::getNewLocation(const sf::Vector2f& direction, const float& seconds) const
{
	return sf::Vector2f(m_location.x + direction.x * seconds * MovementConsts::PIXEL_PER_SECOND,
		m_location.y + direction.y * seconds * MovementConsts::PIXEL_PER_SECOND);
}

const sf::Vector2f Player::getDirection() const
{
	return m_direction;
}

void Player::resetDirection()
{
	m_direction = sf::Vector2f(0.f, 0.f);
}