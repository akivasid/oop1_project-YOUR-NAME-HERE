#pragma once
#include "DynamicParticipant.h"


class Player : public DynamicParticipant
{
public:
	//constructor
	Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	void move();


private:

};