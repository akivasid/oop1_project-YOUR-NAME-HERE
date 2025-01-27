#pragma once
#include "Guard.h"

class SmartGuard : public Guard
{
public:
	//constructor
	SmartGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	sf::Vector2f getWantedDirection() const override;
	

private:
	sf::Vector2f m_target;
};