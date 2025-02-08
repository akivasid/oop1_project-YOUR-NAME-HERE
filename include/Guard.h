#pragma once
#include "DynamicParticipant.h"


class Guard : public DynamicParticipant
{
public:
	//constructor
	Guard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//destructor
	virtual ~Guard() = default;

	//public functions
	void resetLocation(GameInformation& gameInfo) override;

private:

};