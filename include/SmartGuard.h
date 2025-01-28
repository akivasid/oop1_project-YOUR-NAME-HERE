#pragma once
#include "Guard.h"


class SmartGuard : public Guard
{
public:
	//constructor
	SmartGuard(const sf::Vector2f& location, const sf::Vector2f& wantedSize);

	//public functions
	void updateMovement(GameWindow& gameWindow, GameInformation& gameInfo, sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameWindow& gameWindow, GameInformation& gameInfo, Participant& obj,
		sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void handleCollision(GameWindow& gameWindow, GameInformation& gameInfo, SmartGuard& guard,
		sf::Vector2f& newDirection, sf::Vector2f& newTopLeft) override;
	void blockDirection(const sf::Vector2f& blockedDirection);
	void openDirection(const sf::Vector2f& openDirection);
	void finalMovement(const sf::Vector2f& newTopLeft, const sf::Vector2f& newDirection) override;
	
private:
	//members
	sf::Vector2f m_target;
	bool m_upIsOpen;
	bool m_downIsOpen;
	bool m_rightIsOpen;
	bool m_leftIsOpen;

	//private functions
	sf::Vector2f getWantedDirection() const;
	void openAll();

};