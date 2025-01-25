#pragma once
#include "DynamicParticipant.h"


class Player : public DynamicParticipant
{
public:
	//constructor
	Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	bool gotToTopLeft() const override;
	const sf::Vector2f getWantedDirection() const override;
	void updateMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection) override;
	void move(const float& seconds) override;
	
	  
private:
	//private functions
	sf::Vector2f getNewLocation(const float& seconds) const;
};