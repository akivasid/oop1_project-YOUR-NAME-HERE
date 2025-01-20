#pragma once
#include <SFML/Graphics.hpp>


namespace GameInfoConsts
{
	const sf::Vector2f INFO_SIZE(1000.0f, 500.0f);
	const sf::Vector2f INFO_LOCATION(0.0f, 1000.0f);
	const sf::Vector2f TEXT_LOCATION(50.0f, 1050.0f);
	const sf::Color INFO_COLOR(sf::Color(200, 0, 0));

	const sf::Time LEVEL_TIME = sf::seconds(240);

	const unsigned LIFE = 5;
	const unsigned KILL_GUARD = 5;
	const unsigned END_LEVEL = 25;
	const unsigned LEVEL_GUARD = 3;

	const std::string LEVEL_OUTPUT = "Level: ";
	const std::string LIFE_OUTPUT = "Life: ";
	const std::string SCORE_OUTPUT = "Score: ";
	const std::string TIME_OUTPUT = "Time: ";
}