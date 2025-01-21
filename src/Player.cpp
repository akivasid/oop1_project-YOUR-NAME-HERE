#include "Player.h"


//====================================== constructor =================================
Player::Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Player)
{}

//===================================== public functions =============================

void Player::move()
{
	/*sf::Clock clock;
	clock.restart();
	while(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (clock.getElapsedTime() >= sf::seconds(1))
		{
			m_picture.move(1.f, 0.f);
			clock.restart();
		}
	}*/
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_picture.move(0.07f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_picture.move(-0.07f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_picture.move(0.f, -0.07f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_picture.move(0.f, 0.07f);

}