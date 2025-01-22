#pragma once
#include "DynamicParticipant.h"


class Player : public DynamicParticipant
{
public:
	//constructor
	Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	const sf::Vector2f getDirection() const override;
	void move(const sf::Vector2f& newLoc) override;
	const sf::Vector2f getNewLocation(const sf::Vector2f& direction, const float& seconds) const override;


private:

};