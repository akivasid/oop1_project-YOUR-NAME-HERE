#include "SmartGuard.h"

SmartGuard::SmartGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Guard(location, wantedSize), m_target(location)
{}


sf::Vector2f SmartGuard::getWantedDirection() const
{
	
}

