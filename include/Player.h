#pragma once
#include "DynamicParticipant.h"


class Player : public DynamicParticipant
{
public:
	//constructor
	Player(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	sf::Vector2f getWantedDirection() const override;

	void handleCollision(GameInformation& m_gameInfo, sf::Vector2f& newTopLeft,
							sf::Vector2f& newDirection, Participant& obj) override;
	
	  
private:
	
	
};