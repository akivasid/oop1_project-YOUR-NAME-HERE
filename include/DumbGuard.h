#pragma once
#include "Guard.h"

class DumbGuard : public Guard
{
public:
	//constructor
	DumbGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	sf::Vector2f getWantedDirection() const override;
	

private:
};