#include "Gift.h"

Gift::Gift(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type)
	:StaticParticipant(location, wantedSize, type)
{}