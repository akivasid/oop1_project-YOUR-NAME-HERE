#pragma once



namespace MovementConsts
{
	const int PLAYER_SPEED = 120;
	const int GUARD_SPEED = 75;

	const sf::Vector2f DIRECTION_RIGHT = sf::Vector2f(1.f, 0.f);
	const sf::Vector2f DIRECTION_LEFT = sf::Vector2f(-1.f, 0.f);
	const sf::Vector2f DIRECTION_UP = sf::Vector2f(0.f, -1.f);
	const sf::Vector2f DIRECTION_DOWN = sf::Vector2f(0.f, 1.f);
	const sf::Vector2f NO_DIRECTION = sf::Vector2f(0.f, 0.f);
}