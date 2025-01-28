#include "Guard.h"


//====================================== constructor =================================
Guard::Guard(const sf::Vector2f& location, const sf::Vector2f& wantedSize)
	:DynamicParticipant(location, wantedSize, ParticipantType::Guard)
{}

//===================================== public functions =============================

