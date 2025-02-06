#pragma once
#include <SFML/Graphics.hpp>


namespace BombConst
{
	const sf::Time COUNT_DOWN = sf::seconds(5);
	const sf::Time EXPLOSION_TIME = sf::seconds(2);

	const std::string EXPLOSION_SOUND  = "BombExplodeMusic.wav";
	const std::string COUNT_DOWN_SOUND = "CountDownMusic.wav";
}