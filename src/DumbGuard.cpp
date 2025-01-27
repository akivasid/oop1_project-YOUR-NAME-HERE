#include "DumbGuard.h"


DumbGuard::DumbGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:Guard(location, wantedSize)
{}


sf::Vector2f DumbGuard::getWantedDirection() const
{
	int directionRandom = std::rand() % 4;
	switch (directionRandom)
	{
	case  0:
		return MovementConsts::DIRECTION_RIGHT;
		break;
	case 1:
		return MovementConsts::DIRECTION_LEFT;
		break;
	case 2:
		return MovementConsts::DIRECTION_UP;
		break;
	case 3:
		return MovementConsts::DIRECTION_DOWN;
		break;
	}
	return MovementConsts::NO_DIRECTION;
}


