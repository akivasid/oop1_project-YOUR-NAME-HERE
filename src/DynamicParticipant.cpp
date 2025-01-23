#include "DynamicParticipant.h"

DynamicParticipant::DynamicParticipant(const sf::Vector2f& location, const sf::Vector2f& wantedSize, const ParticipantType& type)
	:Participant(location, wantedSize, type), m_direction(0.f, 0.f)
{}


