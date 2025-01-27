#pragma once
#include "DynamicParticipant.h"


class Guard : public DynamicParticipant
{
public:
	//constructor
	Guard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	
	void handleCollision(GameInformation& m_gameInfo, sf::Vector2f& newTopLeft,
		sf::Vector2f& newDirection, Participant& obj) override;
	
private:
	

};