#pragma once
#include "StaticParticipant.h"


class Rock : public StaticParticipant
{
public:
	Rock(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	
	void handleCollision(GameInformation& m_gameInfo, sf::Vector2f& newTopLeft,
		sf::Vector2f& newDirection, Participant& obj) override;



private:

};