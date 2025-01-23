#pragma once
#include "DynamicParticipant.h"


class Guard : public DynamicParticipant
{
public:
	//constructor
	Guard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	const sf::Vector2f getWantedDirection() override;
	void move(const sf::Vector2f& newLoc) override;
	const sf::Vector2f getNewLocation(const sf::Vector2f& direction, const float& seconds) const override;
	const sf::Vector2f getDirection() const;
	void resetDirection() override;




private:




};